#include "m2c_macros.h"

M2C_UNK func_00173928(void *, void *, M2C_UNK, M2C_UNK); /* extern */
extern f32 D_FLT_002BE5DC;
extern f32 g_2dded0;

void func_00173D18(void *arg0, s128 arg1) {
    M2C_UNK var_a2;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    void *temp_a1;
    void *temp_a2;

    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x5C) > 0) {
        var_s2 = 0;
        do {
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x60) + var_s2;
            temp_a2 = M2C_FIELD(temp_a1, void **, 0);
            if (temp_a2 != NULL) {
                if (M2C_FIELD(temp_a2, s32 *, 0x330) != 0) {
                    var_a2 = 1;
                    goto block_18;
                }
                if (((u64) M2C_FIELD(temp_a2, u64 *, 0x28) >> 0x3C) & 1) {
                    if (((u64) M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_a1, void **, 0xC), void **, 8), u64 *, 0x28) >> 0x3C) & 1) {
                        M2C_FIELD(temp_a1, f32 *, 4) = (f32) M2C_ERROR(/* unknown instruction: max.s $f1, $f1, $f0 */);
                    } else {
                        goto block_17;
                    }
                } else {
block_17:
                    var_a2 = 0;
block_18:
                    func_00173928(arg0, temp_a1, var_a2, 0);
                }
            } else if (M2C_FIELD(temp_a1, s32 *, 0x10) == 1) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($a1) */);
                var_v0 = 1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(D_FLT_002BE5DC < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                    var_v0 = 0;
                }
                if (var_v0 != 0) {
                    M2C_FIELD(temp_a1, s32 *, 0x10) = 0;
                    M2C_FIELD(temp_a1, f32 *, 8) = (f32) g_2dded0;
                }
            }
            var_s1 += 1;
            var_s2 += 0x30;
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0x5C));
    }
}
