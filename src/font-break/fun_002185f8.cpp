#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_002185F8 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK QueueSpriteInstanceSlots(s32, s32, s32);     /* extern */
void func_002185F8(s8 *arg0, s32 arg1, s32 arg2) {
    s16 temp_v0;
    temp_v0 = M2C_FIELD(((arg1 * 0x18) + M2C_FIELD(arg0, s32 *, 8)), s16 *, 8);
    if (temp_v0 >= 0) {
        QueueSpriteInstanceSlots(M2C_FIELD(arg0, s32 *, 4) + (temp_v0 * 0x18), arg1, arg2);
    }
}
}
