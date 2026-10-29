typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F1EB8 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
M2C_UNK func_00200F58(s32, s32, M2C_UNK, s32 *);    /* extern */
s32 func_001F1EB8(s32 arg0, s8 *arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 *var_a0;
    s32 *var_a1;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_v1;
    var_a2 = 0;
    temp_a3 = M2C_FIELD(arg1, s32 *, 0x484);
    temp_v1 = M2C_FIELD(arg1, s32 *, 0x488);
    if (temp_v1 < temp_a3) {
        var_a0 = (s32 *)(sp);
        var_v1 = temp_a3 - temp_v1;
        var_a1 = (s32 *)((temp_v1 * 0x10) + 0x404 + arg1);
        do {
            temp_v0 = *var_a1;
            var_a2 += 1;
            var_a1 += 0x10;
            var_v1 -= 1;
            *var_a0 = temp_v0;
            var_a0 += 4;
        } while (var_v1 != 0);
    }
    func_00200F58(arg0, var_a2, 6, (s32 *)(sp));
    return arg0;
}
}
