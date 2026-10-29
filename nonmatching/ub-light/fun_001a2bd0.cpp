typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001A2BD0 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 *sp4;                            /* inferred */
    /* 0x08 */ char pad8[0x18];
};                                                  /* size = 0x20 */

void func_001A2C48(s8 *, s32 **);              /* extern */
extern s32 B_002E1E54;

void func_001A2BD0(s32 arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 *sp4;

    if (arg0 == -1) {
        func_001A2C48(sp, &sp4);
        B_002E1E54 = *sp4;
        return;
    }
    B_002E1E54 = arg0;
}

}
