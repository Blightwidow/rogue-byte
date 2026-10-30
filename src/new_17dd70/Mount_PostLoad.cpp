typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK SetXfKind(s8 *, s32, M2C_UNK);            /* extern */
void func_0017F138();                            /* extern */
M2C_UNK func_0017F408(s8 *, M2C_UNK, s8 *);     /* extern */
M2C_UNK func_0017F770(s8 *);                      /* extern */

typedef void (*Fn2)(s8 *, int);
void Mount_PostLoad(s8 *arg0) {
    func_0017F138();
    s8 *vtable = M2C_FIELD(arg0, s8 **, 0xC);
    s16 offset = M2C_FIELD(vtable, s16 *, 0x278);
    Fn2 method = M2C_FIELD(vtable, Fn2 *, 0x27C);
    method(arg0 + offset, 0);
    SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x58), 2);
    SetXfKind(arg0, M2C_FIELD(arg0, s32 *, 0x5C), 2);
    func_0017F770(arg0);
    func_0017F408(arg0, 5, arg0 + 0x1C8);
}
}
