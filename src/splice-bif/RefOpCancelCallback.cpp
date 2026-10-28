#include "m2c_macros.h"

M2C_UNK CancelSwTimedCall(M2C_UNK *, s32);          /* extern */
M2C_UNK SetTag__4CRef4TAGK(s32, M2C_UNK);           /* extern */
extern M2C_UNK B_003DD490;

s32 RefOpCancelCallback(s32 arg0, s32 arg1, void *arg2) {
    CancelSwTimedCall(&B_003DD490, M2C_FIELD(arg2, s32 *, 4));
    SetTag__4CRef4TAGK(arg0, 0x24);
    return arg0;
}
