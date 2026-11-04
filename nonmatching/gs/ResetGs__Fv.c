#include "m2c_macros.h"

M2C_UNK iSignalSema(s32);                           /* extern */
extern s32 B_002DFB50;
extern s32 B_002DFB54;

s32 ResetGs__Fv(void) {
    if ((B_002DFB54 != 0) && (*(s64 *)0x12001000 & 2)) {
        B_002DFB54 = 0;
        iSignalSema(B_002DFB50);
    }
    M2C_SYNC();
    M2C_ERROR(/* unknown instruction: ei */);
    return -1;
}
