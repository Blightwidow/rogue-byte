typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s32 D_002BE8AC;

void Swarm_AddGroup(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    u32 temp_a0;
    s8 *temp_v0;

    temp_a0 = M2C_FIELD(arg0, u32 *, 0x1C8);
    if (temp_a0 < 4U) {
        M2C_FIELD(arg0, u32 *, 0x1C8) = (u32) (temp_a0 + 1);
        temp_v0 = arg0 + ((temp_a0 * 0x30) + 0x1CC);
        M2C_FIELD(temp_v0, s32 *, 0x1C) = (s32) D_002BE8AC;
        M2C_FIELD(temp_v0, s32 *, 4) = arg2;
        M2C_FIELD(temp_v0, s32 *, 8) = arg3;
        M2C_FIELD(temp_v0, s32 *, 0) = arg1;
        M2C_FIELD(temp_v0, f32 *, 0x2C) = -1.0f;
        M2C_FIELD(temp_v0, f32 *, 0x20) = fparg0;
    }
}

}
