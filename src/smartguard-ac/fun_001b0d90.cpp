#include "sly2.h"
struct SO;
struct CRV;
struct VT { char pad0[0xE8]; short delta; short idx; void (*pfn)(SO *, QW); };
struct SO { char pad0[0xC]; VT *pvt; char pad1[0x16C - 0x10]; CRV *pcrv; int pad2; float u; float du; };
extern "C" void SetSlotSoSmp(SO *, float);
extern "C" void SetSlotSoState(SO *, int);
extern "C" float UMinCrv(CRV *);
extern "C" float bevy_player_p5_target_1e77e8(CRV *);
extern "C" void EvaluateCrvFromU(CRV *, float, QW *, void *);
void func_001B0D90(SO *pso)
{
    SetSlotSoSmp(pso, 1.0f);
    if (pso->pcrv != 0) {
        SetSlotSoState(pso, 1);
        pso->u = UMinCrv(pso->pcrv);
        pso->du = bevy_player_p5_target_1e77e8(pso->pcrv);
        QW pos;
        EvaluateCrvFromU(pso->pcrv, pso->u, &pos, 0);
        pso->pvt->pfn((SO *)((char *)pso + pso->pvt->delta), pos);
    } else {
        SetSlotSoState(pso, 0);
    }
}
