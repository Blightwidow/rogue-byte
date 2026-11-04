#include "m2c_macros.h"

M2C_UNK ConvertXfVec(M2C_UNK, s32, s128);           /* extern */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
M2C_UNK LoadRotateMatrix(M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK WakeXf(void *, void *);                     /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(void *, M2C_UNK);  /* extern */
M2C_UNK func_001F4BF8(void *);                      /* extern */
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;

void func_001FA528(void *arg0) {
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK sp60;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s4;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_v0_3;

    var_s4 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
        var_s3 = 0;
        if ((FFloatsNear__Ffff(g_2a2dd0, M2C_FIELD(arg0, s128 *, 0xF0), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), 0x38D1B717) != 0)) {
            var_s3 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), 0x38D1B717) != 0;
        }
        if (var_s3 == 0) {
            temp_s0 = M2C_FIELD(arg0, void **, 0x58);
            temp_s1 = arg0 + 0xF0;
            var_s4 = 1;
            WakeXf(arg0, temp_s0);
            ConvertXfVec(0, M2C_FIELD(temp_s0, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0xF0));
            M2C_FIELD(temp_s1, s32 *, 4) = 0;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_FIELD(temp_s1, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0xF0) = 0;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($s0) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf1, $vf2 */);
            __as__6VECTORG9VU_VECTOR(temp_s0 + 0x30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */));
            M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
            temp_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
            M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0;
            M2C_FIELD(temp_s0, s32 *, 0xA4) = temp_v0;
        }
        var_s3_2 = 0;
        if ((FFloatsNear__Ffff(g_2a2dd0, M2C_FIELD(arg0, s128 *, 0x100), 0x38D1B717) != 0) && (FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: prot3w $v0, $s0 */), M2C_ERROR(/* unknown instruction: prot3w $v0, $s1 */), 0x38D1B717) != 0)) {
            var_s3_2 = FFloatsNear__Ffff(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s1 */), 0x38D1B717) != 0;
        }
        if (var_s3_2 == 0) {
            temp_s0_2 = M2C_FIELD(arg0, void **, 0x5C);
            temp_s1_2 = arg0 + 0x100;
            var_s4 = 1;
            WakeXf(arg0, temp_s0_2);
            ConvertXfVec(0, M2C_FIELD(temp_s0_2, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0x100));
            M2C_FIELD(temp_s1_2, s32 *, 4) = 0;
            M2C_FIELD(temp_s1_2, s32 *, 8) = 0;
            M2C_FIELD(arg0, s128 *, 0x100) = 0;
            LoadRotateMatrix(&sp60, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x70($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf6x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf6y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf4, $vf6z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf4, $vf1z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf4, $vf2z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xb0($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($s0) */);
            M2C_FIELD(temp_s0_2, s128 *, 0x10) = sp10;
            M2C_FIELD(temp_s0_2, s32 *, 0x1C) = 0;
            M2C_FIELD(temp_s0_2, s128 *, 0x20) = sp20;
            M2C_FIELD(temp_s0_2, s32 *, 0x2C) = 0;
            M2C_FIELD(temp_s0_2, s32 *, 0xC) = 0;
            temp_v0_2 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
            M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_2;
            M2C_FIELD(temp_s0_2, s32 *, 0xA4) = temp_v0_2;
        }
        if (var_s4 != 0) {
            temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *), 0x94)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x90));
            func_001F4BF8(arg0);
        }
    }
}
