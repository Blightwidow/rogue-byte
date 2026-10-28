#include "sly2.h"
static inline QW Rot(QW q) { QW r; asm volatile("prot3w %0, %1" : "=r" (r) : "r" (q)); return r; }
static inline QW Ext(QW q) { QW r; asm volatile("pextuw %0, $0, %1" : "=r" (r) : "r" (q)); return r; }
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
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
    register QW zeroReg asm("$0");
    QW gravity = pso->pphys->gravity;
    QW zero = g_2a2dd0;
    int apply = 0;
    int near = 0;
    if (NearLane(Lane(zero), Lane(gravity))) 
        { float ay = Lane(Rot(zero)); float by = Lane(Rot(gravity));
        if (NearLane(ay, by)) 
            near = NearLane(Lane(Ext(zero)), Lane(Ext(gravity))) != 0; }
    if (!near)
        apply = pso->pphys->ctForce != 3;
    if (apply) {
        PHYS *pphys = pso->pphys;
        AddSoAcceleration(pso, ApplyConstrLocal((char *)pphys + 0xB0, pso->pxfLinear, pphys->gravity));
    }
    if (pso->driven != 0) UpdateSoDriven(pso);
}
