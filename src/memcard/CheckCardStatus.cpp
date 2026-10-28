#include "sly2.h"
struct SAVE { int port; int slot; int unk8; int state; int unk10; float tNext; int cardType; int cFree; int formatted; char pad[0xFD5C - 0x24]; char mc[4]; };
extern "C" {
int sceMcGetInfo(int, int, int *, int *, int *);
int McSync(void *, int, int, int *);
extern float g_2ddf0c;
}
int CheckCardStatus(SAVE *psave)
{
    char *pmc = psave->mc;
    int nStart = sceMcGetInfo(psave->port, psave->slot, &psave->cardType, &psave->cFree, &psave->formatted);
    int nError = McSync(pmc, nStart, 1, 0);
    int nWanted;
    switch (nError) {
    case 0xB:
        nWanted = 1;
        break;
    case 9:
        asm volatile("");
        nWanted = 3;
        break;
    case 10:
    case 0xC:
        nWanted = 2;
        nError = 0xC;
        break;
    case 0:
        if (psave->formatted != 0) {
            if (psave->state > 2)
                goto skip;
            nWanted = 3;
        } else
            nWanted = 2;
        break;
    default:
        goto skip;
    }
    psave->state = nWanted;
skip:
    if (nError == 0 || nError == 0xC) {
        if (psave->cardType != 2) {
            nError = 0xB;
            psave->state = 1;
        }
    }
    psave->tNext = g_2ddf0c + 0.3f;
    return nError;
}
