#include "m2c_macros.h"

M2C_UNK LinkSidebagNode(void *, M2C_UNK *);         /* extern */
M2C_UNK UnlinkSidebagNode();                        /* extern */
extern M2C_UNK B_002DD2CC;

void func_00258178(void *arg0) {
    UnlinkSidebagNode();
    LinkSidebagNode(arg0, &B_002DD2CC);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x8000);
}
