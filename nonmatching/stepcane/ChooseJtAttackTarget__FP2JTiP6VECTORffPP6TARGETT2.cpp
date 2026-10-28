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
    QW conv2;         // 0x40
    QW posAim;        // 0x50
    QW aimMinus;      // 0x60
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
    register QW v2 asm("vf2") = l.posJt;
    register QW v3 asm("vf3") = l.scale;
    register QW v4 asm("vf4");
    asm("qmtc2.ni %1, vf4" : "=j" (v4) : "r" (vel), "j" (v2), "j" (v3));
    register QW v1 asm("vf1");
    asm("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf1, vf4, vf3x" : "=j" (v1) : "j" (v2), "j" (v3), "j" (v4));
    l.posLead = v1;
    QW posConv = ConvertAloPos(jt, 0, *poffset);
    register QW w3 asm("vf3") = *poffset;
    register QW w1 asm("vf1") = l.heading.row[2];
    register QW w5 asm("vf5") = l.heading.row[0];
    register QW w4 asm("vf4") = l.heading.row[1];
    register QW w6 asm("vf6");
    asm("qmtc2.ni %1, vf6" : "=j" (w6) : "r" (posConv), "j" (w3), "j" (w1), "j" (w5), "j" (w4));
    asm("vmulax.xyz ACC, vf5, vf3x\n\tvmadday.xyz ACC, vf4, vf3y\n\tvmaddz.xyz vf3, vf1, vf3z" : "=j" (w3) : "j" (w3), "j" (w1), "j" (w5), "j" (w4));
    register QW w2 asm("vf2") = l.posLead;
    asm("vadd.xyzw vf3, vf3, vf2" : "=j" (w3) : "j" (w3), "j" (w2));
    asm("vsub.xyzw vf1, vf3, vf6" : "=j" (w1) : "j" (w3), "j" (w6));
    l.conv2 = w6;
    l.aimMinus = w1;
    l.posAim = w3;
    for (TOBJ *obj = B_003E13B4; obj; obj = obj->next) {
        if (!(obj->grf & grf))
            continue;
        l.posTarget = PosLoWorld(obj);
        void *xf = obj->vt->fn((char *)obj + obj->vt->delta, &l.local);
        PredictXfTransform(xf, 0, dt, &l.pred, 0);
        asm volatile("" : : "f" (dt));
        register QW c5 asm("vf5") = l.local.row[3];
        register QW c4 asm("vf4") = l.pred.row[0];
        register QW c3 asm("vf3") = l.pred.row[1];
        register QW c2 asm("vf2") = l.pred.row[2];
        register QW c1 asm("vf1") = l.pred.row[3];
        register QW posSub asm("vf6");
        asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf6, vf1, vf0w"
            : "=j" (posSub) : "j" (c5), "j" (c4), "j" (c3), "j" (c2), "j" (c1));
        ClosestPointOnSegment(l.posAim, l.posTarget, posSub, 0, &l.closest[0], &l.closest[1]);
        if (PloFindSwObjectByClass(B_003DD490, 3, 0x33, obj))
            l.closest[1] = l.closest[1] + D_002BF4B8;
        if (l.closest[1] < sBest) {
            register QW t1 asm("vf1") = l.posTarget;
            l.spill = t1;
            QW posJt2 = PosLoWorld(jt);
            register QW t1b asm("vf1") = l.spill;
            register QW t2 asm("vf2");
            asm("qmtc2.ni %1, vf2" : "=j" (t2) : "r" (posJt2), "j" (t1b));
            asm("vsub.xyzw vf1, vf1, vf2" : "=j" (t1b) : "j" (t1b), "j" (t2));
            l.mat.row[0] = t1b;
            float y = ((float *)&l.mat.row[0])[1];
            float x = ((float *)&l.mat.row[0])[0];
            float ang = atan2f(y, x);
            float rel = RadNormalize__Ff(ang - radHeading);
            float mag = rel < 0 ? -rel : rel;
            if (radMax < mag)
                continue;
            register QW o2 asm("vf2") = l.pred.row[3];
            best = obj;
            register QW o1 asm("vf1") = l.posLead;
            asm("vsub.xyzw vf2, vf2, vf1" : "=j" (o2) : "j" (o2), "j" (o1));
            sBest = l.closest[1];
            l.outVec = o2;
        }
    }
    *(TOBJ **)pptarget = best;
    *(QW *)pvecDir = l.outVec;
}
