struct ENTRY { int a; void *pframe; };
struct BLOCK { char pad[8]; ENTRY *aentry; };
#include "sw.h"
extern "C" void *PframeFromSpliceBlock(SW *psw, int iblock)
{
    if (iblock == -1) return 0;
    return psw->pblockCur->aentry[iblock].pframe;
}
