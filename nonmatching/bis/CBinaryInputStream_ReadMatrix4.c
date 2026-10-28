#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_ReadMatrix();            /* extern */
M2C_UNK ReadVector__18CBinaryInputStreamP6VECTOR(s32, s32); /* extern */

void CBinaryInputStream_ReadMatrix4(s32 arg0, void *arg1) {
    CBinaryInputStream_ReadMatrix();
    M2C_FIELD(arg1, s32 *, 0xC) = 0;
    ReadVector__18CBinaryInputStreamP6VECTOR(arg0, arg1 + 0x30);
    M2C_FIELD(arg1, f32 *, 0x3C) = 1.0f;
    M2C_FIELD(arg1, s32 *, 0x1C) = 0;
    M2C_FIELD(arg1, s32 *, 0x2C) = 0;
}
