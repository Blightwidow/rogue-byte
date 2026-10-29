typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK snd_AutoVol(s32, M2C_UNK, f32, M2C_UNK);    /* extern */
M2C_UNK snd_StopSound(s32, M2C_UNK);                /* extern */

void StopSound__FP3AMBi(s8 *arg0) {
    f32 temp_f1;

    temp_f1 = M2C_FIELD(arg0, f32 *, 0x48);
    if (temp_f1 > 0.0f) {
        snd_AutoVol(M2C_FIELD(arg0, s32 *, 0x40), -4, temp_f1, 2);
        return;
    }
    snd_StopSound(M2C_FIELD(arg0, s32 *, 0x40), -4);
}

}
