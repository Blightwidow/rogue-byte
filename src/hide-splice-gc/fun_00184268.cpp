#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
M2C_UNK func_00183F08();                            /* extern */

void func_00184268(s8 *arg0) {
    func_00183F08();
    M2C_FIELD(arg0, s32 *, 0x184) = -1;
    M2C_FIELD(arg0, s32 *, 0x18C) = -1;
    M2C_FIELD(arg0, s32 *, 0x194) = -1;
    M2C_FIELD(arg0, s32 *, 0x19C) = -1;
    M2C_FIELD(arg0, s32 *, 0xF0) = -1;
    M2C_FIELD(arg0, s32 *, 0xFC) = 4;
}

}
