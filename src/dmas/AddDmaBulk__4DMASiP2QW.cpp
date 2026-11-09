#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void CopyAqw__FPvT0i(s32, s32, s32);

void AddDmaBulk__4DMASiP2QW(void *arg0, s32 arg1, s32 arg2) {
    CopyAqw__FPvT0i(M2C_FIELD(arg0, s32 *, 0xC), arg2, arg1);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + (arg1 * 0x10));
}

}
