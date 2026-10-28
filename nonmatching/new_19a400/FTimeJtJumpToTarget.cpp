#include "sly2.h"
extern int CSolveQuadratic(float, float, float, float *);
static inline float LaneZ(QW q) { QW t; float f; asm volatile("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
struct Jmp { char *pjt; };

int FTimeJtJumpToTarget(Jmp *pjmp, QW pos, QW vJump, QW posTarget, QW vTarget, float *pdtPredict)
{
    float roots[4];
    float jumpZ = LaneZ(vJump);
    char *pjt = pjmp->pjt;
    float targetVelocityZ = LaneZ(vTarget);
    float posZ = LaneZ(pos);
    float targetZ = LaneZ(posTarget);
    float gravityZ = *(float *)(*(char **)(pjt + 0xE8) + 0x88);
    int count = CSolveQuadratic(gravityZ * 0.5f, jumpZ - targetVelocityZ, posZ - targetZ, roots);
    if (count < 1)
        return 0;
    float latest = roots[count - 1];
    if (latest <= 0.0f)
        return 0;
    *pdtPredict = latest;
    return 1;
}
