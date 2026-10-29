typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s8 *PwreGetWrCircle__FP2WR4ENSK(M2C_UNK);         /* extern */

void SetWrWavelength__FP2WRf(f32 fparg0) {
    f32 var_f0;
    s8 *temp_v0;

    temp_v0 = PwreGetWrCircle__FP2WR4ENSK(1);
    var_f0 = 0.0f;
    if (fparg0 != 0.0f) {
        var_f0 = 1.0f / fparg0;
    }
    M2C_FIELD(temp_v0, f32 *, 0x64) = var_f0;
}

}
