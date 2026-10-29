typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK ApplyAsegToHandle(M2C_UNK, M2C_UNK, s32, s32, f32, M2C_UNK); /* extern */
s32 FJumperDone();                                  /* extern */
M2C_UNK SetJumperState(s32, M2C_UNK);               /* extern */

void CancelJumper(s32 arg0) {
    if (FJumperDone() == 0) {
        SetJumperState(arg0, 4);
        ApplyAsegToHandle(0, 0, 0, arg0 + 0x38, 0, 0x3F800000);
    }
}

}
