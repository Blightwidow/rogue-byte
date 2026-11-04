#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */
void *PvAllocSlotheapImpl(M2C_UNK *);               /* extern */
extern M2C_UNK B_003E12D4;

void func_001F2500(void *arg0) {
    f32 temp_f1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a2;
    void *temp_v0;
    void *var_a0;
    void *var_s1;
    void *var_v1;

    if (M2C_FIELD(arg0, s64 *, 0xD0) & (0xC000 << 0x12)) {
        var_v1 = M2C_FIELD(arg0, void **, 0x134);
        var_s1 = arg0;
        if (var_v1 == NULL) {
            var_a0 = M2C_FIELD(var_s1, void **, 0x10);
loop_3:
            if (var_a0 != NULL) {
                if (((s32) (((s64) (M2C_FIELD(var_s1, s64 *, 0x148) << 0x20) >> 0x20) << 8) >> 0x1C) != 1) {
                    var_s1 = var_a0;
                    var_v1 = M2C_FIELD(var_s1, void **, 0x134);
                    if (var_v1 == NULL) {
                        var_a0 = M2C_FIELD(var_s1, void **, 0x10);
                        goto loop_3;
                    }
                    M2C_FIELD(arg0, void **, 0x134) = var_v1;
                    goto block_13;
                }
                goto block_7;
            }
block_7:
            temp_v0 = PvAllocSlotheapImpl(&B_003E12D4);
            M2C_FIELD(var_s1, void **, 0x134) = temp_v0;
            M2C_FIELD(arg0, void **, 0x134) = temp_v0;
            M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(var_s1, s32 *, 0x60) + 0x70);
            temp_a0 = M2C_FIELD(arg0, void **, 0x134);
            M2C_FIELD(temp_a0, s32 *, 8) = (s32) (M2C_FIELD(temp_a0, s32 *, 8) + 1);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x134), f32 *, 0x20) = (f32) M2C_FIELD(arg0, f32 *, 0x13C);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0x134), void **, 0) = arg0;
            if (var_s1 != arg0) {
                var_v1 = M2C_FIELD(arg0, void **, 0x134);
                goto block_13;
            }
        } else {
block_13:
            M2C_FIELD(var_v1, s32 *, 8) = (s32) (M2C_FIELD(var_v1, s32 *, 8) + 1);
        }
        PosLoWorld(arg0);
        temp_a2 = M2C_FIELD(arg0, void **, 0x134);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_f1 = M2C_FIELD(arg0, f32 *, 0xA0) + M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        if ((M2C_FIELD(arg0, s64 *, 0xD0) & (0x8000 << 0x11)) && (M2C_FIELD(temp_a2, f32 *, 0x10) < temp_f1)) {
            M2C_FIELD(temp_a2, f32 *, 0x10) = temp_f1;
        }
        if (M2C_FIELD(arg0, s64 *, 0xD0) & (0x8000 << 0x12)) {
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x134);
            if (M2C_FIELD(temp_a0_2, f32 *, 0x1C) < temp_f1) {
                M2C_FIELD(temp_a0_2, f32 *, 0x1C) = temp_f1;
            }
        }
    }
}
