typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_002280D0 {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s8 **); /* extern */
extern M2C_UNK B_003DD490;
s8 *func_002280D0(void) {
    s8 sp[0x80] __attribute__((aligned(16)));
    s32 temp_v0;
    s32 var_a1;
    s8 **var_a0;
    s8 *temp_v1;
    s8 *var_s0;
    var_s0 = NULL;
    temp_v0 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x1A, 0, 0x20, (s8 **)(sp));
    if (temp_v0 > 0) {
        var_a1 = temp_v0;
        var_a0 = (s8 **)(sp);
        do {
            temp_v1 = *var_a0;
            var_a1 -= 1;
            var_a0 += 4;
            var_s0 = (M2C_FIELD(temp_v1, s32 *, 0x130) != 0) ? temp_v1 : var_s0;
        } while (var_a1 != 0);
    }
    return var_s0;
}
}
