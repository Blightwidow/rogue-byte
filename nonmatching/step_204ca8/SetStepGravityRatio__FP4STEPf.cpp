#include "sly2.h"
struct PHYS { char pad0[0x80]; QW grav; char pad1[0x40]; float gMass; };
struct SO { char pad0[0xE8]; PHYS *pphys; char pad1[0x174]; float rGravity; };
struct STEP { char pad0[0xE8]; PHYS *pphys; char pad1[0x174]; float rGravity; };
void SetSoMass(SO *, float);
void SetStepGravityRatio(STEP *pstep, float rGravity)
{
    QW junk;
    float rNew = 0.1f;
    rNew = rNew < rGravity ? rGravity : rNew;
    SetSoMass((SO *)pstep, pstep->pphys->gMass * pstep->rGravity / rNew);
    register PHYS *pphys asm("$2") = pstep->pphys;
    asm volatile("qmtc2.ni %0, vf2" : : "r" (rNew));
    asm volatile("lqc2 vf1, %0" : : "m" (pphys->grav));
    asm volatile("vmulx.xyzw vf1, vf1, vf2x\n\tqmtc2.ni %0, vf3" : : "r" (*(int *)&pstep->rGravity));
    asm volatile("sqc2 vf2, %0" : "=m" (junk));
    asm volatile("sqc2 vf3, %0" : "=m" (junk));
    asm volatile("vdiv Q, vf0w, vf3x\n\tvwaitq\n\tvmulq.xyzw vf1, vf1, Q\n\tsqc2 vf1, %0" : "=m" (pphys->grav));
    pstep->rGravity = rNew;
}
