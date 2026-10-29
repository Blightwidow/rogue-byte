typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern M2C_UNK D_002C44E0;

void InvalidateXfSegment(s8 *arg0, s8 *arg1) {
    s16 temp_v1;
    s8 *temp_v0;

    temp_v1 = M2C_FIELD(arg1, s16 *, 0x98);
    switch (temp_v1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 13:
    case 14:
    case 15:
    case 16:
    case 20:
    case 21:
        break;
    default:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 17:
    case 18:
    case 19:
        M2C_FIELD(arg1, f32 *, 0x84) = -3.4028235e38f;
        M2C_FIELD(arg1, M2C_UNK **, 0x8C) = &D_002C44E0;
        M2C_FIELD(arg1, f32 *, 0x80) = -3.4028235e38f;
        M2C_FIELD(arg1, M2C_UNK **, 0x88) = &D_002C44E0;
        break;
    }
    M2C_FIELD(arg1, s16 *, 0x9A) = 0;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x17C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x178), 4, arg0);
    return;
}

}
