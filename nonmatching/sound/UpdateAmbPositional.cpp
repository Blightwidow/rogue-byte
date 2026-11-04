#include "sly2.h"
struct ALO { char pad[0x28]; unsigned long grfo; };
struct AMB;
struct AMBVT { char pad[0x78]; short delta; short index; void (*fn)(void *, int); };
struct AMB { char pad[0xC]; AMBVT *vptr; float vol; int unk14[2]; ALO *palo; QW pos; char start[0x44 - 0x30]; float volEffective; };
extern "C" {
void StopAmb(AMB *, float);
}
QW ConvertAloPos(ALO *, int, QW);
void CalculateVolPan(AMB *, QW, void *, float *, int *);
void SetAmbPan(AMB *, int);
void SetAmbGrf(AMB *, int, int);
void UpdateAmbPositional(AMB *pamb)
{
    ALO *palo = pamb->palo;
    if (palo != 0 && ((palo->grfo >> 60) & 1) == 0) {
        StopAmb(pamb, 0.0f);
        return;
    }
    QW world = ConvertAloPos(pamb->palo, 0, pamb->pos);
    float falloff;
    int deg;
    CalculateVolPan(pamb, world, pamb->start, &falloff, &deg);
    float effective = pamb->vol * falloff;
    if ((int)(effective * 1024.0f) != (int)(pamb->volEffective * 1024.0f)) {
        if (pamb->volEffective == 0.0f) {
            pamb->vptr->fn((char *)pamb + pamb->vptr->delta, 0);
        } else if (effective == 0.0f) {
            pamb->vptr->fn((char *)pamb + pamb->vptr->delta, 1);
        }
        pamb->volEffective = effective;
        SetAmbGrf(pamb, 0x10, 0x10);
    }
    SetAmbPan(pamb, deg);
}
