#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
s32 FIgnoreSoIntersection();                        /* extern */
s32 IMax(s32, M2C_UNK, s8 *, s32);                /* extern */

s32 FIgnoreBombIntersection(s8 *arg0, s8 *arg1) {
    s32 var_a3;
    s8 *temp_a2;

    var_a3 = FIgnoreSoIntersection();
    temp_a2 = M2C_FIELD(arg0, s8 **, 0x200);
    if (*M2C_FIELD(arg1, s32 **, 0x14) == *M2C_FIELD(temp_a2, s32 **, 0x14)) {
        var_a3 = IMax(var_a3, 1, temp_a2, var_a3);
    }
    return var_a3;
}

}
