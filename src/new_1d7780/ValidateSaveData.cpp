// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct REC { char pad[4]; unsigned short ib; char pad1[4]; };
struct SAVEVARS { int crec; REC *arec; };
struct SAVEDATA { char pad[0x5400]; int nLayout; int nChecksum; };
void *memset(void *, int, unsigned int);
inline int NChecksum(unsigned char *pb, int cb)
{
    int nChecksum = 0;
    for (; cb != 0; cb--)
        nChecksum += *pb++;
    return nChecksum;
}
inline int NChecksumSaveVars(SAVEVARS *psavevars)
{
    return NChecksum((unsigned char *)psavevars->arec, psavevars->crec * sizeof(REC));
}
extern "C" void ValidateSaveData(SAVEVARS *psavevars, SAVEDATA *psavedata)
{
    int nChecksum = NChecksumSaveVars(psavevars);
    unsigned nLayout = psavevars->arec[psavevars->crec - 1].ib;
    if (nLayout != (unsigned)psavedata->nLayout || nChecksum != psavedata->nChecksum) {
        memset(psavedata, 0, 0x5400);
        psavedata->nLayout = nLayout;
        psavedata->nChecksum = nChecksum;
    }
}
