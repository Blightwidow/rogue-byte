typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_002418C8 {};                 /* size 0x0 */
M2C_UNK iSignalSema(...);                  /* extern */
extern s32 B_004502C0;
extern s32 D_002C6754;
extern s32 D_002C6760;
extern s32 D_002C6768;
extern s32 D_002C6774;
extern s32 D_002C67A0;
extern s32 D_002C67A4;
void func_002418C8(s32 *arg0, s64 arg_sp0, s64 arg_sp10) {
    D_002C67A0 = *arg0;
    D_002C67A4 = D_002C67A0;
    if (D_002C67A0 == 0xB) {
        D_002C67A0 = 0;
        D_002C6774 = 0;
        return;
    }
    iSignalSema(D_002C6768, 0xB);
    if ((D_002C6754 != 0) && (B_004502C0 != 0)) {
        iSignalSema(D_002C6760);
    } else {
        D_002C6774 = 0;
    }
    D_002C67A0 = 0;
}
}
