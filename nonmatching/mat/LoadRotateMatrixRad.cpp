#include "sly2.h"
extern "C" void CalculateSinCos__FfPfT1(float);
extern "C" void LoadRotateMatrixSinCos(MATRIX3 *, long, long, QW);
extern "C" MATRIX3 *LoadRotateMatrixRad(MATRIX3 *pmat, QW axis, float rad)
{
    MATRIX3 mat;
    float gSin, gCos;
    CalculateSinCos__FfPfT1(rad);
    LoadRotateMatrixSinCos(&mat, *(int *)&gSin, *(unsigned long *)&gCos, axis);
    memcpy(pmat, &mat, 0x30);
    return pmat;
}
