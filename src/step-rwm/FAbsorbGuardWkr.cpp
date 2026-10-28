#include "sly2.h"
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int FAbsorbSoWkr(void *, void *);
extern "C" void GoalStack_HandleMessage(void *, int, void *);
struct VT { char pad[0x260]; short d260; short i260; int (*f260)(void *, int); char pad2[0x2B0 - 0x268]; short d2B0; short i2B0; int (*f2B0)(void *); };
struct GUARD { char pad[0xC]; VT *vt; int f10; int f14; };
struct WKR { void *src; int f4; int f8; int kind; };
int FAbsorbGuardWkr(GUARD *g, WKR *w)
{
    if (g->vt->f2B0((char *)g + g->vt->d2B0)) goto post;
    if (g->vt->f260((char *)g + g->vt->d260, w->kind)) return 1;
    if (w->src && FIsBasicDerivedFrom(w->src, 0x4F) && *(int *)(*(char **)((char *)w->src + 0x200) + 0x14) == g->f14) return 1;
    if (!FAbsorbSoWkr(g, w)) return 0;
post:
    GoalStack_HandleMessage((char *)g + 0x26C, 0xC, w);
    return 1;
}
