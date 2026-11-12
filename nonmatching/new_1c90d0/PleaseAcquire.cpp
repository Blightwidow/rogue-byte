#include "sly2.h"
#include "sw.h"
#include "so.h"
struct LEASE { void *pool; LEASE *next; int pad[2]; QW matrix[4]; };
struct POOLSET { int count; LO **clones; };
struct CLONESLOT { int kind; int pad; char *source; int bisStart; int bisSize; int *out; };
struct SETX { char pad[0x6C]; };
struct CNODE { char pad[0x10]; int *object; };
struct CLONEOWNER : LO {
    int val50; char pad54[0x60 - 0x54]; QW matrix[4];
    char padA0[0xE0 - 0xA0];
    POOLSET *pool; int locked; LEASE *leases; int slotCount; CLONESLOT *slots;
};
extern "C" void CFramePtr_Assign(int *, int);
extern "C" void CFrame_AddParent(int, int);
extern "C" int CploFindSwObjects(void *, int, int, int, CNODE *, int, int **);
extern "C" int IcloneFromLease(CLONEOWNER *, LEASE *);
extern "C" void LoadOptionFromBrx(int *, void *, int, void *);
extern "C" unsigned MakeCloneId(int, int);
extern "C" CNODE *PcnodeFindOrAddClonePath(void *, int, unsigned *);
extern "C" LEASE *PleaseFindBest(CLONEOWNER *, int);
extern "C" void ReleaseLease(void *, LEASE *);
extern "C" int S16Read__18CBinaryInputStream(void *);
extern "C" void func_00118480(void *);
extern "C" void func_001184B8(void *, int);
extern "C" void func_00118500(void *, int, int, int);
struct SWX { char pad[0x3F08]; SETX *sets; char *cnodes; };
extern SWX B_003DD490;
extern char D_002AC880[];
extern "C" LEASE *PleaseAcquire(CLONEOWNER *self, int grade, int flag) {
    char stream[0x40];
    unsigned cloneId;
    int *found;
    CLONEOWNER *selfSlot;
    LEASE *lease = PleaseFindBest(self, grade);
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
    cloneId = MakeCloneId((SETX *)self->pool - B_003DD490.sets, cloneBase);
    CNODE *cnode = PcnodeFindOrAddClonePath(B_003DD490.cnodes, 1, &cloneId);
    for (int slotIndex = 0; slotIndex < self->slotCount; slotIndex++) {
        CLONESLOT *slot = &self->slots[slotIndex];
        if (slot->kind != 5) {
            if (slot->kind == 6) {
                found = cnode->object;
                if (found == 0) {
                    continue;
                }
            } else if (CploFindSwObjects(&B_003DD490, 0xA05, slot->kind, 0, cnode, 1, &found) != 1) {
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
            LO *object = self->pool->clones[cloneBase * self->pool->count + index];
            LO **objectRef;
            index++;
#define VCALLX(obj, off, T, args...) ((T)(*(void **)(*(char **)((char *)(obj) + 0xC) + (off) + 4)))((char *)(obj) + *(short *)(*(char **)((char *)(obj) + 0xC) + (off)), ## args)
            VCALLX(object, 0x150, void (*)(void *, float), *(float *)((char *)self + 0x38));
            object->SetParent(self->psoParent, (void *)self->val50, 0);
            object->Slot37(&self->matrix);
            object->Add();
            object->Slot26(self);
            objectRef = &object;
            self->HandleSpliceEvent(0xE, 0, 1, (int)&objectRef, 0);
            objectRef = (LO **)&selfSlot;
            object->HandleSpliceEvent(0xE, 0, 1, (int)&objectRef, 0);
        } while (index < self->pool->count);
    }
    return lease;
}
