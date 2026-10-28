#include "m2c_macros.h"

s32 NPercentCompleteSaveData(M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK sprintf(s32, M2C_UNK *, s32);               /* extern */
extern M2C_UNK B_003D4A60;
extern M2C_UNK B_003E0EA8;

void GetPercentCompleteText(s32 arg0) {
    sprintf(arg0, "%d%%", NPercentCompleteSaveData(&B_003E0EA8, &B_003D4A60));
}
