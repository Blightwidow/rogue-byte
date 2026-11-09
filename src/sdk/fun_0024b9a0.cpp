#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024B9A0 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK func_00254988(s32);                         /* extern */
s32 func_0024B9A0(s8 *arg0) {
    func_00254988(M2C_FIELD(arg0, s32 *, 0x40) + 0x68);
    return 1;
}
}
