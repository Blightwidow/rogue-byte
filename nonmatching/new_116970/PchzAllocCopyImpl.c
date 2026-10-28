#include "m2c_macros.h"

M2C_UNK PvAllocCopyImpl(s32, s32, s32, s32);        /* extern */
s32 strlen(s32);                                    /* extern */

void PchzAllocCopyImpl(s32 arg0, s32 arg1, s32 arg2) {
    PvAllocCopyImpl(arg0, strlen(arg1) + 1, arg1, arg2);
}
