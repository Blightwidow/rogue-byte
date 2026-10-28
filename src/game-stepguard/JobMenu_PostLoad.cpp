struct PANEL { char pad[0xB0]; int flag; };
struct MENU { char pad[0x24]; PANEL *panel; };
extern "C" void Menu_PostLoad(MENU *);
extern "C" void JobMenu_PostLoad(MENU *menu)
{
    Menu_PostLoad(menu);
    if (menu->panel)
        menu->panel->flag = 1;
}
