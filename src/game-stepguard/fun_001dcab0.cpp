struct GADGET { int a; int b; int price; int d; int e; int sidName; int sidDesc; int sidHint; };
struct LOOT { int price; int b; int c; };
struct SHOPMENU {
    char pad0[0x30]; int dialog; int pad1; int msgDialog; int pad2;
    int page; char pad3[0x254 - 0x44];
    int gadget; int loot;
};
extern SHOPMENU B_003DA150;
extern char B_003DD490;
extern char B_002DEB30;
extern GADGET D_002BCD00[];
extern LOOT D_002C3288[];
extern "C" const char RO_002A7A38[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" char *strcpy(char *, const char *);
extern "C" int GetGameCoins(void *);
const char *PchzStringFromId(void *, int);

void func_001DCAB0(char *pchz)
{
    if (B_003DA150.dialog != -1) {
        strcpy(pchz, PchzStringFromId(&B_003DD490, B_003DA150.msgDialog));
    } else {
        switch (B_003DA150.page) {
        case 0: {
            unsigned gadget = B_003DA150.gadget;
            if (gadget < 0x2B && D_002BCD00[gadget].sidDesc != -1) {
                int *pprice = &D_002BCD00[gadget].price;
                int coins = GetGameCoins(&B_002DEB30);
                int sidAfford = coins < *pprice ? 0xD9 : 0xDA;
                sprintf(pchz, RO_002A7A38, PchzStringFromId(&B_003DD490, D_002BCD00[gadget].sidName),
                        PchzStringFromId(&B_003DD490, D_002BCD00[gadget].sidDesc), PchzStringFromId(&B_003DD490, sidAfford));
                return;
            }
            strcpy(pchz, PchzStringFromId(&B_003DD490, 0xDC));
            break;
        }
        case 1: {
            unsigned loot = B_003DA150.loot;
            if (loot < 0x40) {
                const char *pchzFormat = PchzStringFromId(&B_003DD490, 0xDB);
                sprintf(pchz, pchzFormat, D_002C3288[loot].price);
                return;
            }
            strcpy(pchz, PchzStringFromId(&B_003DD490, 0xE3));
            break;
        }
        default:
            pchz[0] = 0;
            return;
        }
    }
}
