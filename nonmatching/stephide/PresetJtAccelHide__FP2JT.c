#include "m2c_macros.h"

M2C_UNK AddSoAcceleration(void *, M2C_UNK);         /* extern */
M2C_UNK EvaluateCrvFromU(void *, M2C_UNK, M2C_UNK *, f32, s128); /* extern */
M2C_UNK GSmooth__FfffP3SMPPf(M2C_UNK *, f32 *, M2C_UNK, f32, f32); /* extern */
extern M2C_UNK D_002BF700;
extern M2C_UNK g_2dded0;

void PresetJtAccelHide__FP2JT(void *arg0) {
    M2C_UNK sp10;
    f32 sp40;
    f32 sp44;
    M2C_UNK temp_v0;
    f32 temp_f0;
    void *temp_a1;
    void *temp_s2;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 8) == 3) {
        temp_s2 = M2C_FIELD(arg0, void **, 0x14);
        if (M2C_FIELD(temp_s2, s32 *, 0x1BC) != 0) {
            temp_a1 = M2C_FIELD(arg0, void **, 0);
            temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
            EvaluateCrvFromU(temp_s2, 0, &sp10, M2C_FIELD(arg0, f32 *, 0x1C), M2C_FIELD(temp_v1, s128 (**)(void *, void *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1));
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($v1) */);
            temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf3, $vf2 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf4, $vf3z */);
            GSmooth__FfffP3SMPPf(&D_002BF700, &sp40, temp_v0, M2C_FIELD(temp_s2, f32 *, 0x1C0), M2C_FIELD(&g_2dded0, f32 *, 4));
            GSmooth__FfffP3SMPPf(&D_002BF700, &sp44, temp_v0, -M2C_FIELD(temp_s2, f32 *, 0x1C0), M2C_FIELD(&g_2dded0, f32 *, 4));
            temp_f0 = M2C_FIELD(temp_s2, f32 *, 0x1C4) * M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
            if (temp_f0 < sp44) {

            } else if (sp40 < temp_f0) {

            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
            AddSoAcceleration(M2C_FIELD(arg0, void **, 0), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
        }
    }
}
