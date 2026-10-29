typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CbFill__10CByteQueueiPUc {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

s32 CbFill__10CByteQueueiP11CQueueInput(s32, s8 *, M2C_UNK *, s32, s32, s32, s32); /* extern */
extern M2C_UNK D_002CBE20;

s32 CbFill__10CByteQueueiPUc(s32 arg1, s32 arg2) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s32 var_v0;

    var_v0 = 0;
    if (arg1 != 0) {
        var_v0 = CbFill__10CByteQueueiP11CQueueInput(arg1, sp, &D_002CBE20, arg2, arg1, 0, arg1);
    }
    return var_v0;
}

}
