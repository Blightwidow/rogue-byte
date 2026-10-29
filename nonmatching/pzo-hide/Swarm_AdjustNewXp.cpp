typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FIsBasicDerivedFrom(s32, M2C_UNK);
void func_0017F1A0();
void func_0017F5B0(s8 *, s32);

void Swarm_AdjustNewXp(s8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;

    func_0017F1A0();
    if (M2C_FIELD(arg0, s32 *, 0x188) != 0) {
        temp_s0 = M2C_FIELD((arg1 + ((1 - arg2) << 6)), s32 *, 0xC);
        if (FIsBasicDerivedFrom(temp_s0, 0x47) != 0) {
            func_0017F5B0(arg0, temp_s0);
        }
    }
}

}
