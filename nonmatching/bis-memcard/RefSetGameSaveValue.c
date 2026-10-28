#include "m2c_macros.h"

M2C_UNK RefSetSaveValue(M2C_UNK *, s32, s32);       /* extern */
extern M2C_UNK B_003E0EA8;

s32 RefSetGameSaveValue(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    RefSetSaveValue(&B_003E0EA8, arg1, arg2);
    return arg0;
}
