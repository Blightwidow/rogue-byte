// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CODE {
    int field0;
    int cgrfSequence;
    void (*pfnAction)(int);
    int nArg;
    int igrfMatched;
    int fRemove;
};
struct SL_14BFF8 { char *first; char *last; int offset; float tFire; };
struct SLI_14BFF8 { SL_14BFF8 *list; char *current; int offset; SLI_14BFF8 *next; };
extern "C" {
extern float g_2ddf0c;
extern SLI_14BFF8 *g_2dd2f8;
void RemoveSlEntry(void *, void *);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, int);
void UnmarkAll__10CSplotheap(void *);
}

inline void PushSli(SLI_14BFF8 *it, SL_14BFF8 *list)
{
    it->list = list;
    it->current = (char *)list;
    it->offset = list->offset;
    it->next = g_2dd2f8;
    g_2dd2f8 = it;
}
inline char *PvStep(SLI_14BFF8 *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}
inline void PopSli(SLI_14BFF8 *it) { g_2dd2f8 = it->next; }
static inline int FMatched(CODE *code) { return code->igrfMatched >= code->cgrfSequence; }

// Retail stores the iterator into g_2dd2f8 before it loads list->first: the first item is read through
// the pushed iterator (current starts at the list head, as in UpdateRipg's PushDli/PvStep), so the load
// follows the global store. A draft that read list->first directly let the scheduler hoist it (score 12).
extern "C" void UpdateCodes(SL_14BFF8 *list)
{
    if (list->tFire != 0.0f) {
        if (list->tFire <= g_2ddf0c) {
            SLI_14BFF8 iterator;
            CODE *best = 0;
            PushSli(&iterator, list);
            for (CODE *code = (CODE *)PvStep(&iterator); code != 0; code = (CODE *)PvStep(&iterator)) {
                if (code->fRemove) {
                    RemoveSlEntry(list, code);
                    code->igrfMatched = 0;
                    code->fRemove = 0;
                } else if (FMatched(code)) {
                    if (best == 0 || best->cgrfSequence < code->cgrfSequence)
                        best = code;
                }
            }
            if (best) {
                SetEmitterUnpositioned(NewEmitter(0x34), 0);
                best->pfnAction(best->nArg);
            }
            UnmarkAll__10CSplotheap(list);
            list->tFire = 0.0f;
            PopSli(&iterator);
        }
    }
}
