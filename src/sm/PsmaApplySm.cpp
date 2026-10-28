#include "sly2.h"
struct SM; struct ALO; struct SMA;
void PsmaApplySmInternal(SM*, ALO*, int, int, unsigned, SMA**);
SMA* PsmaApplySm(SM* psm, ALO* paloRoot, int oidInitial, int grfapl)
{
    SMA* psma;
    PsmaApplySmInternal(psm, paloRoot, oidInitial, grfapl, 4, &psma);
    return psma;
}
