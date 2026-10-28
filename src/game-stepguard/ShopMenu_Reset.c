#include "m2c_macros.h"

M2C_UNK Menu_Reset();                               /* extern */
M2C_UNK ShopMenu_InitPage(s32);                     /* extern */

void ShopMenu_Reset(s32 arg0) {
    Menu_Reset();
    ShopMenu_InitPage(arg0);
}
