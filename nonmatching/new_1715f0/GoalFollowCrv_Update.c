#include "m2c_macros.h"

M2C_UNK FindCrvClosestPointAll(void *, s128, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK GoalFollowCrv_Steer(void *);                /* extern */
s128 PosLoWorld(void *);                            /* extern */
f32 SDiffCrv(void *, f32, f32);                     /* extern */
u32 func_001BD718(s128, s32, void *, s32, f32);     /* extern */
M2C_UNK func_001EEF98();                            /* extern */
extern M2C_UNK B_003DD020;

void GoalFollowCrv_Update(void *arg0) {
    M2C_UNK sp0;
    s128 sp10;
    M2C_UNK var_a1_2;
    M2C_UNK var_a1_3;
    f32 var_f1;
    f32 var_f1_2;
    s32 var_a1;
    s32 var_v0;
    s32 var_v0_2;
    u32 temp_s1;
    u32 temp_v0_2;
    void *temp_a0;
    void *temp_v0;
    void *temp_v0_3;
    void *var_v1;

    func_001EEF98();
    GoalFollowCrv_Steer(arg0);
    sp10 = PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
    do {
        temp_s1 = M2C_FIELD(arg0, u32 *, 0x4C);
        switch (temp_s1) {                          /* switch 1 */
        case 0:                                     /* switch 1 */
        case 2:                                     /* switch 1 */
        case 3:                                     /* switch 1 */
            if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
                temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xE8);
                var_v1 = NULL;
                if (temp_v0 != NULL) {
                    var_v1 = M2C_FIELD(temp_v0, void **, 0xDC);
                }
                var_a1 = 0;
                if (var_v1 != NULL) {
                    var_a1 = M2C_FIELD(var_v1, s32 *, 0x10);
                }
                temp_v0_2 = func_001BD718(sp10, var_a1, M2C_FIELD(temp_v0, void **, 0xDC) + 0x20, M2C_FIELD(arg0, s32 *, 0x30), M2C_FIELD(arg0, f32 *, 0x34));
                M2C_FIELD(arg0, u32 *, 0x58) = temp_v0_2;
                switch (temp_v0_2) {                /* switch 2 */
                case 0:                             /* switch 2 */
                    break;
                case 3:                             /* switch 2 */
                case 4:                             /* switch 2 */
                    var_a1_2 = 3;
block_13:
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), M2C_UNK (**)(void *, M2C_UNK), 0x7C)(arg0 + M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s16 *, 0x78), var_a1_2);
                    break;
                case 1:                             /* switch 2 */
                case 2:                             /* switch 2 */
                    FindCrvClosestPointAll(M2C_FIELD(arg0, void **, 0x54), sp10, &B_003DD020, 0);
                    if (fabsf(SDiffCrv(M2C_FIELD(arg0, void **, 0x54), sp0, M2C_FIELD(arg0, f32 *, 0x60))) > 80.0f) {
                        var_a1_2 = 1;
                        M2C_FIELD(arg0, f32 *, 0x5C) = sp0;
                        goto block_13;
                    }
                    M2C_FIELD(arg0, u32 *, 0x58) = 0U;
                    break;
                }
            }
            if (M2C_FIELD(arg0, u32 *, 0x58) == 0) {
                if (M2C_FIELD(arg0, u32 *, 0x4C) != 0) {
                    var_f1 = M2C_FIELD(arg0, f32 *, 0x6C);
                } else {
                    var_f1 = M2C_FIELD(arg0, f32 *, 0x68);
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($s0) */);
                var_v0 = 1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(var_f1 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                    var_v0 = 0;
                }
                var_a1_3 = 0;
                if (var_v0 != 0) {
block_39:
                } else {
                    var_a1_3 = 2;
                }
block_40:
                M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), M2C_UNK (**)(void *, M2C_UNK), 0x7C)(arg0 + M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s16 *, 0x78), var_a1_3);
            default:                                /* switch 1 */
            }
            break;
        case 1:                                     /* switch 1 */
        case 4:                                     /* switch 1 */
            temp_a0 = M2C_FIELD(arg0, void **, 0x54);
            if (((u64) M2C_FIELD(temp_a0, u64 *, 0x28) >> 0x3C) & 1) {
                if (M2C_FIELD(temp_a0, s32 *, 0x1D8) == 0) {
                    var_a1_3 = 0;
                    if (fabsf(SDiffCrv(temp_a0, M2C_FIELD(arg0, f32 *, 0x5C), M2C_FIELD(arg0, f32 *, 0x60))) < 80.0f) {
                        goto block_39;
                    }
                    if (M2C_FIELD(arg0, u32 *, 0x4C) != 1) {
                        var_f1_2 = M2C_FIELD(arg0, f32 *, 0x6C);
                    } else {
                        var_f1_2 = M2C_FIELD(arg0, f32 *, 0x68);
                    }
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($s0) */);
                    var_v0_2 = 1;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    if (!(var_f1_2 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                        var_v0_2 = 0;
                    }
                    var_a1_3 = 1;
                    if (var_v0_2 != 0) {
                        goto block_39;
                    }
                    temp_v0_3 = M2C_FIELD(arg0, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK), 0x7C)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x78), 4);
                } else {
                    goto block_29;
                }
            } else {
block_29:
                var_a1_3 = 0;
                goto block_40;
            }
            break;
        }
    } while (M2C_FIELD(arg0, u32 *, 0x4C) != temp_s1);
}
