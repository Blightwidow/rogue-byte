typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F6B48 {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */

M2C_UNK func_001F2AD0(s8 *, s8 *);              /* extern */

void func_001F6B48(s8 *arg0, s32 arg1) {
    s32 var_s1;
    s32 var_s2;
    s8 *temp_a1;

    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        var_s2 = 0;
        do {
            temp_a1 = (s8 *)(M2C_FIELD(arg0, s32 *, 0xE4) + var_s2);
            if (M2C_FIELD(temp_a1, s32 *, 0xC) == arg1) {
                func_001F2AD0(arg0, temp_a1);
            }
            var_s1 += 1;
            var_s2 += 0xB0;
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0xE0));
    }
}

}
