typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SolveDzg__FP3DZGiiPP2XPPiPPP2SO {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s8 **sp4;                          /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s8 *spC;                           /* inferred */
    /* 0x10 */ char pad10[0x70];
};                                                  /* size = 0x80 */
void AppendDlEntry(s8 *, s8 *);              /* extern */
M2C_UNK EnforceDzgDz__FP3DZGP2DZ(s8 *, s8 *);   /* extern */
M2C_UNK FillDzgDz(s8 *, s32, s8 *, s32);        /* extern */
M2C_UNK RemoveDlEntry(s8 *, s8 *);              /* extern */
s32 func_00158958(s8 *, s8 *);                  /* extern */
extern s8 *g_2dd2fc;
void SolveDzg__FP3DZGiiPP2XPPiPPP2SO(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s8 **sp4;
    s32 sp8;
    s8 *spC;
    f32 temp_f0;
    f32 var_f1;
    s32 temp_v0;
    s8 **temp_v1;
    s8 *temp_a0;
    s8 *temp_a1;
    s8 *temp_v1_2;
    s8 *var_s0;
    s8 *var_s0_2;
    s8 *var_v0;
    temp_v1 = (s8 **)(arg0 + 0x30);
    sp4 = temp_v1;
    temp_a1 = g_2dd2fc;
    temp_v0 = M2C_FIELD(temp_v1, s32 *, 8);
    g_2dd2fc = sp;
    spC = temp_a1;
    temp_v1_2 = M2C_FIELD(arg0, s8 **, 0x30);
    sp8 = temp_v0;
    var_s0 = temp_v1_2;
    sp4 = (s8 **)(temp_v1_2 + temp_v0);
    if (var_s0 != NULL) {
        do {
            if (M2C_FIELD(var_s0, s32 *, 0) == 1) {
                if (M2C_FIELD(var_s0, s32 *, 0x18) == 0) {
                    FillDzgDz(arg0, arg1, var_s0, func_00158958(arg0, var_s0));
                }
                RemoveDlEntry(arg0 + 0x30, var_s0);
                AppendDlEntry(arg0 + 0xC, var_s0);
                M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + 1);
            }
            temp_a0 = *sp4;
            sp4 = (s8 **)(temp_a0 + sp8);
            var_s0 = temp_a0;
        } while (var_s0 != NULL);
    }
    EnforceDzgDz__FP3DZGP2DZ(arg0, NULL);
    g_2dd2fc = spC;
loop_8:
    var_v0 = M2C_FIELD(arg0, s8 **, 0x30);
    var_f1 = -0.01f;
    var_s0_2 = NULL;
    if (var_v0 != NULL) {
        do {
            temp_f0 = M2C_FIELD(var_v0, f32 *, 0x10);
            if (temp_f0 < var_f1) {
                var_f1 = temp_f0;
                var_s0_2 = var_v0;
            }
            var_v0 = M2C_FIELD(var_v0, s8 **, 0x20);
        } while (var_v0 != NULL);
    }
    if (var_s0_2 != NULL) {
        if (M2C_FIELD(var_s0_2, s32 *, 0x18) == 0) {
            FillDzgDz(arg0, arg1, var_s0_2, func_00158958(arg0, var_s0_2));
        }
        EnforceDzgDz__FP3DZGP2DZ(arg0, var_s0_2);
        goto loop_8;
    }
}
}
