#include "m2c_macros.h"

M2C_UNK EnsureAsegBlendDynamic(M2C_UNK, M2C_UNK, s32); /* extern */

void PostJtLoadSwing(s32 arg0, s32 arg1, s32 *arg2) {
    M2C_UNK sp0;
    EnsureAsegBlendDynamic(0xC, 3, arg1);
    if (arg2 != NULL) {
        *arg2 = sp0;
    }
}
