#include "m2c_macros.h"

M2C_UNK SetLoParent(void *, void *, void *, s32);   /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, void *, void *); /* extern */

void SetXfmParent(void *arg0, void *arg1, void *arg2, s32 arg3) {
    char sp[0x400];
    M2C_UNK sp70;
    s128 sp30;
    s128 sp40;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *var_a1;
    void *var_s0;

    if (arg3 & 3) {
        if (!(((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1)) {
            var_s0 = M2C_FIELD(arg0, void **, 0x50);
            sp30 = M2C_FIELD(arg0, s128 *, 0x90);
            if (var_s0 != NULL) {
                var_a1 = var_s0;
                do {
                    __ml__FRC7MATRIX4T0(&sp40, var_a1, sp);
                    sp30 = sp70;
                    var_s0 = M2C_FIELD(var_s0, void **, 0xA0);
                    var_a1 = var_s0;
                } while (var_s0 != NULL);
            }
        } else {
            temp_v1 = M2C_FIELD(arg0, void **, 0xC);
            sp30 = M2C_FIELD(M2C_FIELD(temp_v1, void *(**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8)), s128 *, 0x30);
        }
    }
    if (arg2 != NULL) {
        M2C_FIELD(arg0, void **, 0x50) = arg2;
    } else if (arg1 == NULL) {
        M2C_FIELD(arg0, void **, 0x50) = NULL;
    } else {
        M2C_FIELD(arg0, void **, 0x50) = (void *) M2C_FIELD(arg1, void **, 0x60);
    }
    SetLoParent(arg0, arg1, arg2, arg3);
    if (arg3 & 1) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s128), 0xEC)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xE8), sp30);
    }
    if (arg3 & 2) {
        temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *), 0xF4)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0xF0), sp);
    }
}
