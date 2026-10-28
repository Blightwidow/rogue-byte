#include "sly2.h"
struct SAVE { int port; int slot; char pad[0xFD5C - 8]; char mc[4]; };
struct MCFILEINFO { char b[0x5C]; };
extern "C" {
int sceMcGetDir(int, int, const char *, int, int, void *);
int McSync(void *, int, int, int *);
void ConvertMcDirEntry(void *, MCFILEINFO *);
unsigned strlen(const char *);
char *strcpy(char *, const char *);
extern char B_002E6500[];
extern char B_002E6080[];
}
struct MCENT { char b[0x40]; };
int ReadMemcardDirectory(SAVE *psave, const char *pchzPattern, int cMax, MCFILEINFO *ainfo, int *pcFound)
{
    if (cMax >= 0x13)
        return 0x25;
    int fContinue;
    if (pchzPattern != 0) {
        if (strlen(pchzPattern) > 0x40)
            return 0xD;
        strcpy(B_002E6500, pchzPattern);
        fContinue = 0;
    } else {
        fContinue = 1;
        pchzPattern = B_002E6500;
    }
    memset(B_002E6080, 0, 0x480);
    char *pmc = psave->mc;
    int nStart = sceMcGetDir(psave->port, psave->slot, pchzPattern, fContinue, cMax, B_002E6080);
    int nError = McSync(pmc, nStart, 0xD, pcFound);
    if (nError != 0)
        return nError;
    MCENT *aentry = (MCENT *)B_002E6080;
    for (int ientry = 0; ientry < *pcFound; ientry++)
        ConvertMcDirEntry(&aentry[ientry], &ainfo[ientry]);
    return 0;
}
