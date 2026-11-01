#include "m2c_macros.h"

extern M2C_UNK D_002C36A0;
extern M2C_UNK D_002C3728;

u16 SjisFromAsciiChar(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a2;
    s32 var_a1;
    s32 var_v1;

    var_a1 = arg1;
    temp_a2 = arg0 & 0xFF;
    var_v1 = 0;
    if ((u32) (temp_a2 - 0x20) < 0x10U) {
        var_v1 = 1;
        goto block_14;
    }
    if ((u32) (temp_a2 - 0x30) < 0xAU) {
        var_a1 = 0;
        goto block_14;
    }
    if ((u32) (temp_a2 - 0x3A) < 7U) {
        var_v1 = 0xB;
        goto block_14;
    }
    if ((u32) (temp_a2 - 0x41) < 0x1AU) {
        var_a1 = 1;
        goto block_14;
    }
    if ((u32) (temp_a2 - 0x5B) < 6U) {
        var_v1 = 0x25;
        goto block_14;
    }
    if ((u32) (temp_a2 - 0x61) < 0x1AU) {
        var_a1 = 2;
        goto block_14;
    }
    var_v1 = 0x3F;
    if ((u32) (temp_a2 - 0x7B) >= 4U) {
        return 0U;
    }
block_14:
    if (var_v1 == 0) {
        temp_a0 = var_a1 * 4;
        return ((*(temp_a0 + &D_002C3728) + temp_a2) - M2C_FIELD((&D_002C3728 + temp_a0), u16 *, 2)) & 0xFFFF;
    }
    return *(((temp_a2 - (var_v1 + 0x1F)) * 4) + &D_002C36A0);
}
