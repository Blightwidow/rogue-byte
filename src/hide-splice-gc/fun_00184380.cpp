#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00184380 {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
s32 func_001A6AF8(s8 *, s32);             /* extern */
s32 func_00184380(s8 *arg0, s8 *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0xF4) != M2C_FIELD(arg0, s32 *, 0x19C)) {
        return 1;
    }
    return func_001A6AF8(arg1, M2C_FIELD(arg0, s32 *, 0x180));
}
}
