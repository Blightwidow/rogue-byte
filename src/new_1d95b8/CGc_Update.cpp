struct DL;
extern "C" void RemoveGrfusr__Fi(int);
int FIsDlEmpty__FP2DL(DL *);
extern "C" int FJoyButtonPressed(void *, int);
extern "C" int OpenPauseMenu(int);
extern "C" void func_00187E08(void *, int);
extern "C" void PauseMenu_Update(void *);
extern "C" void ShopMenu_Update(void *);
extern "C" void GadgetMenu_Update(void *);
extern "C" void UpdateCodes(void *);
extern "C" void bevy_gfx_screen_22b198(void *);
extern "C" void UpdateMeter(void *);
extern "C" void UpdateHudLabel(void *);
extern "C" void JobMenu_Update(void *);
extern "C" void MemcardMenu_Update(void *);
extern "C" void BusyMenu_Update(void *);
extern "C" void Menu_Update(void *);
extern "C" void TitleMenu_Update(void *);
extern int B_002DFBC4;
extern char B_002DFC00[];
extern char B_002E0D00[];
extern char B_002E6550[];
extern char B_002E65A0[];
extern char B_003D9E80[];
extern char B_003D9ED0[];
extern char B_003DA0C0[];
extern char B_003DA0F0[];
extern char B_003DA150[];
extern char B_003DA3C0[];
extern char B_003DA4F0[];
extern char B_003DA530[];
extern char B_00443740[];
extern char B_002DDEC0[];
extern int g_2dfbc0;
extern float g_2dded0[];

void CGc_Update(DL *dl)
{
    char *joy;
    if (B_002DFBC4 & 8) {
        if (g_2dded0[2] == 0.0f || g_2dded0[0] / g_2dded0[2] > 0.1f)
            RemoveGrfusr__Fi(8);
    }
    if (g_2dfbc0 & 2)
        joy = B_002DFC00;
    else
        joy = B_002E0D00;
    if (FJoyButtonPressed(joy, 0x800)) {
        if (!OpenPauseMenu(0))
            func_00187E08(joy, 0x800);
    } else if (g_2dfbc0 & 2) {
        int empty = FIsDlEmpty__FP2DL(dl);
        int idle = 0;
        if (*(int *)(joy + 0x100C) == 1 && g_2dded0[0] >= 5.0f)
            idle = 1;
        if (empty && idle)
            OpenPauseMenu(0);
    }
    PauseMenu_Update(B_003D9ED0);
    ShopMenu_Update(B_003DA150);
    GadgetMenu_Update(B_003DA0F0);
    UpdateCodes(B_002DDEC0);
    bevy_gfx_screen_22b198(B_00443740);
    UpdateMeter(B_003D9E80);
    UpdateHudLabel(B_003DA0C0);
    JobMenu_Update(B_003DA3C0);
    MemcardMenu_Update(B_002E6550);
    BusyMenu_Update(B_002E65A0);
    Menu_Update(B_003DA4F0);
    TitleMenu_Update(B_003DA530);
}
