#include "m2c_macros.h"

M2C_UNK GSmooth__FfffP3SMPPf(M2C_UNK *, f32 *, f32, f32, f32); /* extern */
M2C_UNK func_001F4FC0();                            /* extern */
extern M2C_UNK D_002C3C98;
extern M2C_UNK D_002C3CA8;
extern M2C_UNK g_2dded0;

void *AdjustStepXpVelocity(void *arg0, void *arg1, s32 arg2) {
    f32 sp10;
    f32 sp14;
    void *var_v0;

    func_001F4FC0();
    var_v0 = (void *)0xE;
    if (M2C_FIELD(arg1, s32 *, 0x9C) == 0xE) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($s0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf3, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf2, $vf3z */);
        M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
        GSmooth__FfffP3SMPPf(&D_002C3C98, &sp10, M2C_FIELD(arg1, f32 *, 0x90), M2C_FIELD(arg0, f32 *, 0x210), M2C_FIELD(&g_2dded0, f32 *, 4));
        GSmooth__FfffP3SMPPf(&D_002C3CA8, &sp14, M2C_FIELD(arg1, f32 *, 0x90), 0.0f, M2C_FIELD(&g_2dded0, f32 *, 4));
        if (M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f20 */) < sp14) {
            M2C_ERROR(/* unknown instruction: min.s $f0, $f0, $f2 */);
        } else {
            M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f2 */);
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v1) */);
        var_v0 = arg1 + (arg2 << 6);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1b0($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x190($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($s0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf5, $vf3z */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf4 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf1, $vf2z */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf5 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf4, $vf2x */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($v0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf6 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmaddax.xyzw $acc, $vf4, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf3, $vf6x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($sp) */);
        M2C_FIELD(arg1, f32 *, 0x90) = (f32) (M2C_FIELD(arg1, f32 *, 0x90) + (M2C_FIELD(arg0, f32 *, 0x210) - M2C_FIELD(arg0, f32 *, 0x248)));
    }
    return var_v0;
}
