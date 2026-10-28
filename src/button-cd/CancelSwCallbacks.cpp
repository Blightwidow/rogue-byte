#include "sly2.h"
struct SLOTHEAP;
struct PMF { short delta; short index; int pfn; };
struct CB { unsigned plo; PMF pmf; int nArg; CB *pnext; };
struct SW { char pad[0x3C90]; char slotheap[0x18]; CB *pcbFirst; int pcbLast; };
extern "C" void FreeSlotheapPv(SLOTHEAP *, void *);

extern "C" void CancelSwCallbacks(SW *psw, unsigned grf, unsigned plo, PMF pmf, int nArg)
{
    CB **pplink = &psw->pcbFirst;
    CB *pcb = psw->pcbFirst;
    while (pcb != 0) {
        if ((grf & 1) != 0) {
            if (plo != pcb->plo)
                goto next;
        }
        if ((grf & 2) != 0) {
            if (pmf.index != pcb->pmf.index)
                goto next;
            if (pmf.index != -1) {
                if ((short)pmf.pfn == (short)pcb->pmf.pfn)
                    goto matchArg;
            }
            if (pmf.pfn != pcb->pmf.pfn)
                goto next;
        }
    matchArg:
        if ((grf & 4) != 0) {
            if (nArg != pcb->nArg)
                goto next;
        }
        *pplink = pcb->pnext;
        FreeSlotheapPv((SLOTHEAP *)psw->slotheap, pcb);
        goto advance;
    next:
        pplink = &pcb->pnext;
    advance:
        pcb = *pplink;
    }
    if (psw->pcbFirst == 0)
        psw->pcbLast = 0;
}
