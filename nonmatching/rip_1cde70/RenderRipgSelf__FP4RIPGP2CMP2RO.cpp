#include "sly2.h"
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct RVT { char pad[0x30]; short delta; short index; void (*fn)(char *); };
struct RIP { char pad0[0x14]; float created; char pad1[0xEC - 0x18]; RVT *vt; };
struct RIPG { char pad[0x15C]; DL rips; };
extern DLI *g_2dd2fc;
extern float g_2dded0;
struct CM; struct RO;

inline char *BeginDli(DLI *it, DL *list)
{
    g_2dd2fc = it;
    DLI *prev = g_2dd2fc;
    it->next = prev;
    int offset = list->offset;
    it->current = (char *)list;
    it->list = list;
    it->offset = offset;
    char *item = list->first;
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

void RenderRipgSelf__FP4RIPGP2CMP2RO(RIPG *ripg, CM *cm, RO *ro)
{
    DLI iterator;
    for (char *item = BeginDli(&iterator, &ripg->rips); item != 0; item = PvStep(&iterator)) {
        RIP *rip = (RIP *)item;
        float limit = g_2dded0;
        float created = rip->created;
        if (limit <= created) {
        } else
            rip->vt->fn(item + rip->vt->delta);
    }
    PopDli(&iterator);
}
