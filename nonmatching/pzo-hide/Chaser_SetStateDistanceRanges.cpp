typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Chaser_SetStateDistanceRanges {}; /* size 0x0 */
void Chaser_SetStateDistanceRanges(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK temp_v1;
    M2C_UNK temp_v1_2;
    s32 *temp_v0;
    if (arg1 < 5U) {
        temp_v0 = (s32 *)(arg0 + ((arg1 * 0x28) + 0x270));
        *temp_v0 = 1;
        s32 vu_1;
        asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_1) : "r"(arg2));
        s32 vu_2;
        asm volatile("ldr %0, (%1)" : "=r"(vu_2) : "r"(arg2), "0"(vu_1));
        temp_v1 = vu_2;
        asm volatile("sdl %0, 0xf(%1)" : : "r"(temp_v1), "r"(temp_v0));
        asm volatile("sdr %0, 0x8(%1)" : : "r"(temp_v1), "r"(temp_v0));
        s32 vu_3;
        asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_3) : "r"(arg3));
        s32 vu_4;
        asm volatile("ldr %0, (%1)" : "=r"(vu_4) : "r"(arg3), "0"(vu_3));
        temp_v1_2 = vu_4;
        asm volatile("sdl %0, 0x17(%1)" : : "r"(temp_v1_2), "r"(temp_v0));
        asm volatile("sdr %0, 0x10(%1)" : : "r"(temp_v1_2), "r"(temp_v0));
    }
}
}
