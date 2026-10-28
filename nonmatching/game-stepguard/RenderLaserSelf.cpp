#include "sly2.h"
struct MATRIX44 { float mat[4][4]; } __attribute__((aligned(16)));
struct ROWS3 { VECTOR row[3]; };
struct LASERFX { int plo; int unk4; int pasega; int pchn; };
struct LASER {
    char pad0[0xEC]; char *poxa;
    char pad1[0x190 - 0xF0]; int ploBeam; int ploBeamCore; int cbeam; char *pbeams; LASERFX afx[2];
};
struct LASERBEAM { char pad[0x144]; float sClipped; char pad2[0xC]; };
extern "C" void func_001F3C70(LASER *);
extern "C" int FInsideCmFrustrum(void *, QW, QW);
extern "C" void GetLaserBeamPoints(LASER *, LASERBEAM *, VECTOR *, float *);
extern "C" void func_001A5FB8(int, QW, QW, float, float);
extern "C" void func_001A5EE8(int, MATRIX4 *, float, float);
extern "C" void LoadMatrixFromPosRotScale(MATRIX4 *, QW, ROWS3 *, float *);
extern "C" void __as__6VECTORG9VU_VECTOR(VECTOR *, QW);
extern "C" char B_002DDF40[];
extern "C" QW g_2a2dc0;
extern "C" void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(ROWS3 *, QW, QW);

struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, float *, int, float, float); };
struct ENDM { VECTOR row[4]; };

#define AGSCALE ((float *)(buf))
#define APOS ((VECTOR *)(buf + 0x10))
#define MATROT (*(ROWS3 *)(buf + 0x30))
#define BUILT3 (*(ROWS3 *)(buf + 0x60))
#define MATEND (*(ENDM *)(buf + 0x60))
#define ENDBUILT (*(MATRIX4 *)(buf + 0xA0))
#define COREBUILT (*(MATRIX4 *)(buf + 0xD0))
#define COREFINAL (*(MATRIX4 *)(buf + 0x90))
#define SLENGTH (*(float *)(buf + 0x110))
#define DPOS (*(QW *)(buf + 0x120))
void RenderLaserSelf(LASER *plaser)
{
    char buf[0x130] __attribute__((aligned(16)));
    func_001F3C70(plaser);
    char *poxa = plaser->poxa;
    if (poxa == 0) return;
    QW dc;
    asm("lqc2 vf2, %0" : : "m"(*(VECTOR *)(poxa + 0x20)));
    asm("lqc2 vf1, %0" : : "m"(*(VECTOR *)(B_002DDF40 + 0x90)));
    asm("vsub.xyzw vf3, vf2, vf1");
    asm("qmfc2.ni %0, vf3" : "=r" (dc));
    QW radius = *(int *)(poxa + 0x30);
    *(QW *)AGSCALE = radius;
    if (FInsideCmFrustrum(B_002DDF40, dc, radius) == 0) return;
    for (int ibeam = 0; ibeam < plaser->cbeam; ibeam++) {
        LASERBEAM *pbeam = (LASERBEAM *)(plaser->pbeams + ibeam * 0x150);
        GetLaserBeamPoints(plaser, pbeam, APOS, &SLENGTH);
        if (pbeam->sClipped < SLENGTH) {
            float u = pbeam->sClipped / SLENGTH;
            asm("lqc2 vf3, %0" : : "m"(APOS[1]));
            asm("lqc2 vf2, %0" : : "m"(APOS[0]));
            asm("qmtc2.ni %0, vf4" : : "r"(u));
            asm("vmulx.xyzw vf3, vf3, vf4x");
            float inv = 1.0f - u;
            asm("qmtc2.ni %0, vf1" : : "r"(inv));
            asm("vmulx.xyzw vf2, vf2, vf1x");
            asm("sqc2 vf1, %0" : "=m"(*(QW *)AGSCALE));
            asm("vadd.xyzw vf2, vf2, vf3");
            asm("sqc2 vf4, %0" : "=m"(*(QW *)AGSCALE));
            asm("sqc2 vf2, %0" : "=m"(APOS[1]));
        }
        if (plaser->ploBeam != 0)
            func_001A5FB8(plaser->ploBeam, *(QW *)&APOS[0], *(QW *)&APOS[1], 1.0f, 1.0f);
        if (plaser->ploBeamCore != 0 || plaser->afx[0].plo != 0 || plaser->afx[1].plo != 0) {
            asm("lqc2 vf2, %0" : : "m"(APOS[1]));
            asm("lqc2 vf1, %0" : : "m"(APOS[0]));
            asm("vsub.xyzw vf3, vf2, vf1");
            asm("sqc2 vf3, %0" : "=m"(DPOS));
                        BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&BUILT3, DPOS, g_2a2dc0);
            MATROT = BUILT3;
        }
        if (plaser->ploBeamCore != 0) {
            float len;
            asm("lqc2 vf4, %0" : : "m"(DPOS));
            asm("vmul.xyz vf1, vf4, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
            float lim = 0.01f;
            asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
            int bits;
            asm("qmfc2.ni %0, vf1" : "=r"(bits));
            asm("mtc1 %1, %0\n\tnop" : "=f"(len) : "r"(bits));
            if (lim < len) {
                AGSCALE[1] = 1.0f; AGSCALE[2] = 1.0f; AGSCALE[0] = len * lim;
                LoadMatrixFromPosRotScale(&COREBUILT, *(QW *)&APOS[0], &MATROT, AGSCALE);
                COREFINAL = COREBUILT;
                func_001A5EE8(plaser->ploBeamCore, &COREFINAL, 1.0f, 1.0f);
            }
        }
        for (unsigned iend = 0; iend < 2; iend++) {
            LASERFX *pfx = &plaser->afx[iend];
            if (pfx->plo == 0) continue;
            if (pfx->pchn != 0) {
                char *pchn = (char *)pfx->pchn;
                char *pasega = (char *)pfx->pasega;
                VT *vt = *(VT **)pchn;
                vt->fn(pchn + vt->delta, AGSCALE, 0, *(float *)(pasega + 0x1C), *(float *)(pasega + 0x40));
                LoadMatrixFromPosRotScale(&ENDBUILT, *(QW *)&APOS[iend], &MATROT, AGSCALE);
                *(MATRIX4 *)&MATEND = ENDBUILT;
            } else {
                __as__6VECTORG9VU_VECTOR(&MATEND.row[3], *(QW *)&APOS[iend]);
                MATEND.row[0] = MATROT.row[0];
                MATEND.row[1] = MATROT.row[1];
                MATEND.row[2] = MATROT.row[2];
                MATEND.row[2].w = 0.0f;
                MATEND.row[1].w = 0.0f;
                MATEND.row[0].w = 0.0f;
                MATEND.row[3].w = 1.0f;
            }
            func_001A5EE8(pfx->plo, (MATRIX4 *)&MATEND, 1.0f, 1.0f);
        }
    }
}
