// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct M3_1CFD30 { QW r0; QW r1; QW r2; };
struct VT1CFD30 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct LO1CFD30 { char pad[0xC]; VT1CFD30 *vt; };
struct XFO1CFD30 { char pad[0x60]; int xf; };
struct MATCH1CFD30 {
    char pad0[0x18]; float t; XFO1CFD30 *pxfo; char pad1[0x40 - 0x20];
    M3_1CFD30 mat; QW pos; QW pad80; QW vel; QW rel; char pad3[0xF0 - 0xB0];
    QW normal; float rad; LO1CFD30 *plo;
};
/* a float broadcast into a VU0 register; retail keeps a stack copy it never reads */
static inline QW VuFloat(float f)
{
    QW q;
    asm("qmtc2.ni %1, %0" : "=j"(q) : "r"(f));
    struct { float x, y, z, w; } __attribute__((aligned(16))) copy;
    *(QW *)&copy = q;
    return q;
}

extern "C" {
QW PosLoWorld(LO1CFD30 *);
M3_1CFD30 *PmatLoWorld(LO1CFD30 *);
void PredictXfTransform(int, float, int, void *, int);
void MatMulMatTransMat(void *, void *, void *);
void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(M3_1CFD30 *, float *, QW *);
void LaunchMatch__FP5MATCH(MATCH1CFD30 *match)
{
    QW frame[4];
    M3_1CFD30 local;
    match->pos = PosLoWorld(match->plo);
    M3_1CFD30 *pmat = PmatLoWorld(match->plo);
    match->mat = *pmat;
    PredictXfTransform(match->pxfo->xf, match->t, 0, frame, 0);
    float inverse = 1.0f / match->t;
    float negativeHalf = match->t * -0.5f;
    void *pframe = frame;
    void *pmatrix = &match->mat;
    QW pos = match->pos;
    QW framePos = frame[3];
    QW delta;
    asm("vsub.xyzw %0, %1, %2" : "=j"(delta) : "j"(framePos), "j"(pos));
    QW rel = match->rel;
    QW scaleInverse = VuFloat(inverse);
    QW scaleHalf = VuFloat(negativeHalf);
    QW vel;
    asm("vmulax.xyzw ACC, %1, %2x\n\tvmaddx.xyzw %0, %3, %4x" : "=j"(vel) : "j"(delta), "j"(scaleInverse), "j"(rel), "j"(scaleHalf));
    match->vel = vel;
    M3_1CFD30 product;
    MatMulMatTransMat(&product, pframe, pmatrix);
    local = product;
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&local, &match->rad, &match->normal);
    float rad = match->rad;
    if (0.0f < rad)
        match->rad = rad + 6.2831855f;
    else
        match->rad = rad - 6.2831855f;
    LO1CFD30 *plo = match->plo;
    plo->vt->fn((char *)plo + plo->vt->delta);
    match->plo = 0;
}
}
