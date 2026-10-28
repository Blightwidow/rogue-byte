#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct ALO; struct XF;
struct ACT { char pad[0x1C]; int mode; QW point; };
extern "C" ACT *PactNewForXf(int, ALO *, XF *, int, int);
extern "C" void InsertXfAct(ALO *, XF *, ACT *);

ACT *func_0012DC18(ALO *palo, XF *pxf, int priority, int xfk, int mode, QW point)
{
    ACT *pact = PactNewForXf(1, palo, pxf, priority, xfk);
    pact->mode = mode;
    pact->point = point;
    InsertXfAct(palo, pxf, pact);
    return pact;
}
