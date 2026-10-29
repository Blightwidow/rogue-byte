typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_001EEFC0(s8 *);                      /* extern */
M2C_UNK func_001EF038();                            /* extern */
extern f32 g_2dded0;

void func_00146E18(s8 *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x30);
    if (arg1 != temp_v1) {
        if ((temp_v1 < 5) && (temp_v1 >= 2)) {
            func_001EF038();
        }
        M2C_FIELD(arg0, s32 *, 0x30) = arg1;
        M2C_FIELD(arg0, f32 *, 0x34) = (f32) g_2dded0;
        if ((arg1 < 5) && (arg1 >= 2)) {
            func_001EEFC0(arg0);
        }
    }
}

}
