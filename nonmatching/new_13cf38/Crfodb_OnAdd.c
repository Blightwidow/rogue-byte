#include "m2c_macros.h"

M2C_UNK AttachPt_OnAdd();                           /* extern */
M2C_UNK QueueSwCallbackOnce(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void Crfodb_OnAdd(s32 arg0) {
    AttachPt_OnAdd();
    M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A4BB7)($v0) */);
    QueueSwCallbackOnce(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A4BB0)($v0) */), 0);
}
