typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern M2C_UNK RO_002AA6A1;

void UpperizePchz__FPc(u8 *arg0) {
    u8 *var_a2;
    u8 temp_a0;

    var_a2 = arg0;
    if (*var_a2 != 0) {
        do {
            temp_a0 = *var_a2;
            var_a2 += 1;
            *var_a2 = !(*(temp_a0 + &RO_002AA6A1) & 2) ? temp_a0 : (temp_a0 - 0x20);
        } while (*var_a2 != 0);
    }
}

}
