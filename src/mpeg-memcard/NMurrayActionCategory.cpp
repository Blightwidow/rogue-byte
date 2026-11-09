#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 func_00143C78();

s32 NMurrayActionCategory(s8 *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x204) != 0) {
        return 0;
    }
    if ((M2C_FIELD(arg0, s32 *, 0x13D8) == 1) || (M2C_FIELD(arg0, s32 *, 0x13D0) == 0x14)) {
        return 0;
    }
    return func_00143C78();
}

}
