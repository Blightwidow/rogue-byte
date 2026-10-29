typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001B9DB8 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
struct Aseg;
struct Vt { char pad0[0xE8]; short offset; short pad; void (*method)(s8 *, s32); };
struct Aseg { char pad0[0xC]; Vt *vtable; char pad1[0x28 - 0x10]; u64 flags; };
void ApplyAseg(s32, Aseg *, s32, s32, f32, f32);
void func_001B9DB8(s8 *arg0, s32 arg1) {
    Aseg *aseg = M2C_FIELD(arg0, Aseg **, 0x1AD8);
    if (((int)(aseg->flags >> 0x3C) & 1) == 0) {
        aseg->vtable->method((s8 *)aseg + aseg->vtable->offset, arg1);
        ApplyAseg(M2C_FIELD(arg0, s32 *, 0x1ADC), M2C_FIELD(arg0, Aseg **, 0x1AD8), 0, 0, 0.0f, 1.0f);
    }
}
}
