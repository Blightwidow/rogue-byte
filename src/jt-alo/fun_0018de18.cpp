typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
void StartAttach(s8 *, s32, s32, s32);

void func_0018DE18(s8 *arg0, s32 arg1) {
    if (arg1 != 0) {
        *(s32 *)(arg0 + 0x9C0) = 1;
        StartAttach(arg0 + 0x4C0, 6, arg1, 0);
    } else if (*(s32 *)(arg0 + 0x4C8) == 6) {
        s8 *temp_v0 = *(s8 **)(arg0 + 0xC);
        ((void (*)(s8 *, s32))*(void **)(temp_v0 + 0x2C4))(arg0 + *(s16 *)(temp_v0 + 0x2C0), 0);
    }
}
}
