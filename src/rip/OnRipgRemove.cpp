#include "sly2.h"
#include "dl.h"
struct RIPG { char pad[0x10]; int parent; char pad1[0xEC - 0x14]; int poxa; char pad2[0x15C - 0xF0]; DL rips; };
#include "sw.h"
struct SWX { char pad[0x406C]; RIPG *group; };
extern SWX B_003DD490;
extern "C" void RemoveRip(char *);
extern "C" void RemoveSoLoHierarchy(RIPG *);
extern "C" void FreeSwPoxa(SWX *, int);
extern "C" void func_001A57A8(RIPG *);
extern "C" void func_001A53E0(RIPG *);
extern "C" void *PdlFromSwCid(SWX *, int);
extern "C" void RemoveSlEntry(void *, RIPG *);
extern "C" void FreeSlotheapPv(void *, RIPG *);


void OnRipgRemove(RIPG *ripg)
{
    DLI iterator;
    PushDli(&iterator, &ripg->rips);
    char *item;
    for (item = (char *)PvStep(&iterator); item != 0; item = (char *)PvStep(&iterator))
        RemoveRip(item);
    if (ripg == B_003DD490.group)
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
    PopDli(&iterator);
}
