#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK MatchSoOtherObject(void *, void *);         /* extern */
extern s128 g_2a2dd0;

void func_002052E0(void *arg0, void *arg1) {
    char sp[0x400];
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;

    if (arg1 != NULL) {
        if (FIsBasicDerivedFrom(arg1, 3) == 0) {
            MatchSoOtherObject(arg0, arg1);
        } else {
            temp_v1 = M2C_FIELD(arg1, void **, 0xC);
            M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0xFC)(arg1 + M2C_FIELD(temp_v1, s16 *, 0xF8));
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($v0) */);
            temp_a2 = M2C_FIELD(arg0, void **, 0xC);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf6 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x240($s1) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf6x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($v0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf7, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x40($sp) */);
            M2C_FIELD(temp_a2, M2C_UNK (**)(void *, M2C_UNK, void *), 0xEC)(arg0 + M2C_FIELD(temp_a2, s16 *, 0xE8), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf7 */), temp_a2);
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0xF4)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xF0), sp);
            if (FIsBasicDerivedFrom(arg0, 0x34) != 0) {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf3x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x1060($s1) */);
            }
            temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, s128), 0x11C)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x118), g_2a2dd0);
            temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, s128), 0x124)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x120), g_2a2dd0);
            M2C_FIELD(arg0, s32 *, 0x208) = 0;
        }
    }
}
