typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void SetMurrayState(M2C_UNK);
void func_002046F0(s8 *, s32);

void StartMurrayLiftGuard(s8 *arg0, s8 *arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x13EC) != 0) {
        M2C_FIELD(arg0, s8 **, 0x13F0) = arg1;
        M2C_FIELD(arg0, s32 *, 0x144C) = 1;
        SetMurrayState(4);
        func_002046F0(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x13F0), s32 *, 0x180));
    }
}

}
