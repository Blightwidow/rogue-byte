#include "sly2.h"
struct XFM { QW local[4]; QW world[4]; char pad[0xA0 - 0x80]; XFM *pparent; };
struct LIMB { int pxfAnchor; XFM *pxfUpper; XFM *pxfLower; XFM *pxfEnd; QW upperRest[4]; QW lowerRest[4]; QW axis; char pad[0xB0 - 0xA0]; QW effector; float sUpper; float sLower; float radRest; };
extern "C" {
float RadBetweenVectors__FP6VECTORN20(QW, QW, QW *);
QW ConvertXfVec(void *, void *, QW);
}
extern "C" void InitIkLimb(LIMB *plimb)
{
    QW *paxis = &plimb->axis;
    XFM *pupper = plimb->pxfUpper;
    XFM *plower = plimb->pxfLower;
    plimb->upperRest[0] = pupper->local[0];
    XFM *pend = plimb->pxfEnd;
    QW *prow = &pend->world[0];
    asm("lqc2 vf6, %0" : : "m" (plimb->effector));
    plimb->upperRest[1] = pupper->local[1];
    plimb->upperRest[2] = pupper->local[2];
    plimb->upperRest[3] = pupper->local[3];
    plimb->lowerRest[0] = plower->local[0];
    plimb->lowerRest[1] = plower->local[1];
    plimb->lowerRest[2] = plower->local[2];
    plimb->lowerRest[3] = plower->local[3];
    asm("lqc2 vf5, %0" : : "m" (prow[3]));
    asm("lqc2 vf4, %0" : : "m" (prow[1]));
    asm("lqc2 vf3, %0" : : "m" (prow[2]));
    asm("lqc2 vf2, %0" : : "m" (pend->world[0]));
    asm("lqc2 vf1, %0" : : "m" (plower->world[3]));
    asm("vmulax.xyz ACC, vf2, vf6x\n\tvmadday.xyz ACC, vf4, vf6y\n\tvmaddaz.xyz ACC, vf3, vf6z\n\tvmaddw.xyz vf2, vf5, vf0w\n\tvsub.xyzw vf2, vf2, vf1");
    asm("lqc2 vf4, %0" : : "m" (pupper->world[3]));
    asm("vmul.xyz vf3, vf2, vf2\n\tvaddw.x vf5, vf0, vf0w\n\tvadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf5, vf3z\n\tvsub.xyzw vf1, vf1, vf4");
    asm("vsqrt Q, vf3x\n\tvwaitq\n\tvaddq.x vf3, vf0, Q");
    asm("vmul.xyz vf4, vf1, vf1\n\tvaddw.x vf6, vf0, vf0w\n\tvadday.x ACC, vf4, vf4y\n\tvmaddz.x vf4, vf6, vf4z");
    int bitsLower;
    asm volatile("qmfc2.ni %0, vf3" : "=r" (bitsLower));
    asm("vsqrt Q, vf4x\n\tvwaitq\n\tvaddq.x vf4, vf0, Q");
    *(int *)&plimb->sLower = bitsLower;
    QW upperBone;
    QW lowerBone;
    int bitsUpper;
    asm volatile("qmfc2.ni %0, vf1" : "=r" (upperBone));
    asm volatile("qmfc2.ni %0, vf4" : "=r" (bitsUpper));
    asm volatile("qmfc2.ni %0, vf2" : "=r" (lowerBone));
    *(int *)&plimb->sUpper = bitsUpper;
    asm volatile("");
    plimb->radRest = RadBetweenVectors__FP6VECTORN20(upperBone, lowerBone, paxis);
    plimb->axis = ConvertXfVec(0, plimb->pxfLower->pparent, plimb->axis);
}
