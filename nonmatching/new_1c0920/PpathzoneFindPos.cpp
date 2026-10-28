/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct LO;
struct BSP { QW *pplane; unsigned short aichild[2]; };
struct GRAPH { int cbsp; BSP *absp; int pad[2]; int cpathzone; int pad2; LO **appathzone; };
struct SWG { char pad[0x45C8]; LO *ppathzoneDefault; GRAPH *pgraph; };
extern "C" SWG B_003DD490;
extern "C" void *func_002564B8(void *);
extern "C" LO *PpathzoneFindPos(QW pos, int fDefault)
{
    struct L { QW a; QW b; QW pos; QW plane; } l;
    l.pos = pos;
    GRAPH *pgraph = B_003DD490.pgraph;
    if (!pgraph)
        return 0;
    BSP *pbsp = pgraph->absp;
    BSP *pbspEnd = pbsp + pgraph->cbsp;
    LO **appathzone = pgraph->appathzone;
    BSP *pbspBase = pbsp;
    if (pbsp != pbspEnd) {
        do {
            asm("lqc2 vf1, %1\n\tsqc2 vf1, %0" : "=m" (l.plane) : "m" (*pbsp->pplane));
            func_002564B8(&l.a);
            func_002564B8(&l.b);
            float dist;
            int tmp;
            asm("lqc2 vf1, %2\n\tlqc2 vf3, %3\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf1w\n\tqmfc2.ni %1, vf1\n\tmtc1 %1, %0" : "=f" (dist), "=&r" (tmp) : "m" (l.plane), "m" (l.pos));
            asm("sqc2 vf2, %0" : "=m" (l.b));
            int side = (0.0f < dist) ? 1 : 0;
            asm("sqc2 vf1, %0" : "=m" (l.a));
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
