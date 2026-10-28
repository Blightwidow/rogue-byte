#include "sly2.h"
struct M34 { VECTOR row[3]; };
struct PHYS { M34 momint; MATRIX3 inverse; };
struct SO { char pad[0xE8]; PHYS *phys; };
int FInvertMatrix3__FP7MATRIX3T0(MATRIX3 *, MATRIX3 *);
void AdjustSoMomint__FP2SOf(SO *so, float r)
{
    int bits;
    struct L { MATRIX3 tmp; VECTOR splat; MATRIX3 scaled; } l;
    asm("mfc1 %0, %1" : "=r" (bits) : "f" (r));
    asm("qmtc2.ni %0, vf3" : : "r" (bits));
    PHYS *phys = so->phys;
    asm("sqc2 vf3, %0" : "=m" (l.splat));
    asm("lqc2 vf1, %0" : : "m" (phys->momint.row[0]));
    asm("vmulx.xyzw vf1, vf1, vf3x");
    asm("sqc2 vf1, %0" : "=m" (((VECTOR *)&l.scaled)[0]));
    asm("lqc2 vf2, %0" : : "m" (phys->momint.row[1]));
    asm("vmulx.xyzw vf2, vf2, vf3x");
    asm("sqc2 vf2, %0" : "=m" (((VECTOR *)&l.scaled)[1]));
    asm("lqc2 vf1, %0" : : "m" (phys->momint.row[2]));
    asm("vmulx.xyzw vf3, vf1, vf3x");
    asm("sqc2 vf3, %0" : "=m" (((VECTOR *)&l.scaled)[2]));
    memcpy(&l.tmp, &l.scaled, 0x30);
    M34 *momint = &phys->momint;
    *momint = *(M34 *)&l.tmp;
    if (!FInvertMatrix3__FP7MATRIX3T0((MATRIX3 *)&so->phys->momint, &so->phys->inverse))
        memset(&so->phys->inverse, 0, 0x30);
}
