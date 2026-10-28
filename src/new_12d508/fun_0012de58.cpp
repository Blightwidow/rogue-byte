#include "sly2.h"
struct ACTX;
extern "C" ACTX *PactNewForXf(int, int, int, int, int);
extern "C" void InsertXfAct(int, int, ACTX *);
struct ACTX { char pad[0x1C]; float parameter; QW pos; QW vel; };

extern "C" ACTX *func_0012DE58(float parameter, int palo, int pxf, int priority, QW pos, QW vel)
{
    ACTX *pact = PactNewForXf(8, palo, pxf, priority, 0x11);
    pact->parameter = parameter;
    pact->pos = pos;
    pact->vel = vel;
    InsertXfAct(palo, pxf, pact);
    return pact;
}
