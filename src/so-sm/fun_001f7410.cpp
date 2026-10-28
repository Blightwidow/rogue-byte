#include "sly2.h"
struct PARTX { char pad[0x14]; short damage; short pad2; int grftak; };
struct HALF { PARTX *ppart; char pad0[4]; void *pso; void *plo; QW pos; QW unk20; QW vel; };
struct CONTACT { HALF half[2]; char pad[0xAC - 0x80]; CONTACT *pnext; };
struct PHYS { char pad[0x6C]; CONTACT *pcontact; };
struct SO { char pad[0xEC]; PHYS *pphys; };
struct WKR { void *source; PARTX *partsource; void *target; int grftak; int damage; char pad[0x20 - 0x14]; QW pos; QW vel; char pad2[0x60 - 0x40]; };
struct SW; struct MQ;
extern "C" {
extern char B_003DD490;
void *PaloFindWkrAbsorber(void *, int);
void *PaloAbsorbWkr(WKR *);
void FreeSwMqList__FP2SWP2MQ(void *, void *);
}
void func_001F7410(SO *pso)
{
    for (CONTACT *contact = pso->pphys->pcontact; contact != 0; contact = contact->pnext) {
        int second = contact->half[0].pso != pso;
        HALF *self = &contact->half[second];
        if (self->ppart->grftak == 0) continue;
        HALF *other = &contact->half[1 - second];
        void *target = PaloFindWkrAbsorber(other->plo, self->ppart->grftak);
        if (target == 0) continue;
        WKR wkr;
        memset(&wkr, 0, sizeof(WKR));
        wkr.source = pso;
        wkr.partsource = self->ppart;
        wkr.target = target;
        wkr.grftak = self->ppart->grftak;
        wkr.damage = self->ppart->damage;
        wkr.pos = other->pos;
        wkr.vel = self->vel;
        PaloAbsorbWkr(&wkr);
        if (pso->pphys == 0) return;
    }
    if (pso->pphys != 0) {
        FreeSwMqList__FP2SWP2MQ(&B_003DD490, pso->pphys->pcontact);
        pso->pphys->pcontact = 0;
    }
}
