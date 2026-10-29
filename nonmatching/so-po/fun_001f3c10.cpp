typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_001A4478(M2C_UNK *, M2C_UNK, s8 *);  /* extern */
extern M2C_UNK B_003DD490;

void func_001F3C10(s8 *arg0) {
    s8 *temp_a2;

    temp_a2 = M2C_FIELD(arg0, s8 **, 0x134);
    if ((temp_a2 != NULL) && (M2C_FIELD(temp_a2, s32 *, 0xC) != M2C_FIELD(&B_003DD490, s32 *, 0x3D60))) {
        func_001A4478(&B_003DD490, 0, temp_a2);
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x134), s32 *, 0xC) = (s32) M2C_FIELD(&B_003DD490, s32 *, 0x3D60);
    }
}

}
