#include "sly2.h"
extern "C" {
QW ConvertAloPos(void *, void *, QW);
void __as__6VECTORG9VU_VECTOR(VECTOR *, QW);
void func_00230CD0(void *, int, void *, void *);
QW DecomposeRotateMatrix(char *);
}
struct Rows3 { QW row[3]; };
extern "C" const Rows3 RO_002A2D00;
struct Locals {
    VECTOR posLocal;
    MATRIX4 mat;
    MATRIX4 matRate;
};
extern "C" void LoadScaleMatrixVector__FP6VECTORP7MATRIX3T0P7MATRIX4(char *palo, QW posWorld, QW *pvecVelocity, QW *pvecAngular)
{
    Locals l;
    QW pos = ConvertAloPos(0, palo, posWorld);
    *(QW *)&l.posLocal = pos;
    l.posLocal.z = 0.0f;
    const Rows3 *source = &RO_002A2D00;
    __as__6VECTORG9VU_VECTOR((VECTOR *)l.mat.mat[3], *(QW *)&l.posLocal);
    l.matRate.mat[3][1] = *(float *)(palo + 0x164);
    l.mat.mat[3][3] = 1.0f;
    *(Rows3 *)&l.mat = *source;
    l.mat.mat[0][3] = 0.0f;
    l.mat.mat[1][3] = 0.0f;
    memset(&l.matRate, 0, 0x40);
    l.matRate.mat[3][0] = *(float *)(palo + 0x160);
    l.mat.mat[2][3] = 0.0f;
    l.matRate.mat[3][2] = *(float *)(palo + 0x168);
    func_00230CD0(*(void **)(palo + 0x60), 0, &l.mat, &l.matRate);
    if (pvecVelocity)
        *pvecVelocity = *(QW *)l.matRate.mat[3];
    if (pvecAngular)
        *pvecAngular = DecomposeRotateMatrix(palo);
}
