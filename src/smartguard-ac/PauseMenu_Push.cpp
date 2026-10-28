struct MENUITEM { int unk0; int unk4; int unk8; int unkC; int unk10; void (*pfnEnter)(MENUITEM *); int unk18; int unk1C; };
struct FRAME { int cmenuitem; MENUITEM *pamenuitem; int blot; int fPage; int unk10; int unk14; int unk18; };
struct PAUSEMENU { char pad[0x24]; int cframe; FRAME aframe[1]; };
extern "C" void *memset(void *, int, unsigned int);
extern "C" void PauseMenu_SetState(PAUSEMENU *, int);
extern "C" int func_001B0108(PAUSEMENU *);
extern "C" void PauseMenu_Push(PAUSEMENU *pmenu, int cmenuitem, MENUITEM *pamenuitem, int pblot, int unk)
{
    if (pblot == 0 && pmenu->cframe > 0)
        pblot = pmenu->aframe[pmenu->cframe - 1].blot;
    FRAME *frame = &pmenu->aframe[pmenu->cframe++];
    memset(frame, 0, 0x1C);
    frame->pamenuitem = pamenuitem;
    frame->cmenuitem = cmenuitem;
    frame->blot = pblot;
    frame->unk18 = unk;
    frame->fPage = 0;
    PauseMenu_SetState(pmenu, 1);
    for (int i = 0; i < frame->cmenuitem; i++) {
        MENUITEM *item = (MENUITEM *)((char *)frame->pamenuitem + i * 32);
        if (item->pfnEnter) item->pfnEnter(item);
    }
    if (func_001B0108(pmenu)) {
        int c = pmenu->cframe;
        *(int *)((char *)pmenu + 0x1EC) = c;
        pmenu->cframe = c - 1;
    }
}
