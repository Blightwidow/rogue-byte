typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024A7B0 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 func_00237EA8(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK sceClose(s32);                              /* extern */
M2C_UNK sceRead(s32, s8 *, M2C_UNK);                /* extern */
extern s8 D_002C8378;
extern M2C_UNK RO_002AC270;
s8 *func_0024A7B0(void) {
    s32 temp_v0;
    if (D_002C8378 == 0) {
        temp_v0 = func_00237EA8(&RO_002AC270, 1);
        if (temp_v0 >= 0) {
            sceRead(temp_v0, &D_002C8378, 0xE);
            sceClose(temp_v0);
        }
    }
    return &D_002C8378;
}
}
