typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InitDepthSlot {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK ClearSle(s8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK RO_002A3A10;
void InitDepthSlot(s8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x44) = &RO_002A3A10;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0x7F7F7F7F;
    M2C_FIELD(arg0, s32 *, 0x50) = 0xFFFFFFFF;
    M2C_FIELD(arg0, s32 *, 0x64) = -1;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0x7F7F7F7F;
    M2C_FIELD(arg0, s32 *, 4) = 0xFFFFFFFF;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0x7F7F7F7F;
    M2C_FIELD(arg0, s32 *, 0x40) = 0xFFFFFFFF;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    ClearSle(arg0 + 0x68, 0x7F7F7F7F, 0xFFFFFFFF, -1);
}
}
