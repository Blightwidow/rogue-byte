#include "sly2.h"
struct SAVE { int port; int slot; int field8; int state; int field10; float tNext; int cardType; int cFree; int formatted; char pad[0xFD5C - 0x24]; char mc[4]; };
extern "C" {
int sceMcGetInfo(int, int, int *, int *, int *);
int McSync(void *, int, int, int *);
extern float g_2ddf0c;
}
// Retail lays out one block per case (0xB, 9, 10/12, 0) and every case ends in
// one shared `sw v0, 0xC(s1)`. Case 9's `li v0, 3; b` stays its own block: with
// the stores written per case, the jump pass merges only the stores, not the
// constant 3 of case 9 with the one at the end of case 0 (a shared nWanted
// local merged them, score 9). Case 0 leaves the state alone when the card is
// formatted and the state is already past 2 (the branch over the store).
// Retail computes the memcard address (s0 = psave + 0xFD5C) before the
// sceMcGetInfo call: the source takes it into pmc first, as the original did.
int CheckCardStatus(SAVE *psave)
{
    char *pmc = psave->mc;
    int nStart = sceMcGetInfo(psave->port, psave->slot, &psave->cardType, &psave->cFree, &psave->formatted);
    int nError = McSync(pmc, nStart, 1, 0);
    switch (nError) {
    case 0xB:
        psave->state = 1;
        break;
    case 9:
        psave->state = 3;
        break;
    case 10:
    case 0xC:
        psave->state = 2;
        nError = 0xC;
        break;
    case 0:
        if (psave->formatted != 0) {
            if (psave->state > 2)
                break;
            psave->state = 3;
        } else
            psave->state = 2;
        break;
    }
    if (nError == 0 || nError == 0xC) {
        if (psave->cardType != 2) {
            nError = 0xB;
            psave->state = 1;
        }
    }
    psave->tNext = g_2ddf0c + 0.3f;
    return nError;
}
