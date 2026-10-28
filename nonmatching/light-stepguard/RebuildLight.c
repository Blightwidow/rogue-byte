#include "m2c_macros.h"

M2C_UNK ConvertAngleStrength__FffffPfT4(s32, s32, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK ConvertUserHsvToUserRgb__FP6VECTORT0(void *, void *); /* extern */
M2C_UNK FitLinearFunction__FffffPfT4(void *, void *, f32, M2C_UNK, f32, M2C_UNK); /* extern */
M2C_UNK GreyColor_1ed2d8(void *);                   /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK func_001A3B38(void *);                      /* extern */

void RebuildLight(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp4;
    M2C_UNK sp8;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f20_2;
    s32 temp_v1;
    void *temp_v0;
    void *temp_v1_2;

    temp_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f1 */);
    ConvertAngleStrength__FffffPfT4(arg0 + 0x124, arg0 + 0x128, M2C_ERROR(/* unknown instruction: max.s $f12, $f12, $f2 */), 0, 0, temp_f20);
    ConvertUserHsvToUserRgb__FP6VECTORT0(arg0 + 0xF0, sp);
    GreyColor_1ed2d8(sp);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x150);
    M2C_FIELD(arg0, f32 *, 0x130) = sp0;
    M2C_FIELD(arg0, f32 *, 0x134) = sp4;
    M2C_FIELD(arg0, f32 *, 0x138) = sp8;
    M2C_FIELD(arg0, f32 *, 0x13C) = temp_f0;
    if (temp_f20 > 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x13C) = (f32) (temp_f0 / temp_f20);
        M2C_FIELD(arg0, f32 *, 0x130) = (f32) (sp0 / temp_f20);
        M2C_FIELD(arg0, f32 *, 0x134) = (f32) (sp4 / temp_f20);
        M2C_FIELD(arg0, f32 *, 0x138) = (f32) (sp8 / temp_f20);
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0xE0);
    M2C_FIELD(arg0, s32 *, 0x120) = temp_v1;
    M2C_FIELD(arg0, f32 *, 0x128) = (f32) -M2C_FIELD(arg0, f32 *, 0x128);
    switch (temp_v1) {                              /* irregular */
    case 0:
        temp_v0 = arg0 + 0x100;
        M2C_FIELD(temp_v0, f32 *, 4) = 0.0f;
        M2C_FIELD(temp_v0, f32 *, 8) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x110) = 1.0f;
        temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(arg0, f32 *, 0x114) = 0.0f;
        M2C_FIELD(arg0, s128 *, 0x100) = 0.0f;
        M2C_ERROR(/* unknown instruction: ldl $v1, 0x7($v0) */);
        M2C_ERROR(/* unknown instruction: ldr $v1, ($v0) */);
        M2C_ERROR(/* unknown instruction: sdl $v1, 0x147($s0) */);
        M2C_ERROR(/* unknown instruction: sdr $v1, 0x140($s0) */);
        M2C_FIELD(arg0, s32 *, 0x148) = (s32) M2C_FIELD(M2C_FIELD(temp_v1_2, void *(**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0xF8)), s32 *, 8);
        break;
    case 1:
        M2C_FIELD(arg0, s128 *, 0x100) = PosLoWorld(arg0);
        M2C_ERROR(/* unknown instruction: ldl $v0, 0x107($s0) */);
        M2C_ERROR(/* unknown instruction: ldr $v0, 0x100($s0) */);
        M2C_ERROR(/* unknown instruction: sdl $v0, 0x147($s0) */);
        M2C_ERROR(/* unknown instruction: sdr $v0, 0x140($s0) */);
        M2C_FIELD(arg0, s32 *, 0x148) = (s32) M2C_FIELD(arg0, s32 *, 0x108);
        FitLinearFunction__FffffPfT4(arg0 + 0x12C, arg0 + 0x14C, M2C_FIELD(arg0, f32 *, 0x164), 0x3F800000, M2C_FIELD(arg0, f32 *, 0x168), 0);
        M2C_FIELD(arg0, f32 *, 0x110) = (f32) M2C_FIELD(arg0, f32 *, 0x12C);
        M2C_FIELD(arg0, f32 *, 0x114) = (f32) M2C_FIELD(arg0, f32 *, 0x14C);
        break;
    }
    temp_f20_2 = M2C_ERROR(/* unknown instruction: max.s $f20, $f2, $f3 */);
    M2C_FIELD(arg0, f32 *, 0x110) = (f32) (M2C_FIELD(arg0, f32 *, 0x110) * temp_f20_2);
    M2C_FIELD(arg0, f32 *, 0x114) = (f32) (M2C_FIELD(arg0, f32 *, 0x114) * temp_f20_2);
    func_001A3B38(arg0);
}
