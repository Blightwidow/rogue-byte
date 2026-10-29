typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001CBF90 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */

M2C_UNK RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(M2C_UNK *, M2C_UNK, s8 *, s32); /* extern */
extern M2C_UNK B_002DDF40;
extern s32 g_2f7900;

void func_001CBF90(s8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x1010) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x1010) = arg1;
        if (arg1 != 0) {
            SetCmPolicy__FP2CM3CPPP5CPLCYP2SOPv(&B_002DDF40, 6, (s8 *)(&B_002DDF40 + 0x600), g_2f7900);
        } else {
            RevokeCmPolicy__FP2CMi3CPPP5CPLCYP2SOPv(&B_002DDF40, 1, 6, 0);
        }
    }
}

}
