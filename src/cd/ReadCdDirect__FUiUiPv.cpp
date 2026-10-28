#include "sly2.h"
extern "C" int sceCdRead(unsigned, unsigned, void *, const void *);
extern "C" int sceCdSync(int);
extern "C" int sceCdGetError();
extern "C" const char RO_002A2E50[];
extern "C" const char RO_002A2E58[];
extern int g_2dde80;
extern int g_2dde84;
extern "C" void ReadCdDirect__FUiUiPv(unsigned lsn, unsigned csec, void *pvBuffer, int fStream)
{
    const char *pcdrmode = (fStream == 1) ? RO_002A2E50 : RO_002A2E58;
    int result;
    do {
        result = sceCdRead(lsn, csec, pvBuffer, pcdrmode);
        g_2dde80 = result;
        if (result == 1) break;
        sceCdSync(0);
        g_2dde84 = sceCdGetError();
    } while (1);
}
