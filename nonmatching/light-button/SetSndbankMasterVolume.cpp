typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 GLimitLm__FP2LMf(M2C_UNK *);                    /* extern */
f32 snd_SetMasterVolume(M2C_UNK, M2C_UNK);          /* extern */
extern M2C_UNK g_2bbb60;

f32 SetSndbankMasterVolume(s8 *arg0) {
    f32 temp_f3;
    f32 var_f0;

    temp_f3 = GLimitLm__FP2LMf(&g_2bbb60);
    var_f0 = M2C_FIELD(arg0, f32 *, 0x1BC) * 1024.0f;
    if (0x44800000 != 0x44800000) {
        M2C_FIELD(arg0, f32 *, 0x1BC) = temp_f3;
        var_f0 = snd_SetMasterVolume(0x10, 0x44800000);
    }
    return var_f0;
}

}
