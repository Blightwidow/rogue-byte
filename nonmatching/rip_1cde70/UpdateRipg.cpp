#include "sly2.h"
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct RVT { char pad[0x28]; short delta; short index; void (*fn)(char *); };
struct RIP { char pad0[0x14]; float created; char pad1[0xEC - 0x18]; RVT *vt; };
struct LVT { char pad[0x48]; short delta; short index; void (*fn)(char *); };
struct RIPG { char pad[0xC]; LVT *vt; char pad1[0x15C - 0x10]; DL rips; };
extern DLI *g_2dd2fc;
extern float g_2dded0;
struct DLP;
extern "C" int FIsLoInWorld(RIPG *);
extern "C" int FIsDlEmpty__FP2DL(DL *);
extern "C" void BounceRipgRips__FP4RIPG(RIPG *);
extern "C" void AddRipRef__FP3RIP(RIP *);
extern "C" void ReleaseRip(RIP *);

inline void PushDli(DLI *it, DL *list)
{
    it->list = list;
    it->current = (char *)list;
    it->offset = list->offset;
    it->next = g_2dd2fc;
    g_2dd2fc = it;
}
inline char *PvFirst(DLI *it)
{
    int offset = it->offset;
    char *item = it->list->first;
    it->current = item + offset;
    return item;
}
inline char *PvStep(DLI *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}
inline void PopDli(DLI *it) { g_2dd2fc = it->next; }

void UpdateRipg(RIPG *ripg)
{
    DLI iterator;
    PushDli(&iterator, &ripg->rips);
    for (char *item = PvFirst(&iterator); item != 0; item = PvStep(&iterator)) {
        RIP *rip = (RIP *)item;
        float limit = g_2dded0;
        float created = rip->created;
        if (limit <= created) {
        } else {
            AddRipRef__FP3RIP(rip);
            rip->vt->fn(item + rip->vt->delta);
            ReleaseRip(rip);
        }
    }
    if (FIsLoInWorld(ripg) == 0 || FIsDlEmpty__FP2DL(&ripg->rips) != 0)
        ripg->vt->fn((char *)ripg + ripg->vt->delta);
    else
        BounceRipgRips__FP4RIPG(ripg);
    PopDli(&iterator);
}
