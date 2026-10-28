#include "m2c_macros.h"

s32 NPercentCompleteSaveData(M2C_UNK *, M2C_UNK *); /* extern */
s32 NewEmitter(M2C_UNK);                            /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
M2C_UNK SetGadgetAcquired(M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK B_003D4A60;
extern M2C_UNK B_003E0EA8;

void OnCodeGrantGadgetIf100Percent(void) {
    if (NPercentCompleteSaveData(&B_003E0EA8, &B_003D4A60) >= 0x64) {
        SetGadgetAcquired(0x1F, 1);
        return;
    }
    SetEmitterUnpositioned(NewEmitter(0x3E), 0);
}
