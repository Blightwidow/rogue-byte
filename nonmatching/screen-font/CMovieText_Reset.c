#include "m2c_macros.h"

M2C_UNK CMovieText_UpdateFont(void *, M2C_UNK, void *); /* extern */

void CMovieText_Reset(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0) = arg1;
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg0, M2C_UNK *, 0x14) = M2C_UNALIGNED32(M2C_FIELD(arg0, M2C_UNK *, 0x18));
    M2C_FIELD(arg0, s32 *, 0x1C) = 0x80000000;
    M2C_FIELD(arg0, u8 *, 0x1F) = (u8) M2C_FIELD(arg0, u8 *, 0x17);
    CMovieText_UpdateFont(arg0, 0x80000000, arg0);
}
