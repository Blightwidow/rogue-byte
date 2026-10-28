#include "sly2.h"
struct AMB { char pad0[0x1C]; void *palo; QW pos; };
extern "C" {
int FFloatsNear__Ffff(float, float, float);
void SetAmbGrf(AMB *, int, int);
}
extern QW g_2a2dd0;
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW RotY(QW q) { QW t; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); return t; }
static inline QW RotZ(QW q) { QW t; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); return t; }
static inline QW RotY2(QW q, QW prev) { QW t; asm("prot3w %0, %1" : "=r" (t) : "r" (q), "0" (prev)); return t; }
static inline QW RotZ2(QW q, QW prev) { QW t; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q), "0" (prev)); return t; }
static inline float Mtc1(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
void SetAmbPos(AMB *pamb, QW pos)
{
    pamb->pos = pos;
    QW origin = g_2a2dd0;
    int atOrigin = 0;
    if (Near(LaneX(origin), LaneX(pos))) {
        QW ty = RotY(origin);
        float oy = Mtc1(ty);
        if (Near(oy, Mtc1(RotY2(pos, ty)))) {
            QW tz = RotZ(origin);
            float oz = Mtc1(tz);
            atOrigin = Near(oz, Mtc1(RotZ2(pos, tz))) != 0;
        }
    }
    if (atOrigin == 0) {
        SetAmbGrf(pamb, 0x200, 0x200);
    } else if (pamb->palo == 0) {
        SetAmbGrf(pamb, 0x200, 0);
    }
}
