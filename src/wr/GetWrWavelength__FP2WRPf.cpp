typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *PwreGetWrCircle__FP2WR4ENSK(s8 *, M2C_UNK);         /* extern */

f32 GetWrWavelength__FP2WRPf(s8 *pwr, f32 *) {
    f32 temp_f1;
    f32 var_f0;

    temp_f1 = M2C_FIELD(PwreGetWrCircle__FP2WR4ENSK(pwr, 1), f32 *, 0x64);
    var_f0 = 0.0f;
    if (temp_f1 != 0.0f) {
        var_f0 = 1.0f / temp_f1;
    }
    return var_f0;
}

}
