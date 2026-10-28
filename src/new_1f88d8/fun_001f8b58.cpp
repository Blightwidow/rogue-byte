#include "sly2.h"
struct ACT { char pad[0x14]; int xfk; char pad2[0x1C - 0x18]; float ga; float gb; };
struct XFREF { char pad[0x20]; void *alo; void *xf; };
extern "C" ACT *func_001F8910(XFREF *, int, int, int);
extern "C" void CreateXfActbank(void *, void *, int, int, float, float);

void func_001F8B58(XFREF *ref, int xfk, int prio, float ga, float gb)
{
    ACT *act = func_001F8910(ref, 4, xfk, prio);
    if (act) {
        act->xfk = xfk;
        act->ga = ga;
        act->gb = gb;
    } else if (xfk != -1) {
        CreateXfActbank(ref->alo, ref->xf, prio, xfk, ga, gb);
    }
}
