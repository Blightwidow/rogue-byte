#include "m2c_macros.h"

M2C_UNK ValidateSaveData(M2C_UNK *);                /* extern */
extern M2C_UNK B_003E0EA8;

s32 ValidateSaveSlot(void) {
    ValidateSaveData(&B_003E0EA8);
    return 0;
}
