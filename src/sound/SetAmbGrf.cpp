typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s32 ActivateAmb(s8 *, s32, s32);
s32 DeactivateAmb(s8 *, s32, s32);

void SetAmbGrf(s8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    u16 temp_v0;
    s32 temp_a2;

    temp_a1 = arg1 & 0xFFFF;
    temp_a2 = (u16) arg2 & temp_a1;
    temp_v0 = (M2C_FIELD(arg0, u16 *, 0x50) & ~temp_a1) | temp_a2;
    M2C_FIELD(arg0, u16 *, 0x50) = temp_v0;
    if (temp_v0 != 0) {
        ActivateAmb(arg0, temp_a1, temp_a2);
        return;
    }
    DeactivateAmb(arg0, temp_a1, temp_a2);
}

}
