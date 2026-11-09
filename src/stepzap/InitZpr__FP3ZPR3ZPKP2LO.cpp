#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void memset(s8 *, M2C_UNK, M2C_UNK);                   /* extern */

void InitZpr__FP3ZPR3ZPKP2LO(s8 *arg0, s32 arg1, s32 arg2) {
    memset(arg0, 0, 0x630);
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
}

}
