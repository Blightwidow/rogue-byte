typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_InsertSlEntryAfter {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
void AppendSlEntry(s8 *, s32);
void PrependSlEntry(s8 *, s32);
void InsertSlEntryAfter(s8 *arg0, s32 arg1, s32 arg2) {
    s32 offset;
    s32 *previous;
    if (arg1 == 0) {
        PrependSlEntry(arg0, arg2);
    } else if (arg1 == M2C_FIELD(arg0, s32 *, 4)) {
        AppendSlEntry(arg0, arg2);
    } else {
        offset = M2C_FIELD(arg0, s32 *, 8);
        previous = (s32 *)(arg1 + offset);
        *(s32 *)(arg2 + offset) = *previous;
        *previous = arg2;
    }
}
}
