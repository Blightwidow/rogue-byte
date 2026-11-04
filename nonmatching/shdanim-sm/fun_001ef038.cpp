typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK RemoveGuardBusyGoal(s32);                   /* extern */

void func_001EF038(s8 *arg0) {
    s8 *var_a0;

    if (M2C_FIELD(arg0, s32 *, 0x1C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x1C) = 0;
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x10), 0x38) != 0) {
            RemoveGuardBusyGoal(M2C_FIELD(arg0, s32 *, 0x10));
        }
        var_a0 = M2C_FIELD(arg0, s8 **, 0x14);
        if (var_a0 != NULL) {
            do {
                M2C_FIELD(var_a0, s32 *, 0x20) = (s32) (M2C_FIELD(var_a0, s32 *, 0x20) - 1);
                var_a0 = M2C_FIELD(var_a0, s8 **, 0x14);
            } while (var_a0 != NULL);
        }
    }
}

}
