#include "sly2.h"
struct POINT { char pad[0x14]; int fBusy; float tReady; };
struct VT { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct ACTOR { char pad[0xC]; VT *vptr; };
struct SLOT { ACTOR *pactor; char pad4[4]; float tFree; POINT *ppoint; int kind; char pad14[0xC]; QW posRelease; };
struct SPAWNER { char pad[0x58]; int cSlot; };
extern float g_2dded0;
extern "C" QW PosSpawnerFocus(void *);
extern "C" void func_00173928(char *pspawner, SLOT *pslot, int kind, unsigned fKeepPoint)
{
    pslot->kind = kind;
    switch (kind) {
    case 0:
        pslot->tFree = g_2dded0;
        {
            ACTOR *pactor = pslot->pactor;
            pactor->vptr->fn((char *)pactor + pactor->vptr->delta);
        }
        if ((fKeepPoint ^ 1) & 1)
            pslot->ppoint->tReady = g_2dded0;
        break;
    case 1:
        pslot->tFree = g_2dded0 + *(float *)(pspawner + 0xA0);
        pslot->posRelease = PosSpawnerFocus(pspawner);
        if ((fKeepPoint ^ 1) & 1)
            pslot->ppoint->tReady = g_2dded0 + *(float *)(pspawner + 0xA4);
        break;
    }
    pslot->pactor = 0;
    pslot->ppoint->fBusy = 0;
    pslot->ppoint = 0;
    ((SPAWNER *)pspawner)->cSlot--;
}
