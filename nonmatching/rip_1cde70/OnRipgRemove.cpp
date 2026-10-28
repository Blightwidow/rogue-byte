#include "sly2.h"
struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct RIPG { char pad[0x10]; int parent; char pad1[0xEC - 0x14]; int poxa; char pad2[0x15C - 0xF0]; DL rips; };
struct SW { char pad[0x403C]; char slotheap[1]; };
struct SWX { char pad[0x406C]; RIPG *group; };
extern DLI *g_2dd2fc;
extern SWX B_003DD490;
extern "C" void RemoveRip(char *);
extern "C" void RemoveSoLoHierarchy(RIPG *);
extern "C" void FreeSwPoxa(SWX *, int);
extern "C" void func_001A57A8(RIPG *);
extern "C" void func_001A53E0(RIPG *);
extern "C" void *PdlFromSwCid(SWX *, int);
extern "C" void RemoveSlEntry(void *, RIPG *);
extern "C" void FreeSlotheapPv(void *, RIPG *);

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
    int offset = it->offset;
    it->current = item + offset;
    return item;
}
inline char *PvStep(DLI *it)
{
    char *item = *(char **)it->current;
    it->current = item + it->offset;
    return item;
}

void OnRipgRemove(RIPG *ripg)
{
    DLI iterator;
    PushDli(&iterator, &ripg->rips);
    char *item;
    for (item = PvFirst(&iterator); item != 0; item = PvStep(&iterator))
        RemoveRip(item);
    if (B_003DD490.group == ripg)
        B_003DD490.group = 0;
    RemoveSoLoHierarchy(ripg);
    if (ripg->poxa != 0) {
        FreeSwPoxa(&B_003DD490, ripg->poxa);
        ripg->poxa = 0;
    }
    func_001A57A8(ripg);
    RemoveSlEntry(PdlFromSwCid(&B_003DD490, 0x57), ripg);
    if (ripg->parent == 0)
        func_001A53E0(ripg);
    FreeSlotheapPv((char *)&B_003DD490 + 0x403C, ripg);
    g_2dd2fc = iterator.next;
}
