#include "m2c_macros.h"

M2C_UNK InitSaa();                                  /* extern */
M2C_UNK SetEyesEyess__FP4EYES5EYESS(void *, M2C_UNK); /* extern */

void InitEyes__FP4EYESP4SAAF(void *arg0, void *arg1) {
    InitSaa();
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) M2C_FIELD(arg1, s32 *, 0x1C);
    M2C_FIELD(arg0, f32 *, 0x50) = (f32) M2C_FIELD(arg1, f32 *, 0xC);
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) M2C_FIELD(arg1, f32 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0x64) = -1;
    M2C_FIELD(arg0, f32 *, 0x58) = (f32) M2C_FIELD(arg1, f32 *, 0x14);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(arg1, f32 *, 0x18);
    SetEyesEyess__FP4EYES5EYESS(arg0, 0);
}
