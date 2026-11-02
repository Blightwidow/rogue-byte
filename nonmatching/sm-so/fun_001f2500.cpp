// SPDX-License-Identifier: GPL-3.0-or-later
typedef int QW __attribute__((mode(TI)));
struct Slot1F2500 {
    struct Node1F2500 *owner;
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
    long flags;
    char pad4[0x134 - 0xD8];
    Slot1F2500 *slot;
    char pad5[0x13C - 0x138];
    float radiusValue;
    char pad6[0x148 - 0x140];
    long packed;
};
extern char B_003E12D4;
extern "C" {
QW PosLoWorld(void *);
void *PvAllocSlotheapImpl(void *);
}
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" void func_001F2500(Node1F2500 *self)
{
    if (self->flags & (0xC000L << 18)) {
        Slot1F2500 *slot = self->slot;
        Node1F2500 *walker = self;
        if (slot == 0) {
            Node1F2500 *parent = walker->parent;
loop:
            if (parent != 0) {
                long word = (long)(walker->packed << 32) >> 32;
                if (((int)(word << 8) >> 28) != 1) {
                    walker = parent;
                    slot = walker->slot;
                    if (slot == 0) {
                        parent = walker->parent;
                        goto loop;
                    }
                    self->slot = slot;
                    goto increment;
                }
            }
            slot = (Slot1F2500 *)PvAllocSlotheapImpl(&B_003E12D4);
            slot->position = (char *)(walker->anchor + 0x70);
            self->slot->refs = self->slot->refs + 1;
            self->slot->radius = self->radiusValue;
            self->slot->owner = self;
            walker->slot = slot;
            self->slot = slot;
            if (walker != self) {
                slot = self->slot;
                goto increment;
            }
        } else {
increment:
            slot->refs = slot->refs + 1;
        }
        QW world = PosLoWorld(self);
        Slot1F2500 *held = self->slot;
        asm volatile("qmtc2.ni %0, vf3" : : "r"(world));
        asm volatile("lqc2 vf2, 0(%0)" : : "r"(held->position));
        asm volatile("vsub.xyzw vf1, vf3, vf2");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        QW distance;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(distance));
        float reach = self->radiusBase + Lane(distance);
        if (self->flags & (0x8000L << 17)) {
            if (held->maxA < reach)
                held->maxA = reach;
        }
        if (self->flags & (0x8000L << 18)) {
            Slot1F2500 *again = self->slot;
            if (again->maxB < reach)
                again->maxB = reach;
        }
    }
}
