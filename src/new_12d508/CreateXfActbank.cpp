#include "sly2.h"
struct ALO; struct XF;
struct ACT { char pad[0x1C]; float uBank; float dtPredict; };
extern "C" ACT *PactNewForXf(int, ALO *, XF *, int, int);
extern "C" void InsertXfAct(ALO *, XF *, ACT *);

ACT *CreateXfActbank(float uBank, float dtPredict, ALO *palo, XF *pxf, int priority, int xfk)
{
    ACT *pact = PactNewForXf(4, palo, pxf, priority, xfk);
    pact->uBank = uBank;
    pact->dtPredict = dtPredict;
    InsertXfAct(palo, pxf, pact);
    return pact;
}
