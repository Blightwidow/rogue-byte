typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GoalStack_AllocGoals {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */

s32 CbGoalMax();                                    /* extern */
s32 PvAllocSwImpl__Fi(s8 *, s32, s32);            /* extern */

void GoalStack_AllocGoals(s32 arg0) {
    s8 sp[0x50] __attribute__((aligned(16)));
    s32 *var_s0;
    u32 var_s1;

    var_s0 = (s32 *)(arg0 + 8);
    var_s1 = 0;
    do {
        var_s1 += 1;
        *var_s0 = PvAllocSwImpl__Fi(sp, CbGoalMax(), 0x10);
        var_s0 += 1;
    } while (var_s1 < 8U);
}

}
