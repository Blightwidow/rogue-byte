#include "m2c_macros.h"

f32 F32Read__18CBinaryInputStream(s32);             /* extern */
s32 PvAllocSwClearImpl__Fi(void *, s32, s32);       /* extern */
s32 PvAllocSwImpl__Fi(void *, s32, s32);            /* extern */
M2C_UNK ReadVector__18CBinaryInputStreamP6VECTOR(s32, void *); /* extern */
s32 U16Read__18CBinaryInputStream(s32);             /* extern */

void LoadEmitmeshFromBrx__FP8EMITMESHP18CBinaryInputStream(void *arg0, s32 arg1) {
    char sp[0x400];
    f32 temp_f0;
    s32 *temp_s2;
    s32 *var_s0;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;

    var_s1 = 0;
    temp_v0 = U16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0) = temp_v0;
    M2C_FIELD(arg0, s32 *, 4) = PvAllocSwImpl__Fi(sp, temp_v0 * 0x10, 0x10);
    M2C_FIELD(arg0, s32 *, 0x10) = PvAllocSwClearImpl__Fi(sp, M2C_FIELD(arg0, s32 *, 0) * 0x10, 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) > 0) {
        do {
            temp_a1 = var_s1 * 0x10;
            var_s1 += 1;
            ReadVector__18CBinaryInputStreamP6VECTOR(arg1, M2C_FIELD(arg0, s32 *, 4) + temp_a1);
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0));
    }
    temp_v0_2 = U16Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 8) = temp_v0_2;
    var_a0 = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = PvAllocSwImpl__Fi(sp, temp_v0_2 * 0x10, 0x10);
    M2C_FIELD(arg0, f32 *, 0x14) = 0.0f;
    if (M2C_FIELD(arg0, s32 *, 8) > 0) {
loop_4:
        var_s1_2 = 2;
        temp_s2 = M2C_FIELD(arg0, s32 *, 0xC) + (var_a0 * 0x10);
        var_s0 = temp_s2;
        do {
            var_s1_2 -= 1;
            *var_s0 = U16Read__18CBinaryInputStream(arg1);
            var_s0 += 4;
        } while (var_s1_2 >= 0);
        var_s1_3 = 2;
        temp_f0 = F32Read__18CBinaryInputStream(arg1);
        M2C_FIELD(temp_s2, f32 *, 0xC) = temp_f0;
        M2C_FIELD(arg0, f32 *, 0x14) = (f32) (M2C_FIELD(arg0, f32 *, 0x14) + temp_f0);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf1, $vf2 */);
        do {
            var_s1_3 -= 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v0) */);
        } while (var_s1_3 >= 0);
        var_a0 += 1;
        if (var_a0 < M2C_FIELD(arg0, s32 *, 8)) {
            goto loop_4;
        }
    }
    ReadVector__18CBinaryInputStreamP6VECTOR(arg1, arg0 + 0x20);
    var_s1_4 = 0;
    if (M2C_FIELD(arg0, s32 *, 0) > 0) {
loop_13:
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf1 */);
        } else {
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
        }
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($v0) */);
        var_s1_4 += 1;
        if (var_s1_4 < M2C_FIELD(arg0, s32 *, 0)) {
            goto loop_13;
        }
    }
}
