typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FFilterDprizeObjects {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 FFilterDprizeObjects(s32 arg0, s8 *arg1) {
    if (M2C_FIELD(arg1, s64 *, 0x10) & (0x8000L << 0x21)) {
        return 0;
    }
    s32 temp_s0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg1, s8 **, 4), s8 **, 0xEC), s32 *, 0x60);
    if (FIsBasicDerivedFrom(temp_s0, 0x32) != 0) {
        return 0;
    }
    if (FIsBasicDerivedFrom(temp_s0, 0x4F) != 0) {
        return 0;
    }
    return 1;
}
}
