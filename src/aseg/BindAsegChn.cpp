#include "sly2.h"
struct ASEG;
struct ALO;
struct XF;
struct ASEGCHN { int packed; };
struct VT { char pad[0x198]; short delta; short index; XF *(*fn)(void *, int); };
struct ALOV { char pad[0xC]; VT *vt; };
extern "C" char B_003DD490[];
extern "C" ALOV *PloFindSwObject_thunk(void *, int, int, void *);

extern "C" void BindAsegChn(ASEG *paseg, ALO *paloRoot, ASEGCHN *pchn, ALOV **ppalo, XF **ppxf)
{
    if (paloRoot != 0)
        *ppalo = PloFindSwObject_thunk(B_003DD490, 1, (pchn->packed << 12) >> 12, paloRoot);
    else
        *ppalo = PloFindSwObject_thunk(B_003DD490, 4, (pchn->packed << 12) >> 12, paseg);
    if (*ppalo == 0)
        *ppxf = 0;
    else {
        VT *vt = (*ppalo)->vt;
        *ppxf = vt->fn((char *)*ppalo + vt->delta, (pchn->packed << 2) >> 22);
    }
}
