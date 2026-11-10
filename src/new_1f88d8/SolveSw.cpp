#include "sly2.h"
#include "sw.h"
extern "C" void RecalcSwXpAll(SW *);
extern "C" void func_001F8F80(SW *, int);
void SolveSw(SW *psw)
{
    int index;
    RecalcSwXpAll(psw);
    psw->pigrfentryRunning = &index;
    index = 0;
    while (index < psw->cgrfentry) {
        GRFENTRY *pgrfentry = &psw->agrfentry[index];
        if ((pgrfentry->grf & 0x24) == 4)
            pgrfentry->plo->ProjectTransform();
        index++;
    }
    psw->pigrfentryRunning = 0;
    func_001F8F80(psw, 1);
    RecalcSwXpAll(psw);
    func_001F8F80(psw, 6);
}
