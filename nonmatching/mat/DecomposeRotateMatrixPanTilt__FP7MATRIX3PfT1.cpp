#include "sly2.h"
extern "C" float atan2f(MATRIX3 *, float);
extern "C" void DecomposeRotateMatrixPanTilt__FP7MATRIX3PfT1(MATRIX3 *mat, float *pan, float *tilt)
{
    float y = mat->mat[0][1];
    float x = mat->mat[0][0];
    *pan = atan2f(mat, x);
    float lengthSquared = mat->mat[0][0] * mat->mat[0][0] + mat->mat[0][1] * mat->mat[0][1];
    *tilt = atan2f(mat, __builtin_sqrtf(lengthSquared));
}
