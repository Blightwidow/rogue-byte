typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0017F6B0 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
struct Continuation { long value; } __attribute__((packed));
void CancelSwCallbacks(M2C_UNK *, s32, s8 *, long, s32);
extern M2C_UNK B_003DD490;
extern Continuation RO_002A5638;
void func_0017F6B0(s8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x184) = (s32) M2C_FIELD(arg0, s32 *, 0x180);
    if (M2C_FIELD(arg0, s32 *, 0x18C) != 0) {
        CancelSwCallbacks(&B_003DD490, 1, arg0, RO_002A5638.value, 0);
    }
}
}
