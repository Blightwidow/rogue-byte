typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_HandleAsegaEventsFF {
    /* 0x00 */ s8 *sp0;                           /* inferred */
    /* 0x04 */ char pad4[0x2C];
};                                                  /* size = 0x30 */
s32 FAsegaGone(s8 *);                             /* extern */
M2C_UNK HandleAsegaEvent(s8 *, f32 *, s32, s8 *); /* extern */
void HandleAsegaEventsFF(s8 *arg0) {
    s8 *sp0;
    f32 *var_a1;
    f32 temp_f2;
    s32 temp_a0;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s8 *temp_v0;
    s8 *temp_v0_3;
    s8 *temp_v1;
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x14), s32 *, 0xA0) != 0) {
        sp0 = arg0;
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0xC)(arg0 + M2C_FIELD(temp_v0, s16 *, 8));
        M2C_FIELD(arg0, f32 *, 0x20) = (f32) M2C_FIELD(arg0, f32 *, 0x1C);
loop_17:
        if (FAsegaGone(arg0) == 0) {
            temp_v1 = M2C_FIELD(arg0, s8 **, 0x14);
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x50);
            temp_f2 = M2C_FIELD(arg0, f32 *, 0x20);
            if (temp_a0 < M2C_FIELD(temp_v1, s32 *, 0xA0)) {
                var_a1 = (f32 *)((temp_a0 * 0x10) + M2C_FIELD(temp_v1, s32 *, 0xA4));
                if ((*var_a1 <= temp_f2) && (M2C_FIELD(arg0, f32 *, 0x40) >= 0.0f)) {
                    M2C_FIELD(arg0, s32 *, 0x50) = (s32) (temp_a0 + 1);
                    goto block_14;
                }
            }
            if (temp_a0 > 0) {
                if (!(temp_f2 <= M2C_FIELD(((temp_a0 * 0x10) + M2C_FIELD(temp_v1, s32 *, 0xA4)), f32 *, -0x10))) {
                    M2C_FIELD(arg0, f32 *, 0x1C) = temp_f2;
                } else {
                    temp_v1_2 = temp_a0 - 1;
                    if (M2C_FIELD(arg0, f32 *, 0x40) < 0.0f) {
                        M2C_FIELD(arg0, s32 *, 0x50) = temp_v1_2;
                        var_a1 = (f32 *)(M2C_FIELD(temp_v1, s32 *, 0xA4) + (temp_v1_2 * 0x10));
block_14:
                        temp_v0_2 = M2C_FIELD(var_a1, s32 *, 4);
                        switch (temp_v0_2) {
                        case 7:
                        case 8:
                        case 11:
                        case 13:
                        case 14:
                        case 15:
                        case 16:
                        case 21:
                        case 22:
                        case 23:
                        case 24:
                            HandleAsegaEvent(arg0, var_a1, temp_a0, temp_v1);
                            break;
                        }
                        goto loop_17;
                    }
                    goto block_13;
                }
            } else {
block_13:
                M2C_FIELD(arg0, f32 *, 0x1C) = temp_f2;
            }
        }
        temp_v0_3 = M2C_FIELD(sp0, s8 **, 0xC);
        M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s8 *), 0x14)(sp0 + M2C_FIELD(temp_v0_3, s16 *, 0x10), sp0);
    }
}
}
