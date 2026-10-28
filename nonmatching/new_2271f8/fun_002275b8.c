#include "m2c_macros.h"

M2C_UNK *func_002275B8(M2C_UNK *arg0, s32 arg1) {
    M2C_UNK sp0;
    s8 sp10;
    s8 sp11;
    s8 sp12;
    s8 sp13;

    switch (arg1) {
    case 0x35:
        sp10 = 0x33;
        sp11 = 0x66;
        sp12 = 0x99;
        sp13 = 0x7F;
block_8:
        sp0 = M2C_UNALIGNED32(sp10);
        break;
    case 0x37:
        sp11 = 0x99;
        sp12 = 0x33;
        sp13 = 0x7F;
        sp10 = 0x33;
        sp0 = M2C_UNALIGNED32(sp10);
        break;
    case 0x36:
        sp10 = 0x99;
        sp11 = 0x33;
        sp12 = 0x66;
        sp13 = 0x7F;
        sp0 = M2C_UNALIGNED32(sp10);
        break;
    case 0x3F:
        sp12 = 0x33;
        sp10 = 0x99;
        sp13 = 0x7F;
        sp11 = 0x33;
        sp0 = M2C_UNALIGNED32(sp10);
        break;
    case 0x3C:
        sp11 = 0x33;
        sp12 = 0x99;
        sp13 = 0x7F;
        sp10 = 0x99;
        sp0 = M2C_UNALIGNED32(sp10);
        break;
    default:
        sp12 = 0x66;
        sp13 = 0x7F;
        sp10 = 0x66;
        sp11 = 0x66;
        goto block_8;
    }
    *arg0 = M2C_UNALIGNED32(sp0);
    return arg0;
}
