#include "m2c_macros.h"

M2C_UNK InitAmb(s32, s32);                          /* extern */
s32 PvAllocAmb(M2C_UNK);                            /* extern */

void NewEmitter(s32 arg0) {
    InitAmb(PvAllocAmb(0x70), arg0);
}
