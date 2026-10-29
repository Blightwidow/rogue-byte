typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetHubAllowedStates {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */

M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK StepHubState(s32, M2C_UNK);                 /* extern */
M2C_UNK func_002013D8(s8 *, M2C_UNK, M2C_UNK);    /* extern */

void SetHubAllowedStates(s32 arg0) {
    s8 sp[0x30] __attribute__((aligned(16)));
    func_002013D8(sp, 6, 6);
    CRef_Destruct(sp);
    StepHubState(arg0, 0);
}

}
