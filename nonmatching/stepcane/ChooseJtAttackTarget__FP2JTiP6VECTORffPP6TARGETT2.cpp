#include "sly2.h"
struct M3 { QW row[3]; };
struct M4 { QW row[4]; };
struct TARGET;
struct JT { char pad[0xC]; char *vt; };
struct TVT { char pad[0x100]; short delta; short idx; void *(*fn)(void *, void *); };
struct TOBJ { char pad[0xC]; TVT *vt; char pad1[0xD0]; TOBJ *next; char pad2[4]; unsigned grf; };
struct JVT { char pad[0x108]; short delta; short idx; QW (*fn)(void *); };
struct JOBJ { char pad[0xC]; JVT *vt; };
extern "C" {
QW PosLoWorld(void *);
void LoadRotateMatrixRad(M4 *, float, QW);
QW ConvertAloPos(void *, void *, QW);
void PredictXfTransform(void *, void *, float, M4 *, void *);
void ClosestPointOnSegment(QW, QW, QW, void *, float *, float *);
void *PloFindSwObjectByClass(void *, int, int, void *);
float RadNormalize__Ff(float);
float atan2f(float, float);
}
extern QW g_2a2dc0;
extern TOBJ *B_003E13B4;
extern char B_003DD490[];
extern float D_002BF4B8;
struct LOC {
    M3 heading;       // 0x00
    QW posLead;       // 0x30
    QW aimMinus;      // 0x60
    QW posAim;        // 0x50
    QW conv2;         // 0x40
    QW posTarget;     // 0x70
    M4 pred;          // 0x80
    QW outVec;        // 0xC0
    M4 mat;           // 0xD0
    M4 local;         // 0x110
    float closest[2]; // 0x150
    char pad[8];
    QW posJt;         // 0x160
    QW scale;         // 0x170
    QW spill;         // 0x180
};
void ChooseJtAttackTarget(JOBJ *jt, int grf, QW *poffset, float radHeading, float dt, TARGET **pptarget, TARGET **pvecDir, float radMax)
{
    TOBJ *best = 0;
    float sBest = 300.0f;
    LOC l;
    QW scaleBits;
    asm("mfc1 %0, %1" : "=r" (scaleBits) : "f" (dt));
    l.scale = scaleBits;
    LoadRotateMatrixRad(&l.mat, radHeading, g_2a2dc0);
    l.heading.row[0] = l.mat.row[0];
    l.heading.row[2] = l.mat.row[2];
    l.heading.row[1] = l.mat.row[1];
    l.posJt = PosLoWorld(jt);
    JVT *vt = jt->vt;
    short delta = vt->delta;
    l.mat.row[0] = l.scale;
    QW (*fn)(void *) = vt->fn;
    QW vel = fn((char *)jt + delta);
    asm("lqc2 vf2, %0" : : "m" (l.posJt));
    asm("lqc2 vf3, %0" : : "m" (l.scale));
    asm("qmtc2.ni %0, vf4" : : "r" (vel));
    asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf1, vf4, vf3x");
    asm("sqc2 vf1, %0" : "=m" (l.posLead));
    QW posConv = ConvertAloPos(jt, 0, *poffset);
    asm("lqc2 vf3, %0" : : "m" (*poffset));
    asm("lqc2 vf1, %0" : : "m" (l.heading.row[2]));
    asm("lqc2 vf5, %0" : : "m" (l.heading.row[0]));
    asm("lqc2 vf4, %0" : : "m" (l.heading.row[1]));
    asm("qmtc2.ni %0, vf6" : : "r" (posConv));
    asm("vmulax.xyz ACC, vf5, vf3x\n\tvmadday.xyz ACC, vf4, vf3y\n\tvmaddz.xyz vf3, vf1, vf3z");
    asm("lqc2 vf2, %0" : : "m" (l.posLead));
    asm("vadd.xyzw vf3, vf3, vf2");
    asm("vsub.xyzw vf1, vf3, vf6");
    asm("sqc2 vf6, %0" : "=m" (l.conv2));
    asm("sqc2 vf1, %0" : "=m" (l.aimMinus));
    asm("sqc2 vf3, %0" : "=m" (l.posAim));
    for (TOBJ *obj = B_003E13B4; obj; obj = obj->next) {
        if (!(obj->grf & grf))
            continue;
        l.posTarget = PosLoWorld(obj);
        void *xf = obj->vt->fn((char *)obj + obj->vt->delta, &l.local);
        PredictXfTransform(xf, 0, dt, &l.pred, 0);
        asm("lqc2 vf5, %0" : : "m" (l.local.row[3]));
        asm("lqc2 vf4, %0" : : "m" (l.pred.row[0]));
        asm("lqc2 vf3, %0" : : "m" (l.pred.row[1]));
        asm("lqc2 vf2, %0" : : "m" (l.pred.row[2]));
        asm("lqc2 vf1, %0" : : "m" (l.pred.row[3]));
        asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf6, vf1, vf0w");
        QW posSub;
        asm("qmfc2.ni %0, vf6" : "=r" (posSub));
                ClosestPointOnSegment(l.posAim, l.posTarget, posSub, 0, &l.closest[0], &l.closest[1]);
        if (PloFindSwObjectByClass(B_003DD490, 3, 0x33, obj))
            l.closest[1] = l.closest[1] + D_002BF4B8;
        if (l.closest[1] < sBest) {
            asm("lqc2 vf1, %0" : : "m" (l.posTarget));
            asm("sqc2 vf1, %0" : "=m" (l.spill));
            QW posJt2 = PosLoWorld(jt);
            asm("lqc2 vf1, %0" : : "m" (l.spill));
            asm("qmtc2.ni %0, vf2" : : "r" (posJt2));
            asm("vsub.xyzw vf1, vf1, vf2");
            asm("sqc2 vf1, %0" : "=m" (l.mat.row[0]));
                        float y = ((float *)&l.mat.row[0])[1];
            float x = ((float *)&l.mat.row[0])[0];
            float ang = atan2f(y, x);
            float rel = RadNormalize__Ff(ang - radHeading);
            float mag = rel < 0 ? -rel : rel;
            if (radMax < mag)
                continue;
            asm("lqc2 vf2, %0" : : "m" (l.pred.row[3]));
            best = obj;
            asm("lqc2 vf1, %0" : : "m" (l.posLead));
            asm("vsub.xyzw vf2, vf2, vf1");
            asm("sqc2 vf2, %0" : "=m" (l.outVec));
            sBest = l.closest[1];
        }
    }
    *(TOBJ **)pptarget = best;
    *(QW *)pvecDir = l.outVec;
}
