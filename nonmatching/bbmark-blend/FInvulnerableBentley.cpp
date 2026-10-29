typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FInvulnerableJt(s8 *, s32);                   /* extern */
s32 func_00194640(s8 *, s32);                     /* extern */

s32 FInvulnerableBentley(s8 *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x13D0);
    if (temp_v1 != 3) {
        if ((temp_v1 == 0xD) && (arg1 == 0x4000)) {
            return 1;
        }
        goto block_6;
    }
    var_v0 = 1;
    if (func_00194640(arg0 + 0x4C0, arg1) == 0) {
block_6:
        var_v0 = FInvulnerableJt(arg0, arg1);
    }
    return var_v0;
}

}
