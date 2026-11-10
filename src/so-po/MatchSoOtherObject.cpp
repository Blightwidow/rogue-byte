#include "sly2.h"
#include "so.h"
extern "C" void SetLoPosMatFromLo(SO *, LO *);
void MatchSoOtherObject(SO *pso, LO *other)
{
    SetLoPosMatFromLo(pso, other);
    if (pso->pphys) {
        pso->Slot35(other->GetVelocityVec());
        pso->Slot36(other->Slot34());
    }
}
