#include "sly2.h"
extern QW g_2a2da0;
extern "C" QW GetPerpendicularVector(QW vec);
extern "C" MATRIX3 *BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(MATRIX3 *pmat, QW vecX, QW vecUp)
{
    float length;
    float lengthRow1;
    QW *prow = (QW *)pmat;
    QW saved;
    asm("qmtc2.ni %0, vf3" : : "r" (vecX));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    asm("qmfc2.ni %0, vf1" : "=r" (length));
    if (length < 0.0001f) {
        QW axis = g_2a2da0;
        asm("qmtc2.ni %0, vf2" : : "r" (vecUp));
        asm("qmtc2.ni %0, vf4" : : "r" (axis));
    } else {
        asm("qmtc2.ni %0, vf2\n\tnop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf4, vf3, Q" : : "r" (vecUp));
    }
    asm("vopmula.xyz ACC, vf2, vf4\n\tvopmsub.xyz vf1, vf4, vf2");
    asm("vmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z");
    asm("sqc2 vf1, %0" : "=m" (prow[1]));
    asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q");
    asm("sqc2 vf4, %0" : "=m" (prow[0]));
    asm("qmfc2.ni %0, vf2" : "=r" (lengthRow1));
    asm("vdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q");
    asm("sqc2 vf2, %0" : "=m" (prow[1]));
    asm("sqc2 vf1, %0" : "=m" (saved));
    if (lengthRow1 < 0.0001f) {
        QW perp;
        asm("qmfc2.ni %0, vf4" : "=r" (perp));
        prow[1] = GetPerpendicularVector(perp);
    }
    asm("lqc2 vf1, %0" : : "m" (prow[0]));
    asm("lqc2 vf2, %0" : : "m" (prow[1]));
    asm("vopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf1, vf2, vf1");
    asm("sqc2 vf1, %0" : "=m" (prow[2]));
    return pmat;
}
