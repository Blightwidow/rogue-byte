#include "alloc.h"
#include "bis.h"
struct VT_1EFAC0 { char pad[0x48]; short delta; short unused; void (*fn)(void *); };
struct Plo_1EFAC0 { char pad[0xC]; VT_1EFAC0 *vt; char pad2[0x18 - 0x10]; int id; };
struct Ploarray_1EFAC0 { int a; int b; int count; Plo_1EFAC0 **items; };
struct Node_1EFAC0 { int id; int oid; };
struct Edge_1EFAC0 { Plo_1EFAC0 *object; int from; int to; int flags; int x10; float x14; };
struct Group_1EFAC0 { int mask; signed char *matrix; };
struct Sm_1EFAC0 {
    char pad[0x10]; void *sw; char pad2[0x50 - 0x14]; int nodeCount; Node_1EFAC0 *nodes; int edgeCount; Edge_1EFAC0 *edges;
    int groupCount; Group_1EFAC0 *groups; char list[1];
};
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void InitDl__FP2DLi(void *, int);
extern "C" void InitPloarray(Ploarray_1EFAC0 *);
extern "C" int IsmsFindSmRequired__FP2SM3OID(Sm_1EFAC0 *, int);
extern "C" void LoadOptionsFromBrx__FPvP18CBinaryInputStream(Sm_1EFAC0 *, CBinaryInputStream *);
extern "C" void LoadSwObjectsFromBrx(void *, CBinaryInputStream *, Ploarray_1EFAC0 *);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
static inline void *PvAllocSw(ALLOCREQ *preq, int cb)
{
    preq->cb = cb;
    preq->cbAlign = 0x10;
    return PvAllocSwImpl__Fi(preq);
}
static inline void *PvAllocStackClear(ALLOCREQ *preq, int cb)
{
    preq->cb = cb;
    preq->cbAlign = 0x10;
    return PvAllocStackClearImpl__Fi(preq);
}
static inline void *PvAllocSwCopy(ALLOCREQ *preq, int cb, void *pv)
{
    preq->cb = cb;
    preq->cbAlign = 0x10;
    return PvAllocSwCopyImpl__FiPv(preq, pv);
}
extern "C" void CSm_LoadFromBrx(Sm_1EFAC0 *self, CBinaryInputStream *pbis) {
    char frame[0x10];
    Ploarray_1EFAC0 ploarray;
    ALLOCREQ request;
    int masks[0x20];
    int i;
    InitDl__FP2DLi(self->list, 0x14);
    CStackFrame_Construct(frame);
    InitPloarray(&ploarray);
    LoadSwObjectsFromBrx(self->sw, pbis, &ploarray);
    for (i = 0; i < ploarray.count; i++) {
        Plo_1EFAC0 *plo = ploarray.items[i];
        plo->vt->fn((char *)plo + plo->vt->delta);
    }
    self->nodeCount = pbis->U8Read();
    self->nodes = (Node_1EFAC0 *)PvAllocSw(&request, self->nodeCount * 8);
    for (i = 0; i < self->nodeCount; i++) {
        Node_1EFAC0 *node = &self->nodes[i];
        node->id = pbis->S32Read();
        node->oid = pbis->S32Read();
    }
    for (i = 0; i < self->nodeCount; i++) {
        Node_1EFAC0 *node = &self->nodes[i];
        switch (node->oid) {
        case -1:
            node->oid = -1;
            break;
        case 32:
            node->oid = -2;
            break;
        default:
            node->oid = IsmsFindSmRequired__FP2SM3OID(self, node->oid);
            break;
        }
    }
    int allFlags = 0;
    self->edgeCount = pbis->U8Read();
    self->edges = (Edge_1EFAC0 *)PvAllocStackClear(&request, self->edgeCount * 0x18);
    int iedge;
    for (iedge = 0; iedge < self->edgeCount; iedge++) {
        Edge_1EFAC0 *edge = &self->edges[iedge];
        edge->from = IsmsFindSmRequired__FP2SM3OID(self, pbis->S32Read());
        edge->to = IsmsFindSmRequired__FP2SM3OID(self, pbis->S32Read());
        edge->flags = pbis->S32Read();
        edge->x10 = pbis->S32Read();
        edge->x14 = pbis->F32Read();
        int objectId = pbis->S32Read();
        if (objectId != -1) {
            for (i = 0; i < ploarray.count; i++) {
                Plo_1EFAC0 *plo = ploarray.items[i];
                if (plo->id == objectId) {
                    edge->object = plo;
                    break;
                }
            }
            if (edge->object == 0) {
                iedge--;
                self->edgeCount--;
                continue;
            }
        }
        allFlags |= edge->flags & 0xFFFC;
    }
    self->edges = (Edge_1EFAC0 *)PvAllocSwCopy(&request, self->edgeCount * 0x18, self->edges);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(self, pbis);
    int groupCount = 0;
    for (int bit = 4; bit < 0x1001; bit *= 2) {
        if (bit & allFlags) {
            for (int j = 0; j < groupCount; j++) {
                if (bit & masks[j]) {
                    goto next;
                }
            }
            {
                int merged = allFlags;
                for (iedge = 0; iedge < self->edgeCount; iedge++) {
                    if (self->edges[iedge].flags & bit) {
                        merged &= self->edges[iedge].flags;
                    }
                }
                for (iedge = 0; iedge < self->edgeCount; iedge++) {
                    int flags = self->edges[iedge].flags;
                    if ((flags & merged) && !(flags & bit)) {
                        merged &= ~flags;
                    }
                }
                masks[groupCount] = merged;
                groupCount += 1;
            }
        }
    next:;
    }
    int igroup = 0;
    self->groupCount = groupCount;
    self->groups = (Group_1EFAC0 *)PvAllocSw(&request, groupCount * 8);
    if (self->groupCount > 0) {
        do {
            Group_1EFAC0 *group = &self->groups[igroup];
            group->mask = masks[igroup];
            group->matrix = (signed char *)PvAllocSw(&request, self->nodeCount * self->nodeCount);
            for (int row = 0; row < self->nodeCount; row++) {
                for (int column = 0; column < self->nodeCount; column++) {
                    signed char *cell = group->matrix + (row * self->nodeCount + column);
                    if (row != column) {
                        *cell = -1;
                    } else {
                        *cell = 0;
                    }
                }
            }
            int round = 1;
            int changed;
            do {
                changed = 0;
                for (iedge = 0; iedge < self->edgeCount; iedge++) {
                    Edge_1EFAC0 *edge = &self->edges[iedge];
                    if (edge->flags & group->mask) {
                        for (i = 0; i < self->nodeCount; i++) {
                            if (group->matrix[i * self->nodeCount + edge->from] == round - 1 &&
                                group->matrix[i * self->nodeCount + edge->to] < 0) {
                                group->matrix[i * self->nodeCount + edge->to] = round;
                                changed = 1;
                            } else if ((edge->flags & 1) && group->matrix[i * self->nodeCount + edge->to] == round - 1 &&
                                       group->matrix[i * self->nodeCount + edge->from] < 0) {
                                group->matrix[i * self->nodeCount + edge->from] = round;
                                changed = 1;
                            }
                        }
                    }
                }
                round++;
            } while (changed);
            igroup += 1;
        } while (igroup < self->groupCount);
    }
    CStackFrame_Destructor(frame, 2);
}
