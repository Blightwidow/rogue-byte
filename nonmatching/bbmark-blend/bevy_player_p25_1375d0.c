#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(void *, void *, M2C_UNK, void *, M2C_UNK, M2C_UNK); /* extern */
void *PchnFindAseg(void *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK RetractSmaRef(void *);                      /* extern */
M2C_UNK func_002046F0(void *, s32);                 /* extern */
extern s32 D_002BC9B8;
extern f32 g_2dded0;

void bevy_player_p25_1375d0(void *arg0, s32 arg1) {
    char sp[0x400];
    s128 sp20;
    M2C_UNK (*temp_a2_2)(void *, M2C_UNK, M2C_UNK);
    void **temp_a3;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1;
    void *var_s2;

    if (arg1 != M2C_FIELD(arg0, s32 *, 4)) {
        M2C_FIELD(arg0, s32 *, 4) = arg1;
        var_s2 = NULL;
        M2C_FIELD(arg0, f32 *, 8) = (f32) g_2dded0;
        switch (arg1) {                             /* irregular */
        case -1:
            temp_a1 = M2C_FIELD(arg0, void **, 0);
            sp20 = (s128) D_002BC9B8;
            temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
            M2C_FIELD(temp_v1, M2C_UNK (**)(void *, void *, s128), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1, sp20);
            temp_a2 = M2C_FIELD(arg0, void **, 0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
            temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf2, $vf1x */);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x11C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), temp_a2);
            return;
        case 1:
            var_s2 = M2C_FIELD(arg0, void **, 0x14);
block_9:
            temp_a0 = M2C_FIELD(arg0, void **, 0);
            func_002046F0(temp_a0, M2C_FIELD(temp_a0, s32 *, 0x10DC));
            temp_a3 = M2C_FIELD(PchnFindAseg(var_s2, M2C_FIELD(arg0, void **, 0), 1, 1), void ***, 4);
            temp_v0_2 = *temp_a3;
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *, void **, M2C_UNK, f32), 0x1C)(temp_a3 + M2C_FIELD(temp_v0_2, s16 *, 0x18), 0, sp, temp_a3, 0, M2C_FIELD(var_s2, f32 *, 0x78));
            temp_a0_2 = M2C_FIELD(arg0, void **, 0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($sp) */);
            temp_v0_3 = M2C_FIELD(temp_a0_2, void **, 0xC);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1b0($a0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($a1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf3, $vf4z */);
            temp_a2_2 = M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK), 0x11C);
            temp_a2_2(temp_a0_2 + M2C_FIELD(temp_v0_3, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf5 */), temp_a2_2);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($v0) */);
            M2C_FIELD(arg0, s32 *, 0xC) = arg1;
        default:
            RetractSmaRef(M2C_FIELD(arg0, void **, 0) + 0x1034);
            temp_a1_2 = M2C_FIELD(arg0, void **, 0);
            ApplyAsegToHandle(var_s2, temp_a1_2, 1, temp_a1_2 + 0x1030, 0, 0x3F800000);
            break;
        case 0:
            var_s2 = M2C_FIELD(arg0, void **, 0x10);
            goto block_9;
        }
    }
}
