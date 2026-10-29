#include "m2c_macros.h"
extern "C" {

M2C_UNK SetCmPosMat(s8 *, s8 *);                  /* extern */

void SetCmMat(s8 *arg0, s8 *arg1) {
    s8 sp[0x40] __attribute__((aligned(16)));

    M2C_FIELD(sp, s128 *, 0x0) = M2C_FIELD(arg1, s128 *, 0x0);
    M2C_FIELD(sp, s128 *, 0x10) = M2C_FIELD(arg1, s128 *, 0x10);
    M2C_FIELD(sp, s128 *, 0x20) = M2C_FIELD(arg1, s128 *, 0x20);
    M2C_FIELD(sp, s128 *, 0x30) = M2C_FIELD(arg0, s128 *, 0x90);
    M2C_FIELD(sp, s32 *, 0x2C) = 0;
    M2C_FIELD(sp, s32 *, 0x1C) = 0;
    M2C_FIELD(sp, s32 *, 0xC) = 0;
    SetCmPosMat(arg0, sp);
}

}
