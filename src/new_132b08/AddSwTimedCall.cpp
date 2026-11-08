#include "sly2.h"
struct SLOTHEAP;
struct PAIR { int cref; };
struct TIMEDCALL { float tFire; void *powner; PAIR *ppair; int idCall; TIMEDCALL *pnext; };
struct SWW { char pad[0x39FC]; int slotheap; };
struct TCLIST { TIMEDCALL *phead; };
extern TCLIST B_003E0E80;
struct SWG { char pad[0x3D6C]; int cTimed; };
extern SWG B_003DD490;
extern "C" void *PvAllocSlotheapImpl(void *);
extern "C" void InsertSlEntryAfter(TCLIST *, TIMEDCALL *, TIMEDCALL *);

// Retail rotates one list walk: the first test (phead) compares against tFire still in $f20 (CSE of the store
// just made), the loop body reloads pcall->tFire and branches back with bc1fl after a loop-aligned nop. That is
// gcc's loop rotation of a plain `for` over the list with a break, so the source walks the list in one for loop
// rather than testing the head separately (which duplicated the loop or lost the alignment nop).
TIMEDCALL *AddSwTimedCall(SWW *psw, void *powner, PAIR *ppair, float tFire)
{
    ppair->cref++;
    TIMEDCALL *pcall = (TIMEDCALL *)PvAllocSlotheapImpl(&psw->slotheap);
    pcall->powner = powner;
    if (powner == 0)
        pcall->idCall = ++B_003DD490.cTimed;
    else
        pcall->idCall = -1;
    pcall->ppair = ppair;
    pcall->tFire = tFire;
    pcall->pnext = 0;
    TIMEDCALL *pprev = 0;
    for (TIMEDCALL *pnext = B_003E0E80.phead; pnext != 0; pnext = pnext->pnext) {
        if (pnext->tFire > pcall->tFire)
            break;
        pprev = pnext;
    }
    InsertSlEntryAfter(&B_003E0E80, pprev, pcall);
    return pcall;
}
