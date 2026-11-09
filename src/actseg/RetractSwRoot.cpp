#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void RemoveDlEntry(s8 *, s32);
s32 AppendDlEntry(s8 *, s32);

void RetractSwRoot(s8 *arg0, s32 arg1) {
    s8 *temp_s2;

    temp_s2 = arg0 + 0x20;
    RemoveDlEntry(temp_s2, arg1);
    if (M2C_FIELD(arg0, s32 *, 0x39A4) == 0) {
        M2C_FIELD(arg0, s32 *, 0x39A4) = arg1;
    }
    AppendDlEntry(temp_s2, arg1);
}

}
