#include "m2c_macros.h"

s32 PloFindSwObject_thunk(); /* extern */
M2C_UNK SetSwLoadRequest();         /* extern */
M2C_UNK SetWipeWipes();        /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK B_003E10D0;

void ActivateWipe(void *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 *temp_v0_3;
    s32 *temp_v0_4;
    s32 *var_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    s64 var_a2;
    s64 var_a3;
    void *temp_a2;
    void *var_a0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0);
    switch (temp_v1) {                              /* irregular */
    case 2:
        SetWipeWipes(arg0, 0);
        /* fallthrough */
    default:
        temp_a2 = arg1 + 4;
        if (temp_a2 == &B_003E10D0) {
            var_v0 = 1;
        } else if (&B_003E10D0 == NULL) {
            var_v0 = 0;
        } else if (temp_a2 != NULL) {
            var_v0 = (M2C_FIELD(&B_003E10D0, s32 *, 8) ^ M2C_FIELD(&B_003E10D0, s32 *, 0x38)) == (M2C_FIELD(temp_a2, s32 *, 8) ^ M2C_FIELD(temp_a2, s32 *, 0x38));
        } else {
            var_v0 = 0;
        }
        temp_v0 = *arg1;
        if (var_v0 != 0) {
            var_v0_2 = temp_v0 | 2;
        } else {
            var_v0_2 = temp_v0 & ~2;
        }
        *arg1 = var_v0_2;
        temp_v0_2 = PloFindSwObject_thunk(&B_003DD490, 0x405, arg2, 0);
        M2C_FIELD(arg0, s32 *, 0x54) = temp_v0_2;
        if (temp_v0_2 == 0) {
            SetSwLoadRequest(&B_003DD490, arg1);
            return;
        }
        var_a1 = arg1;
        var_a0 = arg0 + 8;
        M2C_FIELD(arg0, s32 *, 4) = 1;
        if (((s32) var_a1 | (s32) var_a0) & 7) {
            temp_v0_3 = var_a1 + 0x40;
            do {
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($a1) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, ($a1) */);
                M2C_ERROR(/* unknown instruction: ldl $a2, 0xf($a1) */);
                M2C_ERROR(/* unknown instruction: ldr $a2, 0x8($a1) */);
                M2C_ERROR(/* unknown instruction: ldl $a3, 0x17($a1) */);
                M2C_ERROR(/* unknown instruction: ldr $a3, 0x10($a1) */);
                M2C_ERROR(/* unknown instruction: ldl $t0, 0x1f($a1) */);
                M2C_ERROR(/* unknown instruction: ldr $t0, 0x18($a1) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($a0) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, ($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $a2, 0xf($a0) */);
                var_a2 = M2C_ERROR(/* unknown instruction: sdr $a2, 0x8($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $a3, 0x17($a0) */);
                var_a3 = M2C_ERROR(/* unknown instruction: sdr $a3, 0x10($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $t0, 0x1f($a0) */);
                M2C_ERROR(/* unknown instruction: sdr $t0, 0x18($a0) */);
                var_a1 += 0x20;
                var_a0 += 0x20;
            } while (var_a1 != temp_v0_3);
        } else {
            temp_v0_4 = var_a1 + 0x40;
            do {
                var_a2 = M2C_FIELD(var_a1, s64 *, 8);
                var_a3 = M2C_FIELD(var_a1, s64 *, 0x10);
                M2C_FIELD(var_a0, s64 *, 0) = (s64) M2C_FIELD(var_a1, s64 *, 0);
                M2C_FIELD(var_a0, s64 *, 8) = var_a2;
                M2C_FIELD(var_a0, s64 *, 0x10) = var_a3;
                M2C_FIELD(var_a0, s64 *, 0x18) = (s64) M2C_FIELD(var_a1, s64 *, 0x18);
                var_a1 += 0x20;
                var_a0 += 0x20;
            } while (var_a1 != temp_v0_4);
        }
        M2C_ERROR(/* unknown instruction: ldl $v0, 0x7($a1) */);
        M2C_ERROR(/* unknown instruction: ldr $v0, ($a1) */);
        M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($a0) */);
        M2C_ERROR(/* unknown instruction: sdr $v0, ($a0) */);
        M2C_FIELD(var_a0, s32 *, 8) = (s32) M2C_FIELD(var_a1, s32 *, 8);
        M2C_FIELD(arg0, s32 *, 0x58) = arg2;
        SetWipeWipes(arg0, arg3, var_a2, var_a3);
    case 1:
    case 3:
        return;
    }
}
