#include "sly2.h"
static inline QW Rot(QW q) { QW r; asm volatile("prot3w %0, %1" : "=r" (r) : "r" (q)); return r; }
static inline QW Ext(QW q) { QW r; asm volatile("pextuw %0, $0, %1" : "=r" (r) : "r" (q)); return r; }
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
struct AMB { char pad[0x1C]; void *palo; QW pos; char pad1[0x40 - 0x30]; int voice; char pad2[0x4E - 0x44]; short pause; unsigned short grf; unsigned short start; };
extern QW g_2a2dd0;
extern "C" int FFloatsNear__Ffff(float, float, float);
void SetAmbGrf(AMB *, int, int);
static inline int NearLane(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
static inline int AtOrigin(QW pos)
{
    register QW zeroReg asm("$0");
    QW zero = g_2a2dd0;
    int near = 0;
    if (NearLane(Lane(zero), Lane(pos)))
        if (NearLane(Lane(Rot(zero)), Lane(Rot(pos))))
            near = NearLane(Lane(Ext(zero)), Lane(Ext(pos))) != 0;
    return near;
}
void func_001FB0C0(AMB *pamb)
{
    register QW zeroReg asm("$0");
    int busy = 0;
    if (pamb->voice == 0) { if (pamb->start != 0) busy = 1; else busy = (pamb->grf & 1) != 0; busy = busy ^ 1; }
    if (!busy) return;
    int grf = 0x1F1;
    int alt = 0x1F3;
    int gt = pamb->pause > 0;
    if (gt) grf = alt;
    if (pamb->palo != 0 || !AtOrigin(pamb->pos))
        grf |= 0x200;
    SetAmbGrf(pamb, grf, grf);
}
