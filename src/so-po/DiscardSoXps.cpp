#include "sly2.h"
struct SO;
struct VT { char pad[0x1B0]; short delta; short index; void (*fn)(void *, void *); };
struct LINK { int pmq; LINK *next; int *pcount; SO *pso; };
struct OXA { char pad[0x60]; SO *owner; LINK *first; int pmqList; };
struct SO { char pad0[0xC]; VT *vt; char pad1[0xDC]; OXA *oxa; };
struct SW;
struct MQ;
extern "C" void func_001F4BF8(SO *);
extern SW B_003DD490;
void FreeSwMqList(SW *, MQ *);
void DiscardSoXps(SO *pso)
{
    if (pso->oxa) {
        func_001F4BF8(pso);
        LINK *link = pso->oxa->first;
        if (link) {
            do {
                SO *owner = pso->oxa->owner;
                owner->vt->fn((char *)owner + owner->vt->delta, link->pso);
                SO *other = link->pso;
                other->vt->fn((char *)other + other->vt->delta, pso->oxa->owner);
                FreeSwMqList(&B_003DD490, (MQ *)link->pmq);
                *link->pcount = 0;
                link->pmq = 0;
                link = link->next;
            } while (link);
        }
        pso->vt->fn((char *)pso + pso->vt->delta, 0);
        FreeSwMqList(&B_003DD490, (MQ *)pso->oxa->pmqList);
        pso->oxa->pmqList = 0;
    }
}
