#include "sly2.h"
struct DMAS { int pbMax; int ab; unsigned long *pqwCnt; unsigned long *pb; };
extern "C" void EndDmaCnt__4DMAS(DMAS *);

extern "C" void AddDmaRefs__4DMASiP2QW(DMAS *pdmas, int cqw, QW *pqw)
{
    int fCntWasOpen = 0;
    if (pdmas->pqwCnt) {
        EndDmaCnt__4DMAS(pdmas);
        fCntWasOpen = 1;
    }
    unsigned long *pullTag = pdmas->pb;
    pdmas->pb = pullTag + 2;
    pullTag[0] = ((unsigned long)(long)cqw | 0x40000000UL) | ((long)(int)pqw << 32);
    pullTag[1] = 0;
    if (fCntWasOpen) {
        unsigned long *pullCnt = pdmas->pb;
        pdmas->pb = pullCnt + 2;
        pdmas->pqwCnt = pullCnt;
        pullCnt[0] = 0x10000000UL;
        pdmas->pqwCnt[1] = 0;
    }
}
