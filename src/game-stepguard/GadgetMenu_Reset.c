#include "m2c_macros.h"

M2C_UNK GadgetMenu_InitPage(s32);                   /* extern */
M2C_UNK Menu_Reset();                               /* extern */

void GadgetMenu_Reset(s32 arg0) {
    Menu_Reset();
    GadgetMenu_InitPage(arg0);
}
