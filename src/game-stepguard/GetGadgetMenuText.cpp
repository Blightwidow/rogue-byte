struct GME { char pad[0x1C]; unsigned grf; };
struct GADGET { int a; int b; int c; int d; int e; int sidName; int sidDesc; int sidHint; };
struct GADGETMENU { char pad0[0x30]; int dialog; int pad1; int msgDialog; char pad2[0x48 - 0x3C]; int gadget; };
extern GADGETMENU B_003DA0F0;
extern char B_003DD490;
extern GADGET D_002BCD00[];
extern const char *D_002C3268[];
extern "C" const char RO_002A7A10[];
extern "C" const char RO_002A7A18[];
extern "C" const char RO_002A7A28[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" char *strcpy(char *, const char *);
extern "C" GME *GadgetMenu_PgmeFind(GADGETMENU *, int);
extern "C" void *PpoSwFocusBase(void *);
extern "C" int IslotJtGadget(void *, int);
const char *PchzStringFromId(void *, int);

void GetGadgetMenuText(char *pchz)
{
    char achzHint[0x100];
    const char *pchzDesc;
    if (B_003DA0F0.dialog != -1) {
        strcpy(pchz, PchzStringFromId(&B_003DD490, B_003DA0F0.msgDialog));
        return;
    }
    if (B_003DA0F0.gadget == -1) {
        strcpy(pchz, PchzStringFromId(&B_003DD490, 0xDD));
        return;
    }
    GME *pgme = GadgetMenu_PgmeFind(&B_003DA0F0, B_003DA0F0.gadget);
    int islot = IslotJtGadget(PpoSwFocusBase(&B_003DD490), B_003DA0F0.gadget);
    if ((pgme->grf & 1) != 0 && islot < 0) {
        strcpy(achzHint, PchzStringFromId(&B_003DD490, 0xE1));
        pchzDesc = RO_002A7A10;
    } else {
        const char *pchzSlot;
        if (islot >= 0)
            pchzSlot = D_002C3268[islot];
        else
            pchzSlot = RO_002A7A10;
        sprintf(achzHint, PchzStringFromId(&B_003DD490, D_002BCD00[B_003DA0F0.gadget].sidHint), pchzSlot, pchzSlot, pchzSlot);
        pchzDesc = PchzStringFromId(&B_003DD490, D_002BCD00[B_003DA0F0.gadget].sidDesc);
    }
    sprintf(pchz, RO_002A7A18, PchzStringFromId(&B_003DD490, D_002BCD00[B_003DA0F0.gadget].sidName),
            *(unsigned char *)pchzDesc ? RO_002A7A28 : RO_002A7A10, pchzDesc, achzHint);
}
