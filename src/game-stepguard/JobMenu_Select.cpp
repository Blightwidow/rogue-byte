struct JOBMENU_1DCE90 { char pad0[0x48]; int count; char pad1[0x118 - 0x4C]; int selected; };
extern "C" void Menu_ClearDialog(JOBMENU_1DCE90 *, int);
extern "C" void JobMenu_Select(JOBMENU_1DCE90 *menu, int index)
{
    int selected;
    if (menu->count == 0) {
        selected = -1;
    } else {
        int last = menu->count - 1;
        selected = 0;
        if (index >= 0)
            selected = (last >= index) ? index : last;
    }
    menu->selected = selected;
    Menu_ClearDialog(menu, index);
}
