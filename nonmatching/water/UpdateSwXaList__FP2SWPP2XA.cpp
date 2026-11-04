#include "sly2.h"
typedef unsigned int ULL_228D20 __attribute__((mode(DI)));
struct SO_228D20 { char p0[0x148]; ULL_228D20 flags148; };
struct XA_228D20 { char p0[4]; SO_228D20 *pso; char p8[4]; XA_228D20 *next; };
extern "C" {
void RemoveSoXa__FP2SOP2XA(SO_228D20 *, XA_228D20 *);
void AddSoXa__FP2SOP2XA(SO_228D20 *, XA_228D20 *);
void FreeSwXaList__FP2SWP2XA(void *, XA_228D20 *);
extern char B_003DD490[];
}

extern "C" void UpdateSwXaList__FP2SWPP2XA(void *psw, XA_228D20 **ppxaHead)
{
    XA_228D20 **pp = ppxaHead;
    XA_228D20 *pxa = *ppxaHead;
    XA_228D20 *pxaRemoved = 0;
    while (pxa != 0) {
        SO_228D20 *pso = pxa->pso;
        ULL_228D20 flags = pso->flags148;
        XA_228D20 *next = pxa->next;
        int bit31 = (flags & 0x80000000ULL) != 0;
        int bit32 = (flags & 0x100000000ULL) != 0;
        if (bit31 != bit32) {
            if (flags & 0x80000000ULL) {
                RemoveSoXa__FP2SOP2XA(pso, pxa);
            } else {
                AddSoXa__FP2SOP2XA(pso, pxa);
            }
        }
        pso = pxa->pso;
        if ((pso->flags148 & 0x100000000ULL) == 0) {
            *pp = next;
            pxa->next = pxaRemoved;
            pxaRemoved = pxa;
        } else {
            pp = &pxa->next;
        }
        pso = pxa->pso;
        pso->flags148 = pso->flags148 & 0x2FFFFFFFFULL & 0x17FFFFFFFULL;
        pxa = next;
    }
    FreeSwXaList__FP2SWP2XA(B_003DD490, pxaRemoved);
}
