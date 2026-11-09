#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
struct Bytes8 { char bytes[8]; };
extern "C" {
void CopyAb__FPvT0Ui(s32, s32, s32);
s32 PvAllocSwImpl__Fi(Bytes8 *);
s32 PvAllocSwCopyImpl__FiPv(s32 *arg0, s32 arg1) {
    Bytes8 copy = *(Bytes8 *)arg0;
    s32 result = PvAllocSwImpl__Fi(&copy);
    if (result != 0) {
        CopyAb__FPvT0Ui(result, arg1, *arg0);
    }
    return result;
}
}
