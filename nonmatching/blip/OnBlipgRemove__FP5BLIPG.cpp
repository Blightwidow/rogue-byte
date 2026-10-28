struct DL { char *first; char *last; int offset; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
extern DLI *g_2dd2fc;
extern "C" char B_002DEAF0[];
extern "C" void RemoveBlip__FP4BLIP(void *);
extern "C" void RemoveLoHierarchy(void *);
extern "C" void func_001A57A8(void *);
extern "C" void func_001A53E0(void *);
extern "C" void AppendDlEntry(void *, void *);
struct BLIPG { char pad0[0x10]; int field10; char pad1[0x448 - 0x14]; DL blips; };

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

void OnBlipgRemove__FP5BLIPG(BLIPG *blipg)
{
    DLI iterator;
    PushDli(&iterator, &blipg->blips);
    for (char *item = PvFirst(&iterator); item != 0; item = PvStep(&iterator))
        RemoveBlip__FP4BLIP(item);
    RemoveLoHierarchy(blipg);
    func_001A57A8(blipg);
    if (blipg->field10 == 0)
        func_001A53E0(blipg);
    AppendDlEntry(B_002DEAF0, blipg);
    PopDli(&iterator);
}
