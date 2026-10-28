#include "sly2.h"
extern "C" void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(MATRIX3 *pmat, float *prad, VECTOR *pnormal);
struct Frame { VECTOR normal; QW scaled; };
extern "C" QW DecomposeRotateMatrix(MATRIX3 *pmat)
{
    Frame frame;
    float rad;
    QW result;
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(pmat, &rad, &frame.normal);
    asm("qmtc2.ni %0, vf2\n\tlqc2 vf1, %1\n\tvmulx.xyzw vf3, vf1, vf2x" : : "r" (*(int *)&rad), "m" (frame.normal));
    asm("qmfc2.ni %0, vf3\n\tsqc2 vf2, %1" : "=r" (result), "=m" (frame.scaled));
    return result;
}
