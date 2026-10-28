#include "m2c_macros.h"

s32 NRandInRange(M2C_UNK, M2C_UNK, s32 *, s32 *);   /* extern */
s32 func_001FD028(void *, M2C_UNK);                 /* extern */
s16 func_001FD070(void *, s32);                     /* extern */
M2C_UNK func_002322F0(s32 *);                       /* extern */
M2C_UNK memset(s32 *, M2C_UNK, M2C_UNK, s32 *);     /* extern */
extern M2C_UNK RO_002A82A8;
extern s32 RO_002A8350;

void func_001FEED0(void *arg0) {
    char sp[0x400];
    s32 spB0;
    s32 sp120;
    s16 sp130;
    s16 sp140;
    s32 sp148;
    M2C_UNK *var_v1;
    s32 *temp_a3;
    s32 *var_a2;
    s32 *var_a3;
    s32 temp_t0;
    void *var_a0;

    if (M2C_FIELD(arg0, s32 *, 0x64) == 0) {
        var_v1 = &RO_002A82A8;
        var_a0 = sp;
        if ((s32) &RO_002A82A8 & 7) {
            do {
                M2C_ERROR(/* unknown instruction: ldl $a2, 0x7($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $a2, ($v1) */);
                M2C_ERROR(/* unknown instruction: ldl $a3, 0xf($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $a3, 0x8($v1) */);
                M2C_ERROR(/* unknown instruction: ldl $t0, 0x17($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $t0, 0x10($v1) */);
                M2C_ERROR(/* unknown instruction: ldl $t1, 0x1f($v1) */);
                M2C_ERROR(/* unknown instruction: ldr $t1, 0x18($v1) */);
                M2C_ERROR(/* unknown instruction: sdl $a2, 0x7($a0) */);
                M2C_ERROR(/* unknown instruction: sdr $a2, ($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $a3, 0xf($a0) */);
                M2C_ERROR(/* unknown instruction: sdr $a3, 0x8($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $t0, 0x17($a0) */);
                M2C_ERROR(/* unknown instruction: sdr $t0, 0x10($a0) */);
                M2C_ERROR(/* unknown instruction: sdl $t1, 0x1f($a0) */);
                M2C_ERROR(/* unknown instruction: sdr $t1, 0x18($a0) */);
                var_v1 += 0x20;
            } while (var_v1 != (&RO_002A82A8 + 0xA0));
        } else {
            do {
                M2C_FIELD(var_a0, s64 *, 0) = (s64) M2C_FIELD(var_v1, s64 *, 0);
                M2C_FIELD(var_a0, s64 *, 8) = (s64) M2C_FIELD(var_v1, s64 *, 8);
                M2C_FIELD(var_a0, s64 *, 0x10) = (s64) M2C_FIELD(var_v1, s64 *, 0x10);
                M2C_FIELD(var_a0, s64 *, 0x18) = (s64) M2C_FIELD(var_v1, s64 *, 0x18);
                var_v1 += 0x20;
                var_a0 += 0x20;
            } while (var_v1 != (&RO_002A82A8 + 0xA0));
        }
        var_a3 = &RO_002A8350;
        M2C_ERROR(/* unknown instruction: ldl $t1, 0x7($v1) */);
        M2C_ERROR(/* unknown instruction: ldr $t1, ($v1) */);
        M2C_ERROR(/* unknown instruction: sdl $t1, 0x7($a0) */);
        var_a2 = &spB0;
        M2C_ERROR(/* unknown instruction: sdr $t1, ($a0) */);
        if ((s32) &RO_002A8350 & 7) {
            do {
                M2C_ERROR(/* unknown instruction: ldl $t1, 0x7($a3) */);
                M2C_ERROR(/* unknown instruction: ldr $t1, ($a3) */);
                M2C_ERROR(/* unknown instruction: ldl $t2, 0xf($a3) */);
                M2C_ERROR(/* unknown instruction: ldr $t2, 0x8($a3) */);
                M2C_ERROR(/* unknown instruction: ldl $v1, 0x17($a3) */);
                M2C_ERROR(/* unknown instruction: ldr $v1, 0x10($a3) */);
                M2C_ERROR(/* unknown instruction: ldl $a0, 0x1f($a3) */);
                M2C_ERROR(/* unknown instruction: ldr $a0, 0x18($a3) */);
                M2C_ERROR(/* unknown instruction: sdl $t1, 0x7($a2) */);
                M2C_ERROR(/* unknown instruction: sdr $t1, ($a2) */);
                M2C_ERROR(/* unknown instruction: sdl $t2, 0xf($a2) */);
                M2C_ERROR(/* unknown instruction: sdr $t2, 0x8($a2) */);
                M2C_ERROR(/* unknown instruction: sdl $v1, 0x17($a2) */);
                M2C_ERROR(/* unknown instruction: sdr $v1, 0x10($a2) */);
                M2C_ERROR(/* unknown instruction: sdl $a0, 0x1f($a2) */);
                M2C_ERROR(/* unknown instruction: sdr $a0, 0x18($a2) */);
                var_a3 += 0x20;
                var_a2 += 0x20;
            } while (var_a3 != (&RO_002A8350 + 0x60));
        } else {
            do {
                M2C_FIELD(var_a2, s64 *, 0) = (s64) M2C_FIELD(var_a3, s64 *, 0);
                M2C_FIELD(var_a2, s64 *, 8) = (s64) M2C_FIELD(var_a3, s64 *, 8);
                M2C_FIELD(var_a2, s64 *, 0x10) = (s64) M2C_FIELD(var_a3, s64 *, 0x10);
                M2C_FIELD(var_a2, s64 *, 0x18) = (s64) M2C_FIELD(var_a3, s64 *, 0x18);
                var_a3 += 0x20;
                var_a2 += 0x20;
            } while (var_a3 != (&RO_002A8350 + 0x60));
        }
        *var_a2 = *var_a3;
        temp_t0 = M2C_FIELD(arg0, s32 *, 0x138);
        temp_a3 = sp + ((NRandInRange(0, 5, var_a2, var_a3) * 4) + ((&spB0)[temp_t0 + 0xC] * 0x18));
        M2C_FIELD(arg0, s32 *, 0x138) = (s32) (temp_t0 + *temp_a3);
        memset(&sp120, 0, 0x30, temp_a3);
        sp148 = 0x13;
        sp120 = M2C_FIELD(arg0, s32 *, 0xE8);
        sp130 = func_001FD070(arg0, func_001FD028(arg0, 0x28));
        sp140 = M2C_FIELD(arg0, s32 *, 0x138) * 0x7F;
        func_002322F0(&sp120);
    }
}
