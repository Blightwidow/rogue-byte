#include "m2c_macros.h"

M2C_UNK GreyColor_1ed2d8(void *);                   /* extern */
M2C_UNK PackColorVecToU8_11dd30(void *, u8, void *); /* extern */
M2C_UNK UnpackColorU8ToVec_11dcd8(M2C_UNK *, void *); /* extern */
extern s32 B_003E12C8;

void FilterColorRgba8_1ed278(void *arg0) {
    char sp[0x400];
    M2C_UNK sp10;

    if (B_003E12C8 != 0) {
        sp10 = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0));
        UnpackColorU8ToVec_11dcd8(&sp10, sp);
        GreyColor_1ed2d8(sp);
        PackColorVecToU8_11dd30(sp, M2C_FIELD(arg0, u8 *, 3), arg0);
    }
}
