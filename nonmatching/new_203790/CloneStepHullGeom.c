#include "m2c_macros.h"

M2C_UNK AddSoGeomsToOxa();       /* extern */
M2C_UNK CloneCloth();   /* extern */
M2C_UNK EnsureSogeomLvo();                    /* extern */
s32 FIsBasicDerivedFrom();   /* extern */
M2C_UNK RemoveSoGeomsFromOxa();                     /* extern */
M2C_UNK TransformGeom();         /* extern */
extern s128 g_2a2dd0;

void CloneStepHullGeom(void *arg0, void *arg1) {
    f32 var_f1;
    s32 temp_a2_3;
    u8 *temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a1;
    s32 var_s2;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_v1;

    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        RemoveSoGeomsFromOxa();
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 0xE0);
    var_s2 = 0;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (temp_v0 + 1);
    temp_a2 = M2C_FIELD(arg0, s32 *, 0xE4) + (temp_v0 * 0xB0);
    M2C_FIELD(arg0, void **, 0x258) = temp_a2;
    if (FIsBasicDerivedFrom(arg0, 0x34, temp_a2) == 0) {
        var_s2 = M2C_FIELD(arg1, s32 *, 0x1C) == M2C_FIELD(arg1, s32 *, 0x78);
    }
    CloneCloth(arg1, M2C_FIELD(arg0, s32 *, 0x60), (var_s2 != 0) ? 3 : 2, M2C_FIELD(arg0, void **, 0x258));
    EnsureSogeomLvo(M2C_FIELD(arg0, void **, 0x258));
    temp_a2_2 = M2C_FIELD(arg0, void **, 0x258);
    var_a1 = 0;
    var_f1 = 3.4028235e38f;
    if (M2C_FIELD(temp_a2_2, s32 *, 0x1C) > 0) {
        do {
            temp_v0_2 = var_a1 * 0x10;
            var_a1 += 1;
            var_f1 = M2C_ERROR(/* unknown instruction: min.s $f1, $f0, $f1 */);
        } while (var_a1 < M2C_FIELD(temp_a2_2, s32 *, 0x1C));
    }
    M2C_FIELD(arg0, f32 *, 0x210) = var_f1;
    temp_v1 = M2C_FIELD(arg0, void **, 0x258);
    temp_v0_3 = M2C_FIELD(temp_v1, s32 *, 0x1C);
    temp_s1 = temp_v0_3 * 0x10;
    M2C_FIELD(temp_v1, s32 *, 0x1C) = (s32) (temp_v0_3 + 2);
    *(temp_s1 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x258), s32 *, 0x7C)) = M2C_FIELD(arg0, s128 *, 0x240);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x240($s0) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf2, $vf3x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($v0) */);
    if (var_s2 != 0) {
        M2C_FIELD((temp_s1 + M2C_FIELD(M2C_FIELD(arg0, void **, 0x258), s32 *, 0x7C)), s128 *, 0x20) = (s128) g_2a2dd0;
    }
    temp_a1 = M2C_FIELD(arg0, void **, 0x258);
    TransformGeom(M2C_FIELD(temp_a1, s32 *, 0) + 0x40, temp_a1 + 0x78, temp_a1 + 0x90);
    temp_a1_2 = M2C_FIELD(arg0, void **, 0x258);
    temp_a2_3 = temp_s1 + 0x10;
    M2C_FIELD(arg0, s32 *, 0x218) = (s32) (M2C_FIELD(temp_a1_2, s32 *, 0x94) + temp_s1);
    M2C_FIELD(arg0, s32 *, 0x21C) = (s32) (M2C_FIELD(temp_a1_2, s32 *, 0x94) + temp_a2_3);
    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        AddSoGeomsToOxa(arg0, temp_a1_2, temp_a2_3);
    }
}
