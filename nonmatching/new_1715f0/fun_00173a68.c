#include "m2c_macros.h"

M2C_UNK FadeAloIn(void *, M2C_UNK);                 /* extern */
void *PalertFind(s32, M2C_UNK);                     /* extern */
s128 PosSpawnerFocus(void *);                       /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK SetAloAlpha(void *, M2C_UNK);               /* extern */
M2C_UNK UpdateLo();                                 /* extern */
M2C_UNK func_00154038(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_00173928(void *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_00173D18(void *, M2C_UNK);             /* extern */
void *func_00173E78(void *, s32);                   /* extern */
void *func_00173F18(void *, s128, void *, M2C_UNK *); /* extern */
void *func_00174490(void *, void *, void *, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BE5CC;
extern f32 D_FLT_002BE5D0;
extern f32 D_FLT_002BE5D4;
extern f32 D_FLT_002BE5D8;
extern f32 g_2dded0;

void func_00173A68(void *arg0) {
    char sp[0x400];
    M2C_UNK sp10;
    s32 sp40;
    void *sp44;
    void **sp48;
    s128 sp50;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;
    s32 var_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1_2;
    void *var_s2;

    UpdateLo();
    sp50 = PosSpawnerFocus(arg0);
    func_00173D18(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    if (!(g_2dded0 < M2C_FIELD(arg0, f32 *, 0xA8))) {
        M2C_FIELD(arg0, f32 *, 0xA8) = (f32) (g_2dded0 + D_FLT_002BE5D0);
        if (M2C_FIELD(arg0, s32 *, 0x58) == M2C_FIELD(arg0, s32 *, 0x5C)) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            var_v0 = 1;
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < D_FLT_002BE5D4)) {
                var_v0 = 0;
            }
            if (var_v0 == 0) {
                goto block_5;
            }
        } else {
block_5:
            var_s2 = NULL;
            temp_v0 = PpoSwFocusBase(&B_003DD490);
            var_a1 = 0;
            if ((temp_v0 != 0) && (var_s2 = PalertFind(temp_v0, 0), var_a1 = 0, (var_s2 != NULL))) {
                if (M2C_FIELD(var_s2, s32 *, 0x28) != 0) {
                    temp_v1 = M2C_FIELD(arg0, s32 *, 0xAC);
                    if (temp_v1 != 1) {
                        var_a1 = 0;
                        if (temp_v1 < 2) {
                            if (temp_v1 != 0) {
                                goto block_17;
                            }
                        } else {
                            goto block_17;
                        }
                    } else if (!(D_FLT_002BE5CC < (g_2dded0 - M2C_FIELD(var_s2, f32 *, 0)))) {
                        var_a1 = 0;
                        goto block_17;
                    }
                } else {
                    var_s2 = NULL;
                    goto block_17;
                }
            } else {
block_17:
                if ((var_s2 != NULL) && (M2C_FIELD(var_s2, s32 *, 0x28) == 1)) {
                    var_a1 = M2C_FIELD(var_s2, s32 *, 0x2C);
                }
                temp_v0_2 = func_00173E78(arg0, var_a1);
                if (temp_v0_2 != NULL) {
                    temp_v0_3 = func_00173F18(arg0, sp50, sp, &sp10);
                    if (temp_v0_3 != NULL) {
                        M2C_FIELD(arg0, s128 *, 0x70) = sp50;
                        if (M2C_FIELD(temp_v0_2, void **, 0) != NULL) {
                            func_00173928(arg0, temp_v0_2, 0, 1);
                        }
                        temp_v0_4 = func_00174490(arg0, temp_v0_3, sp, &sp10);
                        sp44 = temp_v0_4;
                        if (temp_v0_4 != NULL) {
                            SetAloAlpha(temp_v0_4, 0x3C23D70A);
                            FadeAloIn(sp44, 0x3F000000);
                            if (var_s2 != NULL) {
                                func_00154038(M2C_FIELD(sp44, s32 *, 0xF64), M2C_FIELD(var_s2, s32 *, 0xC), 2);
                            }
                            M2C_FIELD(temp_v0_2, void **, 0) = sp44;
                            M2C_FIELD(temp_v0_2, void **, 0xC) = temp_v0_3;
                            M2C_FIELD(temp_v0_2, f32 *, 4) = (f32) g_2dded0;
                            M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + 1);
                            M2C_FIELD(temp_v0_3, s32 *, 0x14) = 1;
                            sp48 = &sp44;
                            temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                            M2C_FIELD(arg0, f32 *, 0xA8) = (f32) (g_2dded0 + D_FLT_002BE5D8);
                            M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x18), 0x19, 0, 1);
                        }
                    }
                }
            }
        }
    }
}
