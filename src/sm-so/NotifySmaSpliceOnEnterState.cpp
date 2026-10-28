#include "sly2.h"
struct VT { char pad[0x18]; short d18; short i18; void (*f18)(void *, int, int, int, void *, int); short d20; short i20; void (*f20)(void *, int, void *); };
struct SMA { char pad[0xC]; VT *vt; char pad2[0x14]; void *psm; };
extern "C" int OidFromSmIsms(void *, int);
struct SC { SMA *p; int from; int to; };
void NotifySmaSpliceOnEnterState(SMA *sma, int a, int b)
{
    SC sc;
    sc.p = sma;
    sc.from = OidFromSmIsms(sma->psm, a);
    sc.to = OidFromSmIsms(sma->psm, b);
    sma->vt->f20((char *)sma + sma->vt->d20, 10, &sc);
    int *args[2];
    args[0] = &sc.from;
    args[1] = &sc.to;
    sma->vt->f18((char *)sma + sma->vt->d18, 8, 0, 2, args, 0);
}
