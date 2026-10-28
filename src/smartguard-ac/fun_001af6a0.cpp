extern "C" void PauseMenu_SetState(void *menu, int state);
extern "C" void func_001AF6A0(char *menu)
{
    if (*(int *)(menu + 0x1E8) == 7)
        PauseMenu_SetState(menu, 0xB);
}
