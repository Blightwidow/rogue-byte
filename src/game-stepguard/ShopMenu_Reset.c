#include "types.h"

struct Menu;
void Menu_Reset(struct Menu *);
void ShopMenu_InitPage(struct Menu *);

void ShopMenu_Reset(struct Menu *menu) {
    Menu_Reset(menu);
    ShopMenu_InitPage(menu);
}
