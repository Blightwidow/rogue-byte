typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_002185F8 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK QueueSpriteInstanceSlots(s32, s32);     /* extern */
void func_002185F8(s8 *arg0, s32 arg1) {
    s16 temp_v0;
    temp_v0 = M2C_FIELD(((arg1 * 0x18) + M2C_FIELD(arg0, s32 *, 8)), s16 *, 8);
    if (temp_v0 >= 0) {
        QueueSpriteInstanceSlots(M2C_FIELD(arg0, s32 *, 4) + (temp_v0 * 0x18), arg1);
    }
}
}
