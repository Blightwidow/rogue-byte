#include "sly2.h"
struct SO { char pad[0x14]; int proot; };
struct OBR { int obrf; void *poxa; void *ps; };
struct POXA { char pad0[0x10]; float gMin[3]; char pad1[0x34 - 0x1C]; char dl[0x2C]; void *pso; };
struct SW { char pad0[0x2C]; char dlRoots[0x3CD0 - 0x2C]; int cobr; OBR *aobr[3]; char pad1[0x3CE0 - 0x3CE0 + 0]; };
struct DL;
extern "C" {
void *PvAllocSlotheapImpl(void *);
void InitDl__FP2DLi(void *, int);
void AppendDlEntry(void *, void *);
int FFindDlEntry(void *, int);
}
void *PoxaAllocSw(SW *psw, SO *pso)
{
    char *pswb = (char *)psw;
    char *poxa = (char *)PvAllocSlotheapImpl(pswb + 0x3CE0);
    InitDl__FP2DLi(poxa + 0x34, 0x60);
    *(SO **)(poxa + 0x60) = pso;
    AppendDlEntry(pswb + 0x3D10, poxa);
    if (FFindDlEntry(pswb + 0x2C, pso->proot))
        AppendDlEntry(pswb + 0x3D1C, poxa);
    for (int axis = 0; axis < 3; axis++) {
        OBR *pobr = &psw->aobr[axis][psw->cobr];
        pobr->ps = poxa + axis * 4;
        pobr->obrf = 0;
        pobr->poxa = poxa;
        pobr++;
        pobr->ps = poxa + 0x10 + axis * 4;
        pobr->poxa = poxa;
        pobr->obrf = 1;
    }
    psw->cobr += 2;
    return poxa;
}
