#include "types.h"
#include "ps2inline.h"
#include "vu0inline.h"

struct Node1F2500;
struct Slot1F2500 {
    Node1F2500 *owner;
    char *position;
    int refs;
    char pad0[0x10 - 0xC];
    float maxA;
    char pad1[0x1C - 0x14];
    float maxB;
    float radius;
};
struct Node1F2500 {
    char pad0[0x10];
    Node1F2500 *parent;
    char pad1[0x60 - 0x14];
    int anchor;
    char pad2[0xA0 - 0x64];
    float radiusBase;
    char pad3[0xD0 - 0xA4];
    s64 flags;
    char pad4[0x134 - 0xD8];
    Slot1F2500 *slot;
    char pad5[0x13C - 0x138];
    float radiusValue;
    char pad6[0x148 - 0x140];
    s64 packed;
};

extern char B_003E12D4;
extern "C" {
QW PosLoWorld(void *);
void *PvAllocSlotheapImpl(void *);
}

extern "C" void func_001F2500(Node1F2500 *self)
{
    if (self->flags & (0xC000L << 18)) {
        Node1F2500 *walker = self;
        Slot1F2500 *slot = self->slot;
        if (slot == 0) {
loop:
            Node1F2500 *parent = walker->parent;
            s64 word = 0;
            if (parent != 0) {
                word = walker->packed;
            }
            if (parent == 0 || (((s32)((word << 32) >> 32) << 8) >> 28) == 1) {
                Slot1F2500 *fresh = (Slot1F2500 *)PvAllocSlotheapImpl(&B_003E12D4);
                walker->slot = fresh;
                self->slot = fresh;
                fresh->position = (char *)(walker->anchor + 0x70);
                self->slot->refs = self->slot->refs + 1;
                self->slot->radius = self->radiusValue;
                self->slot->owner = self;
                if (walker == self) {
                    goto done;
                }
                slot = self->slot;
            } else {
                walker = parent;
                slot = walker->slot;
                if (slot == 0) {
                    goto loop;
                }
                self->slot = slot;
            }
        }
        slot->refs = slot->refs + 1;
done:
        QW world = PosLoWorld(self);
        Slot1F2500 *held = self->slot;
        QW offset = VectorSub(world, *(QW *)held->position);
        QW squared = SquaredLength(offset);
        QW root = SqrtX(squared);
        float reach = self->radiusBase + LaneX(root);
        if (self->flags & (0x8000L << 17)) {
            if (held->maxA < reach) {
                held->maxA = reach;
            }
        }
        if (self->flags & (0x8000L << 18)) {
            Slot1F2500 *again = self->slot;
            if (again->maxB < reach) {
                again->maxB = reach;
            }
        }
    }
}
