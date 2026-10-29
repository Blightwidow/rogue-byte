typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FAsegaGone(s32);                                /* extern */
s32 GetSmaCur(s32);                                 /* extern */
s32 GetSmaGoal(s32);                                /* extern */

s32 func_0017F550(s8 *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x194);
    if (temp_a0 == 0) {
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x198);
        var_v0 = 1;
        if (temp_a0_2 != 0) {
            temp_s0 = GetSmaCur(temp_a0_2);
            var_v0 = temp_s0 == GetSmaGoal(M2C_FIELD(arg0, s32 *, 0x198));
        }
        return var_v0;
    }
    return FAsegaGone(temp_a0);
}

}
