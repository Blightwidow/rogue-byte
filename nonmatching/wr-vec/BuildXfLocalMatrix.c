#include "m2c_macros.h"

M2C_UNK LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(void *, M2C_UNK); /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(void *, s128);     /* extern */
M2C_UNK memcpy(void *, void *, M2C_UNK);            /* extern */

void *BuildXfLocalMatrix(void *arg0, void *arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    s32 temp_s0;
    u32 temp_v1;

    temp_s0 = M2C_ERROR(/* unknown instruction: por $s0, $zero, $a2 */);
    temp_v1 = M2C_FIELD(arg1, u32 *, 0x94);
    switch (temp_v1) {
    case 1:
    case 4:
    case 5:
    case 9:
    case 10:
        memcpy(arg0, arg1, 0x40);
        M2C_FIELD(arg0, s32 *, 0x30) = temp_s0;
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */);
        M2C_FIELD(arg0, f32 *, 0x34) = (f32) M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */);
        break;
    case 2:
    case 3:
        memcpy(arg0, arg1, 0x40);
        break;
    case 6:
    case 7:
        LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(sp, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */));
        __as__6VECTORG9VU_VECTOR(arg0 + 0x30, M2C_FIELD(arg1, s128 *, 0x30));
        M2C_FIELD(arg0, s128 *, 0) = sp0;
        M2C_FIELD(arg0, s128 *, 0x10) = sp10;
        M2C_FIELD(arg0, s128 *, 0x20) = sp20;
        M2C_FIELD(arg0, f32 *, 0x3C) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x2C) = 0;
        M2C_FIELD(arg0, s32 *, 0x1C) = 0;
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
        break;
    case 11:
        memcpy(arg0, arg1, 0x40);
        M2C_FIELD(arg0, s128 *, 0x10) = temp_s0;
        M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */);
        M2C_FIELD(arg0, s128 *, 0x20) = (f32) M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */);
        break;
    case 12:
        memcpy(arg0, arg1, 0x40);
        M2C_FIELD(arg0, s128 *, 0) = temp_s0;
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */);
        M2C_FIELD(arg0, f32 *, 0x14) = (f32) M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */);
        break;
    }
    return arg0;
}
