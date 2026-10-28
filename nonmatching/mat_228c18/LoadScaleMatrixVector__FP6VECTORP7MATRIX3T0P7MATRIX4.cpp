#include "sly2.h"
extern "C" {
QW ConvertAloPos(void *, void *, QW);
void __as__6VECTORG9VU_VECTOR(VECTOR *, QW);
void func_00230CD0(void *, int, void *, void *);
QW DecomposeRotateMatrix(void *);
}
struct Rows3 { QW row[3]; };
extern "C" const Rows3 RO_002A2D00;
struct Locals {
    VECTOR posLocal;
    Rows3 rows;
    VECTOR translation;
    MATRIX4 matRate;
};
void LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4(char *palo, QW posWorld, QW *pvecVelocity, QW *pvecAngular)
{
    Locals l;
    QW pos = ConvertAloPos(0, palo, posWorld);
    *(QW *)&l.posLocal = pos;
    l.posLocal.z = 0.0f;
    __as__6VECTORG9VU_VECTOR(&l.translation, *(QW *)&l.posLocal);
    l.rows = RO_002A2D00;
    float *flat = (float *)&l.rows;
    flat[15] = 1.0f;
    flat[11] = 0.0f;
    flat[7] = 0.0f;
    flat[3] = 0.0f;
    memset(&l.matRate, 0, 0x40);
    l.matRate.mat[3][0] = *(float *)(palo + 0x160);
    l.matRate.mat[3][1] = *(float *)(palo + 0x164);
    l.matRate.mat[3][2] = *(float *)(palo + 0x168);
    func_00230CD0(*(void **)(palo + 0x60), 0, flat, &l.matRate);
    if (pvecVelocity)
        *pvecVelocity = *(QW *)l.matRate.mat[3];
    if (pvecAngular)
        *pvecAngular = DecomposeRotateMatrix(&l.matRate);
}
