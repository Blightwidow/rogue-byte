#include "sly2.h"
struct CBinaryAsyncStream {
    int mode;
    int fd;
    int isector;
    int cbSpooling;
    char *pbSpooling;
    int cbBuf;
    char *pbBuf;
    int pad1C;
    char *pbCur;
    int pad24;
    int cbRemaining;
    int FSpooling();
    void StartSpooling();
};
extern "C" int sceRead(int, void *, int);
extern "C" void ReadCdDirect__FUiUiPv(unsigned, unsigned, void *, int);

void CBinaryAsyncStream::StartSpooling()
{
    int cbHalf = cbBuf / 2;
    if (FSpooling() != 0)
        return;
    int remaining = cbRemaining;
    if (remaining == 0)
        return;
    char *pbDest = pbBuf;
    int cbRead = remaining < cbHalf ? remaining : cbHalf;
    if (pbCur == pbDest)
        pbDest += cbHalf;
    cbSpooling = cbRead;
    pbSpooling = pbDest;
    switch (mode) {
    case 0:
        sceRead(fd, pbDest, cbRead);
        break;
    case 1:
        ReadCdDirect__FUiUiPv(isector, (unsigned)(cbRead + 0x7FF) >> 11, pbDest, 1);
        break;
    }
}
