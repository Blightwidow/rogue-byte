#include "m2c_macros.h"

M2C_UNK BindAsegChn(void *, s32, void *, M2C_UNK *); /* extern */
M2C_UNK EnsureAsegBlendDynamic(s32, M2C_UNK, M2C_UNK, void *); /* extern */
M2C_UNK FillBlAmrsg__FiiPviiP3OID(M2C_UNK, M2C_UNK, void *, M2C_UNK); /* extern */
void *PchnFindAseg(void *, s32, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK ReblendAsegbl(void *);                      /* extern */

void PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(void *arg0) {
    char sp[0x400];
    M2C_UNK sp10;
    M2C_UNK sp30;
    void *sp34;
    s32 temp_v1;
    s32 var_s2_2;
    u32 var_s4;
    void **temp_a3;
    void **temp_a3_2;
    void *temp_a2;
    void *temp_s0;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_s0;
    void *var_s1;
    void *var_s2;

    temp_s0 = arg0 + 0x10;
    if (M2C_FIELD(arg0, s32 *, 0x14) != 0) {
        FillBlAmrsg__FiiPviiP3OID(0x40, 2, temp_s0, 0x20);
        var_s4 = 0;
        FillBlAmrsg__FiiPviiP3OID(0x40, 2, temp_s0, 0x30);
        var_s2 = temp_s0;
        do {
            temp_s1 = M2C_FIELD(var_s2, void **, 4);
            if (temp_s1 != NULL) {
                temp_v0 = PchnFindAseg(temp_s1, M2C_FIELD(arg0, s32 *, 0), 1, 1);
                temp_a3 = M2C_FIELD(temp_v0, void ***, 4);
                temp_v0_2 = *temp_a3;
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, void *, M2C_UNK, void **, M2C_UNK, M2C_UNK), 0x1C)(temp_a3 + M2C_FIELD(temp_v0_2, s16 *, 0x18), sp, 0, temp_a3, 0, 0x3F800000);
                temp_a3_2 = M2C_FIELD(temp_v0, void ***, 4);
                temp_v0_3 = *temp_a3_2;
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, M2C_UNK *, M2C_UNK, void **, M2C_UNK32, M2C_UNK), 0x1C)(temp_a3_2 + M2C_FIELD(temp_v0_3, s16 *, 0x18), &sp10, 0, temp_a3_2, M2C_FIELD(temp_s1, M2C_UNK32 *, 0x74), 0x3F800000);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $s1, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($s2) */);
            }
            var_s4 += 1;
            var_s2 += 0x40;
        } while (var_s4 < 2U);
        EnsureAsegBlendDynamic(M2C_FIELD(arg0, s32 *, 0), 0x40, 2, temp_s0);
        var_s2_2 = 0;
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x5C) > 0) {
            do {
                temp_a2 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x60) + (var_s2_2 * 8);
                if (M2C_FIELD(temp_a2, s32 *, 0) >= 0) {
                    var_s1 = M2C_FIELD(temp_a2, void **, 4);
                    var_s0 = NULL;
                } else {
                    var_s1 = NULL;
                    var_s0 = M2C_FIELD(temp_a2, void **, 4);
                }
                BindAsegChn(M2C_FIELD(arg0, void **, 4), M2C_FIELD(arg0, s32 *, 0), temp_a2, &sp30);
                temp_v1 = M2C_FIELD(sp34, s32 *, 0x9C);
                switch (temp_v1) {
                case 16:
                case 18:
                case 20:
                    if (var_s1 != NULL) {
                        M2C_FIELD(var_s1, s32 *, 8) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xD0) + 0xC);
                    }
                    if (var_s0 != NULL) {
                        M2C_FIELD(var_s0, s32 *, 8) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xD0) + 0xC);
                    case 17:
                    case 19:
                    case 21:
                    }
                    break;
                default:
                    if (var_s1 != NULL) {
                        M2C_FIELD(var_s1, s32 *, 8) = 0;
                    }
                    if (var_s0 != NULL) {
                        M2C_FIELD(var_s0, s32 *, 8) = 0;
                    }
                    break;
                }
                var_s2_2 += 1;
            } while (var_s2_2 < M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x5C));
        }
        ReblendAsegbl(M2C_FIELD(arg0, void **, 4));
    }
}
