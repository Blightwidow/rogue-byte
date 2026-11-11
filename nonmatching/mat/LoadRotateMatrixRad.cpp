#include "sly2.h"
extern "C" void CalculateSinCos__FfPfT1(float, float *, float *);
extern "C" void LoadRotateMatrixSinCos(MATRIX3 *, MATRIX3 *, QW, QW);
union Lane { float f; int i; QW q; };
extern "C" MATRIX3 *LoadRotateMatrixRad(MATRIX3 *pmat, QW axis, float rad)
{
    MATRIX3 mat;
    Lane sinLane, cosLane;
    CalculateSinCos__FfPfT1(rad, &sinLane.f, &cosLane.f);
    LoadRotateMatrixSinCos(pmat, &mat, cosLane.q, axis);
    memcpy(pmat, &mat, 0x30);
    return pmat;
}
