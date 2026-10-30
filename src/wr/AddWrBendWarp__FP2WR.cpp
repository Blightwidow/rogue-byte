typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern s128 g_2a2db0;
extern s128 g_2a2dc0;

void AddWrBendWarp__FP2WR(s8 *arg0) {
    s32 temp_v0;
    s8 *temp_a1;

    struct BW { u8 b[0xD0]; };
    temp_a1 = (s8 *)&((BW *)(arg0 + 0x60))[M2C_FIELD(arg0, s32 *, 0x54)++];
    M2C_FIELD(arg0, s32 *, 0x6E0)++;
    M2C_FIELD(temp_a1, s32 *, 0) = 1;
    M2C_FIELD(temp_a1, s128 *, 0x10) = (s128) g_2a2db0;
    M2C_FIELD(temp_a1, s128 *, 0x20) = (s128) g_2a2dc0;
    M2C_FIELD(temp_a1, f32 *, 0x38) = 0.5f;
    M2C_FIELD(temp_a1, f32 *, 0x88) = 0.5f;
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + 1);
}

}
