#include "sly2.h"
struct BSP;
struct ALLOCREQ { int cb; int align; };
struct VOLUME { char pad0[0xE4]; int cnode; int unkE8; BSP *pbsp; };
extern "C" int func_00227C90(VOLUME *, QW);
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" QW ConvertAloPos(void *, VOLUME *, QW);
extern "C" int PruneBsp__FP3BSPP6VECTORfPP3BSP(BSP *, BSP *, QW, float, int *, void *);
extern "C" int func_00227D20(VOLUME *pvolume, QW pos, float radius)
{
    if (radius <= 1.0f) {
        return func_00227C90(pvolume, pos);
    }
    int fInside = 0;
    char frame[16];
    ALLOCREQ req;
    int cnode;
    void *pscratch;
    CStackFrame_Construct(frame);
    int count = pvolume->cnode;
    int limit = 0x1554;
    int clamped = limit < count ? 0x1555 : count;
    cnode = clamped;
    ALLOCREQ *preq = &req;
    preq->cb = clamped * 12;
    preq->align = 0x10;
    pscratch = PvAllocStackImpl__Fi(preq);
    QW posLocal = ConvertAloPos(0, pvolume, pos);
    int result = PruneBsp__FP3BSPP6VECTORfPP3BSP(pvolume->pbsp, (BSP *)0x7FFFFFFF, posLocal, radius, &cnode, &pscratch);
    if (result == 0 || result == 2)
        fInside = 1;
    CStackFrame_Destructor(frame, 2);
    return fInside;
}
