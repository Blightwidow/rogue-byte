typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0020CFC0 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 FFilterHitTestDefault(s32, s8 *);             /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 func_0020CFC0(s32 arg0, s8 *arg1) {
    s32 var_v0;
    if (!(M2C_FIELD(arg1, s64 *, 0x10) & (0x8000 << 0x21)) || (var_v0 = 1, (FIsBasicDerivedFrom(M2C_FIELD(arg1, s32 *, 4), 0x59) == 0))) {
        var_v0 = FFilterHitTestDefault(arg0, arg1);
    }
    return var_v0;
}
}
