#include "types.h"
#include "sly2.h"
struct ALO { char pad[0x28]; unsigned long grfo; };
struct AMBENT { ALO *palo; float pos[2]; float vol; };
struct AMBSLOT { AMBENT aent[8]; };
struct AMB {
    char pad0[0x1C];
    void *palo;
    QW pos;
    char pad30[0xA0 - 0x30];
    int cent[6];
    AMBSLOT aslot[6];
};
extern "C" {
int FFloatsNear__Ffff(float, float, float);
}
QW PosLoWorld(ALO *);
void UpdateAmbPositional(AMB *);
void CalculateVolPan(AMB *, QW, void *, float *, int *);
void SetAmbSlotPan(AMB *, int, int);
void SetAmbSlotVolume(AMB *, int, float);
extern QW g_2a2dd0;
#include "ps2inline.h"

static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }

void UpdateStreamAmbPositional(AMB *pamb)
{
    if (pamb->palo == 0) {
        QW pos = pamb->pos;
        QW origin = g_2a2dd0;
        int atOrigin = 0;
        if (Near(LaneX(origin), LaneX(pos))) {
            float first = LaneYInGeneralRegister((origin));
            float second = LaneYInGeneralRegister((pos));
            if (Near(first, second)) {
                atOrigin = Near(LaneZInGeneralRegister((origin)), LaneZInGeneralRegister((pos))) != 0;
            }
        }
        if (atOrigin != 0)
            goto slots;
    }
    UpdateAmbPositional(pamb);
slots:
    for (int islot = 0; islot < 6; islot++) {
        int cent = pamb->cent[islot];
        if (cent == 0)
            continue;
        float vol = 0.0f;
        int deg = 0;
        int *pdeg = &deg;
        int cactive = 0;
        for (int ient = 0; ient < cent; ient++) {
            AMBENT *pent = &pamb->aslot[islot].aent[ient];
            ALO *palo = pent->palo;
            if (palo == 0 || ((palo->grfo >> 60) & 1) == 0)
                continue;
            cactive++;
            float falloff;
            CalculateVolPan(pamb, PosLoWorld(palo), pent->pos, &falloff, pdeg);
            pdeg = 0;
            float v = falloff * pent->vol;
            vol = vol > v ? vol : v;
        }
        SetAmbSlotPan(pamb, islot, cactive != 1 ? 0 : deg);
        SetAmbSlotVolume(pamb, islot, vol);
    }
}
