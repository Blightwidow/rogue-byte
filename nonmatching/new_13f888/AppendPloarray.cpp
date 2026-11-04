#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct PLOARRAY { int unk0; int cploMax; int cplo; int *aplo; };
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" void CopyAb__FPvT0Ui(void *, void *, unsigned);
static inline int GMaxI(int a, int b) { return a >= b ? a : b; }
void AppendPloarray(PLOARRAY *pploarray, int cplo, int *aplo)
{
    if (pploarray->cploMax < pploarray->cplo + cplo) {
        int cploMax = pploarray->cploMax;
        do {
            cploMax = GMaxI(cploMax << 1, 0x20);
        } while (cploMax < pploarray->cplo + cplo);
        ALLOCREQ allocreq;
        allocreq.cb = cploMax << 2;
        allocreq.cbAlign = 0x10;
        int *aploNew = (int *)PvAllocStackImpl__Fi(&allocreq);
        CopyAb__FPvT0Ui(aploNew, pploarray->aplo, pploarray->cplo << 2);
        pploarray->cploMax = cploMax;
        pploarray->aplo = aploNew;
    }
    CopyAb__FPvT0Ui(pploarray->aplo + pploarray->cplo, aplo, cplo << 2);
    pploarray->cplo = pploarray->cplo + cplo;
}
