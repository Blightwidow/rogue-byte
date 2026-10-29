#include "m2c_macros.h"
extern "C" {

M2C_UNK SetCmPosMat(void *, void *);                /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s128 *, s128, s128, s128, s128, s128); /* extern */

void func_0014F3C0(void *arg0) {
    char sp[0x30];
    M2C_UNK unksp3C;
    s128 sp30;
    s128 temp_a2;
    s128 temp_a3;

    temp_a3 = M2C_FIELD(arg0, s128 *, 0x60);
    temp_a2 = M2C_FIELD(arg0, s128 *, 0x90);
    sp30 = temp_a2;
    __as__6VECTORG9VU_VECTOR(&sp30, temp_a2, temp_a3, temp_a3, M2C_FIELD(arg0, s128 *, 0x70), M2C_FIELD(arg0, s128 *, 0x80));
    unksp3C = 1.0f;
    SetCmPosMat(arg0, sp);
}
}
