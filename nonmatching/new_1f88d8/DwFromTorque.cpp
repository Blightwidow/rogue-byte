#include "sly2.h"
struct Rows { QW row[3]; };
struct PHYS { char pad[0x30]; QW i0, i1, i2; char pad2[0x30]; char constr[1]; };
struct XF { char pad[0x40]; QW r0, r1, r2; };
struct SO { char pad[0x5C]; XF *pxfAng; char pad2[0xE8 - 0x60]; PHYS *phys; };
extern "C" Rows *InvertMatrix3(Rows *, QW *);
extern "C" QW ApplyConstrLocal(void *, XF *, QW);
QW DwFromTorque(SO *pso, QW torque)
{
    Rows inv;
    QW tq;
    QW result;
    XF *xf = pso->pxfAng;
    QW *m = &xf->r0;
    int chain0;
    asm("qmtc2.ni %1, vf4" : "=r" (chain0) : "r" (torque));
    asm("sqc2 vf4, %0" : "=m" (tq) : "r" (chain0));
    InvertMatrix3(&inv, m);
    PHYS *phys = pso->phys;
    QW *pi = &phys->i0;
    void *cp = phys->constr;
    int chain;
    asm("lqc2 vf5, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tlqc2 vf4, %4\n\tvmulax.xyz ACC, vf5, vf4x\n\tvmadday.xyz ACC, vf2, vf4y\n\tvmaddz.xyz vf4, vf1, vf4z"
        : "=r" (chain) : "m" (inv.row[0]), "m" (inv.row[1]), "m" (inv.row[2]), "m" (tq));
    asm("lqc2 vf3, %1\n\tlqc2 vf1, %2\n\tlqc2 vf2, %3" : "+r" (chain) : "m" (pi[2]), "m" (pi[1]), "m" (phys->i0));
    asm("vmulax.xyz ACC, vf2, vf4x\n\tvmadday.xyz ACC, vf1, vf4y\n\tvmaddz.xyz vf4, vf3, vf4z" : "+r" (chain));
    asm("lqc2 vf5, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3" : "+r" (chain) : "m" (xf->r0), "m" (m[2]), "m" (m[1]));
    asm("vmulax.xyz ACC, vf5, vf4x\n\tvmadday.xyz ACC, vf1, vf4y\n\tvmaddz.xyz vf3, vf2, vf4z" : "+r" (chain));
    asm("qmfc2.ni %0, vf3" : "=r" (result) : "r" (chain));
    return ApplyConstrLocal(cp, pso->pxfAng, result);
}
