#include "m2c_macros.h"

M2C_UNK GadgetMenu_SetPage(s32, M2C_UNK);           /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
extern M2C_UNK B_003DD490;
extern s32 g_2dd5bc;
extern s32 g_2e1e40;
extern s32 g_2f7900;

void GadgetMenu_Open(s32 arg0) {
    s32 temp_v0;

    temp_v0 = PpoSwFocusBase(&B_003DD490);
    if (temp_v0 != 0) {
        if (temp_v0 == g_2e1e40) {
            GadgetMenu_SetPage(arg0, 0);
            return;
        }
        if (temp_v0 == g_2dd5bc) {
            GadgetMenu_SetPage(arg0, 1);
            return;
        }
        if (temp_v0 == g_2f7900) {
            GadgetMenu_SetPage(arg0, 2);
        }
    }
}
