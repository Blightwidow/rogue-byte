typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_new_eh_context {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK __terminate(void);                        /* extern */
s8 *malloc(M2C_UNK);                              /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
s8 *new_eh_context(void) {
    s8 *temp_v0;
    temp_v0 = malloc(0x18);
    if (temp_v0 == NULL) {
        __terminate();
    }
    memset(temp_v0, 0, 0x18);
    M2C_FIELD(temp_v0, s8 **, 4) = (s8 *) (temp_v0 + 0x10);
    return temp_v0;
}
}
