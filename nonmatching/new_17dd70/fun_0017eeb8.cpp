typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 SMaxCrv(s8 *);                                /* extern */
f32 SMinCrv(s8 *);                                /* extern */
extern f32 D_FLT_002BE7B8;

s32 func_0017EEB8(s8 *arg0) {
    f32 var_f0;
    s32 var_v0;
    s8 *temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 **, 0x30);
    var_v0 = 0;
    if (M2C_FIELD(temp_a0, s32 *, 0xE4) == 0) {
        if (M2C_FIELD(arg0, s32 *, 0x34) != 0) {
            var_f0 = SMaxCrv(temp_a0);
        } else {
            var_f0 = SMinCrv(temp_a0);
        }
        var_v0 = 0;
        if (!(D_FLT_002BE7B8 < fabsf(M2C_FIELD(arg0, f32 *, 0x38) - var_f0))) {
            var_v0 = 1;
        }
    }
    return var_v0;
}

}
