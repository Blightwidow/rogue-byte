#include "m2c_macros.h"

s32 CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(M2C_UNK, void *, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
extern f32 D_FLT_002C0D7C;

s32 func_001C5B20(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_v0;
    s32 var_s3;
    s32 var_s4;
    s64 temp_v1;
    void *temp_s0;
    void *temp_v0_2;

    if (M2C_FIELD(arg1, s32 *, 0) != 0) {
        if (M2C_FIELD(arg1, void **, 0xC) != NULL) {
            PosLoWorld(arg0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
            PosLoWorld(M2C_FIELD(arg1, void **, 0xC));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            if (!((D_FLT_002C0D7C * D_FLT_002C0D7C) < temp_v0)) {
                temp_f0 = M2C_FIELD(arg1, f32 *, 8);
                if (!(temp_v0 < (temp_f0 * temp_f0))) {
                    var_s3 = 0;
                    if (M2C_FIELD(M2C_FIELD(arg1, void **, 0xC), s32 *, 0xE0) > 0) {
                        var_s4 = 0;
loop_6:
                        temp_s0 = M2C_FIELD(M2C_FIELD(arg1, void **, 0xC), s32 *, 0xE4) + var_s4;
                        temp_v1 = M2C_FIELD(temp_s0, s64 *, 0x10);
                        if (!(temp_v1 & (0x8000 << 0x23))) {
                            if (temp_v1 & (0x8000 << 0x22)) {
                                temp_f20 = M2C_FIELD(arg0, f32 *, 0x1DC) + M2C_FIELD(temp_s0, f32 *, 8);
                                PosLoWorld(arg0);
                                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($v1) */);
                                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
                                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < (temp_f20 * temp_f20)) {
                                    goto block_9;
                                }
                                goto block_11;
                            }
                            PosLoWorld(arg0);
                            if (CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), temp_s0, 0x7FFFFFFF, 0, M2C_FIELD(arg0, f32 *, 0x1DC)) == 0) {
                                goto block_11;
                            }
                            goto block_9;
                        }
block_11:
                        var_s3 += 1;
                        var_s4 += 0xB0;
                        if (var_s3 >= M2C_FIELD(M2C_FIELD(arg1, void **, 0xC), s32 *, 0xE0)) {
                            goto block_12;
                        }
                        goto loop_6;
                    }
                    goto block_12;
                }
block_9:
                temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x260), 1);
                return 1;
            }
            goto block_12;
        }
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 0;
    }
block_12:
    return 0;
}
