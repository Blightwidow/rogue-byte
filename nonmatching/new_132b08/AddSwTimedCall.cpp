#include "sly2.h"
struct SLOTHEAP;
struct PAIR { int cref; };
struct TIMEDCALL { float tFire; void *powner; PAIR *ppair; int idCall; TIMEDCALL *pnext; };
struct SWW { char pad[0x39FC]; int slotheap; };
extern TIMEDCALL *B_003E0E80;
struct SWG { char pad[0x3D6C]; int cTimed; };
extern SWG B_003DD490;
extern "C" void *PvAllocSlotheapImpl(void *);
extern "C" void InsertSlEntryAfter(TIMEDCALL **, TIMEDCALL *, TIMEDCALL *);

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
    if (B_003E0E80 != 0) {
        if (tFire < B_003E0E80->tFire) {
        } else {
            pprev = B_003E0E80;
        loop:
            TIMEDCALL *pnext = pprev->pnext;
            if (pnext != 0) {
                if (!(pnext->tFire > pcall->tFire)) {
                    pprev = pnext;
                    goto loop;
                }
            }
        }
    }
    InsertSlEntryAfter(&B_003E0E80, pprev, pcall);
    return pcall;
}
