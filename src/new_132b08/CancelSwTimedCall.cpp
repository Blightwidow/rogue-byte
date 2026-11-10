// SPDX-License-Identifier: GPL-3.0-or-later
#include "cref.h"
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct SLOTHEAP;
struct TIMEDCALL { char pad[8]; CPair *ppair; int idCall; TIMEDCALL *pnext; };
#include "sw.h"
extern "C" {
void RemoveSlEntry(TIMEDCALL **, TIMEDCALL *);
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(void *, void *);
extern char B_004520A8;
}
extern "C" void CancelSwTimedCall(SW *psw, int idCall)
{
    if (idCall == -1)
        return;
    for (TIMEDCALL *pcall = psw->ptimedcallFirst; pcall != 0; pcall = pcall->pnext) {
        if (pcall->idCall != idCall)
            continue;
        RemoveSlEntry(&psw->ptimedcallFirst, pcall);
        CPair *ppair = pcall->ppair;
        if (--ppair->cref == 0 && ppair != 0) {
            CPairPtr_Destructor(&ppair->next, 2);
            CRef_Destruct(&ppair->ref);
            UnlinkPairNode(ppair);
            FreeSlotheapPv(&B_004520A8, ppair);
        }
        FreeSlotheapPv(&psw->slotheapTimedcall, pcall);
        return;
    }
}
