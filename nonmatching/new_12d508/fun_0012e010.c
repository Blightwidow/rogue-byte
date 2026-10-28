#include "m2c_macros.h"

M2C_UNK func_0022C818(s32, void *, M2C_UNK);        /* extern */

void func_0012E010(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), f32 *, 0xA8) = (f32) M2C_FIELD(arg0, f32 *, 0x1C);
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0xC0) = (s128) M2C_FIELD(arg0, s128 *, 0x20);
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s128 *, 0xD0) = (s128) M2C_FIELD(arg0, s128 *, 0x30);
    M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 0x9A) = 2;
    func_0022C818(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, void **, 8), 2);
}
