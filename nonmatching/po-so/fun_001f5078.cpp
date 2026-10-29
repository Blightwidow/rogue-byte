typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK WakeXf(s8 *, s32);                        /* extern */

void func_001F5078(s8 *arg0) {
    s8 *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0xEC) != 0) {
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK), 0x17C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x178), 4);
        if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
            WakeXf(arg0, M2C_FIELD(arg0, s32 *, 0x58));
            WakeXf(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
        }
    }
}

}
