typedef int QW __attribute__((mode(TI)));
#define VCALL(T, obj, off, args...) ((T)(*(void **)(*(char **)((char *)(obj) + 0xC) + (off) + 4)))((char *)(obj) + *(short *)(*(char **)((char *)(obj) + 0xC) + (off)), ## args)
struct Lease_1CAA60 { int id; Lease_1CAA60 *next; int pad[2]; float matrix[16]; };
struct Pool_1CAA60 { int count; void **clones; char pad[0x64 - 8]; QW *matrices; };
struct Slot_1CAA60 { int kind; int pad; char *source; int pad2[2]; int *frame; };
struct Obj_1CAA60 {
    char pad[0xE0];
    Pool_1CAA60 *pool; int locked; Lease_1CAA60 *leases; int slotCount; Slot_1CAA60 *slots;
};
extern "C" void CFramePtr_Assign(int *, int);
extern "C" void CFrame_RemoveParent(void *, int);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int IcloneFromLease(Obj_1CAA60 *, Lease_1CAA60 *);
extern "C" void InvertMatrix4Affine(QW *, void *);
extern "C" void func_001A58D0(void *, int, int);
struct Mat_1CAA60 { QW row[4]; };
extern "C" void *memset(void *, int, unsigned);
extern QW g_2a2dd0;
extern "C" void ReleaseLease(Obj_1CAA60 *self, Lease_1CAA60 *lease) {
    QW scratch[4];
    QW inverse[4];
    Lease_1CAA60 *node = self->leases;
    if (node != 0) {
        Lease_1CAA60 **link = &node->next;
        if (node == lease) {
            self->leases = lease->next;
            lease->next = 0;
        } else {
            for (;;) {
                node = node->next;
                if (node == 0) {
                    break;
                }
                if (node == lease) {
                    *link = lease->next;
                    lease->next = 0;
                    break;
                }
                link = &node->next;
            }
        }
    }
    lease->id = 0;
    char *object;
    char **objectRef;
    Obj_1CAA60 *selfSlot = self;
    InvertMatrix4Affine(inverse, lease->matrix);
    float *matrixOut = lease->matrix;
    *(Mat_1CAA60 *)scratch = *(Mat_1CAA60 *)inverse;
    memset(matrixOut, 0, 0x40);
    matrixOut[15] = 1.0f;
    matrixOut[10] = 1.0f;
    matrixOut[5] = 1.0f;
    lease->matrix[0] = 1.0f;
    int cloneBase = IcloneFromLease(self, lease);
    if (self->pool->count > 0) {
        for (int index = 0; index < self->pool->count; index++) {
            object = (char *)self->pool->clones[cloneBase * self->pool->count + index];
            for (int slotIndex = 0; slotIndex < self->slotCount; slotIndex++) {
                Slot_1CAA60 *slot = &self->slots[slotIndex];
                if (slot->kind != 5) {
                    char *source = slot->source;
                    if (source != 0 && self->locked == 0) {
                        int *frame = slot->frame;
                        if (*(int *)(source + 8) != 0) {
                            CFramePtr_Assign(frame, *(int *)(source + 0xC));
                            CFrame_RemoveParent(source, *frame);
                        } else {
                            CFramePtr_Assign(frame, 0);
                        }
                    }
                    slot->frame = 0;
                }
            }
            VCALL(void (*)(void *, void *, void *), object, 0xD8, self, object);
            objectRef = &object;
            VCALL(void (*)(void *, int, int, int, void *, int), self, 0x18, 0xF, 0, 1, &objectRef, 0);
            objectRef = (char **)&selfSlot;
            VCALL(void (*)(void *, int, int, int, void *, int), object, 0x18, 0xF, 0, 1, &objectRef, 0);
            VCALL(void (*)(void *, void *), object, 0x48, object);
            VCALL(void (*)(void *, void *, void *), object, 0x128, scratch, object);
            func_001A58D0(object, 0, 0);
            if (FIsBasicDerivedFrom(object, 0x30) != 0) {
                char *derived = object;
                QW *matrix = self->pool->matrices + index * 4;
                if (*(int *)(derived + 0x58) != 0) {
                    VCALL(void (*)(void *, QW), derived, 0xE8, *matrix);
                    VCALL(void (*)(void *, QW), derived, 0x118, g_2a2dd0);
                }
                if (*(int *)(derived + 0x5C) != 0) {
                    VCALL(void (*)(void *, void *), derived, 0xF0, matrix + 1);
                    VCALL(void (*)(void *, QW), derived, 0x120, g_2a2dd0);
                }
            }
        }
    }
}
