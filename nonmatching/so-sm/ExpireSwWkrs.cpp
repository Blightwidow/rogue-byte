struct DL { char *first; char *last; int ibDle; };
struct DLI { DL *list; char *current; int offset; DLI *next; };
struct SW { char pad0[0x4118]; char slotheap[0x18]; DL dlWkr; };
struct WKR { char pad[0x4C]; float t; };
extern DLI *g_2dd2fc;
extern float g_2dded0;
extern "C" void FreeSlotheapPv(void *, void *);
extern "C" void RemoveDlEntry(void *, void *);

inline void PushDli(DLI *it, DL *list)
{
    it->current = (char *)list;
    it->list = list;
    DLI *old = g_2dd2fc;
    g_2dd2fc = it;
    it->offset = list->ibDle;
    it->next = old;
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

void ExpireSwWkrs(SW *psw)
{
    DLI dli;
    PushDli(&dli, &psw->dlWkr);
    for (char *pwkr = PvFirst(&dli); pwkr != 0; pwkr = PvStep(&dli)) {
        if (g_2dded0 < ((WKR *)pwkr)->t + 0.25f) {
        } else {
            RemoveDlEntry(&psw->dlWkr, pwkr);
            FreeSlotheapPv(psw->slotheap, pwkr);
        }
    }
    g_2dd2fc = dli.next;
}
