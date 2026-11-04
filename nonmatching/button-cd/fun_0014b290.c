#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FIsGuardInSgs(M2C_UNK);                         /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
void *func_002082D0(void *);                        /* extern */
extern M2C_UNK g_2bd4b0;

void *func_0014B290(void *arg0) {
    f32 var_f20;
    f32 var_f3;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    void *temp_a0;
    void *temp_s0;
    void *temp_v1;
    void *var_fp;

    if (FIsGuardInSgs(0x24) == 0) {
        temp_v1 = M2C_FIELD(arg0, void **, 0x390);
        var_fp = NULL;
        if (temp_v1 != NULL) {
            if (((u64) M2C_FIELD(temp_v1, u64 *, 0x28) >> 0x3C) & 1) {
                var_fp = temp_v1;
            } else {
                goto block_8;
            }
        } else {
block_8:
            var_f20 = 3.4028235e38f;
            var_s5 = 0x3E7;
            PosLoWorld(arg0);
            var_s3 = 0;
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0xF64), s32 *, 0xFC) > 0) {
                var_s4 = 0x100;
                do {
                    temp_s0 = M2C_FIELD(arg0, void **, 0xF64) + var_s4;
                    if (M2C_FIELD(temp_s0, s32 *, 4) != 0) {
                        var_s1 = 0;
                        if (FIsBasicDerivedFrom(M2C_FIELD(temp_s0, void **, 0), 0x34) == 0) {
                            var_s1 = (FIsBasicDerivedFrom(M2C_FIELD(temp_s0, void **, 0), 0x3A) != 0) ? 1 : 2;
                        }
                        PosLoWorld(M2C_FIELD(temp_s0, void **, 0));
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                        temp_a0 = M2C_FIELD(temp_s0, void **, 0);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        var_f3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
                        if (temp_a0 == M2C_FIELD(arg0, s32 *, 0x38C)) {
                            var_f3 = M2C_FIELD(&g_2bd4b0, f32 *, 0) + (var_f3 * (M2C_FIELD(&g_2bd4b0, f32 *, 4) + (var_f3 * M2C_FIELD(&g_2bd4b0, f32 *, 8))));
                        }
                        if ((var_s1 < var_s5) || ((var_s1 == var_s5) && (var_f3 < var_f20))) {
                            var_s5 = var_s1;
                            var_f20 = var_f3;
                            var_fp = temp_a0;
                        }
                    }
                    var_s3 += 1;
                    var_s4 += 0x10;
                } while (var_s3 < M2C_FIELD(M2C_FIELD(arg0, void **, 0xF64), s32 *, 0xFC));
            }
        }
        return var_fp;
    }
    return func_002082D0(arg0);
}
