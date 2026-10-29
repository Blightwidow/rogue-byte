typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001BEE60 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */

void func_00169198(s32, s8 *);

void func_001BEE60(s8 *arg0) {
    s32 *var_s1;
    s32 temp_a0;
    s32 var_s2;

    if (M2C_FIELD(arg0, s32 *, 0x128) != 0) {
        var_s2 = 0;
        if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
            var_s1 = (s32 *)(arg0 + 0xE4);
            do {
                temp_a0 = *var_s1;
                var_s2 += 1;
                var_s1 += 4;
                func_00169198(temp_a0 + 0x80, arg0);
            } while (var_s2 < M2C_FIELD(arg0, s32 *, 0xE0));
        }
    }
}

}
