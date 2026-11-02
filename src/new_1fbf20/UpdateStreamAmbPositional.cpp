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
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW RotY(QW q) { QW t; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); return t; }
static inline QW RotZ(QW q) { QW t; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); return t; }
static inline QW RotY2(QW q, QW prev) { QW t; asm("prot3w %0, %1" : "=r" (t) : "r" (q), "0" (prev)); return t; }
static inline QW RotZ2(QW q, QW prev) { QW t; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q), "0" (prev)); return t; }
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }

void UpdateStreamAmbPositional(AMB *pamb)
{
    if (pamb->palo == 0) {
        QW pos = pamb->pos;
        QW origin = g_2a2dd0;
        int atOrigin = 0;
        if (Near(LaneX(origin), LaneX(pos))) {
            QW ty = RotY(origin);
            float oy = LaneX(ty);
            if (Near(oy, LaneX(RotY2(pos, ty)))) {
                QW tz = RotZ(origin);
                float oz = LaneX(tz);
                atOrigin = Near(oz, LaneX(RotZ2(pos, tz))) != 0;
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
