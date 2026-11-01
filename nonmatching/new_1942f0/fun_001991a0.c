#include "m2c_macros.h"

s128 ConvertXfPos(s32, M2C_UNK, s128);              /* extern */
M2C_UNK GetNormalVectors__FP6VECTORN30(M2C_UNK, s128, s128, M2C_UNK *); /* extern */
s128 PosLoWorld(void *);                            /* extern */
extern s128 g_2a2db0;
extern s128 g_2a2dc0;

void func_001991A0(void *arg0) {
    s128 sp0;
    s128 sp10;
    M2C_UNK sp30;
    void *temp_t1;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x1C) == 0x11) {
        sp0 = PosLoWorld(M2C_FIELD(arg0, void **, 0));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($s1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
        sp10 = ConvertXfPos(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC8), s32 *, 0), 0, M2C_FIELD(arg0, s128 *, 0xD0));
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
        GetNormalVectors__FP6VECTORN30(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), g_2a2dc0, g_2a2db0, &sp30);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xf0($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf2, $vf3z */);
        temp_t1 = M2C_FIELD(arg0, void **, 0);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
        temp_v1 = M2C_FIELD(temp_t1, void **, 0xC);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK, s32, M2C_UNK), 0x294)(temp_t1 + M2C_FIELD(temp_v1, s16 *, 0x290), 7, M2C_FIELD(M2C_FIELD(arg0, void **, 0xC8), s32 *, 4), M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf1 */));
    }
}
