#include "m2c_macros.h"

void *PchnFindAseg(s32, s32, M2C_UNK, M2C_UNK);     /* extern */
f32 *PeaFindAsegLabel(s32, M2C_UNK);                /* extern */
s32 PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK B_003DD490;

void LoadJumpAnim(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp28;
    M2C_UNK sp8;
    M2C_UNK sp10;
    M2C_UNK sp20;
    f32 *temp_v0_2;
    f32 *temp_v0_3;
    f32 *temp_v0_4;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    s32 temp_v0;
    void **temp_a3;
    void **temp_a3_2;
    void **temp_a3_3;
    void *temp_v0_5;
    void *temp_v0_6;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;

    if ((M2C_FIELD(arg0, s32 *, 0x30) == 0) && ((M2C_FIELD(arg0, s32 *, 4) != 0) || (temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(arg0, s32 *, 0), arg1), M2C_FIELD(arg0, s32 *, 4) = temp_v0, (temp_v0 != 0)))) {
        temp_v0_2 = PeaFindAsegLabel(M2C_FIELD(arg0, s32 *, 4), 0x22);
        if (temp_v0_2 != NULL) {
            temp_v0_3 = PeaFindAsegLabel(M2C_FIELD(arg0, s32 *, 4), 0x23);
            if (temp_v0_3 != NULL) {
                temp_v0_4 = PeaFindAsegLabel(M2C_FIELD(arg0, s32 *, 4), 0x24);
                if (temp_v0_4 != NULL) {
                    temp_f0 = *temp_v0_2;
                    M2C_FIELD(arg0, f32 *, 8) = temp_f0;
                    temp_f2 = *temp_v0_3;
                    M2C_FIELD(arg0, f32 *, 0xC) = temp_f2;
                    temp_f1 = *temp_v0_4;
                    M2C_FIELD(arg0, f32 *, 0x10) = temp_f1;
                    M2C_FIELD(arg0, f32 *, 0x14) = (f32) (temp_f1 - temp_f0);
                    M2C_FIELD(arg0, f32 *, 0x18) = (f32) (temp_f1 - temp_f2);
                    temp_v0_5 = PchnFindAseg(M2C_FIELD(arg0, s32 *, 4), arg1, 1, 1);
                    if (temp_v0_5 != NULL) {
                        temp_a3 = M2C_FIELD(temp_v0_5, void ***, 4);
                        temp_v0_6 = *temp_a3;
                        M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *, void *, M2C_UNK, void **, f32, M2C_UNK), 0x1C)(temp_a3 + M2C_FIELD(temp_v0_6, s16 *, 0x18), sp, 0, temp_a3, M2C_FIELD(arg0, f32 *, 8), 0x3F800000);
                        temp_a3_2 = M2C_FIELD(temp_v0_5, void ***, 4);
                        temp_v0_7 = *temp_a3_2;
                        M2C_FIELD(temp_v0_7, M2C_UNK (**)(void *, M2C_UNK *, M2C_UNK, void **, f32, M2C_UNK), 0x1C)(temp_a3_2 + M2C_FIELD(temp_v0_7, s16 *, 0x18), &sp10, 0, temp_a3_2, M2C_FIELD(arg0, f32 *, 0x10), 0x3F800000);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                        temp_f12 = M2C_FIELD(arg0, f32 *, 8);
                        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        M2C_FIELD(arg0, s32 *, 0x1C) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                        temp_a3_3 = M2C_FIELD(temp_v0_5, void ***, 4);
                        temp_f20 = (M2C_FIELD(arg0, f32 *, 0x10) - temp_f12) * 0.5f;
                        temp_v0_8 = *temp_a3_3;
                        M2C_FIELD(temp_v0_8, M2C_UNK (**)(void *, M2C_UNK *, M2C_UNK, void **, f32, M2C_UNK), 0x1C)(temp_a3_3 + M2C_FIELD(temp_v0_8, s16 *, 0x18), &sp20, 0, temp_a3_3, temp_f12 + temp_f20, 0x3F800000);
                        temp_v0_9 = arg0 + 0x20;
                        M2C_FIELD(arg0, s32 *, 0x20) = 0;
                        M2C_FIELD(temp_v0_9, s32 *, 4) = 0;
                        M2C_FIELD(temp_v0_9, f32 *, 8) = (f32) ((sp8 - sp28) / (temp_f20 * temp_f20 * 0.5f));
                    }
                    M2C_FIELD(arg0, s32 *, 0x30) = 1;
                }
            }
        }
    }
}
