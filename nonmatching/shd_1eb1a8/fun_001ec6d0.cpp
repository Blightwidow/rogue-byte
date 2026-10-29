typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001EC6D0 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */

M2C_UNK AddVifUnpack__4VIFS3UPKiPvi(s32, M2C_UNK, M2C_UNK, s8 *, s128); /* extern */

s32 func_001EC6D0(s8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0x20] __attribute__((aligned(16)));
    AddVifUnpack__4VIFS3UPKiPvi(arg3, 0xC, 1, sp, M2C_FIELD(M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x20) + (arg1 * 8)), s8 **, 4), s128 *, 0x30));
    return 1;
}

}
