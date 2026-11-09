#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FFilterOxa(s32, s8 *);                        /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */

s32 func_0021FB18(s32 arg0, s8 *arg1) {
    if (FIsBasicDerivedFrom(M2C_FIELD(arg1, s32 *, 4), 0x59) != 0) {
        return 1;
    }
    return FFilterOxa(arg0, arg1);
}

}
