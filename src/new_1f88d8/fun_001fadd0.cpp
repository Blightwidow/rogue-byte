typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s128 VecVelocityAtPos(s8 *, s32, s32);

void func_001FADD0(s8 *arg0, s32 arg1, s32 arg2, s8 *arg3) {
    if (M2C_FIELD(arg0, s32 *, 0xE8) == 0) {
        M2C_FIELD(arg3, s32 *, 8) = 0;
        M2C_FIELD(arg3, s32 *, 4) = 0;
        M2C_FIELD(arg3, s32 *, 0) = 0;
        return;
    }
    *(s128 *)arg3 = VecVelocityAtPos(arg0, arg1, arg2);
}

}
