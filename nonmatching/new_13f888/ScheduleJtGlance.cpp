typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 GRandInRange(f32, f32);                         /* extern */
extern f32 g_2dded0;

void ScheduleJtGlance(s8 *arg0) {
    f32 temp_f20;
    f32 var_f12;
    f32 var_f13;

    if (M2C_FIELD(arg0, s32 *, 0x1148) != 0) {
        var_f12 = M2C_FIELD(arg0, f32 *, 0x1138);
        var_f13 = M2C_FIELD(arg0, f32 *, 0x113C);
    } else {
        var_f13 = M2C_FIELD(arg0, f32 *, 0x1144);
        var_f12 = M2C_FIELD(arg0, f32 *, 0x1140);
    }
    temp_f20 = g_2dded0;
    M2C_FIELD(arg0, f32 *, 0x114C) = (f32) (temp_f20 + GRandInRange(var_f12, var_f13));
}

}
