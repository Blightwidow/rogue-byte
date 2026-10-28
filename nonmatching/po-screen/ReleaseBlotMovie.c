#include "m2c_macros.h"

M2C_UNK ClearSl(void *);                            /* extern */

void ReleaseBlotMovie(void *arg0) {
    void *temp_v0;

    M2C_FIELD(arg0, s32 *, 0xF8) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s16 *, 0x80) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    ClearSl(arg0 + 0xFC);
    temp_v0 = M2C_FIELD(arg0, void **, 0xC0);
    M2C_FIELD(temp_v0, s32 *, 0x48) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x44) = 0;
}
