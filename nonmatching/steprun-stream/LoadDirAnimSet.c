#include "m2c_macros.h"

void *PchnFindAseg(void *, s32, M2C_UNK, M2C_UNK);  /* extern */
void *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, void *, s32); /* extern */
extern M2C_UNK B_003DD490;

void LoadDirAnimSet(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp10;
    void **temp_a3;
    void **temp_a3_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *var_s2;

    if (M2C_FIELD(arg0, s32 *, 0xC0) == 0) {
        var_s2 = arg0;
        do {
            temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(var_s2, void **, 0), arg1);
            M2C_FIELD(var_s2, void **, 0) = temp_v0;
            if (temp_v0 != NULL) {
                temp_v0_2 = PchnFindAseg(temp_v0, arg1, 1, 1);
                temp_a3 = M2C_FIELD(temp_v0_2, void ***, 4);
                temp_v0_3 = *temp_a3;
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *, M2C_UNK, void **, M2C_UNK, M2C_UNK), 0x1C)(temp_a3 + M2C_FIELD(temp_v0_3, s16 *, 0x18), sp, 0, temp_a3, 0, 0x3F800000);
                temp_a3_2 = M2C_FIELD(temp_v0_2, void ***, 4);
                temp_v0_4 = *temp_a3_2;
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK *, M2C_UNK, void **, M2C_UNK32, M2C_UNK), 0x1C)(temp_a3_2 + M2C_FIELD(temp_v0_4, s16 *, 0x18), &sp10, 0, temp_a3_2, M2C_FIELD(temp_v0, M2C_UNK32 *, 0x74), 0x3F800000);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $s1, $vf1 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($s2) */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                M2C_FIELD(var_s2, s32 *, 0x20) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
            }
            var_s2 += 0x30;
        } while ((u32) var_s2 < (u32) (arg0 + 0xC0));
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
    }
}
