typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InvalidateXfmMatWorld {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK ReinsertSwRoot(M2C_UNK *, s32);             /* extern */
extern M2C_UNK B_003DD490;
void InvalidateXfmMatWorld(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x54) = -1;
    if ((M2C_FIELD(arg0, s32 *, 0x10) == 0) && ((int)(M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1)) {
        ReinsertSwRoot(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x14));
    }
}
}
