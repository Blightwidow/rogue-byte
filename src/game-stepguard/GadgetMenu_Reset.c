#include "types.h"

struct Menu;
void Menu_Reset(struct Menu *);
void GadgetMenu_InitPage(struct Menu *);

void GadgetMenu_Reset(struct Menu *menu) {
    Menu_Reset(menu);
    GadgetMenu_InitPage(menu);
}
