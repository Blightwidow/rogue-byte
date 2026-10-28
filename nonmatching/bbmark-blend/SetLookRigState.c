#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(s32, void *, M2C_UNK, void *, f32, M2C_UNK); /* extern */
M2C_UNK ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(void *, M2C_UNK, void *, s32 *, f32, M2C_UNK, M2C_UNK); /* extern */
s128 ConvertAloPos(s32, void *, s128);              /* extern */
M2C_UNK FixStepAngularVelocity__FP4STEP(void *);    /* extern */
M2C_UNK ReblendAsegbl(s32);                         /* extern */
M2C_UNK SetStepRadTargetDir(void *, s128);          /* extern */
M2C_UNK func_00131A90(s32, f32);                    /* extern */
M2C_UNK func_00131B10(s32, void *, s32);            /* extern */
extern s128 g_2a2dd0;
extern f32 g_2dded0;

void SetLookRigState(void *arg0, s32 arg1) {
    M2C_UNK saved_reg_s2;
    M2C_UNK sp0;
    M2C_UNK sp8;
    M2C_UNK unksp14;
    s128 sp10;
    s32 sp20;
    M2C_UNK var_f14;
    f32 temp_f2;
    f32 var_f1;
    f32 var_f20;
    s32 temp_a0_2;
    s32 temp_v1;
    s32 var_s2;
    s32 var_v0;
    void *temp_a0;
    void *temp_a1;
    void *temp_v0;

    var_s2 = saved_reg_s2;
    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    if (arg1 != temp_v1) {
        if (temp_v1 == -1) {
            M2C_FIELD(arg0, s32 *, 0xC) = 0;
            M2C_FIELD(arg0, f32 *, 0x18) = (f32) g_2dded0;
            M2C_FIELD(arg0, s32 *, 0x10) = 0;
            var_f14 = 0x3FC00000;
            M2C_FIELD(arg0, s32 *, 0x14) = 0;
            if (arg1 == 0) {
                var_f14 = 0x4049999A;
            }
            temp_a0 = M2C_FIELD(arg0, void **, 0);
            ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(temp_a0, 2, arg0 + 0x20, &sp20, M2C_FIELD(temp_a0, f32 *, 0x1A8), 0x3E19999A, var_f14);
            if (sp20 != 0) {
                temp_f2 = M2C_FIELD(arg0, f32 *, 0x30);
                var_f1 = (sp8 - temp_f2) / (M2C_FIELD(arg0, f32 *, 0x34) - temp_f2);
                if (var_f1 < 0.0f) {
                    var_f1 = 0.0f;
                } else if (var_f1 > 1.0f) {
                    var_f1 = 1.0f;
                }
                M2C_FIELD(arg0, f32 *, 0x1C) = var_f1;
            } else {
                M2C_FIELD(arg0, f32 *, 0x1C) = 0.5f;
            }
            sp10 = ConvertAloPos(M2C_FIELD(arg0, s32 *, 0xE4), M2C_FIELD(arg0, void **, 0), g_2a2dd0);
            var_v0 = 1;
            if (!(unksp14 > 0.0f)) {
                var_v0 = 0;
            }
            M2C_FIELD(arg0, s32 *, 8) = var_v0;
            if (arg1 == 0) {
                if (sp20 != 0) {
                    SetStepRadTargetDir(M2C_FIELD(arg0, void **, 0), sp0);
                    FixStepAngularVelocity__FP4STEP(M2C_FIELD(arg0, void **, 0));
                }
            }
        }
        var_f20 = 0.0f;
        M2C_FIELD(arg0, s32 *, 4) = arg1;
        if (arg1 == -1) {
            var_s2 = 0;
        } else if ((arg1 >= -1) && (arg1 < 3)) {
            var_f20 = 0.06666667f;
            temp_v0 = arg0 + ((((arg1 * 2) + M2C_FIELD(arg0, s32 *, 8)) * 0x1C) + 0x38);
            M2C_FIELD(temp_v0, f32 *, 0) = (f32) (1.0f - M2C_FIELD(arg0, f32 *, 0x1C));
            var_s2 = M2C_FIELD(temp_v0, s32 *, 0x18);
            M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0x1C);
            ReblendAsegbl(var_s2);
        }
        ApplyAsegToHandle(var_s2, M2C_FIELD(arg0, void **, 0), 1, arg0 + 0xE0, g_2dded0 - M2C_FIELD(arg0, f32 *, 0x18), 0x3F800000);
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0xE0);
        if (temp_a0_2 != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
                temp_a1 = M2C_FIELD(arg0, void **, 0);
                func_00131B10(temp_a0_2, temp_a1, M2C_FIELD(temp_a1, s32 *, 0x10B8));
            }
            if (M2C_FIELD(arg0, s32 *, 0xE0) != 0) {
                if (var_f20 != 0.0f) {
                    func_00131A90(M2C_FIELD(arg0, s32 *, 0xE0), g_2dded0 + var_f20);
                }
            }
        }
    }
}
