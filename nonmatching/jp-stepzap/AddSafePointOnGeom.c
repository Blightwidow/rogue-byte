#include "m2c_macros.h"

M2C_UNK memmove(void *, void *, s32);               /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern f32 g_2dded0;

void AddSafePointOnGeom(void *arg0, void *arg1, s128 arg2) {
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 temp_v0;
    s128 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_s2;
    void *temp_v0_2;
    void *var_a0;
    void *var_s1;

    var_s2 = 1;
    sp20 = arg2;
    if (M2C_FIELD(arg0, s32 *, 4) > 1) {
        var_a2 = 0;
        var_a0 = arg0 + 0x30;
loop_2:
        if (arg1 != M2C_FIELD(var_a0, s32 *, 8)) {
            goto block_10;
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 50.0f)) {
block_10:
            var_s2 += 1;
            var_a2 += 0x20;
            var_a0 += 0x20;
            if (var_s2 < M2C_FIELD(arg0, s32 *, 4)) {
                goto loop_2;
            }
        } else if (var_s2 != 1) {
            temp_v0 = M2C_FIELD(var_a0, s128 *, 0x10);
            temp_v1 = M2C_FIELD(var_a0, s128 *, 0);
            sp10 = temp_v0;
            sp0 = temp_v1;
            memmove(arg0 + 0x50, arg0 + 0x30, var_a2);
            M2C_FIELD(arg0, s128 *, 0x30) = temp_v1;
            M2C_FIELD(arg0, s128 *, 0x40) = temp_v0;
        }
        var_s1 = arg0 + 0x10;
        if (var_s2 >= M2C_FIELD(arg0, s32 *, 4)) {
            goto block_12;
        }
    } else {
block_12:
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 4);
        if ((u32) temp_v1_2 < 0x20U) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_v1_2 + 1);
        }
        temp_v0_2 = arg0 + 0x10;
        var_s1 = temp_v0_2;
        memmove(arg0 + 0x30, temp_v0_2, (M2C_FIELD(arg0, s32 *, 4) << 5) - 0x20);
    }
    memset(var_s1, 0, 0x20);
    if (arg1 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(arg1, s32 *, 4);
        M2C_FIELD(var_s1, void **, 8) = arg1;
        M2C_FIELD(arg1, s64 *, 0x10) = (s64) (M2C_FIELD(arg1, s64 *, 0x10) | (0x8000 << 0x24));
    }
    M2C_FIELD(arg0, s128 *, 0x20) = sp20;
    M2C_FIELD(var_s1, f32 *, 0xC) = (f32) g_2dded0;
}
