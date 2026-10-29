typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F82B8 {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s8 *PalertEnsure();                               /* extern */
void func_001F82B8(s32 arg1, s32 arg2) {
    M2C_UNK temp_v1;
    s8 *temp_v0;
    temp_v0 = PalertEnsure();
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    if (arg2 != 0) {
        s32 vu_1;
        asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_1) : "r"(arg2));
        s32 vu_2;
        asm volatile("ldr %0, (%1)" : "=r"(vu_2) : "r"(arg2), "0"(vu_1));
        temp_v1 = vu_2;
        asm volatile("sdl %0, 0x1b(%1)" : : "r"(temp_v1), "r"(temp_v0));
        asm volatile("sdr %0, 0x14(%1)" : : "r"(temp_v1), "r"(temp_v0));
    }
}
}
