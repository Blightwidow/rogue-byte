#include "m2c_macros.h"

M2C_UNK AddSoAcceleration(void *, M2C_UNK);         /* extern */
M2C_UNK ApplyConstrLocal(s32, s32, M2C_UNK);        /* extern */
M2C_UNK GSmooth__FfffP3SMPPf(void *, M2C_UNK, M2C_UNK, f32, M2C_UNK32, M2C_UNK32); /* extern */
M2C_UNK memset(f32 *, M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK g_2dded0;

void PresetGroundmissAccel(void *arg0) {
    char sp[0x400];
    f32 sp10;
    M2C_UNK32 sp18;
    s128 sp30;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x1E8) == 0) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        sp30 = M2C_FIELD(temp_v1, s128 (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: qmfc2.ni $s0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf4, $vf3, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
        memset(&sp10, 0, 0xC);
        sp10 = M2C_FIELD(arg0, f32 *, 0x274);
        sp18 = 0x3F800000;
        M2C_ERROR(/* unknown instruction: ldl $v0, 0x17($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $v0, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $v0, 0x7($sp) */);
        M2C_ERROR(/* unknown instruction: sdr $v0, ($sp) */);
        GSmooth__FfffP3SMPPf(sp, 0, M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf2 */), M2C_FIELD(arg0, f32 *, 0x270), M2C_FIELD(&g_2dded0, M2C_UNK32 *, 4), sp18);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf4 */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf4, $vf3, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
        ApplyConstrLocal(M2C_FIELD(arg0, s32 *, 0xE8) + 0xB0, M2C_FIELD(arg0, s32 *, 0x58), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf4 */));
        AddSoAcceleration(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    }
}
