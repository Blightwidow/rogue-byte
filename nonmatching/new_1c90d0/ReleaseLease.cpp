#include "sly2.h"
#include "sw.h"
#include "so.h"
struct LEASE { int id; LEASE *next; int pad[2]; float matrix[16]; };
struct POOLSET { int count; LO **clones; char pad[0x64 - 8]; QW *matrices; };
struct CLONESLOT { int kind; int pad; char *source; int pad2[2]; int *frame; };
struct CLONEOWNER : LO {
    char pad50[0xE0 - 0x50];
    POOLSET *pool; int locked; LEASE *leases; int slotCount; CLONESLOT *slots;
};
extern "C" void CFramePtr_Assign(int *, int);
extern "C" void CFrame_RemoveParent(void *, int);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int IcloneFromLease(CLONEOWNER *, LEASE *);
extern "C" void InvertMatrix4Affine(QW *, void *);
extern "C" void func_001A58D0(void *, int, int);
extern QW g_2a2dd0;
extern "C" void ReleaseLease(CLONEOWNER *self, LEASE *lease) {
    QW scratch[4];
    QW inverse[4];
    LEASE *node = self->leases;
    if (node != 0) {
        LEASE **link = &node->next;
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
    CLONEOWNER *selfSlot = self;
    InvertMatrix4Affine(inverse, lease->matrix);
    float *matrixOut = lease->matrix;
    scratch[0] = inverse[0];
    scratch[1] = inverse[1];
    scratch[2] = inverse[2];
    scratch[3] = inverse[3];
    memset(matrixOut, 0, 0x40);
    matrixOut[15] = 1.0f;
    matrixOut[10] = 1.0f;
    matrixOut[5] = 1.0f;
    lease->matrix[0] = 1.0f;
    int cloneBase = IcloneFromLease(self, lease);
    for (int index = 0; index < self->pool->count; index++) {
        LO *object = self->pool->clones[cloneBase * self->pool->count + index];
        LO **objectRef;
        for (int slotIndex = 0; slotIndex < self->slotCount; slotIndex++) {
            CLONESLOT *slot = &self->slots[slotIndex];
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
        object->Slot27(self);
        objectRef = &object;
        self->HandleSpliceEvent(0xF, 0, 1, (int)&objectRef, 0);
        objectRef = (LO **)&selfSlot;
        object->HandleSpliceEvent(0xF, 0, 1, (int)&objectRef, 0);
        object->Remove();
        object->Slot37(scratch);
        func_001A58D0(object, 0, 0);
        if (FIsBasicDerivedFrom(object, 0x30) != 0) {
            SO *solid = (SO *)object;
            QW *matrix = self->pool->matrices + index * 4;
            if (solid->pxfLinear != 0) {
                solid->TranslateToPos(*matrix);
                solid->Slot35(g_2a2dd0);
            }
            if (solid->pxfAngular != 0) {
                ((void (*)(void *, QW *))(*(void **)(*(char **)((char *)solid + 0xC) + 0xF0 + 4)))((char *)solid + *(short *)(*(char **)((char *)solid + 0xC) + 0xF0), matrix + 1);
                solid->Slot36(g_2a2dd0);
            }
        }
    }
}
