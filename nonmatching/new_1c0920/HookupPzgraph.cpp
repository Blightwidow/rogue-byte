/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct LO { char pad[0x124]; int ipathzone; char pad2[0x150 - 0x128]; int ipzlink; };
struct PZGRAPH { char pad[0x10]; int cpathzone; int *aoidPathzone; LO **appathzone; int pad2; int cplink; LO **applink; int pad3; int fHookedUp; };
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" char B_003DD490[];
extern "C" LO *PloFindSwObject_thunk(void *, int, int, int);
extern "C" int CploFindSwObjectsByClass(void *, int, int, int, int, LO **);
void *PvAllocSwCopyImpl(int, void *);
void HookupPzgraph(PZGRAPH *pgraph)
{
    struct { LO *applinkFound[0x400]; ALLOCREQ request; } l;
    int ipathzone;
    for (ipathzone = 0; ipathzone < pgraph->cpathzone; ipathzone++) {
        LO *ppathzone = PloFindSwObject_thunk(B_003DD490, 5, pgraph->aoidPathzone[ipathzone], 0);
        ppathzone->ipathzone = ipathzone;
        pgraph->appathzone[ipathzone] = ppathzone;
    }
    int cfound = CploFindSwObjectsByClass(B_003DD490, 0x205, 0x7C, 0, 0x400, l.applinkFound);
    int cplink = cfound;
    if (cfound > 0x3FF)
        cplink = 0x400;
    ALLOCREQ *preq = &l.request;
    preq->cb = cplink << 2;
    preq->cbAlign = 0x10;
    pgraph->cplink = cplink;
    pgraph->applink = (LO **)PvAllocSwCopyImpl((int)preq, l.applinkFound);
    int iplink;
    for (iplink = 0; iplink < pgraph->cplink; iplink++)
        pgraph->applink[iplink]->ipzlink = iplink;
    pgraph->fHookedUp = 1;
}
