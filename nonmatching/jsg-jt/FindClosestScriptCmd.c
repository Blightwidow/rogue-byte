#include "m2c_macros.h"

M2C_UNK FindCrvClosestPointAll(void *, s128, M2C_UNK, s128 *); /* extern */
M2C_UNK FindCrvClosestPointFromS(void *, s128, M2C_UNK, s128 *, M2C_UNK32); /* extern */
M2C_UNK GetScriptPose(void *, s128, void *, s128 *); /* extern */
void *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, void *); /* extern */
extern M2C_UNK B_003DD490;

void FindClosestScriptCmd(void *arg0, s128 arg1, void *arg2) {
    M2C_UNK32 sp8;
    s128 sp10;
    M2C_UNK32 sp20;
    s128 sp30;
    f32 temp_v0_2;
    f32 temp_v0_3;
    f32 var_f20;
    s128 *temp_v0;
    s32 temp_a2;
    s32 var_s3;
    u32 temp_v1;
    void *temp_a0;
    void *var_s0;
    void *var_s1;

    var_s1 = arg0;
    var_s3 = 0;
    sp30 = arg1;
    var_s0 = M2C_FIELD(var_s1, void **, 0x50);
    var_f20 = 3.4028235e38f;
    if (var_s0 != NULL) {
        do {
            temp_v1 = M2C_FIELD(var_s0, u32 *, 0);
            switch (temp_v1) {
            case 11:
                var_s3 = 1;
                break;
            case 12:
                var_s3 = 0;
                break;
            case 3:
            case 7:
                if (var_s3 == 0) {
                    temp_a2 = M2C_FIELD(var_s0, s32 *, 4);
                    if (temp_a2 != -1) {
                        GetScriptPose(arg0, sp30, PloFindSwObject_thunk(&B_003DD490, 4, temp_a2, var_s1), &sp10);
                        goto block_10;
                    }
                    temp_v0 = M2C_FIELD(var_s0, s128 **, 8);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                    if (temp_v0 != NULL) {
                        sp10 = *temp_v0;
block_10:
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                    }
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                    if (temp_v0_2 < var_f20) {
                        var_f20 = temp_v0_2;
                    }
                }
                break;
            case 6:
                if (var_s3 == 0) {
                    temp_a0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(var_s0, s32 *, 4), var_s1);
                    if (arg2 != NULL) {
                        if (M2C_FIELD(arg2, s32 *, 0) == var_s0) {
                            FindCrvClosestPointFromS(temp_a0, sp30, 0, &sp10, M2C_FIELD(arg2, M2C_UNK32 *, 8));
                        } else {
                            goto block_18;
                        }
                    } else {
block_18:
                        FindCrvClosestPointAll(temp_a0, sp30, 0, &sp10);
                    }
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    temp_v0_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                    if (temp_v0_3 < var_f20) {
                        var_f20 = temp_v0_3;
                        sp8 = sp20;
                    }
                }
                break;
            case 0:
                var_s1 = PloFindSwObject_thunk(&B_003DD490, (var_s1 != NULL) ? 4 : 5, M2C_FIELD(var_s0, s32 *, 4), var_s1);
                break;
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x18);
        } while (var_s0 != NULL);
    }
    if (arg2 != NULL) {
        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($sp) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, ($sp) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x7($s2) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, ($s2) */);
        M2C_FIELD(arg2, M2C_UNK32 *, 8) = sp8;
    }
}
