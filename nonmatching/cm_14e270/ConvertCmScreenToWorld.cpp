#include "sly2.h"
struct CM { char pad[0x40]; float xRange; float yRange; };
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float LaneY(QW q) { QW t; float f; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline float LaneZ(QW q) { QW t; float f; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
QW ConvertCmScreenToWorld(CM *cm, QW pos)
{
    float local[3] __attribute__((aligned(16)));
    float zCam, xIn, sDepth;
    asm("prot3w $2, %2\n\tmtc1 $2, %0\n\tmtc1 %2, %1" : "=f" (zCam), "=f" (xIn) : "r" (pos) : "$2");
    asm("pextuw $3, $0, %1\n\tmtc1 $3, %0" : "=f" (sDepth) : "r" (pos) : "$3");
    local[2] = zCam;
    local[0] = sDepth;
    float yCam = -xIn;
    local[1] = yCam;
    if (0.0001f < sDepth) {
        local[1] = yCam * sDepth;
        local[2] = zCam * sDepth;
    }
    char *pmat = (char *)cm + 0x60;
    asm("lqc2 vf5, 0(%0)" : : "r" (pmat));
    local[1] = local[1] * cm->xRange;
    local[2] = local[2] * cm->yRange;
    asm("lqc2 vf4, 0x30(%0)" : : "r" (pmat));
    asm("lqc2 vf2, 0x10(%0)" : : "r" (pmat));
    asm("lqc2 vf1, 0x20(%0)" : : "r" (pmat));
    asm("lqc2 vf3, 0(%0)" : : "r" (local) : "memory");
    asm("vmulax.xyz ACC, vf5, vf3x");
    asm("vmadday.xyz ACC, vf2, vf3y");
    asm("vmaddaz.xyz ACC, vf1, vf3z");
    asm("vmaddw.xyz vf6, vf4, vf0w");
    register QW result asm("$2");
    asm("qmfc2.ni %0, vf6" : "=r" (result));
    return result;
}
