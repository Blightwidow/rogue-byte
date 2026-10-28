#include "m2c_macros.h"

M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */

s32 ClsgClipEdgeToBsp(u32 arg0, u32 arg1, s128 arg2, s128 arg3) {
    char sp[0x400];
    M2C_UNK sp8;
    M2C_UNK spC;
    u32 sp0;                                        /* compiler-managed */
    void *sp4;
    s128 sp10;
    M2C_UNK sp20;
    M2C_UNK sp430;
    M2C_UNK sp440;
    M2C_UNK sp450;
    M2C_UNK sp460;
    s128 sp470;
    s128 sp480;
    s128 sp490;
    M2C_UNK *temp_fp;
    M2C_UNK *var_s0;
    M2C_UNK *var_s1;
    M2C_UNK *var_s2;
    M2C_UNK *var_s4;
    f32 temp_f3;
    f32 temp_f5;
    f32 temp_f7;
    f32 temp_v0;
    f32 temp_v0_2;
    s128 temp_v1_2;
    s32 temp_s7;
    s32 var_s5;
    s32 var_s6;
    s32 var_v0;
    u32 temp_v0_3;
    u32 temp_v1;
    u32 var_v1;
    u32 var_v1_2;

    var_s1 = &sp20;
    sp470 = arg2;
    temp_s7 = M2C_ERROR(/* Read from unset register $t0 */);
    var_s4 = M2C_ERROR(/* Read from unset register $t1 */);
    var_s2 = NULL;
    temp_fp = var_s1;
    var_s6 = 0;
    var_s5 = 0;
    sp480 = arg3;
    memset(sp, 0, 0x20);
    memset(var_s1, 0, 0x20);
    sp0 = (arg0 >= arg1) ? 0U : arg0;
    M2C_FIELD(var_s1, f32 *, 8) = 1.0f;
loop_1:
    var_v1 = sp0;
    if (sp0 != 0) {
block_12:
        sp490 = *M2C_FIELD(var_v1, s128 **, 8);
        func_002564B8(&sp430);
        func_002564B8(&sp440);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x490($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x470($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf4 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vmsubw.x $vf1, $vf2, $vf3w */);
        temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x440($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x430($sp) */);
        func_002564B8(&sp450);
        func_002564B8(&sp460);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x490($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x480($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf4 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf1, $vf2z */);
        M2C_ERROR(/* unknown instruction: vmsubw.x $vf2, $vf1, $vf3w */);
        temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x460($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x450($sp) */);
        if ((temp_v0 <= 0.0f) && (temp_v0_2 <= 0.0f)) {
            sp4 = (void *) sp0;
            var_v1_2 = M2C_FIELD((void *) sp0, u32 *, 0);
        } else if (!(temp_v0 > 0.0f) || !(temp_v0_2 > 0.0f)) {
            temp_f5 = M2C_FIELD(var_s1, f32 *, 8);
            temp_f7 = temp_v0 / (temp_v0 - temp_v0_2);
            temp_f3 = (temp_v0_2 * sp8) + ((1.0f - sp8) * temp_v0);
            if ((sp8 < temp_f7) && (temp_f7 < temp_f5)) {
                var_s1 += 0x20;
                M2C_FIELD(var_s1, f32 *, 8) = temp_f7;
                M2C_FIELD(var_s1, s128 *, 0x10) = sp490;
                M2C_FIELD(var_s1, s32 *, 0xC) = (s32) M2C_FIELD((void *) sp0, s32 *, 8);
                if (temp_f3 <= 0.0f) {
                    M2C_FIELD(var_s1, s32 *, 4) = 0;
                    temp_v1 = M2C_FIELD((void *) sp0, u32 *, 4);
                    M2C_FIELD(var_s1, u32 *, 0) = (u32) ((temp_v1 >= arg1) ? 0U : temp_v1);
                } else {
                    M2C_FIELD(var_s1, s32 *, 4) = (s32) sp0;
                    temp_v0_3 = M2C_FIELD((void *) sp0, u32 *, 0);
                    M2C_FIELD(var_s1, u32 *, 0) = (u32) ((temp_v0_3 >= arg1) ? 0U : temp_v0_3);
                }
            }
            if ((temp_f3 < 0.0f) || ((temp_f3 == 0.0f) && (((temp_v0_2 * temp_f5) + ((1.0f - temp_f5) * temp_v0)) <= 0.0f))) {
                sp4 = (void *) sp0;
                var_v1_2 = M2C_FIELD((void *) sp0, u32 *, 0);
            } else {
                goto block_27;
            }
        } else {
block_27:
            sp4 = NULL;
            var_v1_2 = M2C_FIELD((void *) sp0, u32 *, 4);
        }
        sp0 = (var_v1_2 >= arg1) ? 0U : var_v1_2;
        goto loop_1;
    }
    var_s0 = var_s4;
loop_3:
    if (sp4 != NULL) {
        if (var_s2 != NULL) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x470($sp) */);
            if (sp8 == M2C_FIELD(var_s2, f32 *, 0x44)) {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x480($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x420($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x420($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf1x */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf4, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($s2) */);
                M2C_FIELD(var_s2, s128 *, 0x30) = (s128) M2C_FIELD(var_s1, s128 *, 0x10);
                M2C_FIELD(var_s2, f32 *, 0x44) = (f32) M2C_FIELD(var_s1, f32 *, 8);
                M2C_FIELD(var_s2, s32 *, 0x50) = (s32) M2C_FIELD(var_s1, s32 *, 0xC);
                goto block_9;
            }
        }
        var_s2 = var_s0;
        if ((var_s5 >> 5) < temp_s7) {
            memset(var_s2, 0, 0x60);
            var_s0 += 0x60;
            var_s6 += 0x20;
            var_s5 += 0x20;
            var_s4 += 0x60;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x470($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x420($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x420($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x480($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf5, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf6, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf5, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf6, $vf4x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x420($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, -0x60($s0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, -0x50($s0) */);
            M2C_FIELD(var_s0, s128 *, -0x40) = sp10;
            M2C_FIELD(var_s0, s128 *, -0x30) = (s128) M2C_FIELD(var_s1, s128 *, 0x10);
            M2C_FIELD(var_s0, f32 *, -0x20) = sp8;
            M2C_FIELD(var_s0, f32 *, -0x1C) = (f32) M2C_FIELD(var_s1, f32 *, 8);
            M2C_FIELD(var_s0, s32 *, -0x14) = spC;
            M2C_FIELD(var_s0, s32 *, -0x10) = (s32) M2C_FIELD(var_s1, s32 *, 0xC);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x420($sp) */);
            goto block_9;
        }
        var_v0 = temp_s7;
    } else {
block_9:
        var_v0 = var_s6 >> 5;
        if ((u32) temp_fp < (u32) var_s1) {
            sp0 = M2C_FIELD(var_s1, s128 *, 0);
            temp_v1_2 = M2C_FIELD(var_s1, s128 *, 0x10);
            var_s1 -= 0x20;
            sp10 = temp_v1_2;
            if ((s32) sp0 != 0) {
                var_v1 = (u32) sp0;
                goto block_12;
            }
            goto loop_3;
        }
    }
    return var_v0;
}
