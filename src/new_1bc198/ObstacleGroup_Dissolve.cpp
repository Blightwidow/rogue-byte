// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct VT { char pad[0x48]; short delta; short index; void (*fn)(char *); };
struct OBS { char pad[0xC]; VT *vt; char pad2[0x1C4 - 0x10]; DL members; char pad3[0x1D8 - 0x1D0]; void *group; };
extern DLI *g_2dd2fc;
extern "C" char B_003E1A4C[];
extern "C" char B_003E1A40[];
void RemoveDlEntry(DL *, void *);
int FFindDlEntry(void *, void *);
void AppendDlEntry(void *, void *);

inline void PushDli(DLI *it, DL *list)
{
    it->list = list;
    it->current = (char *)list;
    it->offset = list->offset;
    it->next = g_2dd2fc;
    g_2dd2fc = it;
}
inline char *PvStep(DLI *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}
inline void PopDli(DLI *it) { g_2dd2fc = it->next; }

// Retail stores the iterator into g_2dd2fc and keeps list->offset in a register before it loads the
// first member (lw 0x1C4 after the global store, addu with the kept offset): the first item is read
// through the pushed iterator (current starts at the list head, as in OnRipgRemove and UpdateCodes),
// and PushDli reads the old head as it->next = g_2dd2fc. A draft that read list->first directly let
// the scheduler hoist that load above the push (score 12).
void ObstacleGroup_Dissolve(OBS *group)
{
    DLI iterator;
    PushDli(&iterator, &group->members);
    for (char *item = PvStep(&iterator); item != 0; item = PvStep(&iterator)) {
        OBS *member = (OBS *)item;
        RemoveDlEntry(&group->members, member);
        member->group = 0;
        if (!FFindDlEntry(B_003E1A4C, member))
            AppendDlEntry(B_003E1A4C, member);
    }
    group->vt->fn((char *)group + group->vt->delta);
    AppendDlEntry(B_003E1A40, group);
    PopDli(&iterator);
}
