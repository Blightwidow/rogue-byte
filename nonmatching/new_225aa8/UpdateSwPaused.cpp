typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSwPaused {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s8 **sp4;                          /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s8 *spC;                           /* inferred */
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0x5C];
};                                                  /* size = 0x70 */
M2C_UNK UpdateAsega(s8 *, s8 *);                /* extern */
extern s8 *g_2dd2fc;
void UpdateSwPaused(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 **sp4;
    s32 sp8;
    s8 *spC;
    s32 sp10;
    s32 temp_v0_2;
    s32 temp_v0_6;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_3;
    s8 **temp_v0_3;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *temp_v0;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v1;
    s8 *temp_v1_3;
    s8 *var_a1_2;
    var_a1 = 0;
    M2C_FIELD(arg0, s32 **, 0x3F1C) = &sp10;
    sp10 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x3F14) > 0) {
        do {
            temp_v1 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x3F20) + (var_a1 * 8));
            if ((M2C_FIELD(temp_v1, s32 *, 0) & 0x102) == 0x102) {
                temp_a1 = M2C_FIELD(temp_v1, s8 **, 4);
                temp_v0 = M2C_FIELD(temp_a1, s8 **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0x84)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x80), temp_a1);
            }
            temp_v0_2 = sp10 + 1;
            var_a1 = temp_v0_2;
            sp10 = temp_v0_2;
        } while (var_a1 < M2C_FIELD(arg0, s32 *, 0x3F14));
    }
    M2C_FIELD(arg0, s32 **, 0x3F1C) = NULL;
    temp_v0_3 = (s8 **)(arg0 + 0x3D88);
    sp4 = temp_v0_3;
    temp_a0 = g_2dd2fc;
    temp_v1_2 = M2C_FIELD(temp_v0_3, s32 *, 8);
    g_2dd2fc = sp;
    spC = temp_a0;
    temp_v0_4 = M2C_FIELD(arg0, s8 **, 0x3D88);
    sp8 = temp_v1_2;
    var_a1_2 = temp_v0_4;
    sp4 = (s8 **)(temp_v0_4 + temp_v1_2);
    if (var_a1_2 != NULL) {
        do {
            var_a0 = M2C_FIELD(M2C_FIELD(var_a1_2, s8 **, 0x14), s32 *, 0x40);
            if ((var_a0 ^ 1) & 1) {
                var_a0 = *(s32 *)var_a0;
            }
            if (var_a0 & 0x100) {
                UpdateAsega(var_a1_2, var_a1_2);
            }
            temp_a0_2 = *sp4;
            var_a1_2 = temp_a0_2;
            sp4 = (s8 **)(temp_a0_2 + sp8);
        } while (var_a1_2 != NULL);
    }
    var_a1_3 = 0;
    M2C_FIELD(arg0, s32 **, 0x3F1C) = &sp10;
    sp10 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x3F14) > 0) {
        do {
            temp_v1_3 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x3F20) + (var_a1_3 * 8));
            if ((M2C_FIELD(temp_v1_3, s32 *, 0) & 0x124) == 0x104) {
                temp_a1_2 = M2C_FIELD(temp_v1_3, s8 **, 4);
                temp_v0_5 = M2C_FIELD(temp_a1_2, s8 **, 0xC);
                M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, s8 *), 0x8C)(temp_a1_2 + M2C_FIELD(temp_v0_5, s16 *, 0x88), temp_a1_2);
            }
            temp_v0_6 = sp10 + 1;
            var_a1_3 = temp_v0_6;
            sp10 = temp_v0_6;
        } while (var_a1_3 < M2C_FIELD(arg0, s32 *, 0x3F14));
    }
    M2C_FIELD(arg0, s32 **, 0x3F1C) = NULL;
    g_2dd2fc = spC;
}
}
