extern "C" void func_00213928(int, int);
extern "C" void func_00213B00(int, int);
struct GME { int gadget; int labelOnSale; int labelAcquired; int labelSelected; int labelCur; int pad14[2]; int grf; };
struct GADGETMENU { char pad0[0x24]; int pblot; char pad1[0x20]; int gadget; int cgme; GME *agme; };

void GadgetMenu_SelectGadget(GADGETMENU *menu, int gadget)
{
    menu->gadget = gadget;
    for (int index = 0; index < menu->cgme; index++) {
        GME *gme = &menu->agme[index];
        int label;
        if (gme->gadget == gadget) {
            label = gme->labelSelected;
        } else if ((gme->grf & 4) != 0) {
            label = gme->labelAcquired;
        } else {
            label = ((gme->grf & 2) != 0) ? gme->labelOnSale : -1;
        }
        if (label == gme->labelCur)
            continue;
        if (menu->pblot != 0 && gme->labelCur != -1)
            func_00213928(menu->pblot, gme->labelCur);
        gme->labelCur = label;
        if (menu->pblot != 0 && label != -1)
            func_00213B00(menu->pblot, label);
    }
}
