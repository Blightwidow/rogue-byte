typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00241B18 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK DeleteSema(s32);                            /* extern */
M2C_UNK SignalSema(s32);                            /* extern */
s32 func_00239450();                                /* extern */
M2C_UNK func_002394A0();                            /* extern */
M2C_UNK func_0023AE20(M2C_UNK);                     /* extern */
extern s32 D_002C6754;
extern s32 D_002C6760;
extern s32 D_002C6768;
extern s32 D_002C676C;
extern s32 D_002C6770;
extern s32 D_002C67A0;
void func_00241B18(void) {
    s32 temp_s0;
    if (D_002C6754 != 0) {
        D_002C67A0 = -1;
        SignalSema(D_002C6760);
    }
    DeleteSema(D_002C6768);
    DeleteSema(D_002C676C);
    DeleteSema(D_002C6770);
    DeleteSema(D_002C6760);
    temp_s0 = func_00239450();
    func_0023AE20(0x80000012);
    if (temp_s0 != 0) {
        func_002394A0();
    }
}
}
