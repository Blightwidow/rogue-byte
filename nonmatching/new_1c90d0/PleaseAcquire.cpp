typedef int QW __attribute__((mode(TI)));
struct Lease_1CAEC8 { void *pool; Lease_1CAEC8 *next; int pad[2]; QW matrix[4]; };
struct Slot_1CAEC8 { int kind; int pad; char *source; int bisStart; int bisSize; int *out; };
struct Set_1CAEC8 { char pad[0x6C]; };
struct Cnode_1CAEC8 { char pad[0x10]; int *object; };
struct Base_1CAEC8;
struct VT_1CAEC8 {
    char pad0[0x18]; short delta18; short unused18; void (*fn18)(void *, int, int, int, void *, int);
    char pad1[0x40 - 0x20]; short delta40; short unused40; void (*fn40)(void *, void *);
    short delta48; short unused48; void *fn48;
    short delta50; short unused50; void (*fn50)(void *, int, int, int);
    char pad2[0x128 - 0x58]; short delta128; short unused128; void (*fn128)(void *, void *, void *);
    char pad3[0x150 - 0x130]; short delta150; short unused150; void (*fn150)(void *, void *, float);
    char pad4[0xD0 - 0xD0];
};
struct VT2_1CAEC8 { char pad[0xD0]; short deltaD0; short unusedD0; void (*fnD0)(void *, void *, void *); };
struct Base_1CAEC8 { char pad[0xC]; VT_1CAEC8 *vt; };
struct Pool_1CAEC8 { int count; void **clones; };
struct Obj_1CAEC8 {
    char pad[0xC]; VT_1CAEC8 *vt;
    char pad0[0x10 - 0x10]; int val10; char pad00[0x38 - 0x14]; float time;
    char pad1[0x50 - 0x3C]; int val50; char pad11[0x60 - 0x54]; QW matrix[4];
    char pad2[0xE0 - 0xA0]; Pool_1CAEC8 *pool; int locked; Lease_1CAEC8 *leases; int slotCount; Slot_1CAEC8 *slots;
};
extern "C" void CFramePtr_Assign(int *, int);
extern "C" void CFrame_AddParent(int, int);
extern "C" int CploFindSwObjects(void *, int, int, int, int, int **);
extern "C" int IcloneFromLease(Obj_1CAEC8 *, Lease_1CAEC8 *);
extern "C" void LoadOptionFromBrx(int *, void *, int, void *);
extern "C" unsigned MakeCloneId(int, int);
extern "C" Cnode_1CAEC8 *PcnodeFindOrAddClonePath(void *, int, unsigned *);
extern "C" Lease_1CAEC8 *PleaseFindBest(Obj_1CAEC8 *, int);
extern "C" void ReleaseLease(void *, Lease_1CAEC8 *);
extern "C" int S16Read__18CBinaryInputStream(void *);
extern "C" void func_00118480(void *);
extern "C" void func_001184B8(void *, int);
extern "C" void func_00118500(void *, int, int, int);
struct Sw_1CAEC8 { char pad[0x3F08]; Set_1CAEC8 *sets; char *cnodes; };
extern Sw_1CAEC8 B_003DD490;
extern char D_002AC880[];
extern "C" Lease_1CAEC8 *PleaseAcquire(Obj_1CAEC8 *self, int grade, int flag) {
    char stream[0x40];
    unsigned cloneId;
    int *found;
    Base_1CAEC8 *object;
    Base_1CAEC8 **objectRef;
    Obj_1CAEC8 *selfSlot;
    Lease_1CAEC8 *lease = PleaseFindBest(self, grade);
    if (lease == 0) {
        return 0;
    }
    if (lease->pool != 0) {
        ReleaseLease(lease->pool, lease);
    }
    lease->pool = self;
    lease->next = self->leases;
    selfSlot = self;
    self->leases = lease;
    lease->matrix[0] = self->matrix[0];
    lease->matrix[1] = self->matrix[1];
    lease->matrix[2] = self->matrix[2];
    lease->matrix[3] = self->matrix[3];
    int cloneBase = IcloneFromLease(self, lease);
    cloneId = MakeCloneId((Set_1CAEC8 *)self->pool - B_003DD490.sets, cloneBase);
    Cnode_1CAEC8 *cnode = PcnodeFindOrAddClonePath(B_003DD490.cnodes, 1, &cloneId);
    for (int slotIndex = 0; slotIndex < self->slotCount; slotIndex++) {
        Slot_1CAEC8 *slot = &self->slots[slotIndex];
        if (slot->kind != 5) {
            if (slot->kind == 6) {
                found = cnode->object;
                if (found == 0) {
                    continue;
                }
            } else if (CploFindSwObjects(&B_003DD490, 0xA05, slot->kind, 0, 1, &found) != 1) {
                continue;
            }
            slot->out = found;
            func_00118480(stream);
            func_00118500(stream, slot->bisStart, slot->bisSize, 0);
            for (;;) {
                int option = S16Read__18CBinaryInputStream(stream);
                if (option < 0) {
                    break;
                }
                char *entry = D_002AC880 + option * 0x28;
                LoadOptionFromBrx(found, entry, *(int *)(entry + 4) & 0x2031, stream);
            }
            if (slot->source != 0 && self->locked == 0) {
                if (*found != 0) {
                    CFrame_AddParent((int)slot->source, *found);
                }
                CFramePtr_Assign(found, (int)slot->source);
            }
            func_001184B8(stream, 2);
        }
    }
    if (self->pool->count > 0) {
        int index = 0;
        do {
            object = (Base_1CAEC8 *)self->pool->clones[cloneBase * self->pool->count + index];
            index++;
            object->vt->fn150((char *)object + object->vt->delta150, 0, self->time);
            object->vt->fn50((char *)object + object->vt->delta50, self->val10, self->val50, 0);
            object->vt->fn128((char *)object + object->vt->delta128, &self->matrix, object);
            object->vt->fn40((char *)object + object->vt->delta40, object);
            ((VT2_1CAEC8 *)object->vt)->fnD0((char *)object + ((VT2_1CAEC8 *)object->vt)->deltaD0, self, object);
            objectRef = &object;
            self->vt->fn18((char *)self + self->vt->delta18, 0xE, 0, 1, &objectRef, 0);
            objectRef = (Base_1CAEC8 **)&selfSlot;
            object->vt->fn18((char *)object + object->vt->delta18, 0xE, 0, 1, &objectRef, 0);
        } while (index < self->pool->count);
    }
    return lease;
}
