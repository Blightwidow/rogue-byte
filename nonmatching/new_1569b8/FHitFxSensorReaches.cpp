#include "sly2.h"
struct Sensor_156FE8 { char pad0[0x50]; int busy; float reach; char lm[1]; };
struct Probe_156FE8 { char pad0[0x14]; Sensor_156FE8 *sensor; char pad18[0x20 - 0x18]; QW position; };
struct HitFx_156FE8 { char pad0[0x28]; unsigned long flags; };
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
static inline float UpperLane(QW q) { float f; QW t; asm("pextuw %1, $0, %2\n\tmtc1 %1, %0" : "=f"(f), "=r"(t) : "r"(q)); return f; }
extern "C" {
QW PosLoWorld(HitFx_156FE8 *);
int FCheckLm__FP2LMf(void *, float);
int FHitFxSensorReaches(HitFx_156FE8 *hit, Probe_156FE8 *probe)
{
    if (((hit->flags >> 60) & 1) == 0)
        return 0;
    {
        Sensor_156FE8 *sensor = probe->sensor;
        if (sensor->busy == 0) {
            QW world = PosLoWorld(hit);
            QW spill;
            int fenceLoad, fenceSub;
            asm("lqc2 vf1, %1" : "=r"(fenceLoad) : "m"(probe->position));
            asm("qmtc2.ni %1, vf2\n\tvsub.xyzw vf2, vf2, vf1" : "=r"(fenceSub) : "r"(world), "r"(fenceLoad));
            QW delta;
            asm("qmfc2.ni %0, vf2" : "=r"(delta) : "r"(fenceSub));
            asm volatile("sqc2 vf2, %0" : "=m"(spill) : "r"(fenceSub));
            if (FCheckLm__FP2LMf(sensor->lm, UpperLane(delta)) != 0) {
                int fenceReload, fenceLen;
                asm("lqc2 vf2, %1" : "=r"(fenceReload) : "m"(spill));
                asm("vmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y\n\t.word 0x4A0103BD\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r"(fenceLen) : "r"(fenceReload));
                QW lengthBits;
                asm("qmfc2.ni %0, vf1" : "=r"(lengthBits) : "r"(fenceLen));
                float length = Lane(lengthBits);
                int inside = length < sensor->reach;
                if (inside)
                    return 1;
            }
            return 0;
        }
    }
    return 0;
}
}
