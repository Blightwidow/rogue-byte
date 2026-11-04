struct CRef { int tagk; int n; int p2; int p3; CRef &operator=(const CRef &); };
struct ITEM { int index; int b; };
struct SHOP { char pad0[0x40]; int mode; int pad44; int count; ITEM items[0x41]; };
extern "C" {
void CRef_Destruct(CRef *);
int FGadgetAcquired(int);
int FGadgetOnSale(int);
void ShopMenu_Select(SHOP *, int);
void func_001D8A38(CRef *, const char *, const char *, char *, int);
int sprintf(char *, const char *, ...);
extern const char RO_002A79A0[];
extern const char RO_002A79D0[];
extern const char RO_002A79D8[];
void ShopMenu_BuildList(SHOP *menu)
{
    for (int clear = 0; clear < menu->count; clear++)
        menu->items[clear].index = -1;
    int mode = menu->mode;
    menu->count = 0;
    switch (mode) {
    case 0: {
        int index = 7;
        while (index < 0x2B) {
            if (FGadgetOnSale(index) != 0 && FGadgetAcquired(index) == 0) {
                unsigned int count = menu->count;
                if (count >= 0x41)
                    break;
                menu->items[count].index = index;
                menu->count = count + 1;
            }
            index++;
        }
        break;
    }
    case 1: {
        for (int index = 0; index < 0x40; index++) {
            CRef ref;
            char name[0x20];
            CRef temp;
            ref.tagk = -1;
            sprintf(name, RO_002A79A0, index);
            func_001D8A38(&temp, RO_002A79D0, RO_002A79D8, name, 0);
            ref = temp;
            CRef_Destruct(&temp);
            if (ref.n == 0) {
                CRef_Destruct(&ref);
                continue;
            }
            unsigned int count = menu->count;
            if (count >= 0x41) {
                CRef_Destruct(&ref);
                break;
            }
            menu->items[count].index = index;
            menu->count = count + 1;
            CRef_Destruct(&ref);
        }
        break;
    }
    }
    ShopMenu_Select(menu, *(int *)((char *)menu + 0x24C));
}
}
