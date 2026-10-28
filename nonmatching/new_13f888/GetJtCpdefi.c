#include "m2c_macros.h"

f32 GSmooth__FfffP3SMPPf(M2C_UNK *, M2C_UNK, f32, f32, f32); /* extern */
M2C_UNK GetAttachCpdefi(void *, void *);            /* extern */
M2C_UNK GetSoCpdefi__FP2SOfP6CPDEFI();              /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK PosSmooth(s128, s128, M2C_UNK *, M2C_UNK, f32); /* extern */
M2C_UNK bevy_player_p7_damage_1a2160(void *, void *); /* extern */
M2C_UNK func_0019C8B0(void *, void *);              /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK D_002BCCB8;
extern M2C_UNK D_002BCCC8;
extern M2C_UNK D_002BCCD8;
extern f32 D_FLT_002BCC98;
extern f32 D_FLT_002BCC9C;
extern f32 D_FLT_002BCCA0;
extern f32 D_FLT_002BCCA4;
extern f32 D_FLT_002BCCA8;
extern f32 D_FLT_002BCCAC;
extern f32 D_FLT_002BCCB0;
extern f32 D_FLT_002BCCB4;
extern M2C_UNK D_FLT_002BCCF0;
extern s128 g_2a2dd0;
extern M2C_UNK g_2bbb60;
extern M2C_UNK g_2dded0;

void GetJtCpdefi(void *arg0, void *arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp4;
    M2C_UNK sp8;
    M2C_UNK *var_a0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_v0_2;
    f32 temp_v1;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f1;
    f32 var_f3;
    void *temp_v0;
    void *temp_v1_2;

    GetSoCpdefi__FP2SOfP6CPDEFI();
    if (M2C_FIELD(arg0, s32 *, 0x1044) != 0) {
        M2C_FIELD(arg1, s128 *, 0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x1060);
        M2C_FIELD(arg0, f32 *, 0x104C) = (f32) M2C_FIELD(arg0, f32 *, 0x1068);
    } else {
        PosLoWorld(arg0);
        temp_v1 = M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */);
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x30C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x308), sp);
        if (M2C_FIELD(arg0, s32 *, 0x434) != 0) {
            var_f0 = D_FLT_002BCCA0;
            var_f1 = D_FLT_002BCCA4;
        } else if (M2C_FIELD(arg0, s32 *, 0x2DC) == 0x16) {
            var_f0 = D_FLT_002BCCB0;
            var_f1 = D_FLT_002BCCB4;
        } else {
            var_f0 = D_FLT_002BCCA8;
            var_f1 = D_FLT_002BCCAC;
        }
        temp_f2 = temp_v1 + var_f0;
        var_f0_2 = sp8;
        temp_f1 = temp_v1 + var_f1;
        if (var_f0_2 < temp_f2) {
            var_f0_2 = temp_f2;
        } else if (temp_f1 < var_f0_2) {
            var_f0_2 = temp_f1;
        }
        M2C_FIELD(arg0, f32 *, 0x104C) = var_f0_2;
        if (M2C_FIELD(&B_002DDF40, s32 *, 0x300) == 0) {
            if (M2C_FIELD(&B_002DDF40, s32 *, 0x260) == arg0) {
                if (M2C_FIELD(arg0, s32 *, 0x434) != 0) {
                    var_a0 = &D_002BCCC8;
                } else {
                    var_a0 = &D_002BCCB8;
                }
                temp_f0 = GSmooth__FfffP3SMPPf(var_a0, 0, M2C_FIELD(arg0, f32 *, 0x1050), M2C_FIELD(arg0, f32 *, 0x104C), M2C_FIELD(&g_2dded0, f32 *, 4));
                var_f0_3 = temp_v1 + D_FLT_002BCC98;
                M2C_FIELD(arg1, f32 *, 0x18) = temp_f0;
                temp_f1_2 = temp_v1 + D_FLT_002BCC9C;
                if (!(temp_f0 < var_f0_3)) {
                    var_f0_3 = temp_f0;
                    if (temp_f1_2 < temp_f0) {
                        var_f0_3 = temp_f1_2;
                    }
                }
                M2C_FIELD(arg1, f32 *, 0x18) = var_f0_3;
            } else {
                goto block_15;
            }
        } else {
block_15:
            M2C_FIELD(arg1, f32 *, 0x18) = var_f0_2;
        }
        M2C_FIELD(arg1, s128 *, 0x10) = sp0;
        M2C_FIELD(arg1, f32 *, 0x14) = sp4;
    }
    PosSmooth(M2C_FIELD(arg0, s128 *, 0x1070), g_2a2dd0, &D_002BCCD8, 0, M2C_FIELD(&g_2dded0, f32 *, 4));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1070($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s2) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($s2) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x1060($s1) */);
    M2C_FIELD(arg0, f32 *, 0x1050) = (f32) M2C_FIELD(arg1, f32 *, 0x18);
    if (M2C_FIELD(arg0, s32 *, 0x2DC) != -1) {
        func_0019C8B0(arg0 + 0x2C0, arg1);
    }
    if (M2C_FIELD(arg0, s32 *, 0x4CC) != -1) {
        GetAttachCpdefi(arg0 + 0x4C0, arg1);
    }
    if (M2C_FIELD(arg0, s32 *, 0xDF4) != -1) {
        bevy_player_p7_damage_1a2160(arg0 + 0xDF0, arg1);
    }
    temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0x114)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x110));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    var_f3 = M2C_FIELD(&D_FLT_002BCCF0, f32 *, 0) + (temp_v0_2 * (M2C_FIELD(&D_FLT_002BCCF0, f32 *, 4) + (temp_v0_2 * M2C_FIELD(&D_FLT_002BCCF0, f32 *, 8))));
    if (var_f3 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
        var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 0);
    } else if (M2C_FIELD(&g_2bbb60, f32 *, 4) < var_f3) {
        var_f3 = M2C_FIELD(&g_2bbb60, f32 *, 4);
    }
    M2C_FIELD(arg1, f32 *, 0x34) = (f32) (M2C_FIELD(arg1, f32 *, 0x34) * var_f3);
}
