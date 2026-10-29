typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001564E8 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
void InitLo();
extern M2C_UNK D_002BDCD8;
extern f32 D_FLT_002BDCD0;
void func_001564E8(s8 *arg0) {
    M2C_UNK temp_v0;
    InitLo();
    M2C_FIELD(arg0, f32 *, 0x54) = (f32) D_FLT_002BDCD0;
    s32 vu_1;
    asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_1) : "r"(&D_002BDCD8));
    s32 vu_2;
    asm volatile("ldr %0, (%1)" : "=r"(vu_2) : "r"(&D_002BDCD8), "0"(vu_1));
    temp_v0 = vu_2;
    asm volatile("sdl %0, 0x5f(%1)" : : "r"(temp_v0), "r"(arg0));
    asm volatile("sdr %0, 0x58(%1)" : : "r"(temp_v0), "r"(arg0));
    M2C_FIELD(arg0, f32 *, 0x60) = 0.25f;
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) | 0x40);
}
}
