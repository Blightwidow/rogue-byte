typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C48C0 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */

void func_001A58D0(s8 *, s32, M2C_UNK);

void func_001C48C0(s8 *arg0) {
    s8 **var_s1;
    s32 var_s2;
    s8 *var_a0;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x4778) > 0) {
        var_a0 = M2C_FIELD(arg0, s8 **, 0x477C);
        var_s1 = (s8 **)(arg0 + 0x477C);
loop_2:
        var_s1 += 1;
        var_s2 += 1;
        *M2C_FIELD(M2C_FIELD(var_a0, s8 **, 0xE4), s32 **, 8) = M2C_FIELD(arg0, s32 *, 0x3EFC);
        func_001A58D0(var_a0, M2C_FIELD(arg0, s32 *, 0x3EFC), 0);
        if (var_s2 < M2C_FIELD(arg0, s32 *, 0x4778)) {
            var_a0 = *var_s1;
            goto loop_2;
        }
    }
}

}
