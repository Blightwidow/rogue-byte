#include "m2c_macros.h"

M2C_UNK bevy_splice_bif_transpose(M2C_UNK, M2C_UNK, s32, s32); /* extern */

s32 TransposeMatrix4(s32 arg0, s32 arg1) {
    bevy_splice_bif_transpose(4, 4, arg1, arg0);
    return arg0;
}
