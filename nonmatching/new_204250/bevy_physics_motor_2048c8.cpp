#include "sly2.h"
static inline float Lane(QW q) { float f; asm volatile("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
struct STEP { char pad[0x210]; float g210; char pad2[0x34]; float g248; };
struct GEOM { char pad[0x94]; QW *aposWorld; char pad2[4]; char *aface; };
struct EDGE { unsigned short a, b, face1, face0; EDGE *next0; EDGE *next1; };
struct FACE { char pad[8]; float nz; int unk; EDGE *list0; EDGE *list1; };
extern "C" void ClosestPointOnSegment(QW pos, QW posA, QW posB, float *pclosest, float *pu, float *pdist);
long bevy_physics_motor_2048c8(STEP *pstep, QW pos, GEOM *pgeom, FACE *pfaceStart)
{
    struct Locals { FACE *visited[0x20]; float closest[4] __attribute__((aligned(16))); float dist; } l;
    register QW zeroReg asm("$0");
    float reach = pstep->g210 - pstep->g248;
    float reachScaled = reach * 1.45f;
    float walkable = 0.7f;
    int count = 1;
    l.visited[0] = pfaceStart;
    for (int ivisited = 0; ivisited < count; ivisited++) {
        FACE *pface = l.visited[ivisited];
        for (int ilist = 0; ilist < 2; ilist++) {
            EDGE *pedge = ilist == 0 ? pface->list0 : pface->list1;
            while (pedge) {
                float posz = Lane(__builtin_pextuw(zeroReg, pos));
                ClosestPointOnSegment(pos, pgeom->aposWorld[pedge->a], pgeom->aposWorld[pedge->b], l.closest, 0, &l.dist);
                if (reachScaled < l.dist || posz + reach < l.closest[2]) {
                } else {
                    FACE *pneighbor = (FACE *)(pgeom->aface + ((unsigned short *)((char *)pedge + 4))[1 - ilist] * 0x20);
                    if (walkable < pneighbor->nz)
                        return 1;
                    int seen = 0;
                    for (int k = 0; k < count; k++) {
                        if (l.visited[k] == pneighbor) { seen = 1; break; }
                    }
                    if (!seen && count < 0x20)
                        l.visited[count++] = pneighbor;
                }
                pedge = ilist == 0 ? pedge->next0 : pedge->next1;
            }
        }
    }
    return 0;
}
