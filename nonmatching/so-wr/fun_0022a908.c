#include "m2c_macros.h"

M2C_UNK ClosestPointOnSegment(); /* extern */
M2C_UNK *FEndTaskComplete();                     /* extern */
M2C_UNK *FGadgetAcquired(); /* extern */
s32 PchzStringFromId(); /* extern */
M2C_UNK PmatLoWorld();                   /* extern */
s128 PosLoWorld();                               /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR();  /* extern */
M2C_UNK *bevy_camera_cm_screen_px_ps2(); /* extern */
M2C_UNK *func_001A5EE8();   /* extern */
M2C_UNK *func_001A5FB8();  /* extern */
M2C_UNK func_001F3C70();                            /* extern */
M2C_UNK func_0022A220();                      /* extern */
M2C_UNK memcpy();         /* extern */
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002C449C;
extern M2C_UNK D_FLT_002C44A0;
extern M2C_UNK D_FLT_002C44B0;
extern M2C_UNK D_FLT_002C44C0;
extern M2C_UNK D_FLT_002C44D0;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded0;

M2C_UNK *func_0022A908(void *arg0) {
    M2C_UNK spD0;
    M2C_UNK spE0;
    M2C_UNK unksp1C;
    M2C_UNK unksp3;
    M2C_UNK unksp53;
    s32 sp0;
    s128 sp10;
    s32 sp2C;
    s32 sp3C;
    M2C_UNK sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    M2C_UNK sp80;
    f32 spB0;
    s128 spC0;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_v1_3;
    f32 var_f0;
    f32 var_f12;
    f32 var_f20;
    f32 var_f21;
    f32 var_f22;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_4;
    s32 temp_a2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;
    void *temp_a0_3;
    void *temp_a0_5;

    func_001F3C70();
    temp_f1 = g_2dded0 - M2C_ERROR(/* unknown instruction: max.s $f4, $f4, $f0 */);
    temp_f3 = M2C_FIELD(&D_FLT_002C44A0, f32 *, 0) + (temp_f1 * (M2C_FIELD(&D_FLT_002C44A0, f32 *, 4) + (temp_f1 * M2C_FIELD(&D_FLT_002C44A0, f32 *, 8))));
    if (temp_f3 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
        var_f12 = M2C_FIELD(&g_2bbb60, f32 *, 0);
    } else {
        var_f12 = temp_f3;
        if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f3) {
            var_f12 = M2C_FIELD(&g_2bbb60, f32 *, 4);
        }
    }
    var_f21 = var_f12;
    temp_f0 = g_2dded0 - (M2C_FIELD(&B_003DD490, f32 *, 0x4750) + D_FLT_002C449C);
    temp_f3_2 = M2C_FIELD(&D_FLT_002C44B0, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002C44B0, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002C44B0, f32 *, 8))));
    if (temp_f3_2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
        var_f0 = M2C_FIELD(&g_2bbb60, f32 *, 0);
    } else {
        var_f0 = temp_f3_2;
        if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f3_2) {
            var_f0 = M2C_FIELD(&g_2bbb60, f32 *, 4);
        }
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    var_f22 = var_f0;
    if (temp_v1 != 1) {
        if (temp_v1 >= 2) {
            var_v0 = 2;
            if (temp_v1 != 2) {

            } else {
                var_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x4764) < M2C_FIELD(&B_003DD490, s32 *, 0x4768);
                if ((var_v0 == 0) && (var_v0 = -1, (M2C_FIELD(&B_003DD490, s32 *, 0x3B0C) == 0)) && ((temp_a0 = M2C_FIELD(arg0, s32 *, 0x184), (temp_a0 == -1)) || (var_v0 = FGadgetAcquired(temp_a0, &g_2bbb60, &g_2dded0, var_f12), (var_v0 == 0)))) {
                    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x188);
                    if (temp_a0_2 != 0) {
                        var_v0 = FEndTaskComplete(temp_a0_2);
                        if (var_v0 == 0) {
                            goto block_26;
                        }
                    }
                } else {
                    goto block_26;
                }
            }
        } else {
            var_v0 = (s32) &B_003DD490;
            if (temp_v1 != 0) {

            } else if (M2C_FIELD((s32) &B_003DD490, s32 *, 0x3B0C) != 0) {
                goto block_26;
            }
        }
    } else {
        var_v0 = (s32) &B_003DD490;
        if (M2C_FIELD((s32) &B_003DD490, s32 *, 0x3B0C) == 0) {
block_26:
            var_f22 = 0.0f;
            var_f21 = 0.0f;
        }
    }
    if (var_f21 != 0.0f) {
        func_0022A220(arg0);
        spC0 = PosLoWorld(M2C_FIELD(arg0, s32 *, 0x168));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xc0($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xd0($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        ClosestPointOnSegment(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s1 */), spC0, spD0, 0);
        temp_f12 = M2C_FIELD(&D_FLT_002C44C0, f32 *, 0) + (spB0 * (M2C_FIELD(&D_FLT_002C44C0, f32 *, 4) + (spB0 * M2C_FIELD(&D_FLT_002C44C0, f32 *, 8))));
        if (temp_f12 < M2C_FIELD(&D_FLT_002C44D0, f32 *, 0)) {
            var_f20 = M2C_FIELD(&D_FLT_002C44D0, f32 *, 0);
        } else {
            var_f20 = temp_f12;
            if (M2C_FIELD(&D_FLT_002C44D0, f32 *, 4) < temp_f12) {
                var_f20 = M2C_FIELD(&D_FLT_002C44D0, f32 *, 4);
            }
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xd0($sp) */);
        temp_a0_3 = M2C_FIELD(arg0, void **, 0x16C);
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xe0($sp) */);
        if (temp_a0_3 != NULL) {
            PmatLoWorld(temp_a0_3, temp_f12);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf3x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xa0($sp) */);
            memcpy(&sp50, &sp80, 0x30);
            __as__6VECTORG9VU_VECTOR(&sp40, spE0);
            sp10 = sp50;
            M2C_FIELD(&sp10, s128 *, 0x10) = sp60;
            M2C_FIELD(&sp10, s128 *, 0x20) = sp70;
            sp3C = 0;
            sp2C = 0;
            unksp1C = 0;
            M2C_FIELD(&sp10, f32 *, 0x3C) = 1.0f;
            var_v0 = func_001A5EE8(M2C_FIELD(arg0, void **, 0x16C), &sp10, var_f21, var_f21);
        }
        temp_a0_4 = M2C_FIELD(arg0, s32 *, 0x170);
        if (temp_a0_4 != 0) {
            var_v0 = func_001A5FB8(temp_a0_4, spC0, spE0, var_f20, var_f21);
        }
        temp_a0_5 = M2C_FIELD(arg0, void **, 0x174);
        if (temp_a0_5 != NULL) {
            PmatLoWorld(temp_a0_5);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf3x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xa0($sp) */);
            memcpy(&sp50, &sp80, 0x30);
            __as__6VECTORG9VU_VECTOR(&sp40, spC0);
            sp10 = sp50;
            M2C_FIELD(&sp10, s128 *, 0x10) = sp60;
            M2C_FIELD(&sp10, s128 *, 0x20) = sp70;
            sp3C = 0;
            sp2C = 0;
            unksp1C = 0;
            M2C_FIELD(&sp10, f32 *, 0x3C) = 1.0f;
            var_v0 = func_001A5EE8(M2C_FIELD(arg0, void **, 0x174), &sp10, var_f21, var_f21);
        }
        if (var_f22 > 0.0f) {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x160);
            if ((var_v0 != 0) && (var_v0 = M2C_FIELD(var_v0, s32 *, 0x7C), (var_v0 != 0))) {
                temp_v1_2 = M2C_FIELD(var_v0, s32 *, 0x6C);
                var_v0 = -1;
                if (temp_v1_2 != -1) {
                    if (M2C_FIELD(arg0, void **, 0x16C) != NULL) {

                    }
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                    sp0 = 0x80603030;
                    sp50 = 0xFFC0C0C0;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
                    temp_a2 = M2C_FIELD(arg0, s32 *, 0x160);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xe0($sp) */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf2x */);
                    temp_v1_3 = var_f22 * (f32) unksp3;
                    unksp3 = M2C_ERROR(/* Read from unset register $f2 */);
                    unksp53 = M2C_BITWISE(s8, temp_v1_3);
                    sp60 = M2C_UNALIGNED32(sp0);
                    sp70 = M2C_UNALIGNED32(sp50);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xf0($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xf0($sp) */);
                    var_v0 = bevy_camera_cm_screen_px_ps2(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), PchzStringFromId(&B_003DD490, M2C_FIELD(M2C_FIELD(temp_a2, s32 *, 0x7C), s32 *, 0x6C), (M2C_UNK *) temp_a2, M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf2 */)), &sp60, &sp70, var_f20);
                }
            }
        }
    }
    return (M2C_UNK *) var_v0;
}
