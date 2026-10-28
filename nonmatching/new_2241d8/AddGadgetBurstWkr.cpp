#include "sly2.h"
struct SO;
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct VT {
    char pad[0x108];
    short delta0;
    short index0;
    QW (*fnGetVel)(void *);
    short delta1;
    short index1;
    QW (*fnGetAng)(void *);
    short delta2;
    short index2;
    void (*fnSetVel)(void *, QW);
    short delta3;
    short index3;
    void (*fnSetAng)(void *, QW);
};
struct PSO { char pad[0xC]; VT *vt; };
struct Wkr {
    int ploSource;
    int unk4;
    int ploTarget;
    int grftak;
    int nDamage;
    char pad[0x20 - 0x14];
    QW pos;
    QW vecImpulse;
    char pad2[0x60 - 0x40];
};
struct Frame {
    QW posHit;
    char lsgPad[0x60 - 0x10];
    QW junk;
    QW start;
    QW end;
    QW vecDir;
    QW impulse;
    QW dv;
    QW dw;
    QW uFactor;
    QW velNew;
    QW angNew;
};
extern "C" {
void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, void *, void *);
char *PaloFindWkrAbsorber(void *, int);
QW VelocityXfAtPos(void *, int, QW);
QW DvFromImpulse(void *, QW);
QW DwFromImpulseAtPos(void *, QW, QW);
extern float D_002C4334;
extern float D_002C4320[3];
extern float g_2bbb60[2];
extern float D_002C4330;
}
void AddGadgetBurstWkr(void *ploSource, int grftak, int nDamage, QW posStart, QW posEnd, int cgeom, void *ageom, int cwkrMax, int *pcwkr, Wkr *awkr)
{
    Frame f;
    f.start = posStart;
    f.end = posEnd;
    void *pvHit = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, f.start, f.end, cgeom, ageom, &f);
    if (!pvHit)
        return;
    asm("lqc2 vf2, %3\n\tlqc2 vf3, %2\n\tvsub.xyzw vf1, vf2, vf3" : : "m"(f), "m"(f), "m"(f.start), "m"(f.end));
    asm("vmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf4, vf1, Q\n\tsqc2 vf4, %0" : "=m"(f.vecDir));
    char *paloAbsorber = PaloFindWkrAbsorber(*(void **)((char *)pvHit + 4), grftak);
    if (!paloAbsorber)
        return;
    char *pso = *(char **)(*(char **)(paloAbsorber + 0xEC) + 0x60);
    int cwkr = *pcwkr;
    int iwkr = 0;
    while (iwkr < cwkr) {
        if ((char *)awkr[iwkr].ploTarget == paloAbsorber)
            break;
        iwkr++;
    }
    if (iwkr >= cwkr && cwkr < cwkrMax) {
        Wkr *pwkr = &awkr[cwkr];
        *pcwkr = cwkr + 1;
        memset(pwkr, 0, 0x60);
        pwkr->ploSource = (int)ploSource;
        QW hitPos = f.posHit;
        asm("qmtc2.ni %1, vf2\n\tlqc2 vf3, %2\n\tvmulx.xyzw vf1, vf3, vf2x\n\tsqc2 vf1, %0\n\tsqc2 vf2, %3" : "=m"(pwkr->vecImpulse) : "r"(*(int *)&D_002C4334), "m"(f.vecDir), "m"(f.junk));
        pwkr->ploTarget = (int)paloAbsorber;
        pwkr->grftak = grftak;
        pwkr->nDamage = nDamage;
        pwkr->pos = hitPos;
    }
    if (*(int *)(pso + 0xE8) == 0)
        return;
    QW vel = VelocityXfAtPos(*(void **)(pso + 0x60), 0, f.posHit);
    int sAlongBits;
    asm("qmtc2.ni %2, vf4\n\tlqc2 vf3, %1\n\tvmul.xyz vf1, vf4, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r"(sAlongBits) : "m"(f.vecDir), "r"(vel));
    float sAlong = *(float *)&sAlongBits;
    float uRatio = sAlong / D_002C4334;
    float gScale = D_002C4320[0] + uRatio * (D_002C4320[1] + uRatio * D_002C4320[2]);
    if (gScale < g_2bbb60[0])
        gScale = g_2bbb60[0];
    else if (g_2bbb60[1] < gScale)
        gScale = g_2bbb60[1];
    if (0.0f < gScale) {
    float impulseScale = gScale * D_002C4330;
    asm("lqc2 vf2, %2\n\tmfc1 $2, %3\n\tqmtc2.ni $2, vf1\n\tvmulx.xyzw vf2, vf2, vf1x\n\tsqc2 vf1, %0\n\tsqc2 vf2, %1" : "=m"(f.junk), "=m"(f.impulse) : "m"(f.vecDir), "f"(impulseScale) : "$2");
    f.dv = DvFromImpulse(pso, f.impulse);
    f.dw = DwFromImpulseAtPos(pso, f.posHit, f.impulse);
    int sRateBits;
    asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tlqc2 vf3, %3\n\tvopmula.xyz ACC, vf3, vf1\n\tvopmsub.xyz vf1, vf1, vf3\n\tlqc2 vf4, %4\n\tvadd.xyzw vf1, vf4, vf1\n\tlqc2 vf3, %5\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r"(sRateBits) : "m"(f.posHit), "m"(*(QW *)(*(char **)(pso + 0x5C) + 0x70)), "m"(f.dw), "m"(f.dv), "m"(f.vecDir));
    float sRate = *(float *)&sRateBits;
    if (0.0f < sRate) {
    float uRaw = (D_002C4334 - sAlong) / sRate;
    float uFactor = 0.0f;
    if (uRaw < 0.0f) {
    } else {
        uFactor = uRaw;
        if (1.0f < uRaw)
            uFactor = 1.0f;
    }
    QW uBits;
    asm("mfc1 %0, %1" : "=r"(uBits) : "f"(uFactor));
    f.uFactor = uBits;
    QW velNow = (*(VT **)(pso + 0xC))->fnGetVel(pso + (*(VT **)(pso + 0xC))->delta0);
    QW junk2;
    asm("lqc2 vf2, %3\n\tqmtc2.ni %4, vf1\n\tlqc2 vf3, %5\n\tvadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf3, vf2x\n\tqmfc2.ni %0, vf2\n\tsqc2 vf1, %1\n\tsq %0, %2" : "=r"(junk2), "=m"(f.velNew), "=m"(f.junk) : "m"(f.uFactor), "r"(velNow), "m"(f.dv));
    QW angNow = (*(VT **)(pso + 0xC))->fnGetAng(pso + (*(VT **)(pso + 0xC))->delta1);
    asm("lqc2 vf2, %3\n\tqmtc2.ni %4, vf1\n\tlqc2 vf3, %5\n\tvadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf3, vf2x\n\tqmfc2.ni %0, vf2\n\tsqc2 vf1, %1\n\tsq %0, %2" : "=r"(junk2), "=m"(f.angNew), "=m"(f.junk) : "m"(f.uFactor), "r"(angNow), "m"(f.dw));
    (*(VT **)(pso + 0xC))->fnSetVel(pso + (*(VT **)(pso + 0xC))->delta2, f.velNew);
    (*(VT **)(pso + 0xC))->fnSetAng(pso + (*(VT **)(pso + 0xC))->delta3, f.angNew);
    }
    }
}
