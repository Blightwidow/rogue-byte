// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct M3_1CFD30 { QW r0; QW r1; QW r2; };
struct VT1CFD30 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct LO1CFD30 { char pad[0xC]; VT1CFD30 *vt; };
struct XFO1CFD30 { char pad[0x60]; int xf; };
struct MATCH1CFD30 {
    char pad0[0x18]; float t; XFO1CFD30 *pxfo; char pad1[0x40 - 0x20];
    M3_1CFD30 mat; QW pos; char pad2[0xA0 - 0x80]; QW rel; char pad3[0xF0 - 0xB0];
    QW normal; float rad; LO1CFD30 *plo;
};
extern "C" {
QW PosLoWorld(LO1CFD30 *);
M3_1CFD30 *PmatLoWorld(LO1CFD30 *);
void PredictXfTransform(int, float, int, void *, int);
void MatMulMatTransMat(void *, void *, void *);
void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(M3_1CFD30 *, float *, QW *);
void LaunchMatch__FP5MATCH(MATCH1CFD30 *match)
{
    struct { QW frame[4]; M3_1CFD30 local; QW scratch; M3_1CFD30 product; } stack;
    match->pos = PosLoWorld(match->plo);
    M3_1CFD30 *pmat = PmatLoWorld(match->plo);
    match->mat = *pmat;
    PredictXfTransform(match->pxfo->xf, match->t, 0, stack.frame, 0);
    float t = match->t;
    float negativeHalf = t * -0.5f;
    float inverse = 1.0f / t;
    void *pproduct = &stack.product;
    void *pmatrix = &match->mat;
    asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(match));
    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(stack.frame));
    asm volatile("vsub.xyzw vf2, vf2, vf1");
    asm volatile("lqc2 vf1, 0xa0(%0)" : : "r"(match));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(inverse));
    asm volatile("qmtc2.ni %0, vf4" : : "r"(negativeHalf));
    asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(stack.frame));
    asm volatile("vmulax.xyzw ACC, vf2, vf3x");
    asm volatile("vmaddx.xyzw vf2, vf1, vf4x");
    asm volatile("sqc2 vf2, 0x90(%0)" : : "r"(match));
    asm volatile("sqc2 vf4, 0x70(%0)" : : "r"(stack.frame));
    MatMulMatTransMat(pproduct, stack.frame, pmatrix);
    stack.local = stack.product;
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&stack.local, &match->rad, &match->normal);
    float rad = match->rad;
    if (0.0f < rad)
        rad = rad + 6.2831855f;
    else
        rad = rad - 6.2831855f;
    match->rad = rad;
    LO1CFD30 *plo = match->plo;
    plo->vt->fn((char *)plo + plo->vt->delta);
    match->plo = 0;
}
}
