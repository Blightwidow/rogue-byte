struct GME { char pad[0x1C]; unsigned grf; };
struct GADGETMENU {
    char pad0[0x10]; int pjoy;
    char pad1[0x24 - 0x14]; int pblot;
    char pad2[0x30 - 0x28]; int dialog;
    char pad3[0x40 - 0x34]; int page; int pad4; int gadget;
};
extern "C" {
extern int D_002C3258[];
extern char B_003DD490[];
void Menu_Update(GADGETMENU *);
int FJoyButtonPressed(int, int);
void *PpoSwFocusBase(void *);
int FIsBasicDerivedFrom(void *, int);
void GadgetMenu_SetPage(GADGETMENU *, int);
void Menu_UpdateStick(GADGETMENU *);
GME *GadgetMenu_PgmeFind(GADGETMENU *, int);
void Menu_SetDialog(GADGETMENU *, int, int);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, int);
void EquipJtGadget(void *, int, int);
void GadgetMenu_Update(GADGETMENU *menu)
{
    Menu_Update(menu);
    if (menu->pblot == 0 || menu->page == -1 || menu->pjoy == 0)
        return;
    void *pjt = 0;
    if (menu->dialog == 0 || FJoyButtonPressed(menu->pjoy, 0x10) == 0) {
        pjt = PpoSwFocusBase(B_003DD490);
        if (pjt == 0 || FIsBasicDerivedFrom(pjt, 0x34) == 0) {
            GadgetMenu_SetPage(menu, -1);
            return;
        }
    } else {
        GadgetMenu_SetPage(menu, -1);
        return;
    }
    Menu_UpdateStick(menu);
    if (FJoyButtonPressed(menu->pjoy, 0x7E8) != 0) {
        GME *pgme = GadgetMenu_PgmeFind(menu, menu->gadget);
        if (pgme == 0 || (pgme->grf & 1) == 0)
            Menu_SetDialog(menu, 1, 0xE2);
        else
            Menu_SetDialog(menu, 1, 0x31);
    }
    for (int islot = 0; islot < 3; islot++) {
        if (FJoyButtonPressed(menu->pjoy, D_002C3258[islot]) != 0) {
            GME *pgme = GadgetMenu_PgmeFind(menu, menu->gadget);
            if (pgme == 0 || (pgme->grf & 4) == 0) {
                Menu_SetDialog(menu, 1, 0x32);
            } else if ((pgme->grf & 1) == 0) {
                Menu_SetDialog(menu, 1, 0x33);
            } else {
                SetEmitterUnpositioned(NewEmitter(0x34), 0);
                EquipJtGadget(pjt, islot, menu->gadget);
            }
        }
    }
}
}
