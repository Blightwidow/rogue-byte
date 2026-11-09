#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK Mount_SetState(s32, M2C_UNK);               /* extern */

void func_00181728(s8 *arg0) {
    s8 *temp_v1;

    Mount_SetState(M2C_FIELD(arg0, s32 *, 0x1C8), 1);
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(arg0, s32 *, 0x1C8) = 0;
    M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 6, 0, 0, 0, 0);
}

}
