typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern M2C_UNK D_002BF670;

void ResetJtDynamicTunnel__FP2JT(s8 *arg0) {
    s8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 **, 0x68);
    M2C_FIELD(temp_v0, s32 *, 0x164) = 5;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x114) = &D_002BF670;
    M2C_FIELD(temp_v0, s32 *, 0x168) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x128) = 3;
    M2C_FIELD(temp_v0, s32 *, 0x140) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x100) = 0;
    M2C_FIELD(temp_v0, s32 *, 0xFC) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x108) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x10C) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x110) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x120) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x124) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x130) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x16C) = 0;
}

}
