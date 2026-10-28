#include "sly2.h"
struct SM; struct ALO; struct SMA;
void PsmaApplySmInternal(SM*, ALO*, int, int, unsigned, SMA**);
SMA* PsmaApplySmEx(SM* psm, ALO* paloRoot, int oidInitial, int grfapl, unsigned mask)
{
    SMA* psma;
    PsmaApplySmInternal(psm, paloRoot, oidInitial, grfapl, mask, &psma);
    return psma;
}
