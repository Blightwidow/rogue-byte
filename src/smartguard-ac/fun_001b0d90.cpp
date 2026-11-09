#include "sly2.h"
struct CRV;
#include "slotso.h"
extern "C" void SetSlotSoSmp(SLOTSO *, float);
extern "C" void SetSlotSoState(SLOTSO *, int);
extern "C" float UMinCrv(CRV *);
extern "C" float bevy_player_p5_target_1e77e8(CRV *);
extern "C" void EvaluateCrvFromU(CRV *, float, QW *, void *);
void func_001B0D90(SLOTSO *pso)
{
    SetSlotSoSmp(pso, 1.0f);
    if (pso->pcrvWander != 0) {
        SetSlotSoState(pso, 1);
        pso->uWander = UMinCrv(pso->pcrvWander);
        pso->duWander = bevy_player_p5_target_1e77e8(pso->pcrvWander);
        QW pos;
        EvaluateCrvFromU(pso->pcrvWander, pso->uWander, &pos, 0);
        pso->TranslateToPos(pos);
    } else {
        SetSlotSoState(pso, 0);
    }
}
