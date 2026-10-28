#include "sly2.h"
struct SM;
struct ALO;
struct VT { char pad[8]; short d8; short i8; void (*f8)(void *); short d10; short i10; void (*f10)(void *); };
struct SMA { char pad[0xC]; VT *vt; };
extern "C" void RetractSma(SMA *);
extern "C" SMA *PsmaApplySm(SM *, ALO *, int, int);
void func_001F1448(SM *psm, ALO *root, int oid, int grf, SMA **ppsma)
{
    if (*ppsma) {
        RetractSma(*ppsma);
        SMA *old = *ppsma;
        old->vt->f10((char *)old + old->vt->d10);
        *ppsma = 0;
    }
    if (psm) {
        SMA *sma = PsmaApplySm(psm, root, oid, grf);
        *ppsma = sma;
        sma->vt->f8((char *)sma + sma->vt->d8);
    }
}
