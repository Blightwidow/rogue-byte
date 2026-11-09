#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GIFS_ListXYZ {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
M2C_UNK CheckReg__4GIFSii(s8 *, M2C_UNK, M2C_UNK);        /* extern */
void GIFS_ListXYZ(s8 *arg0, s32 arg1, s32 arg2, s64 arg3) {
    s64 *temp_v1;
    CheckReg__4GIFSii(arg0, 0, 5);
    temp_v1 = M2C_FIELD(arg0, s64 **, 0xC);
    M2C_FIELD(arg0, s64 **, 0xC) = (s64 *) (temp_v1 + 1);
    *temp_v1 = arg1 | (arg2 << 0x10) | (arg3 << 0x20);
}
}
