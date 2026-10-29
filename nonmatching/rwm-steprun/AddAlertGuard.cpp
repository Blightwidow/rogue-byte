typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void SetAlertState(s8 *, M2C_UNK);                     /* extern */
extern f32 g_2dded0;

void AddAlertGuard(s8 *arg0, s32 arg1) {
    s32 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x28) == 0) {
        M2C_FIELD(arg0, f32 *, 0) = (f32) g_2dded0;
        SetAlertState(arg0, 0);
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0x2C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (temp_v1 + 1);
}

}
