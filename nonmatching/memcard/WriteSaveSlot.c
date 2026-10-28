#include "m2c_macros.h"

M2C_UNK BuildSlotFilePath(void *);                  /* extern */
M2C_UNK WriteMemcardFile(s32, void *, s32, M2C_UNK); /* extern */

void WriteSaveSlot(s32 arg0, s32 arg1) {
    char sp[0x400];
    BuildSlotFilePath(sp);
    WriteMemcardFile(arg0, sp, arg1, 0x5408);
}
