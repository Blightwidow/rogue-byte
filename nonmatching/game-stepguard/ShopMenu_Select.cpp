struct ENT { int id; int unk; };
struct SHOPMENU {
    char pad0[0x48];
    int cent;
    ENT aent[0x40];
    char padx[0x24C - 0x4C - 0x40 * 8];
    int isel;
    int ifirst;
    int loot;
    int gadget;
};
extern int B_003DA570;
extern int D_002C35B4;
extern "C" {
int ShopMenu_IrowEnd(SHOPMENU *);
void Menu_ClearDialog(SHOPMENU *);
}

void ShopMenu_Select(SHOPMENU *pshop, int isel)
{
    if (pshop->cent == 0) {
        pshop->ifirst = 0;
        pshop->isel = -1;
        pshop->loot = -1;
        pshop->gadget = -1;
    } else {
        int iselMax = pshop->cent - 1;
        if (isel < 0) {
            isel = 0;
        } else if (iselMax < isel) {
            isel = iselMax;
        }
        pshop->isel = isel;
        if (B_003DA570 != 0) {
            if (isel < pshop->ifirst) {
                pshop->ifirst = isel;
            } else {
                while (ShopMenu_IrowEnd(pshop) - 1 < pshop->isel) {
                    pshop->ifirst++;
                }
            }
            if (pshop->ifirst == 1) {
                pshop->ifirst = 0;
            }
        } else {
            int ifirstMin = (isel - D_002C35B4) + 1;
            if (ifirstMin < 0) {
                ifirstMin = 0;
            }
            int ifirst = pshop->ifirst;
            if (ifirst < ifirstMin) {
                pshop->ifirst = ifirstMin;
            } else {
                if (!(isel < ifirst))
                    isel = ifirst;
                pshop->ifirst = isel;
            }
        }
        pshop->loot = pshop->aent[pshop->isel].id;
        pshop->gadget = pshop->aent[pshop->isel].id;
    }
    Menu_ClearDialog(pshop);
}
