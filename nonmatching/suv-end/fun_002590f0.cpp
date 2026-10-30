typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_002590F0 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 *PvAllocSwCopyImpl__FiPv(s8 *, s32 *, M2C_UNK, s32, s32); /* extern */
s32 *func_002590F0(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 *temp_a0;
    s32 *temp_v0;
    s32 temp_v1;
    if (arg1 == 1) {
        M2C_FIELD(arg0, s32 *, 0xE0) = arg1;
        temp_a0 = M2C_FIELD(arg0, s32 **, 0xE4);
        temp_v1 = *temp_a0;
        if (temp_v1 >= 2) {
            *temp_a0 = temp_v1 - 1;
            temp_v0 = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s32 **, 0xE4), 0x10, 0x100, 0x10);
            M2C_FIELD(arg0, s32 **, 0xE4) = temp_v0;
            *temp_v0 = arg1;
        }
    }
    return M2C_FIELD(arg0, s32 **, 0xE4);
}
}
