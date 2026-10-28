#include "sly2.h"
void CalculateSinCos__FfPfT1(float rad, float *pgSin, float *pgCos);
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" MATRIX3 *LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(MATRIX3 *pmatResult, QW eul)
{
    register QW zeroReg asm("$0");
    float gSinX, gCosX, gSinY, gCosY, gSinZ, gCosZ;
    CalculateSinCos__FfPfT1(Lane(eul), &gSinX, &gCosX);
    float y = Lane(__builtin_prot3w(eul));
    CalculateSinCos__FfPfT1(y, &gSinY, &gCosY);
    float z = Lane(__builtin_pextuw(zeroReg, eul));
    CalculateSinCos__FfPfT1(z, &gSinZ, &gCosZ);
    float *ag = (float *)pmatResult;
    ag[0] = gCosY * gCosZ;
    ag[1] = gCosY * gSinZ;
    ag[2] = -gSinY;
    ag[4] = gSinX * gSinY * gCosZ - gCosX * gSinZ;
    ag[5] = gSinX * gSinY * gSinZ + gCosX * gCosZ;
    ag[6] = gSinX * gCosY;
    ag[8] = gCosX * gSinY * gCosZ + gSinX * gSinZ;
    ag[9] = gCosX * gSinY * gSinZ - gSinX * gCosZ;
    ag[10] = gCosX * gCosY;
    return pmatResult;
}
