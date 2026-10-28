#include "m2c_macros.h"

M2C_UNK SetLoParent(void *, void *, s32, s32);      /* extern */
M2C_UNK UpdateAloXfWorld(void *);                   /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, void *, void *); /* extern */
M2C_UNK func_001F2468(void *);                      /* extern */
M2C_UNK func_001F26A8(void *);                      /* extern */
M2C_UNK func_001F8668(void *, M2C_UNK);             /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void SetSoParent(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    char sp[0x400];
    M2C_UNK sp70;
    M2C_UNK unksp3C;
    s128 sp30;
    s128 sp40;
    s128 sp80;
    s32 temp_s6;
    s32 temp_v0_2;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s7;
    s32 var_t0;
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v1;
    void *temp_v1_2;
    void *var_a1;
    void *var_s0;

    if (arg3 & 3) {
        if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
            sp30 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s128 *, 0x70);
        } else {
            memset(sp, 0, 0x40);
            var_s0 = M2C_FIELD(arg0, void **, 0x60);
            unksp3C = 1.0f;
            if (var_s0 != NULL) {
                var_a1 = var_s0;
                do {
                    __ml__FRC7MATRIX4T0(&sp40, var_a1, sp);
                    sp30 = sp70;
                    var_s0 = M2C_FIELD(var_s0, void **, 0xA0);
                    var_a1 = var_s0;
                } while (var_s0 != NULL);
            }
        }
    }
    temp_s6 = arg3 & 4;
    var_s7 = arg3 & 8;
    if (temp_s6 != 0) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
        M2C_ERROR(/* unknown instruction: por $fp, $zero, $v0 */);
        var_s7 = arg3 & 8;
    }
    if (var_s7 != 0) {
        temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
        sp80 = M2C_FIELD(temp_v1_2, s128 (**)(void *), 0x114)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x110));
    }
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    var_a3 = 1;
    if (temp_v0 != NULL) {
        var_t0 = M2C_FIELD(temp_v0, s32 *, 0x54);
        var_a3 = M2C_FIELD(temp_v0, s32 *, 0x50);
    } else {
        var_t0 = 0;
    }
    var_a2 = arg2;
    if ((arg2 == 0) && (arg1 != NULL)) {
        var_a2 = M2C_FIELD(arg1, s32 *, 0x60);
    }
    var_a1_2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x50) > 0) {
loop_18:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x54) + (var_a1_2 << 8);
        temp_v0_2 = (s32) (M2C_FIELD(temp_a0, s32 *, 0xA0) - var_t0) >> 8;
        if ((temp_v0_2 >= 0) && (temp_v0_2 < var_a3)) {
            M2C_FIELD(temp_a0, s32 *, 0xA0) = var_a2;
        }
        var_a1_2 += 1;
        if (var_a1_2 < M2C_FIELD(arg0, s32 *, 0x50)) {
            goto loop_18;
        }
    }
    SetLoParent(arg0, arg1, arg2, arg3);
    UpdateAloXfWorld(arg0);
    if (arg3 & 1) {
        temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, s128), 0xEC)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0xE8), sp30);
    }
    if (arg3 & 2) {
        temp_v0_4 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, void *), 0xF4)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0xF0), sp);
    }
    if (temp_s6 != 0) {
        temp_v0_5 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x118), M2C_ERROR(/* unknown instruction: por $a1, $zero, $fp */));
    }
    if (var_s7 != 0) {
        temp_v0_6 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, s128), 0x124)(arg0 + M2C_FIELD(temp_v0_6, s16 *, 0x120), sp80);
    }
    func_001F2468(arg0);
    func_001F26A8(arg0);
    temp_v0_7 = M2C_FIELD(arg0, void **, 0x10);
    if ((temp_v0_7 != NULL) && !(M2C_FIELD(temp_v0_7, s64 *, 0x148) & (0x8000 << 0x14))) {
        func_001F8668(arg0, 0);
    }
}
