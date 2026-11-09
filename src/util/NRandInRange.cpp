#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 NRandRaw();                                     /* extern */

s32 NRandInRange(s32 arg0, s32 arg1) {
    s32 raw = NRandRaw();
    s32 below = arg0 - 1;
    return arg0 + (raw % (arg1 - below));
}

}
