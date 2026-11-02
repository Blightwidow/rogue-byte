#include "sly2.h"
// IntegrateCloth: Verlet-style step of the cloth particles, then rebuilds the triangle planes.
// Behaviour: for each particle i < ccp: vel' = vel + accel * dt; pos' = pos + (vel + vel') * dt / 2;
// if pcloth->fStretch != -1 and |pos - pos'|^2 > 1, pcloth->fStretch = -1; stores pos', vel';
// pcloth->rMax = sqrt(max |pos'|^2). Then BuildPlane(&aplane[i], pos[a], pos[b], pos[c]) per triangle.
struct TRI { int aipos[3]; };
struct PLANE { QW normal; QW extra; };
struct CLOTHDATA { QW *avel; QW *aaccel; TRI *atri; };
struct CLOTH {
    char pad0[8];
    float rMax;
    char pad0C[4];
    CLOTHDATA *pdata;
    char pad14[0x78 - 0x14];
    int cpos;
    QW *apos;
    int ctri;
    PLANE *aplane;
    char pad88[0xA8 - 0x88];
    int fStretch;
};
void BuildPlane(PLANE *, QW, QW, QW);

static inline float SqrtF(float value)
{
    float result;
    asm("sqrt.s %0, %1" : "=f" (result) : "f" (value));
    return result;
}

void IntegrateCloth(CLOTH *pcloth, float dt)
{
    QW *avel = pcloth->pdata->avel;
    QW *aaccel = pcloth->pdata->aaccel;
    QW *apos = pcloth->apos;
    float rSqMax = 0.0f;
    float dtHalf = dt * 0.5f;
    for (int i = 0; i < pcloth->cpos; i++) {
        QW vel;
        QW pos;
        asm("qmtc2.ni %4, $vf7\n\t"
            "qmtc2.ni %5, $vf6\n\t"
            "lqc2 $vf1, %2\n\t"
            "lqc2 $vf4, %3\n\t"
            "lqc2 $vf2, 0(%6)\n\t"
            "vadda.xyzw $ACC, $vf0, $vf1\n\t"
            "vmaddx.xyzw $vf5, $vf2, $vf7x\n\t"
            "vadda.xyzw $ACC, $vf0, $vf4\n\t"
            "vmaddax.xyzw $ACC, $vf1, $vf6x\n\t"
            "vmaddx.xyzw $vf3, $vf5, $vf6x\n\t"
            "sqc2 $vf5, %0\n\t"
            "sqc2 $vf3, %1"
            : "=m" (vel), "=m" (pos)
            : "m" (avel[i]), "m" (apos[i]), "r" (dt), "r" (dtHalf), "r" (&aaccel[i]));
        if (pcloth->fStretch != -1) {
            float rSqMove;
            asm("lqc2 $vf4, %1\n\t"
                "lqc2 $vf3, %2\n\t"
                "vsub.xyzw $vf1, $vf4, $vf3\n\t"
                "vmul.xyz $vf1, $vf1, $vf1\n\t"
                "vaddw.x $vf2, $vf0, $vf0w\n\t"
                "vadday.x $ACC, $vf1, $vf1y\n\t"
                "vmaddz.x $vf1, $vf2, $vf1z\n\t"
                "qmfc2.ni $2, $vf1\n\t"
                "mtc1 $2, %0"
                : "=f" (rSqMove)
                : "m" (apos[i]), "m" (pos)
                : "$2");
            if (rSqMove > 1.0f)
                pcloth->fStretch = -1;
        }
        float rSq;
        asm("lqc2 $vf3, %1\n\t"
            "vmul.xyz $vf2, $vf3, $vf3\n\t"
            "vaddw.x $vf1, $vf0, $vf0w\n\t"
            "vadday.x $ACC, $vf2, $vf2y\n\t"
            "vmaddz.x $vf2, $vf1, $vf2z\n\t"
            "qmfc2.ni $2, $vf2\n\t"
            "mtc1 $2, %0"
            : "=f" (rSq)
            : "m" (pos)
            : "$2");
        apos[i] = pos;
        avel[i] = vel;
        if (rSqMax < rSq)
            rSqMax = rSq;
    }
    pcloth->rMax = SqrtF(rSqMax);
    TRI *atri = pcloth->pdata->atri;
    for (int itri = 0; itri < pcloth->ctri; itri++) {
        TRI *ptri = &atri[itri];
        BuildPlane(&pcloth->aplane[itri], apos[ptri->aipos[0]], apos[ptri->aipos[1]], apos[ptri->aipos[2]]);
    }
}
