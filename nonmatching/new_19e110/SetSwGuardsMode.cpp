typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetSwGuardsMode {
    /* 0x00 */ char pad0[0xC0];
};                                                  /* size = 0xC0 */
s32 CploFindSwObjectsByClass(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetGuardMode(s32, s32);                     /* extern */
void SetSwGuardsMode(s32 arg1) {
    s8 sp[0x80] __attribute__((aligned(16)));
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_s1;
    temp_v0 = CploFindSwObjectsByClass(0x105, 0x38, 0);
    var_s1 = temp_v0;
    if (temp_v0 > 0) {
        var_s0 = (s32 *)(sp);
        do {
            temp_a0 = *var_s0;
            var_s0 += 4;
            var_s1 -= 1;
            SetGuardMode(temp_a0, arg1);
        } while (var_s1 != 0);
    }
}
}
