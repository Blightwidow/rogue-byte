extern "C" float g_2ddf0c;
extern "C" void Menu_SetDialog(int *, int, int);
extern "C" void Menu_ResetState(int *menu)
{
    menu[10] = -1;
    *(float *)&menu[11] = g_2ddf0c;
    Menu_SetDialog(menu, -1, -1);
}
