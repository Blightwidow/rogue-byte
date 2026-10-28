#include "sly2.h"
struct SMP { float a, b, c, d; };
struct Rows { QW row[3]; };
extern "C" void MatMulMatTransMat(Rows *pmatResult, Rows *pmatA, Rows *pmatB);
extern "C" void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(Rows *pmat, float *prad, QW *pnormal);
extern "C" float GSmooth__FfffP3SMPPf(float g, float gGoal, float dt, SMP *psmp, float *psv);
extern "C" void LoadRotateMatrixRad(Rows *pmatResult, float rad, QW normal);
extern "C" void SmoothMatrix(float dt, Rows *pmatPrev, Rows *pmatNext, SMP *psmp, Rows *pmatSmooth, QW *pvecOmega)
{
    struct Frame { QW normal; Rows matDelta; Rows matStep; Rows junk; float radDelta; float dradSmooth; float pad[2]; } frame;
    MatMulMatTransMat(&frame.matDelta, pmatPrev, pmatNext);
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&frame.matDelta, &frame.radDelta, &frame.normal);
    float radStep = GSmooth__FfffP3SMPPf(0.0f, frame.radDelta, dt, psmp, &frame.dradSmooth);
    if (pmatSmooth) {
        if (radStep == frame.radDelta) {
            *pmatSmooth = *pmatNext;
        } else {
            LoadRotateMatrixRad(&frame.matStep, radStep, frame.normal);
            asm("lqc2 vf5, %0" : : "m" (pmatPrev->row[2]));
            asm("lqc2 vf4, %0" : : "m" (pmatPrev->row[0]));
            asm("lqc2 vf2, %0" : : "m" (frame.matStep.row[0]));
            asm("lqc2 vf3, %0" : : "m" (frame.matStep.row[1]));
            asm("lqc2 vf1, %0" : : "m" (frame.matStep.row[2]));
            asm("lqc2 vf6, %0" : : "m" (pmatPrev->row[1]));
            asm("vmulax.xyz ACC, vf2, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddz.xyz vf5, vf1, vf5z\n\tvmulax.xyz ACC, vf2, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddz.xyz vf4, vf1, vf4z");
            asm("sqc2 vf5, %0" : "=m" (pmatSmooth->row[2]));
            asm("vmulax.xyz ACC, vf2, vf6x\n\tvmadday.xyz ACC, vf3, vf6y\n\tvmaddz.xyz vf2, vf1, vf6z");
            asm("sqc2 vf2, %0" : "=m" (pmatSmooth->row[1]));
            asm("sqc2 vf4, %0" : "=m" (pmatSmooth->row[0]));
            asm("sqc2 vf4, %0" : "=m" (frame.junk.row[0]));
            asm("sqc2 vf4, %0" : "=m" (frame.matDelta.row[0]));
            asm("sqc2 vf2, %0" : "=m" (frame.junk.row[1]));
            asm("sqc2 vf2, %0" : "=m" (frame.matDelta.row[1]));
            asm("sqc2 vf5, %0" : "=m" (frame.junk.row[2]));
            asm("sqc2 vf5, %0" : "=m" (frame.matDelta.row[2]));
        }
    }
    if (pvecOmega) {
        int bits = *(int *)&frame.dradSmooth;
        asm("qmtc2.ni %0, vf2" : : "r" (bits));
        asm("lqc2 vf1, %0" : : "m" (frame.normal));
        asm("vmulx.xyzw vf1, vf1, vf2x\n\tsqc2 vf2, %0\n\tsqc2 vf1, %1" : "=m" (frame.matDelta.row[0]), "=m" (*pvecOmega));
    }
}
