typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK RequestTransition(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK bevy_jobs_162e38(s32);                      /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A3928;

void func_001B09A8(s8 *arg0) {
    RequestTransition(&B_003DD490, &RO_002A3928, 0x189, -1, 0x80, -1);
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B0C) != 0) {
        bevy_jobs_162e38(M2C_FIELD(&B_003DD490, s32 *, 0x3B0C));
    }
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) | 2);
    }
}

}
