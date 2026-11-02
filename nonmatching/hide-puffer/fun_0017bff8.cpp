#include "sly2.h"
struct LM_17BFF8 { float gMin; float gMax; };
struct SCALER_17BFF8 { char pad[0x20]; float scale; };
struct TUNING_17BFF8 { char pad0[0x10]; int mode; float radYaw; float radPitch; };
struct PLAYER_17BFF8 {
    char pad0[0x31C];
    LM_17BFF8 lmTurn;
    LM_17BFF8 lmTilt;
    char pad1[0x3CC - 0x32C];
    TUNING_17BFF8 *ptuning;
    char pad2[0xFBC - 0x3D0];
    int mode;
    char pad3[0xFC4 - 0xFC0];
    SCALER_17BFF8 *pscaler;
};
struct GUARD_17BFF8 { char pad0[0x10]; PLAYER_17BFF8 *pplayer; };
struct CLSG_17BFF8 { QW pos0; QW pos1; QW pad[4]; };
extern "C" {
extern const float RO_002A5600;
void ClosestPointOnSegment(QW, QW, QW, QW *, float *, float *);
int ClsgClipEdgeToPathzoneObstacles(int, QW, QW, int, CLSG_17BFF8 *);
void DecomposeCylind(QW, float *, float *, int);
int FCheckLm__FP2LMf(LM_17BFF8 *, float);
float GLimitAbs__Fff(float, float);
float GLimitLm__FP2LMf(LM_17BFF8 *, float);
QW PosLoWorld(PLAYER_17BFF8 *);
float RadNormalize__Ff(float);
QW SetVectorCylind__FP6VECTORfff(float, float, float);
int func_001C0B50(int, QW, QW *);
}
/* v - *pbase */
static inline QW SubVecMem_17BFF8(QW v, QW *pbase)
{
    int fence0, fence1, fence2;
    QW out;
    asm("qmtc2.ni %1, vf1" : "=r"(fence0) : "r"(v));
    asm("lqc2 vf2, %1" : "=r"(fence1) : "m"(*pbase), "r"(fence0));
    asm("vsub.xyzw vf1, vf1, vf2" : "=r"(fence2) : "r"(fence1));
    asm("qmfc2.ni %0, vf1" : "=r"(out) : "r"(fence2));
    return out;
}
/* *pbase + v */
static inline QW AddVecMem_17BFF8(QW *pbase, QW v)
{
    int fence0, fence1, fence2;
    QW out;
    asm("lqc2 vf4, %1" : "=r"(fence0) : "m"(*pbase));
    asm("qmtc2.ni %1, vf1" : "=r"(fence1) : "r"(v), "r"(fence0));
    asm("vadd.xyzw vf4, vf4, vf1" : "=r"(fence2) : "r"(fence1));
    asm("qmfc2.ni %0, vf4" : "=r"(out) : "r"(fence2));
    return out;
}
extern "C" QW func_0017BFF8(GUARD_17BFF8 *pguard, int graph, QW posStart, float radHeading)
{
    struct {
        QW posResult;
        LM_17BFF8 lmTurn __attribute__((aligned(16)));
        LM_17BFF8 lmTilt __attribute__((aligned(16)));
        LM_17BFF8 lmPick __attribute__((aligned(16)));
        QW posClosest;
        CLSG_17BFF8 aclsg[8];
        float radYaw, radPitch;
        float radYaw2, radPitch2;
        float dist;
    } L;
    QW posRef;
    int count;
    PLAYER_17BFF8 *pplayer = pguard->pplayer;
    L.lmTurn = pplayer->lmTurn;
    L.lmTilt = pplayer->lmTilt;
    if (pplayer->mode == 8 || pplayer->mode == 0xD) {
        SCALER_17BFF8 *pscaler = pplayer->pscaler;
        if (pscaler != 0) {
            float scale = pscaler->scale;
            L.lmTurn.gMin *= scale;
            L.lmTurn.gMax *= scale;
            L.lmTilt.gMin *= scale;
            L.lmTilt.gMax *= scale;
        }
    }
    TUNING_17BFF8 *ptuning = pguard->pplayer->ptuning;
    DecomposeCylind(SubVecMem_17BFF8(PosLoWorld(pguard->pplayer), &posStart), &L.radYaw, &L.radPitch, 0);
    float radAim = radHeading + GLimitAbs__Fff(RadNormalize__Ff(L.radYaw - radHeading), ptuning->radYaw);
    QW dir = SetVectorCylind__FP6VECTORfff(radAim, GLimitLm__FP2LMf(&L.lmTurn, L.radPitch), 0.0f);
    if (func_001C0B50(graph, AddVecMem_17BFF8(&posStart, dir), &L.posResult) != 0) {
        int fence0, fence1, fence2;
        QW delta;
        asm("lqc2 vf1, %1" : "=r"(fence0) : "m"(L.posResult));
        asm("lqc2 vf2, %1" : "=r"(fence1) : "m"(posStart), "r"(fence0));
        asm("vsub.xyzw vf2, vf1, vf2" : "=r"(fence2) : "r"(fence1));
        asm("qmfc2.ni %0, vf2" : "=r"(delta) : "r"(fence2));
        DecomposeCylind(delta, &L.radYaw2, &L.radPitch2, 0);
        if (__builtin_fabsf(RadNormalize__Ff(L.radYaw2 - radHeading)) < ptuning->radPitch && FCheckLm__FP2LMf(&L.lmTilt, L.radPitch2))
            return L.posResult;
    }
    int phase = 0;
    float radSpread;
    QW posBest;
    do {
        switch (phase) {
        case 0:
            L.lmPick = L.lmTurn;
            count = 10;
            radSpread = ptuning->radYaw;
            break;
        case 1:
            L.lmPick = L.lmTilt;
            count = 10;
            radSpread = ptuning->radPitch;
            break;
        case 2:
            count = 15;
            L.lmPick.gMin = 0.0f;
            L.lmPick.gMax = L.lmTilt.gMax;
            radSpread = 3.1415927f;
            break;
        }
        if (ptuning->mode == -1)
            radSpread = 3.1415927f;
        float distBest = RO_002A5600;
        for (int index = 0; index < count; index++) {
            QW dirProbe = SetVectorCylind__FP6VECTORfff(radHeading + ((float)index / ((float)(count - 1) * 0.5f) + -1.0f) * radSpread, 1.0f, 0.0f);
            int fence0, fence1, fence2, fence3, fence4, fence5, fence6, fence7, fence8, fence9, fence10;
            QW posFar, posNear;
            asm("qmtc2.ni %1, vf1" : "=r"(fence0) : "r"(dirProbe));
            asm("qmtc2.ni %1, vf3" : "=r"(fence1) : "r"(*(int *)&L.lmPick.gMin), "r"(fence0));
            asm("qmtc2.ni %1, vf2" : "=r"(fence2) : "r"(*(int *)&L.lmPick.gMax), "r"(fence1));
            asm("lqc2 vf4, %1" : "=r"(fence3) : "m"(posStart), "r"(fence2));
            asm("vadda.xyzw ACC, vf0, vf4" : "=r"(fence4) : "r"(fence3));
            asm("vmaddx.xyzw vf4, vf1, vf2x" : "=r"(fence5) : "r"(fence4));
            asm("sqc2 vf3, %0" : "=m"(L.posClosest), "=r"(fence9) : "r"(fence5));
            asm("qmfc2.ni %0, vf4" : "=r"(posFar) : "r"(fence9));
            asm("lqc2 vf4, %1" : "=r"(fence6) : "m"(posStart), "r"(posFar));
            asm("vadda.xyzw ACC, vf0, vf4" : "=r"(fence7) : "r"(fence6));
            asm("vmaddx.xyzw vf4, vf1, vf3x" : "=r"(fence8) : "r"(fence7));
            asm("sqc2 vf2, %0" : "=m"(L.posClosest), "=r"(fence10) : "r"(fence8));
            asm("qmfc2.ni %0, vf4" : "=r"(posNear) : "r"(fence10));
            int cclsg = ClsgClipEdgeToPathzoneObstacles(graph, posNear, posFar, 8, L.aclsg);
            CLSG_17BFF8 *pclsg = L.aclsg;
            for (int iclsg = 0; iclsg < cclsg; iclsg++) {
                ClosestPointOnSegment(posRef, pclsg->pos0, pclsg->pos1, &L.posClosest, 0, &L.dist);
                if (L.dist < distBest) {
                    posBest = L.posClosest;
                    distBest = L.dist;
                }
                pclsg++;
            }
        }
        if (distBest != RO_002A5600)
            return posBest;
    } while (++phase < 3);
    if (func_001C0B50(graph, posStart, &L.posResult))
        return L.posResult;
    return posStart;
}
