typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK InitLo();                                   /* extern */
M2C_UNK InvalidateXfmMatWorld(void);              /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */

void InitXfm(s8 *arg0) {
    s8 *temp_s0;
    s8 *temp_v0;

    InitLo();
    temp_v0 = M2C_FIELD(arg0, s8 **, 0x10);
    temp_s0 = arg0 + 0x60;
    if (temp_v0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(temp_v0, s32 *, 0x60);
    }
    memset(temp_s0, 0, 0x40);
    M2C_FIELD(temp_s0, f32 *, 0x14) = 1.0f;
    M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
    M2C_FIELD(temp_s0, f32 *, 0x28) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x60) = 1.0f;
    InvalidateXfmMatWorld();
}

}
