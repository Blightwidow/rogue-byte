#include "m2c_macros.h"

s32 InitStreamAmb(s32, s32, s32);                   /* extern */
s32 PvAllocStreamAmb(M2C_UNK);                      /* extern */

s32 NewStreamAmb(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        return InitStreamAmb(PvAllocStreamAmb(0x3C0), arg0, arg1);
    }
    return 0;
}
