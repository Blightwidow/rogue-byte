typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SweepSidebags {
    /* 0x00 */ char pad0[0x80];
};                                                  /* size = 0x80 */
M2C_UNK FreeSlotheapPv(M2C_UNK *, s8 *);          /* extern */
M2C_UNK UnlinkSidebagNode(s8 *);                  /* extern */
extern s8 *B_002DD2C0;
extern s32 B_002DD2C8;
extern M2C_UNK B_00452138;
extern M2C_UNK B_00452148;
extern s32 g_2dd598;
void SweepSidebags(void) {
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0_2;
    u32 temp_a0;
    u32 temp_v0;
    u32 temp_v0_2;
    s8 *var_s0;
    s8 *var_s1;
    s8 *var_s2;
    s8 *var_v0;
    var_s0 = B_002DD2C0;
    if ((s32)var_s0 != B_002DD2C8) {
        do {
            temp_a0 = M2C_FIELD(var_s0, u32 *, 4);
            if ((temp_a0 >> 0x1F) != g_2dd598) {
                M2C_FIELD(var_s0, u32 *, 4) = (u32) ((temp_a0 & 0x7FFFFFFF) | (g_2dd598 << 0x1F));
            }
            temp_v0 = M2C_FIELD(var_s0, u32 *, 4);
            temp_a0_2 = (temp_v0 >> 0x10) & 0x1FFF;
            temp_v1 = (temp_v0 >> 0x1D) & 3;
            if ((temp_a0_2 != 0) || (var_v0 = NULL, (temp_v1 != 0))) {
                var_v0 = (s8 *)(*((temp_v1 * 4) + &B_00452138) + (temp_a0_2 * 0xC));
            }
            var_s0 = var_v0;
        } while ((s32)var_s0 != B_002DD2C8);
    }
    if (var_s0 != NULL) {
        var_s1 = var_s0;
        do {
            temp_v0_2 = M2C_FIELD(var_s1, u32 *, 4);
            temp_a0_3 = (temp_v0_2 >> 0x10) & 0x1FFF;
            temp_v1_2 = (temp_v0_2 >> 0x1D) & 3;
            if (temp_a0_3 == 0) {
                var_v0_2 = temp_v1_2 * 4;
                if (temp_v1_2 == 0) {
                    var_s2 = NULL;
                } else {
                    goto block_14;
                }
            } else {
                var_v0_2 = temp_v1_2 * 4;
block_14:
                var_s2 = (s8 *)(*(var_v0_2 + &B_00452138) + (temp_a0_3 * 0xC));
            }
            if (((u32) M2C_FIELD(var_s1, u32 *, 4) >> 0x1F) != g_2dd598) {
                UnlinkSidebagNode(var_s1);
                FreeSlotheapPv(&B_00452148, var_s1);
            }
            var_s1 = var_s2;
        } while (var_s2 != NULL);
    }
}
}
