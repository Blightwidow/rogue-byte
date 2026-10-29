typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern f32 D_FLT_002BFB20;
extern M2C_UNK32 D_FLT_002BFB24;

void AdjustJtZapNewXp(s8 *arg0, s8 *arg1) {
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u32 *, 4);
    switch (temp_v1) {
    case 4:
    case 12:
        M2C_FIELD(arg1, f32 *, 0x94) = (f32) D_FLT_002BFB20;
        M2C_FIELD(arg1, M2C_UNK32 *, 0x98) = 0;
        return;
    default:
    case 1:
    case 2:
    case 3:
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
        M2C_FIELD(arg1, f32 *, 0x94) = (f32) D_FLT_002BFB20;
        M2C_FIELD(arg1, M2C_UNK32 *, 0x98) = (M2C_UNK32) D_FLT_002BFB24;
        /* fallthrough */
    case 0:
    case 6:
    case 7:
        return;
    }
}

}
