// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct ALO; struct XF;
struct MAT { QW row[4]; };
struct ACT { char pad[0x1C]; XF *pxfTarget; int unk0x20[4]; MAT mat; };
extern "C" ACT *PactNewForXf(int, ALO *, XF *, int, int);
extern "C" void InsertXfAct(ALO *, XF *, ACT *);

ACT *func_0012DDB0(ALO *palo, XF *pxf, int priority, int xfk, XF *pxfTarget, MAT *pmat)
{
    ACT *pact = PactNewForXf(6, palo, pxf, priority, xfk);
    pact->pxfTarget = pxfTarget;
    *(MAT *)((char *)pact + 0x20) = *pmat;
    InsertXfAct(palo, pxf, pact);
    return pact;
}
