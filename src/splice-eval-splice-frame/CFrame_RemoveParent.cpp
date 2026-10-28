#include "sly2.h"
struct CFrame { int pad0; int pad4; int count; CFrame *parents[1]; };
extern "C" void CFramePtr_Assign(CFrame **, CFrame *);
void CopyAb(void *, void *, unsigned int);

extern "C" void CFrame_RemoveParent(CFrame *pframe, CFrame *pparent)
{
    for (int index = 0; index < pframe->count; index++) {
        CFrame **pslot = &pframe->parents[index];
        if (*pslot == pparent) {
            CFramePtr_Assign(pslot, 0);
            int remaining = --pframe->count;
            CopyAb(pslot[0], pslot[1], (remaining - index) * 4);
            return;
        }
    }
}
