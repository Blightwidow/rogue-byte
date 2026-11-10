#include "sly2.h"
struct HITFX;
struct VTE { short delta; short index; void (*fn)(void *, ...); };
struct VT { char pad[8]; VTE entry[4]; };
struct PARMS { int frame; char pad[0x60]; int param64; };
struct HITFX {
    int f0; int f4; int f8; VT *vt; int refs; PARMS *parms; int f18; int f1c;
    QW pos20; QW pos30; int owner; int f44; int id; float time; int f50; int f54;
};
#include "sw.h"
extern "C" SW B_003DD490;
extern "C" char D_002CE2B8;
struct CLOCK_156548 { float t; float dt; int cframe; };
extern "C" CLOCK_156548 g_2dded0;
extern "C" void *PvAllocSlotheapImpl(void *);
extern "C" void AppendDlEntry(void *, void *);
extern "C" void CFramePtr_Assign(void *, int);
struct HOLD {
    HITFX *fx;
    HOLD(HITFX *target) { fx = target; fx->vt->entry[0].fn((char *)fx + fx->vt->entry[0].delta); }
    ~HOLD() { fx->vt->entry[1].fn((char *)fx + fx->vt->entry[1].delta); }
};
extern "C" void PhitfxSpawn_156548(PARMS *parms, QW pos, int owner, HITFX **out)
{
    HITFX *fx = (HITFX *)PvAllocSlotheapImpl(&B_003DD490.slotheapHitfx);
    memset(fx, 0, 0x60);
    fx->vt = (VT *)&D_002CE2B8;
    fx->f0 = 0;
    fx->f4 = 0;
    fx->parms = parms;
    fx->pos20 = pos;
    fx->pos30 = pos;
    fx->owner = owner;
    int id = B_003DD490.idHitfxLast + 1;
    B_003DD490.idHitfxLast = id;
    fx->id = id;
    fx->time = g_2dded0.t;
    fx->f54 = parms->param64;
    AppendDlEntry(&B_003DD490.dlHitfx, fx);
    fx->vt->entry[0].fn((char *)fx + fx->vt->entry[0].delta);
    HOLD hold(fx);
    CFramePtr_Assign(fx, parms->frame);
    if (out) *out = fx;
    fx->vt->entry[2].fn((char *)fx + fx->vt->entry[2].delta, 2, 0, 0, 0, 0);
}
