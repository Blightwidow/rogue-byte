typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 GRandInRange(f32);                         /* extern */
extern f32 g_2dded0;

void func_00179E80(s8 *arg0) {
    f32 temp_f12;
    f32 temp_f20;
    s8 *temp_v0;

    if (!(M2C_FIELD(arg0, f32 *, 0x30) < 3.4028235e38f)) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0x10);
        temp_f12 = M2C_FIELD(temp_v0, f32 *, 0x2CC);
        if (temp_f12 != 3.4028235e38f) {
            temp_f20 = g_2dded0;
            M2C_FIELD(arg0, f32 *, 0x30) = (f32) (temp_f20 + GRandInRange(temp_f12));
        } else {
            M2C_FIELD(arg0, f32 *, 0x30) = 3.4028235e38f;
        }
    }
}

}
