#include "m2c_macros.h"

M2C_UNK CreateMemcardThread__FP7MEMCARDii(void *, M2C_UNK); /* extern */
M2C_UNK SnapshotSaveData(M2C_UNK *, s32);           /* extern */
M2C_UNK StoreAudioModeInSave();                     /* extern */
extern M2C_UNK B_003E0EA8;

void func_001ABD40(void *arg0) {
    StoreAudioModeInSave();
    SnapshotSaveData(&B_003E0EA8, M2C_FIELD(arg0, s32 *, 0xFD50));
    M2C_ERROR(/* unknown instruction: ldl $a1, %lo(RO_002A6C97)($v0) */);
    CreateMemcardThread__FP7MEMCARDii(arg0 + 0xFD5C, M2C_ERROR(/* unknown instruction: ldr $a1, %lo(RO_002A6C90)($v0) */));
}
