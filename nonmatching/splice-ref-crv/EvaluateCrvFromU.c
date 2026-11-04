#include "m2c_macros.h"

s32 EvaluateBezierPos__FfffP6VECTORN63(); /* extern */
s32 IcvFindCrvU();                      /* extern */

s32 EvaluateCrvFromU(void *arg0, s32 arg1, s32 arg2) {
    f32 sp50;
    f32 sp54;
    s32 temp_s2;
    u8 *temp_v0;
    s32 var_v0;
    void *temp_t3;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    temp_s2 = IcvFindCrvU(&sp50, &sp54);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    M2C_ERROR(/* unknown instruction: lqc2 $vf8, ($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf8, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x30($sp) */);
    if (M2C_FIELD(arg0, s32 *, 0xE0) == 0) {
        if (arg1 != 0) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf4 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyzw $acc, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf8, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf7, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf6, $vf1z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf1, $vf5, $vf0w */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s1) */);
        }
        var_v0 = temp_s2 * 0x10;
        if (arg2 != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
            var_v0 += M2C_FIELD(arg0, s32 *, 0xF4);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
            goto block_9;
        }
    } else {
        temp_v0 = temp_s2 * 0x10;
        temp_t3 = temp_v0 + M2C_FIELD(arg0, s32 *, 0xF4);
        var_v0 = EvaluateBezierPos__FfffP6VECTORN63(M2C_FIELD(temp_t3, s128 *, 0), *(temp_v0 + M2C_FIELD(arg0, s32 *, 0x144)), M2C_FIELD(temp_t3, s128 *, 0x10), M2C_FIELD((temp_v0 + M2C_FIELD(arg0, s32 *, 0x140)), s128 *, 0x10), sp54, sp50, 0x3F800000);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
        if (arg1 != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf5z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($sp) */);
        if (arg2 != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s3) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
block_9:
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf3, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf6, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf6, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf2, $q */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s3) */);
        }
    }
    return var_v0;
}
