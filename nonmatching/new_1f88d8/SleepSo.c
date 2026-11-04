#include "m2c_macros.h"

M2C_UNK LoadRotateMatrix();       /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(); /* extern */
M2C_UNK SleepXf();                    /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR();  /* extern */
M2C_UNK func_001F38A8();                      /* extern */
M2C_UNK func_001F3900();                      /* extern */
M2C_UNK func_001F4D50();                      /* extern */
extern M2C_UNK B_003DD490;

void SleepSo(void *arg0) {
    M2C_UNK sp20;
    M2C_UNK sp30;
    s128 sp10;
    M2C_UNK sp70;
    s32 temp_v0;
    s32 temp_v0_2;
    void *temp_a0;
    void *temp_s0;
    void *temp_s1;
    void *temp_s4;
    void *temp_s5;
    void *temp_v0_3;
    void *var_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x58);
    temp_s1 = M2C_FIELD(arg0, void **, 0x5C);
    SleepXf(temp_s0);
    temp_s4 = temp_s0 + 0xB0;
    SleepXf(arg0, temp_s1);
    temp_s5 = temp_s1 + 0xB0;
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($s0) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s0) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf2x */);
    __as__6VECTORG9VU_VECTOR(temp_s0 + 0x30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf4 */));
    M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
    temp_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
    M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0;
    M2C_FIELD(temp_s0, s32 *, 0xA4) = temp_v0;
    M2C_FIELD(temp_s4, s32 *, 4) = 0;
    M2C_FIELD(temp_s4, s32 *, 8) = 0;
    M2C_FIELD(temp_s0, s32 *, 0xB0) = 0;
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xb0($s1) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
    LoadRotateMatrix(&sp70, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($s1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf4, $vf5z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf4, $vf2z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xb0($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf4, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xc0($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($sp) */);
    NormalizeRotateMatrix3__FP7MATRIX3(&sp10);
    M2C_FIELD(temp_s1, s128 *, 0) = sp10;
    M2C_FIELD(temp_s1, s128 *, 0x10) = sp20;
    M2C_FIELD(temp_s1, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_s1, s128 *, 0x20) = sp30;
    M2C_FIELD(temp_s1, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_s1, s32 *, 0xC) = 0;
    temp_v0_2 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
    M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_2;
    M2C_FIELD(temp_s1, s32 *, 0xA4) = temp_v0_2;
    M2C_FIELD(temp_s5, s32 *, 4) = 0;
    M2C_FIELD(temp_s5, s32 *, 8) = 0;
    M2C_FIELD(temp_s1, s32 *, 0xB0) = 0;
    temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *), 0x94)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x90));
    func_001F3900(arg0);
    temp_a0 = M2C_FIELD(arg0, void **, 0xEC);
    if (temp_a0 != NULL) {
        var_s0 = M2C_FIELD(temp_a0, void **, 0x34);
        if (var_s0 != NULL) {
            do {
                if (!(M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000 << 0x23))) {
                    func_001F38A8(var_s0);
                }
                var_s0 = M2C_FIELD(var_s0, void **, 0x60);
            } while (var_s0 != NULL);
        }
    }
    func_001F4D50(arg0);
}
