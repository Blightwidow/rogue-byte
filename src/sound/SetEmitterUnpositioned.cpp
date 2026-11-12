// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "sly2.h"
struct AMB { char pad0[0x1C]; void *palo; QW pos; };
extern "C" {
int FFloatsNear__Ffff(float, float, float);
void SetAmbGrf(AMB *, int, int);
}
extern QW g_2a2dd0;
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
void SetEmitterUnpositioned(AMB *pamb, void *palo)
{
    pamb->palo = palo;
    if (palo != 0) {
        SetAmbGrf(pamb, 0x200, 0x200);
        return;
    }
    QW pos = pamb->pos;
    QW origin = g_2a2dd0;
    int atOrigin = 0;
    if (Near(LaneX(origin), LaneX(pos))) {
        if (Near(LaneYInGeneralRegister(origin), LaneYInGeneralRegister(pos))) {
            atOrigin = Near(LaneZInGeneralRegister(origin), LaneZInGeneralRegister(pos)) != 0;
        }
    }
    if (atOrigin)
        SetAmbGrf(pamb, 0x200, 0);
}
