#include "sly2.h"
struct VE { short delta; short idx; void (*fn)(void *, int, void *); };
struct VT { char p[0x48]; VE e; };
struct SCR { char p0[0xC]; VT *vt; void *pjoy; };
struct CGC { SCR *pnew; char p[8]; SCR *ptop; };
extern char B_002DFC00;
void CGc_UpdateTop(CGC *g)
{
    SCR *pnew = g->pnew;
    if (pnew == g->ptop)
        return;
    if (g->ptop) {
        g->ptop->pjoy = 0;
        VE *e = &g->ptop->vt->e;
        e->fn((char *)g->ptop + e->delta, 0, pnew);
    }
    SCR *pold = g->ptop;
    g->ptop = pnew;
    if (pnew) {
        pnew->pjoy = &B_002DFC00;
        VE *e = &pnew->vt->e;
        e->fn((char *)pnew + e->delta, 1, pold);
    }
}
