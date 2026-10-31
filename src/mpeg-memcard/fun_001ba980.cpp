typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001BA980 {
    /* 0x00 */ char pad0[0xA0];
};                                                  /* size = 0xA0 */
M2C_UNK GoalBrain_SetCommand(s32, s8 *);          /* extern */
s32 func_00205458(s8 *, M2C_UNK);            /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
void func_001BA980(s8 *arg0, s32 arg1) {
    s8 sp[0x70] __attribute__((aligned(16)));
    s32 temp_v0;
    memset(arg0 + 0x1090, 0, 0xC);
    M2C_FIELD(arg0, s32 *, 0x108C) = arg1;
    memset(sp, 0, 0x70);
    *(s32 *)sp = 0xF;
    temp_v0 = func_00205458(arg0, 0x9C);
    if (temp_v0 != 0) {
        GoalBrain_SetCommand(temp_v0, sp);
    }
}
}
