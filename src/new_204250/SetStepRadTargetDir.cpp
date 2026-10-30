#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" void SetStepRadTarget(void *pstep, float rad);
extern "C" float atan2f(float y, float x);
void SetStepRadTargetDir(void *pstep, QW delta)
{
QW rotated = __builtin_prot3w(delta);
    float dx, dy;
    asm("mtc1 %2, %0\n\tmtc1 %3, %1" : "=f"(dx), "=f"(dy) : "r"(delta), "r"(rotated));
    float rad = atan2f(dy, dx);
    SetStepRadTarget(pstep, rad);
}
