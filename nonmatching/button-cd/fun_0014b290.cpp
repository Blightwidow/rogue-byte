#include "sly2.h"
struct Entry { char *object; int active; int pad[2]; };
struct List { char pad[0xFC]; int count; Entry entry[1]; };
struct Sgs { char pad[0x38C]; char *current; char *guard; char pad2[0xF64 - 0x394]; List *list; };
extern "C" {
int FIsGuardInSgs(void *, int);
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
void *func_002082D0(void *);
extern float g_2bd4b0[3];
}
extern "C" char *func_0014B290(Sgs *psgs)
{
    if (FIsGuardInSgs(psgs, 0x24) != 0)
        return (char *)func_002082D0(psgs);
    char *result = 0;
    float bestDistance;
    int bestRank;
    QW origin;
    int index;
    char *guard = psgs->guard;
    if (guard != 0) {
        if ((int)(*(unsigned long *)(guard + 0x28) >> 60) & 1) {
            result = guard;
            goto done;
        }
    }
    bestDistance = 3.4028235e38f;
    bestRank = 0x3E7;
    origin = PosLoWorld(psgs);
    for (index = 0; index < psgs->list->count; index++) {
        Entry *entry = (Entry *)((char *)psgs->list + 0x100 + index * 0x10);
        if (entry->active != 0) {
        int rank;
        if (FIsBasicDerivedFrom(entry->object, 0x34) == 0)
            rank = FIsBasicDerivedFrom(entry->object, 0x3A) != 0 ? 1 : 2;
        else
            rank = 0;
        QW position = PosLoWorld(entry->object);
        float distance;
        asm volatile("lqc2 vf2, %0" : : "m" (origin));
        asm volatile("qmtc2.ni %0, vf3" : : "r" (position));
        char *objectNow = entry->object;
        asm volatile("vsub.xyzw vf1, vf2, vf3");
        char *currentNow = psgs->current;
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        asm volatile("qmfc2.ni %0, vf1" : "=r" (distance));
        if (objectNow == currentNow)
            distance = g_2bd4b0[0] + distance * (g_2bd4b0[1] + distance * g_2bd4b0[2]);
        if (rank < bestRank || (rank == bestRank && distance < bestDistance)) {
            bestRank = rank;
            bestDistance = distance;
            result = entry->object;
        }
        }
    }
done:
    return result;
}
