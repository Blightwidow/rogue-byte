typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0019F0A8 {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
s32 CploFindSwObjectsByClass(M2C_UNK *, f32, f32, f32); /* extern */
extern M2C_UNK B_003DD490;
void func_0019F0A8(void) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 temp_v0;
    s32 var_s1;
    s8 **var_s0;
    s8 *temp_a1;
    s8 *temp_v0_2;
    temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x34, 0);
    var_s1 = temp_v0;
    if (temp_v0 > 0) {
        var_s0 = (s8 **)(sp);
        do {
            temp_a1 = *var_s0;
            var_s1 -= 1;
            var_s0 += 4;
            temp_v0_2 = M2C_FIELD(temp_a1, s8 **, 0xC);
            M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s8 *), 0x344)(temp_a1 + M2C_FIELD(temp_v0_2, s16 *, 0x340), temp_a1);
        } while (var_s1 != 0);
    }
}
}
