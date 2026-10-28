#include "sly2.h"
struct ITEM { int kind; char b[0x1C]; };
struct ITEMCOPY { char b[0x20]; };
struct PAUSE { char pad[0x20]; int blot; };
struct MENUITEM { char pad[0x1C]; unsigned grf; };
struct G1 { char pad[0x24]; int f; };
struct G2 { char pad[0x3B0C]; int f; };
extern "C" {
extern ITEM D_002C00E8[];
extern ITEM B_002F65D0[];
extern PAUSE B_003D9ED0;
extern char B_003DD490[];
extern G1 B_003DA3C0;
extern char B_002E6550[];
extern char D_002BFD38[];
int FSwLoadBusy(void *);
int CGc_FFindScreen(void *);
void *PpoSwFocusBase(void *);
int FIsBasicDerivedFrom(void *, int);
void SetBinocState(void *, int);
int func_002127C8();
int IEpisodeCurrent();
int CidGetBasic(void *);
void PauseMenu_Push(PAUSE *, int, ITEM *, int, void *);
}
int OpenPauseMenu(MENUITEM *caller)
{
    if (B_003D9ED0.blot == 0) return 0;
    if (FSwLoadBusy(B_003DD490) != 0) return 0;
    if (CGc_FFindScreen(B_002E6550) != 0) return 0;
    void *ppo = PpoSwFocusBase(B_003DD490);
    if (ppo != 0) {
        if (FIsBasicDerivedFrom(ppo, 0x34) != 0)
            SetBinocState((char *)ppo + 0xF00, -1);
    }
    if (func_002127C8() == 0) return 0;
    {
    ITEM *source = D_002C00E8;
    ITEM *dest = B_002F65D0;
    unsigned index = 0;
    do {
        int show = 1;
        switch (source->kind) {
        case 0x2C:
            break;
        case 0x6A:
            show = 0;
            if (B_003DA3C0.f != 0)
                if (IEpisodeCurrent() != 0) show = 1;
            break;
        case 0x6B:
            show = 0;
            if (((G2 *)B_003DD490)->f != 0)
                if (IEpisodeCurrent() != 0) show = 1;
            break;
        case 0x43:
            show = 0;
            if (ppo != 0) {
                int cid = CidGetBasic(ppo);
                if (cid < 0x38) {
                    show = 1;
                    if (cid < 0x35) show = 0;
                }
            }
            break;
        case 0x42:
            show = IEpisodeCurrent() != 0;
            break;
        }
        if (show) {
            *(ITEMCOPY *)dest = *(ITEMCOPY *)source;
            dest++;
        }
        index++;
        source++;
    } while (index < 7);
    PauseMenu_Push(&B_003D9ED0, dest - B_002F65D0, B_002F65D0, B_003D9ED0.blot, D_002BFD38);
    if (caller != 0)
        caller->grf |= 2;
    return 1;
    }
}
