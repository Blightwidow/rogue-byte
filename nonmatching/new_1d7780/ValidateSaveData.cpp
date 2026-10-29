#include "sly2.h"
struct REC { char pad[4]; unsigned short ib; char pad1[4]; };
struct SAVEVARS { int crec; REC *arec; };
struct SAVEDATA { char pad[0x5400]; int nLayout; int nChecksum; };
void *memset(void *, int, unsigned int);
inline int NChecksumSaveVars(SAVEVARS *psavevars)
{
    unsigned char *pb = (unsigned char *)psavevars->arec;
    int nChecksum = 0;
    for (int count = psavevars->crec * 10; count != 0; count--)
        nChecksum += *pb++;
    return nChecksum;
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
