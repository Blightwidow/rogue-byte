#include "types.h"
#include "xf.h"
struct GUARD { char pad[0xF08]; XF *paim; void *pact; int unk; char pad2[0xF20-0xF14]; QW vecLook; };
extern "C" { extern QW g_2a2dd0; void func_0012E460(void *); void *func_0012DC18(void *, void *, int, int, int, QW); }
void func_0020AC28(GUARD *pguard, XF *paim, int pxfLookFrom, QW vecLook)
{
    if (pguard->paim != 0) {
        func_0012E460(&pguard->pact);
        pguard->pact = 0;
        pguard->paim = 0;
    }
    pguard->paim = paim;
    if (paim != 0 && paim->pxfParent != 0) {
        void *pact = func_0012DC18(pguard, paim->pxfParent, 5, 8, 3, g_2a2dd0);
        pguard->pact = pact;
        pguard->unk = pxfLookFrom;
        pguard->vecLook = vecLook;
    }
}
