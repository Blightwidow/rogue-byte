struct PANEL { char pad[0x58]; int state; char pad2[8]; int mode; };
struct MENU { char pad[0x24]; PANEL *panel; };
extern "C" bool func_001DD780(MENU *menu)
{
    PANEL *panel = menu->panel;
    if (panel == 0) return false;
    if (panel->state != 2) return false;
    return panel->mode == 2;
}
