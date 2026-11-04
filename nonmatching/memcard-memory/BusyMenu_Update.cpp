struct MEMCARD;
struct BLOT { char pad0[0x58]; int blots; float tBlots; char pad1[4]; int timers; };
struct MENU { char pad[0x24]; BLOT *pblot; };
extern "C" MEMCARD B_002F633C;
extern "C" float g_2ddf0c;
extern "C" void Menu_Update(MENU *);
extern "C" void BusyMenu_Hide(MENU *);
int FMemcardThreadValid(MEMCARD *);
void BusyMenu_Update(MENU *pmenu)
{
    Menu_Update(pmenu);
    BLOT *pblot = pmenu->pblot;
    if (pblot != 0 && pblot->blots == 2 && pblot->timers == 2 && 1.0f < g_2ddf0c - pblot->tBlots
        && FMemcardThreadValid(&B_002F633C) == 0)
        BusyMenu_Hide(pmenu);
}
