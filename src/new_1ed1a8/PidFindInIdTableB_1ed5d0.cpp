typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PidFindInIdTableA_1ed5d0 {};      /* size 0x0 */
extern s32 **B_003DD018;
s32 *PidFindInIdTableA_1ed5d0(s32 arg0) {
    s32 index;
    s32 *entry;
    if (B_003DD018 == 0) {
        return NULL;
    }
    index = arg0 % 16381;
    for (;;) {
        entry = B_003DD018[index];
        if (entry == NULL || *entry == arg0) {
            return entry;
        }
        index = (index + 1) % 16381;
    }
}
}
