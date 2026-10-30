typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FInvulnerableJt {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 FIsPoSwFocusBase(s32);                          /* extern */
s32 ZapFInvulnerable(s8 *);                  /* extern */
extern s32 B_003D4A54;
s32 FInvulnerableJt(s8 *arg0, s32 arg1) {
    s32 result;
    s32  var_v0 = 1;
    if (M2C_FIELD(arg0, s32 *, 0xF20) != 1) {
        if (M2C_FIELD(arg0, s32 *, 0x2DC) == 0x15) {
            return 1;
        }
        if ((B_003D4A54 == 0) || (var_v0 = 1, (FIsPoSwFocusBase(B_003D4A54) == 0))) {
            var_v0 = ZapFInvulnerable(arg0 + 0xDF0);
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        { result = var_v0; goto done; }
    }
    { result = var_v0; goto done; }
done:
    return result;
}
}
