#include "sly2.h"
#include "ps2inline.h"
struct STEP { char pad[0x210]; float g210; char pad2[0x34]; float g248; };
struct GEOM { char pad[0x94]; QW *aposWorld; char pad2[4]; char *aface; };
struct EDGE { unsigned short a, b; char faceByte[4]; EDGE *next0; EDGE *next1; };
struct FACE { char pad[8]; float nz; int unk; EDGE *list0; EDGE *list1; };
extern "C" void ClosestPointOnSegment(QW pos, QW posA, QW posB, float *pclosest, float *pu, float *pdist);
long bevy_physics_motor_2048c8(STEP *pstep, QW pos, GEOM *pgeom, FACE *pfaceStart)
{
    struct Locals { FACE *visited[0x20]; float closest[4] __attribute__((aligned(16))); float dist; } l;
    float reach = pstep->g210 - pstep->g248;
    float reachScaled = reach * 1.45f;
    float walkable = 0.7f;
    int count = 1;
    l.visited[0] = pfaceStart;
    for (int ivisited = 0; ivisited < count; ivisited++) {
        FACE *pface = l.visited[ivisited];
                for (int ilist = 0; ilist < 2; ilist++) {
            EDGE *pedge = ilist == 0 ? pface->list0 : pface->list1;
            float posz = LaneZ(pos);
            while (pedge) {
                ClosestPointOnSegment(pos, pgeom->aposWorld[pedge->a], pgeom->aposWorld[pedge->b], l.closest, 0, &l.dist);
                if (reachScaled < l.dist || posz + reach < l.closest[2]) {
                } else {
                    FACE *pneighbor = (FACE *)(pgeom->aface + *(unsigned short *)&pedge->faceByte[2 - ilist * 2] * 0x20);
                    if (walkable < pneighbor->nz)
                        return 1;
                    for (int k = 0;; k++) {
                        if (k >= count) {
                            if ((unsigned)count < 0x20)
                                l.visited[count++] = pneighbor;
                            break;
                        }
                        if (l.visited[k] == pneighbor)
                            break;
                    }
                }
                pedge = ilist == 0 ? pedge->next0 : pedge->next1;
            }
        }
    }
    return 0;
}
