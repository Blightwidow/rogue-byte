#include "sly2.h"
struct TASK { char pad0[0x54]; int nState; char pad58[0x3C]; int cPrereq; TASK **apPrereq; char pad9C[0x54]; int nPending; };
extern "C" void SetTaskStateCascade(TASK *, int);
extern "C" void UpdateDependentTaskState(TASK *ptask, int nStateParent)
{
    if (ptask->nPending != -1)
        return;
    int nStateOld = ptask->nState;
    int nState = nStateOld;
    if (-1 < nStateParent) {
        if (nStateParent < 2) {
            nState = 0;
        } else if (nStateParent < 4) {
            int fAllComplete = 1; int cPrereq = ptask->cPrereq;
            for (int itask = 0; itask < cPrereq; itask++) {
                if (ptask->apPrereq[itask]->nState < 2) {
                    fAllComplete = 0;
                    break;
                }
            }
            if (!fAllComplete)
                nState = 0;
            else switch (nStateOld) {
            case 0: nState = 1; break;
            case 3: nState = nStateParent; break;
            }
        }
    }
    SetTaskStateCascade(ptask, nState);
}
