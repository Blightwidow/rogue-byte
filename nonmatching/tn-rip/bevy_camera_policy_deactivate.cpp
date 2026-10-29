typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void DeactivateCplcy();
s32 SetResetFlag__FP2CM(M2C_UNK *);
extern M2C_UNK B_002DDF40;

void bevy_camera_policy_deactivate(s8 *arg0, s8 *arg2) {
    s8 *temp_a1;
    s8 *temp_v1;

    DeactivateCplcy();
    if (M2C_FIELD(arg2, s32 *, 0xC) != 0) {
        SetResetFlag__FP2CM(&B_002DDF40);
    }
    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s8 **, 0x14);
    temp_v1 = M2C_FIELD(temp_a1, s8 **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, s8 *), 0x14)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x10), temp_a1);
    M2C_FIELD(arg0, s8 **, 0x10) = NULL;
}

}
