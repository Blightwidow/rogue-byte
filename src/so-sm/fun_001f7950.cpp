#include "sly2.h"
#include "so.h"
struct OXA { char pad[0x6C]; void *pcontact; };
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
    if (pso->poxa == 0) return;
    if (pso->poxa->pcontact != 0)
        pso->Slot74();
    if (pso->poxa == 0) return;
    int kind = ((int)((pso->grfso << 8) >> 32)) & 3;
    if (kind == 0) return;
    func_001F7A68(pso, 0);
    WKR wkr;
    memset(&wkr, 0, sizeof(WKR));
    wkr.target = pso;
    wkr.pos = PosLoWorld(pso);
    wkr.vel = pso->GetVelocityVec();
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
