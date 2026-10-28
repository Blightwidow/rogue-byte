#include "m2c_macros.h"

M2C_UNK func_001F4BA8(void *, void *, M2C_UNK);     /* extern */
extern s32 B_003E115C;

void func_001CE170(void *arg0) {
    void *temp_a1;
    void *temp_a2;

    M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), s128 *, 0) = (s128) M2C_FIELD(arg0, s128 *, 0x170);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x180);
    temp_a2 = M2C_FIELD(arg0, void **, 0xEC);
    M2C_FIELD(temp_a2, s128 *, 0x20) = (s128) M2C_FIELD(arg0, s128 *, 0x190);
    temp_a1 = M2C_FIELD(arg0, void **, 0xEC);
    M2C_FIELD(temp_a1, f32 *, 0x30) = (f32) M2C_FIELD(arg0, f32 *, 0x1A0);
    B_003E115C = 1;
    func_001F4BA8(temp_a1, temp_a2, 1);
}
