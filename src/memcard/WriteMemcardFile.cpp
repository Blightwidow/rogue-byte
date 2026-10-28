#include "sly2.h"
struct SAVE;
struct FILEPAIR { int fd; int cbDone; };
int McOpenFile(SAVE *, const char *, int, int *);
int McWrite(SAVE *, int, void *, int, int *);
int McClose(SAVE *, int);
int WriteMemcardFile(SAVE *psave, const char *pchzPath, void *pvBuffer, int cb)
{
    FILEPAIR file;
    file.fd = -1;
    int nError = McOpenFile(psave, pchzPath, 0x202, &file.fd);
    if (nError != 0)
        return nError;
    nError = McWrite(psave, file.fd, pvBuffer, cb, &file.cbDone);
    if (nError == 0 && file.cbDone != cb)
        nError = 7;
    McClose(psave, file.fd);
    return nError;
}
