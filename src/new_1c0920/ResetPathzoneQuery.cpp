#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */

void ResetPathzoneQuery(s8 *arg0, s8 *arg1) {
    s32 temp_v0;
    s32 temp_v1;

    memset(arg1, 0, 0x40);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x100) - 2;
    M2C_FIELD(arg1, s32 *, 0x28) = temp_v1;
    M2C_FIELD(arg1, s32 *, 0x24) = temp_v1;
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x100) - 2;
    M2C_FIELD(arg1, s32 *, 0x20) = -1;
    M2C_FIELD(arg1, s32 *, 0x30) = temp_v0;
    M2C_FIELD(arg1, s32 *, 0x2C) = temp_v0;
}

}
