#include "types.h"

struct Menu;
void Menu_Reset(struct Menu *);
void JobMenu_InitPage(struct Menu *);

void JobMenu_Reset(struct Menu *menu) {
    Menu_Reset(menu);
    JobMenu_InitPage(menu);
}
