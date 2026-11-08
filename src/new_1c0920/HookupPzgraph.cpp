/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct LO { char pad[0x124]; int ipathzone; char pad2[0x150 - 0x128]; int ipzlink; };
struct PZGRAPH { char pad[0x10]; int cpathzone; int *aoidPathzone; LO **appathzone; int pad2; int cplink; LO **applink; int pad3; int fHookedUp; };
struct ALLOCREQ { int cb; int cbAlign; };
extern "C" char B_003DD490[];
extern "C" LO *PloFindSwObject_thunk(void *, int, int, LO *);
extern "C" int CploFindSwObjectsByClass(void *, int, int, LO *, int, LO **);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
static inline int MinInt(int first, int second) { return (first < second) ? first : second; }
// Retail clamps the found count with `slt v1, 0x3FF-reg, v0; movz a2(0x400), v0, v1` (a min whose
// operand order survives only through an inline helper; plain if/ternary spellings give slti+movn),
// stores pgraph->cplink in the delay slot of the PvAllocSwCopyImpl call and re-reads it as the loop
// bound, so the cplink store comes right after the clamp and before the request is filled. The
// request pointer lives in s4 across the first loop (sw via sp and via s4): the same `preq = &req`
// form as the other PvAllocSwCopyImpl callers (src/button-cd/fun_0014a008.cpp).
void HookupPzgraph(PZGRAPH *pgraph)
{
    LO *aplo[0x400];
    ALLOCREQ req;
    int ipathzone;
    for (ipathzone = 0; ipathzone < pgraph->cpathzone; ipathzone++) {
        LO *ppathzone = PloFindSwObject_thunk(B_003DD490, 5, pgraph->aoidPathzone[ipathzone], 0);
        ppathzone->ipathzone = ipathzone;
        pgraph->appathzone[ipathzone] = ppathzone;
    }
    int cfound = CploFindSwObjectsByClass(B_003DD490, 0x205, 0x7C, 0, 0x400, aplo);
    int cplink = MinInt(cfound, 0x400);
    pgraph->cplink = cplink;
    ALLOCREQ *preq = &req;
    preq->cb = cplink << 2;
    preq->cbAlign = 0x10;
    pgraph->applink = (LO **)PvAllocSwCopyImpl__FiPv(preq, aplo);
    int iplink;
    for (iplink = 0; iplink < pgraph->cplink; iplink++)
        pgraph->applink[iplink]->ipzlink = iplink;
    pgraph->fHookedUp = 1;
}
