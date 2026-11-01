// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct DL_1CE608 { char *first; char *last; int offset; };
struct DLI_1CE608 { DL_1CE608 *list; char *current; int offset; DLI_1CE608 *next; };
struct RVT_1CE608 { char pad[0x30]; short delta; short index; void (*fn)(char *); };
struct RIP_1CE608 { char pad0[0x14]; float created; char pad1[0xEC - 0x18]; RVT_1CE608 *vt; };
struct RIPG_1CE608 { char pad[0x15C]; DL_1CE608 rips; };
extern DLI_1CE608 *g_2dd2fc;
extern float g_2dded0;
struct CM_1CE608; struct RO_1CE608;

inline void PushDli(DLI_1CE608 *it, DL_1CE608 *list)
{
    it->list = list;
    it->current = (char *)list;
    it->offset = list->offset;
    it->next = g_2dd2fc;
    g_2dd2fc = it;
}
inline char *PvStep(DLI_1CE608 *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}
inline void PopDli(DLI_1CE608 *it) { g_2dd2fc = it->next; }

extern "C" void RenderRipgSelf__FP4RIPGP2CMP2RO(RIPG_1CE608 *ripg, CM_1CE608 *cm, RO_1CE608 *ro)
{
    DLI_1CE608 iterator;
    PushDli(&iterator, &ripg->rips);
    for (char *item = PvStep(&iterator); item != 0; item = PvStep(&iterator)) {
        RIP_1CE608 *rip = (RIP_1CE608 *)item;
        float limit = g_2dded0;
        float created = rip->created;
        if (limit <= created) {
        } else
            rip->vt->fn(item + rip->vt->delta);
    }
    PopDli(&iterator);
}
