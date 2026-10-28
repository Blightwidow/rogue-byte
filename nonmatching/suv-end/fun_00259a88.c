#include "m2c_macros.h"

M2C_UNK LinkFrameNode(void *, M2C_UNK *);           /* extern */
M2C_UNK UnlinkFrameNode();                          /* extern */
extern M2C_UNK B_002DD2AC;

void func_00259A88(void *arg0) {
    UnlinkFrameNode();
    LinkFrameNode(arg0, &B_002DD2AC);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x8000);
}
