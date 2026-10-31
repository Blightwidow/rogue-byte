typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001C4848 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s8 * PemitbEnsureEmitter(s32);    /* extern */
s32 PvAllocSwClearImpl__Fi(s8 *, s32, f32);       /* extern */
void func_001C4848(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    u32 temp_v1;
    s8 *temp_v0;
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x4778);
    if (temp_v1 < 4U) {
        M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0x477C) = arg1;
        M2C_FIELD(arg0, u32 *, 0x4778) = (u32) (temp_v1 + 1);
        temp_v0 = PemitbEnsureEmitter(arg1);
        if (M2C_FIELD(temp_v0, s32 *, 8) == 0) {
            M2C_FIELD(temp_v0, s32 *, 8) = PvAllocSwClearImpl__Fi(sp, 0x14, 0x10);
        }
    }
}
}
