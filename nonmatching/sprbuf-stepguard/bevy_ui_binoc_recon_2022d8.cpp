typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_bevy_ui_binoc_recon_2022d8 {};    /* size 0x0 */
s32 bevy_ui_binoc_recon_2022d8(s8 *arg0) {
    s32 temp_v0;
    s32 var_a1;
    s8 **var_a0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    if (M2C_FIELD(arg0, s32 *, 0xB8) == 0) {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x30);
        var_a1 = 0;
        if (temp_v0 > 0) {
            var_a0 = (s8 **)(arg0 + 0x34);
loop_6:
            temp_v1 = *var_a0;
            if ((int)((u64) M2C_FIELD(temp_v1, u64 *, 0x28) >> 0x3C) & 1) {
                temp_v0_2 = M2C_FIELD(temp_v1, s8 **, 0x100);
                if (temp_v0_2 != NULL) {
                    if ((int)((u64) M2C_FIELD(temp_v0_2, u64 *, 0x28) >> 0x3C) & 1) {
                        goto block_11;
                    }
                    /* Duplicate return node #3. Try simplifying control flow for better match */
                    return 1;
                }
                /* Duplicate return node #3. Try simplifying control flow for better match */
                return 1;
            }
block_11:
            var_a1 += 1;
            var_a0 += 4;
            if (var_a1 >= temp_v0) {
                /* Duplicate return node #12. Try simplifying control flow for better match */
                return 0;
            }
            goto loop_6;
        }
        return 0;
    }
    return 1;
}
}
