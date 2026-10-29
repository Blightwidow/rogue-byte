typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_vprintf {
    /* 0x000 */ char pad0[0x450];
};                                                  /* size = 0x450 */

s32 CchOstrmPrintf__FP5OSTRMPcT1(s8 *, s32, s32); /* extern */
M2C_UNK __5OSTRMi(s8 *, M2C_UNK);                 /* extern */
M2C_UNK func_0020D618(s8 *, M2C_UNK);             /* extern */

s32 vprintf(s32 arg0, s32 arg1) {
    s8 sp[0x420] __attribute__((aligned(16)));
    s32 temp_s0;

    __5OSTRMi(sp, -1);
    temp_s0 = CchOstrmPrintf__FP5OSTRMPcT1(sp, arg0, arg1);
    func_0020D618(sp, 2);
    return temp_s0;
}

}
