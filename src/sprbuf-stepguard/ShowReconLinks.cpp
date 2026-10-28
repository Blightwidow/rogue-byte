#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct LINK { char pad[0xC]; VT *vptr; };
struct LO { char pad0[0x28]; unsigned long grf; char pad1[0xD0]; LINK *plink; };
struct RECON { char pad[0x30]; int ctarget; LO *aptarget[1]; };
extern "C" void ShowReconLinks(RECON *precon)
{
    for (int itarget = 0; itarget < precon->ctarget; ++itarget) {
        LO *ptarget = precon->aptarget[itarget];
        if (((ptarget->grf >> 60) & 1) == 0)
            continue;
        LINK *plink = ptarget->plink;
        if (plink != 0)
            plink->vptr->fn((char *)plink + plink->vptr->delta);
    }
}
