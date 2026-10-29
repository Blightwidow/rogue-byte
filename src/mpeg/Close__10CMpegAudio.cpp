typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK snd_CloseMovieSound();                      /* extern */
M2C_UNK snd_ContinueAllSoundsInGroup(u32);      /* extern */
M2C_UNK snd_SetMasterVolume(M2C_UNK, s32);          /* extern */

void Close__10CMpegAudio(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    snd_CloseMovieSound();
    snd_SetMasterVolume(2, M2C_FIELD(arg0, s32 *, 0xA0));
    snd_SetMasterVolume(0x10, M2C_FIELD(arg0, s32 *, 0xA4));
    snd_ContinueAllSoundsInGroup(0xFFFFFFFFu);
}

}
