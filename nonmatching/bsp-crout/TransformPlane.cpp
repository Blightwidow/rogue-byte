#include "sly2.h"
extern "C" void func_002564C0(QW *);
extern "C" QW *func_002564A8(QW *, QW);
extern "C" void SetPlane(QW *, QW, float);
extern "C" QW TransformPlane(MATRIX4 *pmat, QW plane)
{
    struct Frame { QW result; QW temp; QW plane; QW row3; QW normal; } frame;
    QW *prow = (QW *)pmat;
    int t1, t2, t3, t4, t5, t6, t7;
    QW normalBits;
    float dist;
    frame.plane = plane;
    func_002564C0(&frame.temp);
    register QW planeCopy asm("$5") = frame.plane;
    asm("lqc2 vf4, %1" : "=r" (t1) : "m" (prow[1]), "r" (planeCopy));
    asm("lqc2 vf1, %1" : "=r" (t2) : "m" (prow[2]), "r" (t1));
    asm("lqc2 vf3, %1" : "=r" (t3) : "m" (prow[0]), "r" (t2));
    asm("qmtc2.ni %1, vf2" : "=r" (t4) : "r" (planeCopy), "r" (t3));
    asm("vmulax.xyz ACC, vf3, vf2x\n\tvmadday.xyz ACC, vf4, vf2y\n\tvmaddz.xyz vf3, vf1, vf2z" : "=r" (t5) : "r" (t4));
    asm("lqc2 vf2, %1" : "=r" (t6) : "m" (prow[3]), "r" (t5));
    int t6b;
    asm("sq %3, %1" : "=r" (t6b), "=m" (frame.temp) : "r" (t6), "r" (planeCopy));
    asm("sqc2 vf3, %1" : "=r" (t7), "=m" (frame.normal) : "r" (t6b));
    asm("sqc2 vf2, %0" : "=m" (frame.row3) : "r" (t7));
    func_002564A8(&frame.result, planeCopy);
    float w = ((float *)&frame.result)[3];
    int t8, t9;
    asm("lqc2 vf3, %1" : "=r" (t8) : "m" (frame.normal));
    asm("qmtc2.ni %1, vf1" : "=r" (t9) : "r" (w), "r" (t8));
    asm("lqc2 vf2, %1\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf3, vf1x\n\tqmfc2.ni %0, vf3" : "=r" (normalBits) : "m" (frame.row3), "r" (t9));
    asm("vmul.xyz vf2, vf2, vf3\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z\n\tsqc2 vf1, %1\n\tqmfc2.ni %0, vf2" : "=r" (dist), "=m" (frame.result) : "r" (normalBits));
    SetPlane(&frame.result, normalBits, dist);
    return frame.result;
}
