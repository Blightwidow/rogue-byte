// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "sly2.h"
struct AMB { char pad0[0x1C]; void *palo; QW pos; char pad1[0x40 - 0x30]; int voice; char pad2[0x4E - 0x44]; short pause; unsigned short grf; unsigned short start; };
extern "C" {
int FFloatsNear__Ffff(float, float, float);
void SetAmbGrf(AMB *, int, int);
}
extern QW g_2a2dd0;
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
static inline bool FAmbStarting(AMB *pamb) { return pamb->start != 0 || (pamb->grf & 1) != 0; }
void func_001FB0C0(AMB *pamb)
{
    int fReplay = 0;
    if (pamb->voice == 0)
        fReplay = !FAmbStarting(pamb);
    if (!fReplay)
        return;
    int fPaused = pamb->pause > 0;
    int grf = 0x1F1;
    if (fPaused)
        grf = 0x1F3;
    if (pamb->palo == 0) {
        QW pos = pamb->pos;
        QW origin = g_2a2dd0;
        int atOrigin = 0;
        if (Near(LaneX(origin), LaneX(pos))) {
            if (Near(LaneYInGeneralRegister(origin), LaneYInGeneralRegister(pos))) {
                atOrigin = Near(LaneZInGeneralRegister(origin), LaneZInGeneralRegister(pos)) != 0;
            }
        }
        if (atOrigin)
            goto set;
    }
    grf |= 0x200;
set:
    SetAmbGrf(pamb, grf, grf);
}
