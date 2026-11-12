// SPDX-License-Identifier: GPL-3.0-or-later
#include "vu0inline.h"
#include "ps2inline.h"
#include "sly2.h"
struct PHYS { char pad[0x80]; QW gravity; char pad1[0xC0 - 0x90]; int ctForce; };
struct SO { char pad[0x58]; void *pxfLinear; char pad1[0xE8 - 0x5C]; PHYS *pphys; char pad2[0x138 - 0xEC]; int driven; };
extern QW g_2a2dd0;
extern "C" int FFloatsNear__Ffff(float, float, float);
QW ApplyConstrLocal(void *, void *, QW);
void AddSoAcceleration(SO *, QW);
void UpdateSoDriven(SO *);
static inline int NearLane(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
void AddSoGravityAcceleration(SO *pso)
{
    QW gravity = pso->pphys->gravity;
    QW zero = g_2a2dd0;
    int apply = 0;
    int near = 0;
    if (NearLane(LaneX(zero), LaneX(gravity))) {
        if (NearLane(LaneYInGeneralRegister(zero), LaneYInGeneralRegister(gravity))) {
            near = NearLane(LaneZInGeneralRegister(zero), LaneZInGeneralRegister(gravity)) != 0;
        }
    }
    if (!near)
        apply = pso->pphys->ctForce != 3;
    if (apply) {
        PHYS *pphys = pso->pphys;
        AddSoAcceleration(pso, ApplyConstrLocal((char *)pphys + 0xB0, pso->pxfLinear, pphys->gravity));
    }
    if (pso->driven != 0) UpdateSoDriven(pso);
}
