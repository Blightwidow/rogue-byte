#include "sly2.h"
extern "C" void InitPlaneFromNormalPos(QW *pplane, QW normal, QW pos)
{
    int dist;
    asm("qmtc2.ni %0, vf1\n\tqmtc2.ni %1, vf4\n\tvmul.xyz vf2, vf1, vf4\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z" : : "r" (normal), "r" (pos));
    asm("sqc2 vf1, %0" : "=m" (*pplane));
    asm("qmfc2.ni %0, vf2" : "=r" (dist));
    ((volatile int *)pplane)[3] = dist;
}
