#include "m2c_macros.h"

M2C_UNK BuildJmpEdgeProbes(void **, s128 *, M2C_UNK, s128 *); /* extern */
s32 ClsgClipEdgeToObject(void *, s128, s128, M2C_UNK); /* extern */
M2C_UNK GetNormalVectors__FP6VECTORN30(M2C_UNK, s128, s128, s128 *); /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(M2C_UNK *, M2C_UNK); /* extern */
extern s128 g_2a2db0;
extern s128 g_2a2dc0;

s32 FCheckJtEdgeNormal__FP2JTP6VECTORT1(void **arg0) {
    M2C_UNK sp1F8;
    M2C_UNK sp20;
    M2C_UNK sp210;
    M2C_UNK unksp3C;
    s128 sp0;
    s128 sp10;
    s128 sp30;
    s32 sp4C;
    s32 sp5C;
    M2C_UNK sp60;
    s128 sp70;
    M2C_UNK sp80;
    M2C_UNK sp1D0;
    s128 *var_s3;
    s32 var_fp;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    void *var_s0;
    void *var_s4;

    M2C_ERROR(/* unknown instruction: por $s1, $zero, $a1 */);
    var_fp = 0;
    sp0 = M2C_ERROR(/* unknown instruction: por $t0, $zero, $a2 */);
    GetNormalVectors__FP6VECTORN30(M2C_ERROR(/* unknown instruction: por $a0, $zero, $t0 */), g_2a2dc0, g_2a2db0, &sp10);
    __as__6VECTORG9VU_VECTOR(&sp60, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s1 */));
    sp30 = sp0;
    M2C_FIELD(&sp30, s128 *, 0x10) = sp10;
    M2C_FIELD(&sp30, s128 *, 0x20) = sp20;
    sp5C = 0;
    sp4C = 0;
    unksp3C = 0;
    M2C_FIELD(&sp30, f32 *, 0x3C) = 1.0f;
    BuildJmpEdgeProbes(arg0, &sp30, 0x16, &sp70);
    var_s4 = M2C_FIELD(M2C_FIELD(*arg0, void **, 0xEC), void **, 0x64);
    var_v0_2 = 0 < 2;
    if (var_s4 != NULL) {
loop_1:
        if (!(M2C_FIELD(M2C_FIELD(M2C_FIELD(var_s4, void **, 0xC), void **, 0xEC), s64 *, 0x70) & 4)) {
            var_s2 = 0;
            var_s3 = &sp70;
loop_3:
            var_s0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(var_s4, void **, 0xC), void **, 0xEC), void **, 0x34);
            if (var_s0 != NULL) {
loop_5:
                if (!(M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000 << 0x21)) && (ClsgClipEdgeToObject(var_s0, *var_s3, *(&sp80 + (var_s2 * 0x10)), 1) > 0)) {
                    var_v0 = 0;
                    if ((var_s2 >= 4) && (sp210 != 0.0f)) {
                        if (sp1F8 > 0.7f) {
                            var_fp += 1;
                        }
                        goto block_11;
                    }
                } else {
block_11:
                    var_s0 = M2C_FIELD(var_s0, void **, 0x60);
                    if (var_s0 == NULL) {
                        goto block_12;
                    }
                    goto loop_5;
                }
            } else {
block_12:
                var_s2 += 2;
                var_s3 += 0x20;
                if ((u32) var_s2 >= 0x16U) {
                    goto block_13;
                }
                goto loop_3;
            }
        } else {
block_13:
            var_s4 = M2C_FIELD(var_s4, void **, 4);
            if (var_s4 == NULL) {
                var_v0_2 = var_fp < 2;
                goto block_15;
            }
            goto loop_1;
        }
    } else {
block_15:
        var_v0 = var_v0_2 ^ 1;
    }
    return var_v0;
}
