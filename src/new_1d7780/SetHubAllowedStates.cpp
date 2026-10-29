typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
void CRef_Destruct(s8 *);
void StepHubState(s8 *, s32);
void func_002013D8(s8 *, s32, s32, s32, s8 *, s8 *);

void SetHubAllowedStates(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    func_002013D8(sp, arg1, 6, 6, arg0 + 0x220, arg0 + 0x224);
    CRef_Destruct(sp);
    StepHubState(arg0, 0);
}

}
