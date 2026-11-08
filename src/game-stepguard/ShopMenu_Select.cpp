/* SPDX-License-Identifier: GPL-3.0-or-later */
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
extern int g_fShopArrowsTakeRow_3DA570;
extern int g_crowShop_2C35B4;
extern "C" {
int ShopMenu_IrowEnd(SHOPMENU *);
void Menu_ClearDialog(SHOPMENU *);
}

static inline int Clamp(int value, int low, int high) { if (value < low) return low; if (value > high) return high; return value; }

// Retail clamps the first visible row with one shared value register: the lower bound (isel - crow + 1, floored at 0)
// lands in $v0 and is stored straight from the bnel delay slot, while the upper-bound path computes min(isel, ifirst)
// into isel's own register ($a1, movz) and copies it to $v0. Only an inline clamp helper, whose result pseudo is tied
// to its low argument, reproduces that; open-coded if/else or ternaries put the bound in $a0 (score 12-13). The floor
// at 0 is a ternary in the argument for the same reason (a separate if statement gave score 9).
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
        if (g_fShopArrowsTakeRow_3DA570 != 0) {
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
            int ifirstMin = (isel - g_crowShop_2C35B4) + 1;
            pshop->ifirst = Clamp(pshop->ifirst, (ifirstMin < 0) ? 0 : ifirstMin, isel);
        }
        pshop->loot = pshop->aent[pshop->isel].id;
        pshop->gadget = pshop->aent[pshop->isel].id;
    }
    Menu_ClearDialog(pshop);
}
