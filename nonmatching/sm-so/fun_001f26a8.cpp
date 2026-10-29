typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F26A8 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
M2C_UNK func_001F2500();                            /* extern */
void func_001F26A8(s8 *arg0) {
    s8 *var_a0;
    s8 *var_s0;
    func_001F2500();
    var_s0 = M2C_FIELD(arg0, s8 **, 0x64);
    if ((s32)var_s0 != M2C_FIELD(arg0, s32 *, 0x70)) {
        var_a0 = var_s0;
loop_2:
        if (FIsBasicDerivedFrom(var_a0, 0x30) != 0) {
            func_001F26A8(var_s0);
        }
        var_s0 = M2C_FIELD(var_s0, s8 **, 0x24);
        if ((s32)var_s0 != M2C_FIELD(arg0, s32 *, 0x70)) {
            var_a0 = var_s0;
            goto loop_2;
        }
    }
}
}
