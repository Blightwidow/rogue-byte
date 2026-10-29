typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK SetHandsOff(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_001A6CA8(s8 *, M2C_UNK);                     /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;

void Warp_SetState(s8 *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x13C)) {
        if (arg1 == 4) {
            func_001A6CA8(arg0, 1);
            SetHandsOff(&B_003DD490, 3);
            M2C_FIELD(&B_003DD490, s8 **, 0x3C84) = arg0;
        }
        M2C_FIELD(arg0, s32 *, 0x13C) = arg1;
        M2C_FIELD(arg0, f32 *, 0x140) = (f32) g_2dded0;
    }
}

}
