#include "sly2.h"
struct PHYS { char pad[0x6C]; void *pcontact; };
struct SOVT { char pad[0x108]; short d108; short i108; QW (*vel)(void *); char pad2[0x250 - 0x110]; short d250; short i250; void (*absorb)(void *); };
struct SO { char pad0[0xC]; SOVT *vptr; char pad1[0xEC - 0x10]; PHYS *pphys; char pad2[0x148 - 0xF0]; unsigned long impact; };
struct WKR { void *source; void *partsource; void *target; int grftak; int damage; char pad[0x20 - 0x14]; QW pos; QW vel; char pad2[0x60 - 0x40]; };
extern "C" {
extern void *g_2f7900;
void func_001F7A68(SO *, int);
void *PaloAbsorbWkr(WKR *);
}
QW PosLoWorld(SO *);
int FIsBasicDerivedFrom(SO *, int);
void func_001F7950(SO *pso)
{
    if (pso->pphys == 0) return;
    if (pso->pphys->pcontact != 0)
        pso->vptr->absorb((char *)pso + pso->vptr->d250);
    if (pso->pphys == 0) return;
    int kind = ((int)((pso->impact << 8) >> 32)) & 3;
    if (kind == 0) return;
    func_001F7A68(pso, 0);
    WKR wkr;
    memset(&wkr, 0, sizeof(WKR));
    wkr.target = pso;
    wkr.pos = PosLoWorld(pso);
    wkr.vel = pso->vptr->vel((char *)pso + pso->vptr->d108);
    if (kind == 3 && FIsBasicDerivedFrom(pso, 0x38) != 0) {
        wkr.grftak = 0x40000;
        wkr.damage = -50;
        wkr.source = g_2f7900;
    } else {
        wkr.grftak = 0x20000;
        wkr.damage = *((signed char *)pso + 0x149);
        wkr.source = pso;
    }
    PaloAbsorbWkr(&wkr);
}
