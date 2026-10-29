typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK Blot_Construct();                           /* extern */
extern M2C_UNK D_002C9670;

s8 *func_00211C58(s8 *arg0) {
    Blot_Construct();
    M2C_FIELD(arg0, s32 *, 0x120) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002C9670;
    M2C_FIELD(arg0, s32 *, 0x110) = -1;
    M2C_FIELD(arg0, s32 *, 0x114) = -1;
    M2C_FIELD(arg0, s32 *, 0x118) = -1;
    M2C_FIELD(arg0, s32 *, 0x11C) = -1;
    return arg0;
}

}
