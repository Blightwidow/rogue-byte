typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK PrependSlEntry(s8 *, s8 *);             /* extern */
M2C_UNK func_002185F8(s32, s32, u8, s8 *);        /* extern */

void func_00215960(s8 *arg0, s8 *arg1, u8 arg2) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    switch (temp_v1) {
    case 4:
        func_002185F8(M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s32 *, 0x84) + (M2C_FIELD(arg0, s32 *, 0x10) * 0x30), M2C_FIELD(arg1, s32 *, 0x58), M2C_FIELD(arg1, u8 *, 0x61), arg0);
        return;
    case 1:
    case 3:
    case 6:
    case 7:
        M2C_FIELD(arg1, u8 *, 0x61) = arg2;
        PrependSlEntry(M2C_FIELD(arg0, s8 **, 8) + 0xFC, arg0);
        /* fallthrough */
    default:
        return;
    }
}

}
