/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct LO;
struct BSP { QW *pplane; unsigned short aichild[2]; };
struct GRAPH { int cbsp; BSP *absp; int pad[2]; int cpathzone; int pad2; LO **appathzone; };
struct SWG { char pad[0x45C8]; LO *ppathzoneDefault; GRAPH *pgraph; };
extern "C" SWG B_003DD490;
extern "C" void *func_002564B8(void *);

/* lane 0 of a vector as a float */
static inline float FloatX(QW v)
{
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(v));
    return f;
}

extern "C" LO *PpathzoneFindPos(QW pos, int fDefault)
{
    GRAPH *pgraph = B_003DD490.pgraph;
    if (!pgraph)
        return 0;
    BSP *pbsp = pgraph->absp;
    BSP *pbspEnd = pbsp + pgraph->cbsp;
    LO **appathzone = pgraph->appathzone;
    BSP *pbspBase = pbsp;
    if (pbsp != pbspEnd) {
        do {
            QW a, b;
            QW plane = *pbsp->pplane;
            func_002564B8(&a);
            func_002564B8(&b);
            QW dist4, one;
            asm("vmul.xyz %0, %2, %3\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddaz.x ACC, %1, %0z\n\tvmsubw.x %0, %1, %0w"
                : "=j"(dist4), "=j"(one) : "j"(plane), "j"(pos));
            b = one;
            a = dist4;
            float dist = FloatX(dist4);
            int side = (0.0f < dist) ? 1 : 0;
            unsigned ichild = pbsp->aichild[side];
            if (ichild & 0x8000)
                return appathzone[ichild & 0x7FFF];
            pbsp = pbspBase + ichild;
        } while (pbsp != pbspEnd);
    }
    if (fDefault != 0 || pgraph->cpathzone == 0)
        return B_003DD490.ppathzoneDefault;
    return 0;
}
