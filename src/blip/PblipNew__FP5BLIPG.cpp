#include "sly2.h"
struct BLIPG;
struct BLIP { char pad[0x1088]; void *psp; BLIPG *pblipg; };
extern "C" void *PvAllocSlotheapImpl(void *);
extern "C" void FreeSlotheapPv(void *, void *);
extern "C" void AppendDlEntry(void *, void *);
extern "C" BLIP *PblipNew__FP5BLIPG(char *psw, char *pblipg)
{
    BLIP *pblip = (BLIP *)PvAllocSlotheapImpl(psw + 0x4088);
    if (pblip == 0)
        return 0;
    if (*(int *)(pblipg + 0x160) == 2) {
        void *psp = PvAllocSlotheapImpl(psw + 0x40A0);
        pblip->psp = psp;
        if (psp == 0) {
            FreeSlotheapPv(psw + 0x4088, pblip);
            return 0;
        }
    }
    pblip->pblipg = (BLIPG *)pblipg;
    AppendDlEntry(pblipg + 0x448, pblip);
    return pblip;
}
