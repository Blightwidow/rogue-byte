typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Chaser_SetStateAngleRanges {};    /* size 0x0 */
struct Saved { char bytes[8]; };
struct Range { int pad0; int enabled; char pad1[0x10]; Saved minimum; Saved maximum; };
void Chaser_SetStateAngleRanges(char *arg0, u32 arg1, Saved *arg2, Saved *arg3) {
    if (arg1 < 5U) {
        Range *range = (Range *)(arg0 + 0x270) + arg1;
        range->enabled = 1;
        range->minimum = *arg2;
        range->maximum = *arg3;
    }
}
}
