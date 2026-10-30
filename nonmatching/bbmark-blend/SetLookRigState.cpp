typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetLookRigState {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x08 */ f32 sp8;                             /* overlap; inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0x6C];
};                                                  /* size = 0x90 */
#define sp0 (*(s128 *)(sp + 0x00))
#define sp8 (*(f32 *)(sp + 0x08))
M2C_UNK ApplyAsegToHandle(s32, s8 *, M2C_UNK, s8 *, f32, M2C_UNK); /* extern */
M2C_UNK ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(s8 *, M2C_UNK, s8 *, s32 *, f32, M2C_UNK, M2C_UNK); /* extern */
s128 ConvertAloPos(s32, s8 *, s128);              /* extern */
M2C_UNK FixStepAngularVelocity__FP4STEP(s8 *);    /* extern */
M2C_UNK ReblendAsegbl(s32);                         /* extern */
M2C_UNK SetStepRadTargetDir(s8 *, s128);          /* extern */
M2C_UNK func_00131A90(s32, f32);                    /* extern */
M2C_UNK func_00131B10(s32, s8 *, s32);            /* extern */
extern s128 g_2a2dd0;
extern f32 g_2dded0;
void SetLookRigState(s8 *arg0, s32 arg1) {
    s32 unksp14;
    s32 saved_reg_s2;
    s8 sp[0x10] __attribute__((aligned(16)));
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
    s8 *temp_a0;
    s8 *temp_a1;
    s8 *temp_v0;
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
            temp_a0 = M2C_FIELD(arg0, s8 **, 0);
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
            sp10 = ConvertAloPos(M2C_FIELD(arg0, s32 *, 0xE4), M2C_FIELD(arg0, s8 **, 0), g_2a2dd0);
            var_v0 = 1;
            if (!(unksp14 > 0.0f)) {
                var_v0 = 0;
            }
            M2C_FIELD(arg0, s32 *, 8) = var_v0;
            if (arg1 == 0) {
                if (sp20 != 0) {
                    SetStepRadTargetDir(M2C_FIELD(arg0, s8 **, 0), sp0);
                    FixStepAngularVelocity__FP4STEP(M2C_FIELD(arg0, s8 **, 0));
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
        ApplyAsegToHandle(var_s2, M2C_FIELD(arg0, s8 **, 0), 1, arg0 + 0xE0, g_2dded0 - M2C_FIELD(arg0, f32 *, 0x18), 0x3F800000);
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0xE0);
        if (temp_a0_2 != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
                temp_a1 = M2C_FIELD(arg0, s8 **, 0);
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
}
