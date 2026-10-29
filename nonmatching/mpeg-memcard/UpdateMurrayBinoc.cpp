typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FButtonPressedWithin(s32, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK StopBinoc(s8 *);                          /* extern */
M2C_UNK UpdateBinoc(s8 *);                        /* extern */
s32 bevy_player_p15_binoc_active();                 /* extern */

void UpdateMurrayBinoc(s8 *arg0) {
    s8 *temp_s1;

    if (bevy_player_p15_binoc_active() != 0) {
        temp_s1 = arg0 + 0xF00;
        if ((M2C_FIELD(arg0, s32 *, 0xF04) == 1) && (M2C_FIELD(arg0, s32 *, 0xF20) == 0) && (FButtonPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 0x4F0, 0x3E800000) != 0)) {
            StopBinoc(temp_s1);
        }
        UpdateBinoc(temp_s1);
    }
}

}
