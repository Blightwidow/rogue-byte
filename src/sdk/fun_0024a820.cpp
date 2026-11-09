#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024A820 {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
M2C_UNK func_0024A7B0();                            /* extern */
extern M2C_UNK D_002C8378;
s32 func_0024A820(void) {
    if (M2C_FIELD(&D_002C8378, s8 *, 0) == 0) {
        func_0024A7B0();
    }
    return M2C_FIELD(&D_002C8378, s8 *, 4) == 0x54;
}
}
