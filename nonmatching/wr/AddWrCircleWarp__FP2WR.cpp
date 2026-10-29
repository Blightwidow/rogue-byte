typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s128 g_2a2da0;

void AddWrCircleWarp__FP2WR(s8 *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s8 *temp_a0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x54);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) (temp_v0 + 1);
    M2C_FIELD(arg0, s32 *, 0x6E0) = (s32) (M2C_FIELD(arg0, s32 *, 0x6E0) + 1);
    temp_a0 = arg0 + ((temp_v0 * 0xD0) + 0x60);
    M2C_FIELD(temp_a0, s32 *, 0) = 0;
    M2C_FIELD(temp_a0, s128 *, 0x10) = (s128) g_2a2da0;
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x5C);
    if (temp_v0_2 < 0) {
        temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x58);
        M2C_FIELD(temp_a0, s32 *, 4) = temp_v0_3;
        M2C_FIELD(arg0, s32 *, 0x5C) = (s32) M2C_FIELD(temp_a0, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_v0_3 + 1);
        M2C_FIELD(temp_a0, s32 *, 0x60) = 0;
        return;
    }
    M2C_FIELD(temp_a0, s32 *, 4) = temp_v0_2;
    M2C_FIELD(temp_a0, s32 *, 0x60) = 2;
    M2C_FIELD(arg0, s32 *, 0x5C) = -1;
}

}
