#include "m2c_macros.h"

M2C_UNK func_001F38A8(void *);                      /* extern */
M2C_UNK func_001F4BA8(void *, void *, M2C_UNK);     /* extern */
extern M2C_UNK B_003DD490;

void UpdateSoBounds(void *arg0) {
    f32 temp_a2;
    f32 temp_f0;
    f32 temp_v0_5;
    f32 var_f2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    void *var_s0;
    void *var_s0_2;

    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
    var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void **, 0x34);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($v1) */);
    if (var_s0 != NULL) {
        do {
            if (!(M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000 << 0x23))) {
                M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x20($sp) */);
                func_001F38A8(var_s0);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($sp) */);
                if (M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000 << 0x22)) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($s2) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf4 */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vmini.xyz $vf5, $vf5, $vf1 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($v0) */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf3, $vf4x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
                    M2C_ERROR(/* unknown instruction: vmax.xyz $vf6, $vf6, $vf2 */);
                } else {
                    temp_v0 = M2C_FIELD(var_s0, s32 *, 0x90);
                    if (temp_v0 > 0) {
                        var_a1 = temp_v0;
                        do {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                            var_a1 -= 1;
                            M2C_ERROR(/* unknown instruction: vmax.xyz $vf6, $vf6, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vmini.xyz $vf5, $vf5, $vf1 */);
                        } while (var_a1 != 0);
                    }
                }
                if (M2C_FIELD(var_s0, s32 *, 0xA8) != M2C_FIELD(var_s0, s32 *, 0xAC)) {
                    temp_v0_2 = M2C_FIELD(var_s0, s32 *, 0x90);
                    temp_a1 = M2C_FIELD(var_s0, s32 *, 0x1C);
                    if (temp_a1 < temp_v0_2) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x30($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v0) */);
                        var_a1_2 = temp_v0_2 - temp_a1;
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
loop_11:
                        var_a1_2 -= 1;
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf1x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf1, $vf7, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vmax.xyz $vf6, $vf6, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vmini.xyz $vf5, $vf5, $vf1 */);
                        if (var_a1_2 != 0) {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
                            goto loop_11;
                        }
                    }
                }
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x60);
        } while (var_s0 != NULL);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($v0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    var_f2 = 0.0f;
    M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf5, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf8, $vf6, $vf1x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    var_s0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void **, 0x34);
    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf9, $vf8 */);
    if (var_s0_2 != NULL) {
        do {
            if (!(M2C_FIELD(var_s0_2, s64 *, 0x10) & (0x8000 << 0x22))) {
                temp_v0_3 = M2C_FIELD(var_s0_2, s32 *, 0x90);
                if (temp_v0_3 > 0) {
                    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf3, $vf8 */);
                    var_a1_3 = temp_v0_3;
                    do {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        temp_a2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */);
                        if (var_f2 < temp_a2) {
                            var_f2 = temp_a2;
                        }
                        var_a1_3 -= 1;
                    } while (var_a1_3 != 0);
                }
            } else {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf9, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                temp_f0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */) + M2C_FIELD(var_s0_2, f32 *, 8);
                if (var_f2 < temp_f0) {
                    var_f2 = temp_f0;
                }
            }
            if (M2C_FIELD(var_s0_2, s32 *, 0xA8) != M2C_FIELD(var_s0_2, s32 *, 0xAC)) {
                temp_v0_4 = M2C_FIELD(var_s0_2, s32 *, 0x90);
                temp_a1_2 = M2C_FIELD(var_s0_2, s32 *, 0x1C);
                if (temp_a1_2 < temp_v0_4) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x30($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x10($v0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($v0) */);
                    var_a1_4 = temp_v0_4 - temp_a1_2;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($s0) */);
                    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf3, $vf8 */);
                    do {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
                        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
                        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf5, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf1, $vf7, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf2 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf1, $vf2z */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                        temp_v0_5 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                        if (var_f2 < temp_v0_5) {
                            var_f2 = temp_v0_5;
                        }
                        var_a1_4 -= 1;
                    } while (var_a1_4 != 0);
                }
            }
            var_s0_2 = M2C_FIELD(var_s0_2, void **, 0x60);
        } while (var_s0_2 != NULL);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x20($a1) */);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), f32 *, 0x30) = var_f2;
    M2C_FIELD(&B_003DD490, s32 *, 0x3CCC) = 1;
    func_001F4BA8(arg0, M2C_FIELD(arg0, void **, 0xEC), 1);
}
