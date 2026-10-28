#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK QueueSwCallback(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void PostRhythmLoad(s32 arg0) {
    PostLoLoad();
    M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A5017)($v0) */);
    QueueSwCallback(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A5010)($v0) */), 0);
}
