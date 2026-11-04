#include "m2c_macros.h"

M2C_UNK ClosestPointOnLine(); /* extern */
f32 GRandInRange();                         /* extern */
s128 PosLoWorld();                       /* extern */
extern M2C_UNK D_FLT_002BE710;
extern M2C_UNK D_FLT_002BE720;
extern M2C_UNK D_FLT_002BE730;
extern M2C_UNK D_FLT_002BE740;
extern f32 g_2dded0;

void func_0017B9C0(void *arg0) {
    M2C_UNK sp0;
    M2C_UNK sp20;
    f32 sp4;
    f32 sp8;
    f32 spC;
    s128 sp10;
    f32 temp_f20;
    f32 temp_v0;
    f32 var_f20;
    f32 var_f21;
    f32 var_f23;
    f32 var_f3;
    s32 var_a1;
    s32 var_s0;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    void *temp_s0;
    void *temp_s2;
    void *var_fp;
    void *var_s3;
    void *var_v0_3;

    temp_f20 = g_2dded0;
    if (!(temp_f20 < M2C_FIELD(arg0, f32 *, 0x44))) {
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf0, $vf0 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
        var_fp = NULL;
        M2C_FIELD(arg0, f32 *, 0x44) = (f32) (temp_f20 + GRandInRange(M2C_FIELD(&D_FLT_002BE710, f32 *, 0), M2C_FIELD(&D_FLT_002BE710, f32 *, 4)));
        sp10 = PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
        var_a1 = 0;
        var_f23 = 3.4028235e38f;
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF94) > 0) {
            var_v1 = 0 * 4;
            do {
                temp_s2 = M2C_FIELD((M2C_FIELD(arg0, void **, 0x10) + var_v1), void **, 0xF98);
                if (((u64) M2C_FIELD(temp_s2, u64 *, 0x28) >> 0x3C) & 1) {
                    PosLoWorld(temp_s2, var_a1);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    var_f20 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
                    if (temp_s2 == M2C_FIELD(arg0, void **, 0x38)) {
                        var_f20 = M2C_FIELD(&D_FLT_002BE720, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002BE720, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002BE720, f32 *, 8))));
                    }
                    var_s0 = 0;
                    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xFA8) > 0) {
                        var_v0 = 0 * 4;
                        do {
                            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
                            PosLoWorld(M2C_FIELD((M2C_FIELD(arg0, void **, 0x10) + var_v0), void **, 0xFAC));
                            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
                            ClosestPointOnLine(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), sp10, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */), 0);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
                            if (!(sp0 < 0.0f) && !(sp0 > 1.0f)) {
                                var_f3 = M2C_FIELD(&D_FLT_002BE730, f32 *, 0) + (sp4 * (M2C_FIELD(&D_FLT_002BE730, f32 *, 4) + (sp4 * M2C_FIELD(&D_FLT_002BE730, f32 *, 8))));
                                if (var_f3 < M2C_FIELD(&D_FLT_002BE740, f32 *, 0)) {
                                    var_f3 = M2C_FIELD(&D_FLT_002BE740, f32 *, 0);
                                } else if (M2C_FIELD(&D_FLT_002BE740, f32 *, 4) < var_f3) {
                                    var_f3 = M2C_FIELD(&D_FLT_002BE740, f32 *, 4);
                                }
                                var_f20 += var_f3;
                            }
                            var_s0 += 1;
                            var_v0 = var_s0 * 4;
                        } while (var_s0 < M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xFA8));
                    }
                    if (var_f20 < var_f23) {
                        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
                        var_f23 = var_f20;
                        var_fp = temp_s2;
                    }
                }
                var_a1 += 1;
                var_v1 = var_a1 * 4;
            } while (var_a1 < M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF94));
        }
        M2C_FIELD(arg0, void **, 0x38) = var_fp;
        var_s2 = 0;
        var_f21 = 800.0f;
        var_s3 = NULL;
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xFA8) > 0) {
            var_v0_2 = 0 * 4;
            do {
                temp_s0 = M2C_FIELD((M2C_FIELD(arg0, void **, 0x10) + var_v0_2), void **, 0xFAC);
                PosLoWorld(temp_s0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                if (!(var_f21 < temp_v0) && ((var_fp == NULL) || ((ClosestPointOnLine(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf3 */), sp10, sp20, 0), !(sp8 < 0.0f)) && !(sp8 > 1.0f) && !(spC > 500.0f)))) {
                    var_s3 = temp_s0;
                    var_f21 = temp_v0;
                }
                var_s2 += 1;
                var_v0_2 = var_s2 * 4;
            } while (var_s2 < M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xFA8));
        }
        var_v0_3 = var_s3;
        M2C_FIELD(arg0, void **, 0x3C) = var_s3;
        if (var_v0_3 == NULL) {
            var_v0_3 = M2C_FIELD(arg0, void **, 0x38);
        }
        M2C_FIELD(arg0, void **, 0x40) = var_v0_3;
    }
}
