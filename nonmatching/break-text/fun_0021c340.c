#include "m2c_macros.h"

M2C_UNK func_001F3C70(void *, s32, s32, void *);    /* extern */
extern f32 g_2dded0;

void func_0021C340(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    s32 temp_a0;
    s32 temp_hi;
    s32 var_a1;
    s32 var_a2;
    s32 var_t5;
    s32 var_v0;
    void *temp_t2;
    void *var_a3;
    void *var_t0;
    void *var_t1;
    void *var_t3;
    void *var_t4;

    var_a1 = arg1;
    var_a2 = arg2;
    var_a3 = arg3;
    var_t4 = M2C_FIELD(arg0, void **, 0xDC);
    if (var_t4 != NULL) {
        var_v0 = M2C_FIELD(var_t4, s32 *, 4);
loop_2:
        var_a1 = 0;
        if (var_v0 > 0) {
loop_4:
            var_t5 = 0;
            temp_t2 = M2C_FIELD(var_t4, s32 *, 8) + (var_a1 << 5);
            var_t1 = M2C_FIELD(temp_t2, void **, 0x1C);
            var_t0 = M2C_FIELD(temp_t2, void **, 0xC);
            var_t3 = M2C_FIELD(temp_t2, void **, 0x14);
            var_a3 = M2C_FIELD(temp_t2, void **, 0x10);
            if (M2C_FIELD(temp_t2, s32 *, 0) > 0) {
                do {
                    temp_a0 = M2C_FIELD(arg0, s32 *, 0x158);
                    temp_f0 = (f32) (temp_a0 - 2);
                    if (temp_a0 == 0) {
                        M2C_BREAK(0);
                    }
                    if (temp_a0 == 0) {
                        M2C_BREAK(0);
                    }
                    var_a2 = M2C_FIELD(arg0, s32 *, 0x15C);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf8, ($t1) */);
                    temp_hi = (s32) (((M2C_FIELD(arg0, s32 *, 0x160) + temp_a0) - M2C_BITWISE(s32, temp_f0)) - 1) % temp_a0;
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf7 */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf6 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($a0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf7, ($sp) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf8x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf8y */);
                    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf8z */);
                    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf3, $vf0w */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v1) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v0) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf8x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf8y */);
                    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf8z */);
                    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf4, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf5, $vf6x */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf7x */);
                    M2C_FIELD(var_t0, s32 *, 0) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                    M2C_FIELD(var_t0, f32 *, 8) = (f32) M2C_ERROR(/* unknown instruction: pextuw $a1, $zero, $v0 */);
                    M2C_FIELD(var_t0, f32 *, 4) = (f32) M2C_ERROR(/* unknown instruction: prot3w $a1, $v0 */);
                    var_t0 += 0x10;
                    if (var_t3 != NULL) {
                        temp_f0_2 = 1.0f - ((g_2dded0 - M2C_FIELD((var_a2 + (temp_hi * 0x50)), f32 *, 0)) / M2C_FIELD(arg0, f32 *, 0x150));
                        if (temp_f0_2 < 0.0f) {

                        } else if (temp_f0_2 > 1.0f) {

                        }
                        M2C_FIELD(var_t3, s8 *, 3) = M2C_BITWISE(s8, (f32) M2C_FIELD(var_t1, u8 *, 0x1B));
                        var_t3 += 4;
                    }
                    if ((var_a3 != NULL) && (M2C_FIELD(arg0, s32 *, 0x180) != 0)) {
                        temp_f1 = ((M2C_FIELD(var_t1, f32 *, 0x10) * temp_f0) - (f32) temp_f0) * M2C_FIELD(((((s32) ((temp_hi + temp_a0) - 1) % temp_a0) * 0x50) + var_a2), f32 *, 8);
                        M2C_FIELD(var_a3, s8 *, 0) = M2C_BITWISE(s8, temp_f1);
                        M2C_FIELD(var_a3, s8 *, 1) = (s8) (M2C_BITWISE(u64, temp_f1) >> 8);
                        var_a3 += 6;
                    }
                    var_t5 += 1;
                    var_t1 += 0x20;
                } while (var_t5 < M2C_FIELD(temp_t2, s32 *, 0));
            }
            var_a1 += 1;
            if (var_a1 < M2C_FIELD(var_t4, s32 *, 4)) {
                goto loop_4;
            }
        }
        var_t4 = M2C_FIELD(var_t4, void **, 0xC);
        if (var_t4 != NULL) {
            var_v0 = M2C_FIELD(var_t4, s32 *, 4);
            goto loop_2;
        }
    }
    temp_f20 = M2C_FIELD(arg0, f32 *, 0x12C);
    M2C_FIELD(arg0, f32 *, 0x12C) = 1.0f;
    func_001F3C70(arg0, var_a1, var_a2, var_a3);
    M2C_FIELD(arg0, f32 *, 0x12C) = temp_f20;
}
