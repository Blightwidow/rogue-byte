#include "m2c_macros.h"

M2C_UNK CRef_Destruct(void *);                      /* extern */
M2C_UNK RefGetGameSaveValue(void *, s32, M2C_UNK *); /* extern */
extern M2C_UNK B_003D4A60;
extern s32 B_003E0FB0;

s32 GetGameCoins(void) {
    char sp[0x400];
    M2C_UNK sp4;
    RefGetGameSaveValue(sp, B_003E0FB0, &B_003D4A60);
    CRef_Destruct(sp);
    return sp4;
}
