// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct DL_1CE1C8 { char *first; char *last; int offset; };
struct DLI_1CE1C8 { DL_1CE1C8 *list; char *current; int offset; DLI_1CE1C8 *next; };
struct RVT_1CE1C8 { char pad[0x28]; short delta; short index; void (*fn)(char *); };
struct RIP_1CE1C8 { char pad0[0x14]; float created; char pad1[0xEC - 0x18]; RVT_1CE1C8 *vt; };
struct LVT_1CE1C8 { char pad[0x48]; short delta; short index; void (*fn)(char *); };
struct RIPG_1CE1C8 { char pad[0xC]; LVT_1CE1C8 *vt; char pad1[0x15C - 0x10]; DL_1CE1C8 rips; };
extern DLI_1CE1C8 *g_2dd2fc;
extern float g_2dded0;
extern "C" int FIsLoInWorld(RIPG_1CE1C8 *);
extern "C" int FIsDlEmpty__FP2DL(DL_1CE1C8 *);
extern "C" void BounceRipgRips__FP4RIPG(RIPG_1CE1C8 *);
extern "C" void AddRipRef__FP3RIP(RIP_1CE1C8 *);
extern "C" void ReleaseRip(RIP_1CE1C8 *);

inline void PushDli(DLI_1CE1C8 *it, DL_1CE1C8 *list)
{
    it->list = list;
    it->current = (char *)list;
    it->offset = list->offset;
    it->next = g_2dd2fc;
    g_2dd2fc = it;
}
inline char *PvStep(DLI_1CE1C8 *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}
inline void PopDli(DLI_1CE1C8 *it) { g_2dd2fc = it->next; }

extern "C" void UpdateRipg__FP4RIPG(RIPG_1CE1C8 *ripg)
{
    DLI_1CE1C8 iterator;
    PushDli(&iterator, &ripg->rips);
    for (char *item = PvStep(&iterator); item != 0; item = PvStep(&iterator)) {
        RIP_1CE1C8 *rip = (RIP_1CE1C8 *)item;
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
