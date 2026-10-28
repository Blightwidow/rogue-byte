#include "sly2.h"
struct CARRY { char pad[0x14]; void *crvA; char pad2[0x10]; void *crvB; };
extern "C" {
void EvaluateCrvFromU(void *, float, QW *, void *);
void ClosestPointOnSegment(QW, QW, QW, void *, float *, float *);
}

void func_001CC168(CARRY *pcarry, float u, QW pos, float *pu, float *ps)
{
    QW posA;
    QW posB;
    EvaluateCrvFromU(pcarry->crvA, u, &posA, 0);
    EvaluateCrvFromU(pcarry->crvB, u, &posB, 0);
    ClosestPointOnSegment(pos, posA, posB, 0, pu, ps);
}
