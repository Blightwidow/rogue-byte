#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(void *, s128); /* extern */
M2C_UNK memcpy(s32, void *, M2C_UNK);               /* extern */
extern s128 g_2a2dc0;

s32 LoadLookAtMatrix(s32 arg0) {
    char sp[0x400];
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(sp, g_2a2dc0);
    memcpy(arg0, sp, 0x30);
    return arg0;
}
