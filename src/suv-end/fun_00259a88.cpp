#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void LinkFrameNode(s8 *, M2C_UNK *);           /* extern */
M2C_UNK UnlinkFrameNode();                          /* extern */
extern M2C_UNK B_002DD2AC;

void func_00259A88(s8 *arg0) {
    UnlinkFrameNode();
    LinkFrameNode(arg0, &B_002DD2AC);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x8000);
}

}
