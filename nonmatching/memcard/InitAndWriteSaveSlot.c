#include "m2c_macros.h"

M2C_UNK BuildSlotFilePath(s32, s32, void *);        /* extern */
M2C_UNK ResetSaveKeepingOptions(s32, M2C_UNK);      /* extern */
M2C_UNK WriteMemcardFile(s32, void *, s32, M2C_UNK); /* extern */

void InitAndWriteSaveSlot(s32 arg0, s32 arg1) {
    char sp[0x400];
    ResetSaveKeepingOptions(arg1, 0);
    BuildSlotFilePath(arg0, arg1, sp);
    WriteMemcardFile(arg0, sp, arg1, 0x5408);
}
