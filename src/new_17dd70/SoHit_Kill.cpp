#include "sly2.h"
struct Wkr { void *so; int pad4; void *victim; int kind; int dhp; char pad14[0xC]; QW pos; QW velocity; char pad40[0x20]; };
struct Vcall { short delta; short index; QW (*fn)(void *); };
struct Vcall2 { short delta; short index; void (*fn)(void *); };
struct Obj { char pad0[0xC]; char *vtable; char pad10[0x178]; int dhp; char pad18c[4]; void *expl; };
extern "C" QW PosLoWorld(void *);
extern "C" void PaloAbsorbWkr(Wkr *);
extern "C" void ExplodeExpl(void *);
extern "C" void SoHit_Kill(Obj *so, void *victim)
{
    if (victim != 0 && so->dhp != 0) {
        Wkr wkr;
        memset(&wkr, 0, sizeof(Wkr));
        wkr.victim = victim;
        wkr.so = so;
        wkr.pos = PosLoWorld(so);
        Vcall *getVelocity = (Vcall *)(so->vtable + 0x108);
        wkr.velocity = getVelocity->fn((char *)so + getVelocity->delta);
        wkr.dhp = -so->dhp;
        wkr.kind = 0x100;
        PaloAbsorbWkr(&wkr);
    }
    if (so->expl != 0)
        ExplodeExpl(so->expl);
    Vcall2 *remove = (Vcall2 *)(so->vtable + 0x48);
    remove->fn((char *)so + remove->delta);
}
