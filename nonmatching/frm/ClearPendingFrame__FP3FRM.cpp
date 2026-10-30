typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ClearPendingFrame__FP3FRM {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s8 **sp4;                          /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s8 *spC;                           /* inferred */
    /* 0x10 */ char pad10[0x60];
};                                                  /* size = 0x70 */
M2C_UNK ClearDl__FP2DL(s8 *);                     /* extern */
s32 FIsDlEmpty__FP2DL(s8 *);                      /* extern */
M2C_UNK FreeSlotheapPv(M2C_UNK *, s8 *);          /* extern */
M2C_UNK RemoveDlEntry(s8 *, s8 *);              /* extern */
extern M2C_UNK B_003E1518;
extern M2C_UNK B_003E1530;
extern s8 *g_2dd2fc;
void ClearPendingFrame__FP3FRM(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 **sp4;
    s32 sp8;
    s8 *spC;
    s32 temp_a0;
    s32 temp_a0_2;
    s8 *temp_a0_3;
    s8 *temp_a1;
    s8 *temp_s0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    s8 *var_a0;
    s8 *var_s0;
    s8 *var_s0_2;
    temp_s0 = arg0 + 0x34;
    var_a0 = arg0 + 0x40;
    if (FIsDlEmpty__FP2DL(temp_s0) == 0) {
        temp_a0 = M2C_FIELD(temp_s0, s32 *, 8);
        temp_v1 = g_2dd2fc;
        g_2dd2fc = sp;
        spC = temp_v1;
        temp_v0 = M2C_FIELD(arg0, s8 **, 0x34);
        var_s0 = temp_v0;
        sp4 = (s8 **)(temp_v0 + temp_a0);
        sp8 = temp_a0;
        if (var_s0 != NULL) {
            do {
                RemoveDlEntry(temp_s0, var_s0);
                temp_v0_2 = M2C_FIELD(var_s0, s8 **, 0xC);
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *), 0x14)(var_s0 + M2C_FIELD(temp_v0_2, s16 *, 0x10));
                temp_v1_2 = *sp4;
                var_s0 = temp_v1_2;
                sp4 = (s8 **)(temp_v1_2 + sp8);
            } while (var_s0 != NULL);
        }
        ClearDl__FP2DL(temp_s0);
        g_2dd2fc = spC;
        var_a0 = arg0 + 0x40;
    }
    if (FIsDlEmpty__FP2DL(var_a0) == 0) {
        temp_a0_2 = M2C_FIELD(var_a0, s32 *, 8);
        temp_v1_3 = g_2dd2fc;
        g_2dd2fc = sp;
        spC = temp_v1_3;
        temp_v0_3 = M2C_FIELD(arg0, s8 **, 0x40);
        var_s0_2 = temp_v0_3;
        sp4 = (s8 **)(temp_v0_3 + temp_a0_2);
        sp8 = temp_a0_2;
        if (var_s0_2 != NULL) {
            do {
                temp_a1 = M2C_FIELD(var_s0_2, s8 **, 0x1088);
                if (temp_a1 != NULL) {
                    FreeSlotheapPv(&B_003E1530, temp_a1);
                }
                RemoveDlEntry(var_a0, var_s0_2);
                FreeSlotheapPv(&B_003E1518, var_s0_2);
                temp_a0_3 = *sp4;
                var_s0_2 = temp_a0_3;
                sp4 = (s8 **)(temp_a0_3 + sp8);
            } while (var_s0_2 != NULL);
        }
        ClearDl__FP2DL(var_a0);
        g_2dd2fc = spC;
    }
}
}
