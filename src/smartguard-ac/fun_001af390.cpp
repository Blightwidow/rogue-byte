#include "sly2.h"
struct ITEM { char pad[0x14]; void (*enter)(ITEM *); char pad1[8]; };
struct FRAME { int cmenuitem; ITEM *pamenuitem; int pblot; int fPage; int pad10; int pad14; int pmenudef; };
struct MENU { char pad0[0x24]; int cframe; char pad2[0x1EC - 0x28]; int cframePending; };
extern "C" void PauseMenu_SetState(MENU *, int);
extern "C" void func_001AF390(MENU *pmenu, int cmenuitem, ITEM *pamenuitem)
{
    PauseMenu_SetState(pmenu, 3);
    int pmenudef;
    int pblot;
    FRAME *pnew;
    int cframe = pmenu->cframe;
    if (cframe > 0) {
        pnew = (FRAME *)((char *)pmenu + 0xC + 0x1C * cframe);
        pblot = pnew->pblot;
        pmenudef = pnew->pmenudef;
    }
    pmenu->cframePending = cframe + 1;
    pnew = (FRAME *)((char *)pmenu + 0x28 + 0x1C * cframe);
    memset(pnew, 0, 0x1C);
    pnew->pamenuitem = pamenuitem;
    pnew->pblot = pblot;
    pnew->fPage = 1;
    pnew->pmenudef = pmenudef;
    pnew->cmenuitem = cmenuitem;
    for (int i = 0; i < pnew->cmenuitem; i++) {
        ITEM *pitem = &pnew->pamenuitem[i];
        if (pitem->enter)
            pitem->enter(pitem);
    }
}
