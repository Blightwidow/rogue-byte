struct ALLOCREQ { int size; int align; };
struct Stream_1EFAC0;
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
extern "C" float F32Read__18CBinaryInputStream(Stream_1EFAC0 *);
extern "C" void InitDl__FP2DLi(void *, int);
extern "C" void InitPloarray(Ploarray_1EFAC0 *);
extern "C" int IsmsFindSmRequired__FP2SM3OID(Sm_1EFAC0 *, int);
extern "C" void LoadOptionsFromBrx__FPvP18CBinaryInputStream(Sm_1EFAC0 *, Stream_1EFAC0 *);
extern "C" void LoadSwObjectsFromBrx(void *, Stream_1EFAC0 *, Ploarray_1EFAC0 *);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void *PvAllocSwImpl__Fi(ALLOCREQ *);
extern "C" int S32Read__18CBinaryInputStream(Stream_1EFAC0 *);
extern "C" int U8Read__18CBinaryInputStream(Stream_1EFAC0 *);
extern "C" void CSm_LoadFromBrx(Sm_1EFAC0 *self, Stream_1EFAC0 *stream) {
    char frame[0x10];
    Ploarray_1EFAC0 ploarray;
    ALLOCREQ request;
    int masks[0x20];
    int index = 0;
    InitDl__FP2DLi(self->list, 0x14);
    CStackFrame_Construct(frame);
    InitPloarray(&ploarray);
    LoadSwObjectsFromBrx(self->sw, stream, &ploarray);
    if (ploarray.count > 0) {
        do {
            Plo_1EFAC0 *plo = ploarray.items[index];
            index += 1;
            plo->vt->fn((char *)plo + plo->vt->delta);
        } while (index < ploarray.count);
    }
    index = 0;
    self->nodeCount = U8Read__18CBinaryInputStream(stream);
    request.size = self->nodeCount * 8;
    request.align = 0x10;
    self->nodes = (Node_1EFAC0 *)PvAllocSwImpl__Fi(&request);
    if (self->nodeCount > 0) {
        do {
            Node_1EFAC0 *node = &self->nodes[index];
            index += 1;
            node->id = S32Read__18CBinaryInputStream(stream);
            node->oid = S32Read__18CBinaryInputStream(stream);
        } while (index < self->nodeCount);
    }
    index = 0;
    if (self->nodeCount > 0) {
        do {
            Node_1EFAC0 *node = &self->nodes[index];
            switch (node->oid) {
            case 32:
                node->oid = -2;
                break;
            case -1:
                break;
            default:
                node->oid = IsmsFindSmRequired__FP2SM3OID(self, node->oid);
                break;
            }
            index += 1;
        } while (index < self->nodeCount);
    }
    int allFlags = 0;
    self->edgeCount = U8Read__18CBinaryInputStream(stream);
    index = 0;
    request.size = self->edgeCount * 0x18;
    request.align = 0x10;
    self->edges = (Edge_1EFAC0 *)PvAllocStackClearImpl__Fi(&request);
    if (self->edgeCount > 0) {
        int offset = 0;
        do {
            Edge_1EFAC0 *edge = (Edge_1EFAC0 *)((char *)self->edges + offset);
            edge->x10 = S32Read__18CBinaryInputStream(stream);
            edge->x14 = F32Read__18CBinaryInputStream(stream);
            edge->to = IsmsFindSmRequired__FP2SM3OID(self, S32Read__18CBinaryInputStream(stream));
            edge->from = IsmsFindSmRequired__FP2SM3OID(self, S32Read__18CBinaryInputStream(stream));
            edge->flags = S32Read__18CBinaryInputStream(stream);
            int objectId = S32Read__18CBinaryInputStream(stream);
            if (objectId != -1) {
                if (ploarray.count > 0) {
                    Plo_1EFAC0 *found = ploarray.items[0];
                    if (found->id != objectId) {
                        int search = 1;
                        for (;;) {
                            if (search >= ploarray.count) {
                                break;
                            }
                            found = ploarray.items[search];
                            if (found->id == objectId) {
                                edge->object = found;
                                break;
                            }
                            search += 1;
                        }
                    } else {
                        edge->object = found;
                    }
                }
                if (edge->object == 0) {
                    offset -= 0x18;
                    index -= 1;
                    self->edgeCount -= 1;
                } else {
                    allFlags |= edge->flags & 0xFFFC;
                }
            } else {
                allFlags |= edge->flags & 0xFFFC;
            }
            index += 1;
            offset += 0x18;
        } while (index < self->edgeCount);
    }
    request.size = self->edgeCount * 0x18;
    request.align = 0x10;
    self->edges = (Edge_1EFAC0 *)PvAllocSwCopyImpl__FiPv(&request, self->edges);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(self, stream);
    int groupCount = 0;
    int bit = 4;
    int bitTest = 4 & allFlags;
    do {
        if (bitTest != 0) {
            int search = 0;
            if (groupCount > 0) {
                int *mask = masks;
                for (;;) {
                    search += 1;
                    if (bit & *mask) {
                        goto next;
                    }
                    mask += 1;
                    if (search >= groupCount) {
                        break;
                    }
                }
            }
            {
                int merged = allFlags;
                int count = self->edgeCount;
                if (count > 0) {
                    Edge_1EFAC0 *edge = self->edges;
                    int remaining = count;
                    do {
                        int flags = edge->flags;
                        remaining -= 1;
                        edge += 1;
                        merged = (flags & bit) ? (merged & flags) : merged;
                    } while (remaining != 0);
                }
                if (count > 0) {
                    Edge_1EFAC0 *edge = self->edges;
                    int remaining = count;
                    do {
                        int flags = edge->flags;
                        if ((flags & merged) && !(flags & bit)) {
                            merged &= ~flags;
                        }
                        remaining -= 1;
                        edge += 1;
                    } while (remaining != 0);
                }
                masks[groupCount] = merged;
                groupCount += 1;
            }
        }
    next:
        bit *= 2;
        bitTest = bit & allFlags;
    } while (bit < 0x1001);
    request.size = groupCount * 8;
    request.align = 0x10;
    index = 0;
    self->groupCount = groupCount;
    self->groups = (Group_1EFAC0 *)PvAllocSwImpl__Fi(&request);
    if (self->groupCount > 0) {
        do {
            Group_1EFAC0 *group = &self->groups[index];
            group->mask = masks[index];
            request.align = 0x10;
            int nodeCount = self->nodeCount;
            request.size = nodeCount * nodeCount;
            group->matrix = (signed char *)PvAllocSwImpl__Fi(&request);
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
            signed char round = 1;
            int changed;
            do {
                changed = 0;
                for (int edgeIndex = 0; edgeIndex < self->edgeCount; edgeIndex++) {
                    Edge_1EFAC0 *edge = &self->edges[edgeIndex];
                    if (edge->flags & group->mask) {
                        for (int node = 0; node < self->nodeCount; node++) {
                            int rowBase = node * self->nodeCount;
                            signed char *matrix = group->matrix;
                            if (matrix[rowBase + edge->from] != round - 1 || matrix[rowBase + edge->to] >= 0) {
                                if (edge->flags & 1) {
                                    if (matrix[rowBase + edge->to] == round - 1 && matrix[rowBase + edge->from] < 0) {
                                        matrix[rowBase + edge->from] = round;
                                        changed = 1;
                                    }
                                }
                            } else {
                                matrix[rowBase + edge->to] = round;
                                changed = 1;
                            }
                        }
                    }
                }
                round += 1;
            } while (changed != 0);
            index += 1;
        } while (index < self->groupCount);
    }
    CStackFrame_Destructor(frame, 2);
}
