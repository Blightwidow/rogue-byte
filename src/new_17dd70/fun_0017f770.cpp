// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct REC { int oidPart; int oidObject; void *pxf; void *pact; void *plo; void *psma; };
struct SO { char pad[0x230]; int crec; REC arec[1]; };
extern "C" char B_003DD490;
extern "C" QW g_2a2dd0;
extern "C" void *func_001F4C58(SO *, int, int);
extern "C" void *PloFindSwObject_thunk(void *, int, int, SO *);
extern "C" void *func_0012DC18(SO *, void *, int, int, int, QW);
extern "C" void *PsmaApplySm(void *, SO *, int, int);
void func_0017F770(SO *pso)
{
    for (int irec = 0; irec < pso->crec; ++irec) {
        REC *prec = &pso->arec[irec];
        prec->pxf = func_001F4C58(pso, prec->oidPart, 6);
        prec->plo = PloFindSwObject_thunk(&B_003DD490, 4, prec->oidObject, pso);
        if (prec->pxf != 0)
            prec->pact = func_0012DC18(pso, prec->pxf, 0, 7, 2, g_2a2dd0);
        if (prec->plo != 0)
            prec->psma = PsmaApplySm(prec->plo, pso, -1, 0);
    }
}
