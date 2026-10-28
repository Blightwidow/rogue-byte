#include "sly2.h"
struct SAVE;
struct FILEPAIR { int fd; int cbDone; };
int McOpenFile(SAVE *, const char *, int, int *);
int McRead(SAVE *, int, void *, int, int *);
int McClose(SAVE *, int);
int ReadMemcardFile(SAVE *psave, const char *pchzPath, void *pvBuffer, int cb)
{
    FILEPAIR file;
    file.fd = -1;
    int nError = McOpenFile(psave, pchzPath, 1, &file.fd);
    if (nError != 0)
        return nError;
    nError = McRead(psave, file.fd, pvBuffer, cb, &file.cbDone);
    if (nError == 0 && file.cbDone != cb)
        nError = 8;
    McClose(psave, file.fd);
    return nError;
}
