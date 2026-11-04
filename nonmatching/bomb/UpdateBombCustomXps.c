#include "m2c_macros.h"

s32 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK UpdateSwPox(M2C_UNK *, s32, void *, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;
extern void *B_003E13B4;

void UpdateBombCustomXps(void *arg0) {
    M2C_UNK sp10;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s1;
    void *temp_s2;
    void *temp_v0;
    void *temp_v1;
    void *temp_v1_2;
    void *var_s4;
    void *var_s5;
    void *var_v1;

    var_s0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x1F8) > 0) {
        var_s1 = 0;
loop_2:
        var_s0 += 1;
        temp_v1 = M2C_FIELD((var_s1 + M2C_FIELD(arg0, s32 *, 0x1FC)), void **, 0x24);
        var_s1 += 0x30;
        UpdateSwPox(&B_003DD490, M2C_FIELD(arg0, s32 *, 0xEC), M2C_FIELD(temp_v1, void **, 0xEC), 2);
        if (var_s0 < M2C_FIELD(arg0, s32 *, 0x1F8)) {
            goto loop_2;
        }
    }
    M2C_FIELD(arg0, s32 *, 0x1F8) = 0;
    var_s4 = B_003E13B4;
    if (var_s4 != NULL) {
loop_7:
        if ((M2C_FIELD(var_s4, s32 *, 0xF0) != 0) && (var_s5 = NULL, ((M2C_FIELD(var_s4, s32 *, 0xE8) & 0x100) != 0))) {
            var_v1 = M2C_FIELD(var_s4, void **, 0x10);
loop_10:
            if (var_v1 != NULL) {
                temp_v0 = M2C_FIELD(var_v1, void **, 0xEC);
                if (temp_v0 == NULL) {
                    var_v1 = M2C_FIELD(var_v1, void **, 0x10);
                    goto loop_10;
                }
                var_s5 = M2C_FIELD(temp_v0, void **, 0x60);
            }
            if ((var_s5 == NULL) || !(((u64) M2C_FIELD(var_s5, u64 *, 0x28) >> 0x3C) & 1) || (PosLoWorld(var_s4), M2C_ERROR(/* unknown instruction: por $s1, $zero, $v0 */), temp_s2 = M2C_FIELD(var_s5, void **, 0xEC), PosLoWorld(arg0), (ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s1 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), 1, M2C_FIELD(temp_s2, f32 *, 0x30)) == 0)) || (UpdateSwPox(&B_003DD490, M2C_FIELD(arg0, s32 *, 0xEC), M2C_FIELD(var_s5, void **, 0xEC), 1), temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1F8), M2C_FIELD(arg0, s32 *, 0x1F8) = (s32) (temp_v0_2 + 1), temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x1FC) + (temp_v0_2 * 0x30), M2C_FIELD(temp_v1_2, void **, 0x24) = var_s5, M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */), M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($v1) */), M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */), M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */), M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */), M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */), M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */), M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($v1) */), M2C_FIELD(temp_v1_2, s32 *, 0x20) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */), ((M2C_FIELD(arg0, s32 *, 0x1F8) < 4) != 0))) {
                goto block_19;
            }
        } else {
block_19:
            var_s4 = M2C_FIELD(var_s4, void **, 0xE0);
            if (var_s4 == NULL) {

            } else {
                goto loop_7;
            }
        }
    }
}
