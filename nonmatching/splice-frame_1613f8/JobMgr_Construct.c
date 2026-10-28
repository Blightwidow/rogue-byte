#include "m2c_macros.h"

M2C_UNK OnDifficultyGameLoad__FP10DIFFICULTY(M2C_UNK *); /* extern */
M2C_UNK ResetSaveKeepingOptions(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK memset(M2C_UNK, M2C_UNK);                   /* extern */
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003D4A60;
extern s32 g_2e1e00;

void JobMgr_Construct(void *arg0) {
    memset(0, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x10) = -1;
    M2C_FIELD(arg0, s32 *, 0x14) = -1;
    M2C_FIELD(arg0, s32 *, 0x18) = -1;
    ResetSaveKeepingOptions(&B_003D4A60, 0);
    OnDifficultyGameLoad__FP10DIFFICULTY(&B_002DE578);
    g_2e1e00 = 0;
}
