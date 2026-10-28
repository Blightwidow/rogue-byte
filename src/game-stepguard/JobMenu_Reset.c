#include "m2c_macros.h"

M2C_UNK JobMenu_InitPage(s32);                      /* extern */
M2C_UNK Menu_Reset();                               /* extern */

void JobMenu_Reset(s32 arg0) {
    Menu_Reset();
    JobMenu_InitPage(arg0);
}
