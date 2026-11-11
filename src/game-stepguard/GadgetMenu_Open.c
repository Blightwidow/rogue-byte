#include "types.h"

void GadgetMenu_SetPage(s32, s32);
s32 PpoSwFocusBase(s32 *);
extern s32 B_003DD490;
extern s32 g_2dd5bc;
extern s32 g_2e1e40;
extern s32 g_2f7900;

void GadgetMenu_Open(s32 menu) {
    s32 focus;

    focus = PpoSwFocusBase(&B_003DD490);
    if (focus != 0) {
        if (focus == g_2e1e40) {
            GadgetMenu_SetPage(menu, 0);
            return;
        }
        if (focus == g_2dd5bc) {
            GadgetMenu_SetPage(menu, 1);
            return;
        }
        if (focus == g_2f7900) {
            GadgetMenu_SetPage(menu, 2);
        }
    }
}
