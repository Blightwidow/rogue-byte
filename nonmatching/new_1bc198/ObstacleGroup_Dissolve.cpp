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
    DLI *prev = g_2dd2fc;
    g_2dd2fc = it;
    it->offset = list->offset;
    it->next = prev;
}
inline char *PvFirst(DLI *it)
{
    char *item = it->list->first;
    it->current = item + it->offset;
    return item;
}
inline char *PvStep(DLI *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}
inline void PopDli(DLI *it) { g_2dd2fc = it->next; }

void ObstacleGroup_Dissolve(OBS *group)
{
    DLI iterator;
    PushDli(&iterator, &group->members);
    for (char *item = PvFirst(&iterator); item != 0; item = PvStep(&iterator)) {
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
