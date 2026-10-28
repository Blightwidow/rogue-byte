#include "m2c_macros.h"

M2C_UNK QueueSwCallbackOnce(M2C_UNK *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001A6178();                            /* extern */
extern M2C_UNK B_003DD490;

void ClonePool_AddLoGrfEntry(void *arg0) {
    func_001A6178();
    if (M2C_FIELD(arg0, s32 *, 0xE4) == 0) {
        M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A77C7)($v0) */);
        QueueSwCallbackOnce(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A77C0)($v0) */), 0);
    }
}
