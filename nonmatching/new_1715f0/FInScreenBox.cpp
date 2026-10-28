#include "sly2.h"
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float LaneY(QW q) { QW t; float f; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline float LaneZ(QW q) { QW t; float f; asm volatile("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
extern "C" int FInScreenBox(float half, QW pos)
{
    int result = 0;
    if (LaneZ(pos) > 0.0001f) {
        float x = LaneX(pos);
        if (-half < x && x < half) {
            float y = LaneY(pos);
            if (-half < y && y < half) result = 1;
        }
    }
    return result;
}
