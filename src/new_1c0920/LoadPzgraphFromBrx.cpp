#include "sly2.h"
struct ALLOCREQ { int cb; int align; };
struct CBIS;
struct PZENTRY { QW *ppos; short iA; short iB; };
struct PZGRAPH { int cent; PZENTRY *aent; int cvec; QW *avec; int cint; int *aint; int *aintClear; };
extern "C" {
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
int U32Read__18CBinaryInputStream(CBIS *);
int U16Read__18CBinaryInputStream(CBIS *);
int S32Read__18CBinaryInputStream(CBIS *);
void CBinaryInputStream_ReadVector4(CBIS *, void *);
void LoadPzgraphFromBrx(PZGRAPH *pzg, int cent, CBIS *pcbis)
{
    ALLOCREQ req;
    pzg->cent = cent;
    pzg->cvec = U32Read__18CBinaryInputStream(pcbis);
    pzg->cint = U32Read__18CBinaryInputStream(pcbis);
    req.cb = pzg->cent * 8;
    req.align = 0x10;
    pzg->aent = (PZENTRY *)PvAllocSwImpl__Fi(&req);
    req.cb = pzg->cvec * 16;
    req.align = 0x10;
    pzg->avec = (QW *)PvAllocSwImpl__Fi(&req);
    req.cb = pzg->cint * 4;
    req.align = 0x10;
    pzg->aintClear = (int *)PvAllocSwClearImpl__Fi(&req);
    req.cb = pzg->cint * 4;
    req.align = 0x10;
    pzg->aint = (int *)PvAllocSwImpl__Fi(&req);
    for (int ient = 0; ient < pzg->cent; ient++) {
        PZENTRY *pent = &pzg->aent[ient];
        pent->ppos = pzg->avec + U16Read__18CBinaryInputStream(pcbis);
        pent->iA = U16Read__18CBinaryInputStream(pcbis);
        pent->iB = U16Read__18CBinaryInputStream(pcbis);
    }
    for (int ivec = 0; ivec < pzg->cvec; ivec++)
        CBinaryInputStream_ReadVector4(pcbis, &pzg->avec[ivec]);
    for (int iint = 0; iint < pzg->cint; iint++)
        pzg->aint[iint] = S32Read__18CBinaryInputStream(pcbis);
}
}
