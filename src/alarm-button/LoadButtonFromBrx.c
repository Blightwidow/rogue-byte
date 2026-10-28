#include "m2c_macros.h"

M2C_UNK LoadBtn(s32, s32);                          /* extern */
M2C_UNK CSo_LoadFromBrx();                            /* extern */

void LoadButtonFromBrx(s32 arg0) {
    CSo_LoadFromBrx();
    LoadBtn(arg0 + 0x150, arg0);
}
