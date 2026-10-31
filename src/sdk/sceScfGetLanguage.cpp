typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_sceScfGetLanguage {
    /* 0x00 */ u32 sp0;                             /* inferred */
    /* 0x04 */ char pad4[0x1C];
};                                                  /* size = 0x20 */
#define sp0 (*(u32 *)(sp + 0x00))
M2C_UNK GetOsdConfigParam(s8 *);                  /* extern */
s32 func_0024A820();                                /* extern */
extern u8 D_002C8374;
u8 sceScfGetLanguage(void) {
    u8 result;
    s8 sp[0x10] __attribute__((aligned(16)));
    GetOsdConfigParam(sp);
    if (func_0024A820() != 0) {
        { result = D_002C8374; goto done; }
    }
    GetOsdConfigParam(sp);
    if ((sp0 >> 0xD) & 7) {
        { result = (sp0 >> 0x10) & 0x1F; goto done; }
    }
    return (sp0 >> 4) & 1;
done:
    return result;
}
}
