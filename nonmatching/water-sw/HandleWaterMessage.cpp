#include "sly2.h"
struct SW;
struct SO;
struct XA { char pad0[4]; SO *pso; char pad1[4]; XA *pxaNext; };
struct VT { char pad[0x20]; short delta; short index; void (*fn)(void *, int, void *); };
struct SOV { char pad[0xC]; VT *vt; };
struct WATER { char pad[0x150]; XA *pxaFirst; };
struct MSGWATER { WATER *pwater; SOV *pso; };
extern "C" char B_003DD490[];
void RemoveSoXa__FP2SOP2XA(SO *, XA *);
void FreeSwXaList__FP2SWP2XA(SW *, XA *);
extern "C" void HandleLoMessage(void *, int, void *);
extern "C" void HandleWaterMessage(WATER *pwater, int msgid, void *pvMessage)
{
    if (msgid == 1 && pwater != pvMessage) {
        XA **ppxa = &pwater->pxaFirst;
        XA *pxa;
        for (pxa = *ppxa; pxa; pxa = *ppxa) {
            if (pxa->pso == pvMessage) {
                *ppxa = pxa->pxaNext;
                break;
            }
            ppxa = &pxa->pxaNext;
        }
        MSGWATER msg;
        msg.pwater = pwater;
        msg.pso = (SOV *)pxa->pso;
        if (pxa) {
            pxa->pxaNext = 0;
            RemoveSoXa__FP2SOP2XA(pxa->pso, pxa);
            FreeSwXaList__FP2SWP2XA((SW *)B_003DD490, pxa);
        }
        VT *vt = msg.pso->vt;
        vt->fn((char *)msg.pso + vt->delta, 5, &msg);
    }
    HandleLoMessage(pwater, msgid, pvMessage);
}
