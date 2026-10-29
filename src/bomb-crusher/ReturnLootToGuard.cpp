typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ReturnLootToGuard {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
s32 FIsLoInWorld(s32);                              /* extern */
M2C_UNK SetLootState(...);              /* extern */
void ReturnLootToGuard(s8 *arg0) {
    s32 temp_s1;
    s32 temp_s2;
    if (M2C_FIELD(arg0, s32 *, 0x184) == 5) {
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x15C);
        M2C_FIELD(arg0, s32 *, 0x15C) = 0;
        temp_s2 = M2C_FIELD(arg0, s32 *, 0x158);
        SetLootState(arg0, 0);
        if ((temp_s1 != 0) && (FIsLoInWorld(temp_s1) != 0)) {
            M2C_FIELD(arg0, s32 *, 0x15C) = temp_s1;
            M2C_FIELD(arg0, s32 *, 0x158) = temp_s2;
            SetLootState(arg0, 1);
        }
    }
}
}
