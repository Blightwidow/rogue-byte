typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_OidFromCloneId {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 IcloneFromCloneId(...);                         /* extern */
s32 IsetFromCloneId(s32);                           /* extern */
extern s32 B_003E1398;
s32 OidFromCloneId(s32 arg0) {
    s8 *temp_s0;
    if (IcloneFromCloneId() == -1) {
        return -1;
    }
    temp_s0 = (s8 *)(B_003E1398 + (IsetFromCloneId(arg0) * 0x6C));
    return *(s32 *)((IcloneFromCloneId(arg0) * 4) + M2C_FIELD(temp_s0, s32 *, 0x18));
}
}
