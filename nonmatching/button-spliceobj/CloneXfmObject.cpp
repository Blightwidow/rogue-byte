typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CloneXfmObject {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
void CloneXfm();
void CloneXfmObject(s32 arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    M2C_UNK temp_v0;
    M2C_UNK temp_v0_2;
    s32 vu_1;
    asm volatile("ldl %0, 0x10b(%1)" : "=r"(vu_1) : "r"(arg0));
    s32 vu_2;
    asm volatile("ldr %0, 0x104(%1)" : "=r"(vu_2) : "r"(arg0), "0"(vu_1));
    temp_v0 = vu_2;
    asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v0), "r"(sp));
    asm volatile("sdr %0, (%1)" : : "r"(temp_v0), "r"(sp));
    CloneXfm();
    s32 vu_3;
    asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_3) : "r"(sp));
    s32 vu_4;
    asm volatile("ldr %0, (%1)" : "=r"(vu_4) : "r"(sp), "0"(vu_3));
    temp_v0_2 = vu_4;
    asm volatile("sdl %0, 0x10b(%1)" : : "r"(temp_v0_2), "r"(arg0));
    asm volatile("sdr %0, 0x104(%1)" : : "r"(temp_v0_2), "r"(arg0));
}
}
