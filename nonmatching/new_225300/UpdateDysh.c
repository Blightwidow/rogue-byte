#include "m2c_macros.h"

M2C_UNK CpdprizeAttractSwDprizes(M2C_UNK *, M2C_UNK, M2C_UNK, void *); /* extern */
void *PmatLoWorld(void *);                          /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK UpdateGadgetObj();                          /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
M2C_UNK func_0012D108(s32, M2C_UNK);                /* extern */
M2C_UNK func_0017A8C8(void *, M2C_UNK);             /* extern */
s32 func_0017A9C0(void *);                          /* extern */
void *func_00205458(void *, M2C_UNK);               /* extern */
M2C_UNK func_00209840(void *, void *, s128, s128, s128); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002C43B0;
extern M2C_UNK D_FLT_002C43C0;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded0;

void UpdateDysh(void *arg0) {
    char sp[0x400];
    M2C_UNK var_a1;
    f32 temp_f0;
    f32 temp_f4;
    void *temp_a0;
    void *temp_a1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1;
    void *var_a0;
    void *var_a0_2;

    UpdateGadgetObj();
loop_1:
    if (M2C_FIELD(arg0, s32 *, 0x150) == 5) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x1B4);
        var_a1 = 3;
        if (temp_a0 == NULL) {
            goto block_9;
        }
        temp_v0 = func_00205458(temp_a0, 0xB0);
        if (temp_v0 != NULL) {
            if (func_0017A9C0(temp_v0) == 0) {
                var_a0 = M2C_FIELD(arg0, void **, 0x1B0);
                if (var_a0 == NULL) {
                    var_a0 = arg0;
                }
                temp_v0_2 = PmatLoWorld(var_a0);
                func_00209840(M2C_FIELD(arg0, void **, 0x1B4) + 0xFD0, sp, M2C_FIELD(temp_v0_2, s128 *, 0), M2C_FIELD(temp_v0_2, s128 *, 0x10), M2C_FIELD(temp_v0_2, s128 *, 0x20));
                if (M2C_FIELD(temp_v0, s32 *, 0x30) != 4) {
                    var_a0_2 = M2C_FIELD(arg0, void **, 0x1B0);
                    if (var_a0_2 == NULL) {
                        var_a0_2 = arg0;
                    }
                    PosLoWorld(var_a0_2);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
                    PosLoWorld(M2C_FIELD(arg0, void **, 0x1B4));
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 100.0f) {
                        func_0017A8C8(temp_v0, 4);
                    }
                }
                temp_v1 = M2C_FIELD(arg0, void **, 0x1B4);
                if (M2C_FIELD(temp_v1, s32 *, 0xFC4) != 0) {
                    temp_f0 = (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x154)) / D_FLT_002C43B0;
                    temp_f4 = M2C_FIELD(&D_FLT_002C43C0, f32 *, 0) + (temp_f0 * (M2C_FIELD(&D_FLT_002C43C0, f32 *, 4) + (temp_f0 * M2C_FIELD(&D_FLT_002C43C0, f32 *, 8))));
                    if (temp_f4 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {

                    } else if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f4) {

                    }
                    M2C_ERROR(/* unknown instruction: pextlw $v0, $v0, $v0 */);
                    func_0012D108(M2C_FIELD(temp_v1, s32 *, 0xFC4), M2C_ERROR(/* unknown instruction: pextlw $a1, $v0, $v0 */));
                }
                if (D_FLT_002C43B0 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x154))) {
                    PosLoWorld(M2C_FIELD(arg0, void **, 0x1B0));
                    CpdprizeAttractSwDprizes(&B_003DD490, 0x5D, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), arg0);
                    temp_a1 = M2C_FIELD(arg0, void **, 0x1B4);
                    temp_v0_3 = M2C_FIELD(temp_a1, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *), 0x4C)(temp_a1 + M2C_FIELD(temp_v0_3, s16 *, 0x48), temp_a1);
                    bevy_camera_follow_activity(&B_002DEB30, 0x18, M2C_FIELD(arg0, void **, 0x1B4));
                    temp_v0_4 = M2C_FIELD(arg0, void **, 0xC);
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(temp_v0_4, s16 *, 0x260), 3);
                }
            } else {
                goto block_8;
            }
        } else {
block_8:
            var_a1 = 2;
block_9:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), M2C_UNK (**)(void *, M2C_UNK), 0x264)(arg0 + M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), s16 *, 0x260), var_a1);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x150) != M2C_FIELD(arg0, s32 *, 0x150)) {
        goto loop_1;
    }
}
