#include "sly2.h"
struct ACT { char pad[0x14]; int xfk; };
struct XFREF { char pad[0x20]; void *alo; void *xf; };
extern "C" ACT *func_001F8910(XFREF *, int, int, int);
extern "C" void func_0012D108(ACT *, QW);
extern "C" void func_0012DC18(void *, void *, int, int, int, QW);

void func_001F89E0(XFREF *ref, int xfk, int prio, QW pos)
{
    ACT *act = func_001F8910(ref, 1, xfk, prio);
    if (act) {
        act->xfk = xfk;
        func_0012D108(act, pos);
    } else if (xfk != -1) {
        func_0012DC18(ref->alo, ref->xf, prio, xfk, 2, pos);
    }
}
