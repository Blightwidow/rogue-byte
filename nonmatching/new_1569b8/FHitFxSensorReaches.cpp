#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
static inline float LaneNoNop(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline int Less(float a, float b) { return a < b; }
struct PARMS { char pad0[0x50]; int kind; float reach; char lm[1]; };
struct HITFX { char pad0[0x14]; PARMS *parms; char pad1[0x20 - 0x18]; QW pos; };
struct ALO { char pad[0x28]; unsigned long grfo; };
extern "C" QW PosLoWorld(ALO *);
struct LM;
extern "C" int FCheckLm__FP2LMf(LM *, float);
int FHitFxSensorReaches(ALO *sensor, HITFX *hitfx)
{
    register QW zeroReg asm("$0");
    if (((sensor->grfo >> 60) & 1) == 0)
        return 0;
    PARMS *parms = hitfx->parms;
    if (parms->kind != 0)
        return 0;
    QW world = PosLoWorld(sensor);
    QW spill;
    QW low;
    asm volatile("lqc2 vf1, %0" : : "m" (hitfx->pos));
    asm volatile("qmtc2.ni %0, vf2\n\tvsub.xyzw vf2, vf2, vf1\n\tqmfc2.ni %1, vf2" : "=r" (low) : "r" (world));
    float z = LaneNoNop(__builtin_pextuw(zeroReg, low));
    asm volatile("sqc2 vf2, %0" : "=m" (spill));
    if (!FCheckLm__FP2LMf((LM *)parms->lm, z))
        return 0;
    asm volatile("lqc2 vf2, %0" : : "m" (spill));
    asm volatile("vmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y");
    float reach = parms->reach;
    QW lengthBits;
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (lengthBits));
    float length = Lane(lengthBits);
    if (Less(length, reach)) return 1;
    return 0;
}
