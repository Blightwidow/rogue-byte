#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float ZeroNop() { float f; asm("mtc1 $0, %0\n\tnop" : "=f"(f)); return f; }
extern "C" {
QW PosLoWorld(void *);
QW ConvertAloPos(void *, void *, QW);
float atan2f(float, float);
float fabsf(float);
extern const float D_FLT_002BD2C0;
extern const float D_FLT_002BD2C4;
}
struct JT { char pad[0x10F8]; void *ploTarget; int nPriority; };

extern "C" int func_001430C8(JT *pjt, int nUnused, unsigned side)
{
    if (pjt->ploTarget != 0) {
        QW local = ConvertAloPos(0, pjt, PosLoWorld(pjt->ploTarget));
        float rad = atan2f(Lane(__builtin_prot3w(local)), Lane(local));
        if (fabsf(rad) < D_FLT_002BD2C0) {
            side = 0;
        } else if (D_FLT_002BD2C4 < fabsf(rad)) {
            side = 3;
        } else if (ZeroNop() < rad) {
            side = 1;
        } else {
            side = 2;
        }
    }
    int grf = 8;
    switch (pjt->nPriority) {
    case 1:
        grf = 0x10 << side;
        break;
    case 2:
        grf = 0x100 << side;
        break;
    case 3:
        grf = 0x1000;
        break;
    case 4:
        grf = 0x100;
        break;
    case -1:
    case 0:
        break;
    }
    return grf;
}
