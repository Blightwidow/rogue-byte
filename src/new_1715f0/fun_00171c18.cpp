typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */

void func_00171C18(s8 *arg0, s8 *arg1) {
    s32 *temp_v1;
    s32 temp_a2;

    temp_a2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xF80);
    if (temp_a2 == -1) {
        temp_v1 = M2C_FIELD(arg0, s32 **, 0x38);
        M2C_FIELD(arg1, s32 **, 0) = temp_v1;
        M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
        if (temp_v1 != NULL) {
            if (*temp_v1 == 6) {
                M2C_FIELD(arg1, f32 *, 8) = (f32) M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x18), f32 *, 0x38);
            }
        }
    } else if (temp_a2 >= -1) {
        if (temp_a2 < 2) {
            memset(arg1, 0, 0xC);
        }
    }
}

}
