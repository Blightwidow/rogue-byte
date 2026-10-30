typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_TriggerRsmg {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
M2C_UNK TriggerRsmgEntry(s32, s32, s32, s32, M2C_UNK, M2C_UNK); /* extern */
void TriggerRsmg(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_s0;
    s32 var_s1;
    if (arg1 > 0) {
        var_s1 = arg2;
        var_s0 = arg1;
        do {
            TriggerRsmgEntry(arg0, var_s1, arg3, arg4, 0, 0);
            var_s0 -= 1;
            var_s1 += 0x10;
        } while (var_s0 != 0);
    }
}
}
