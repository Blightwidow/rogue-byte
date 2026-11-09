#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetLightFExcludeDynamicObjects {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
void func_001A3B38(s8 *);                      /* extern */
void SetLightFExcludeDynamicObjects(s8 *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x15C)) {
        func_001A3B38(arg0);
        M2C_FIELD(arg0, s32 *, 0x15C) = arg1;
        if (arg1 != 0) {
            M2C_FIELD(arg0, s32 *, 0x160) = 0;
        }
        func_001A3B38(arg0);
    }
}
}
