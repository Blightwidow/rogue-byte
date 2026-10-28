#include "m2c_macros.h"

extern M2C_UNK D_002BF670;

void ResetJtDynamicTunnel__FP2JT(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_v0, s32 *, 0x164) = 5;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x114) = &D_002BF670;
    M2C_FIELD(temp_v0, s32 *, 0x168) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x128) = 3;
    M2C_FIELD(temp_v0, s32 *, 0x140) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x100) = 0;
    M2C_FIELD(temp_v0, s32 *, 0xFC) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x108) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x10C) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x110) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x120) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x124) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x16C) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x130) = 0;
}
