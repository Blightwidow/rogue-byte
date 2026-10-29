typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PleaseFromPlo {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
s32 PleaseFromIclone(s8 *, s32, s8 *, s8 *);  /* extern */
s32 PleaseFromPlo(s8 *arg0, s32 arg1) {
    s32 var_a1;
    s32 var_t0;
    s8 *temp_a0;
    temp_a0 = M2C_FIELD(arg0, s8 **, 0xE0);
    if (M2C_FIELD(temp_a0, s32 *, 0) != 1) {
        return 0;
    }
    var_a1 = M2C_FIELD(temp_a0, s32 *, 0xC);
    var_t0 = 0;
loop_3:
    if (var_a1 < M2C_FIELD(temp_a0, s32 *, 8)) {
        if (arg1 != *(s32 *)((var_a1 * 4) + M2C_FIELD(temp_a0, s32 *, 4))) {
            var_a1 += 1;
            goto loop_3;
        }
        var_t0 = PleaseFromIclone(arg0, var_a1, temp_a0, arg0);
    }
    return var_t0;
}
}
