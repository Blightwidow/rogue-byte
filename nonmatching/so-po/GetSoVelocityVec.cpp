typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s128 VelocityXfAtPos(s8 *, M2C_UNK, s128);        /* extern */
extern s128 g_2a2dd0;

s128 GetSoVelocityVec(s8 *arg0) {
    s8 *temp_a0;

    temp_a0 = M2C_FIELD(arg0, s8 **, 0x58);
    if (temp_a0 != NULL) {
        if (M2C_FIELD(temp_a0, s32 *, 0x94) == 1) {
            return VelocityXfAtPos(temp_a0, 0, M2C_FIELD(temp_a0, s128 *, 0x70));
        }
        goto block_4;
    }
block_4:
    return g_2a2dd0;
}

}
