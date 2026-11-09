#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void CheckReg__4GIFSii(s8 *, M2C_UNK, M2C_UNK);        /* extern */

void PackAD__4GIFSll(s8 *arg0, s64 arg1, s64 arg2) {
    s8 *temp_v0;

    CheckReg__4GIFSii(arg0, 1, 0xE);
    temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(arg0, s8 **, 0xC) = (s8 *) (temp_v0 + 0x10);
    M2C_FIELD(temp_v0, s64 *, 0) = arg2;
    M2C_FIELD(temp_v0, s64 *, 8) = arg1;
}

}
