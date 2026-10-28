#include "sly2.h"
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct RVT { char pad[0x30]; short delta; short index; void (*fn)(char *); };
struct RIP { char pad0[0x14]; float created; char pad1[0xEC - 0x18]; RVT *vt; };
struct RIPG { char pad[0x15C]; DL rips; };
extern DLI *g_2dd2fc;
extern float g_2dded0;
struct CM; struct RO;

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
    char *item = it->list->first;
    it->current = item + it->list->offset;
    return item;
}
inline char *PvStep(DLI *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}
inline void PopDli(DLI *it) { g_2dd2fc = it->next; }

void RenderRipgSelf__FP4RIPGP2CMP2RO(RIPG *ripg, CM *cm, RO *ro)
{
    DLI iterator;
    PushDli(&iterator, &ripg->rips);
    for (char *item = PvFirst(&iterator); item != 0; item = PvStep(&iterator)) {
        RIP *rip = (RIP *)item;
        float limit = g_2dded0;
        float created = rip->created;
        if (limit <= created) {
        } else
            rip->vt->fn(item + rip->vt->delta);
    }
    PopDli(&iterator);
}
