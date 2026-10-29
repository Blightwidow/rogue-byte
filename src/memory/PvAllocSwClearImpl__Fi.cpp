typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PvAllocSwClearImpl__Fi {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
struct Saved { char bytes[8]; };
s32 PvAllocSwImpl__Fi(Saved *);
M2C_UNK memset(s32, M2C_UNK, s32);
s32 PvAllocSwClearImpl__Fi(s32 *arg0) {
    Saved saved = *(Saved *)arg0;
    s32 temp_v0 = PvAllocSwImpl__Fi(&saved);
    if (temp_v0 != 0) {
        memset(temp_v0, 0, *arg0);
    }
    return temp_v0;
}
}
