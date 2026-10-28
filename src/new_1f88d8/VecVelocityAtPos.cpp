#include "sly2.h"
struct XF { char pad[0x70]; QW row3; };
struct SO { char pad[0x5C]; XF *pxfAngular; };
extern "C" QW VecVelocityAtPos(SO *pso, QW *pvel, QW pos)
{
    register XF *xf asm("$2") = pso->pxfAngular;
    QW result;
    asm("qmtc2.ni %1, vf4\n\tlqc2 vf2, %3\n\tlqc2 vf1, %4\n\tvsub.xyzw vf3, vf4, vf1\n\tlqc2 vf4, %2\n\tvopmula.xyz ACC, vf2, vf3\n\tvopmsub.xyz vf2, vf3, vf2\n\tvadd.xyzw vf1, vf4, vf2\n\tqmfc2.ni %0, vf1"
        : "=r" (result) : "r" (pos), "m" (pvel[0]), "m" (pvel[1]), "m" (xf->row3));
    return result;
}
