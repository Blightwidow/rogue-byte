typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetSndbankMasterVolume {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
f32 GLimitLm__FP2LMf(M2C_UNK *);                    /* extern */
M2C_UNK snd_SetMasterVolume(M2C_UNK, s32);          /* extern */
extern M2C_UNK g_2bbb60;
void SetSndbankMasterVolume(s8 *arg0) {
    f32 temp_f0;
    s32 temp_f1;
    temp_f0 = GLimitLm__FP2LMf(&g_2bbb60);
    temp_f1 = (s32) (temp_f0 * 1024.0f);
    if ((s32) (M2C_FIELD(arg0, f32 *, 0x1BC) * 1024.0f) != temp_f1) {
        M2C_FIELD(arg0, f32 *, 0x1BC) = temp_f0;
        snd_SetMasterVolume(0x10, temp_f1);
    }
}
}
