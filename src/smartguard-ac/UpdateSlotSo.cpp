#include "slotso.h"
extern float g_2dded0;
extern float g_2a70e0;
extern "C" {
void UpdateSo(SLOTSO *, float);
int SenseSlotSoTargetState(SLOTSO *);
int FSlotSoFacingHeading(SLOTSO *);
void FadeAloOut(SLOTSO *, float);
void SetSlotSoState(SLOTSO *, int);
void SteerSlotSoAlongCrv(SLOTSO *);
}

extern "C" void UpdateSlotSo(SLOTSO *pso, float dt)
{
    UpdateSo(pso, dt);
    int stateNext = pso->state;
    switch (pso->state) {
    case 0: {
        stateNext = SenseSlotSoTargetState(pso);
        if (stateNext != 3 && pso->tNext <= g_2dded0) {
            if (pso->pcrvWander)
                stateNext = 1;
        }
        break;
    }
    case 1:
        stateNext = SenseSlotSoTargetState(pso);
        if (stateNext != 3 && pso->tNext <= g_2dded0)
            stateNext = 0;
        break;
    case 2:
        stateNext = SenseSlotSoTargetState(pso);
        if (stateNext != 3 && FSlotSoFacingHeading(pso))
            stateNext = 1;
        break;
    case 3:
        if (pso->pactAnim == 0 && FSlotSoFacingHeading(pso))
            stateNext = 4;
        break;
    case 4:
        if (pso->tFade <= g_2dded0) {
            FadeAloOut(pso, pso->dtFade);
            pso->tFade = g_2a70e0;
        }
        break;
    }
    SetSlotSoState(pso, stateNext);
    SteerSlotSoAlongCrv(pso);
}
