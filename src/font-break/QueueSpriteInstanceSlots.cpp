#include "sly2.h"
struct SLOT { char pad[0x30]; void *pchar; int maskMode; char pad2[0x70 - 0x38]; };
struct INST { int count; SLOT *slots; int pad[4]; };
struct MOVIE { char pad[0xC]; char *owner; };
struct LABEL { char pad[0xC]; char *owner; struct { char pad[8]; INST *insts; } *movie; };
extern "C" void func_00215960(void *, SLOT *, int);
extern "C" void PrependSlEntry(void *, SLOT *);

void QueueSpriteInstanceSlots(LABEL *label, int index, int alpha)
{
    INST *inst = (INST *)(index * sizeof(INST) + (unsigned)label->movie->insts);
    SLOT *slots = inst->slots;
    for (int slot = inst->count - 1; slot >= 0; slot--) {
        SLOT *entry = &slots[slot];
        if (entry->pchar != 0) {
            func_00215960(entry->pchar, entry, alpha);
        } else if (entry->maskMode == 4) {
            PrependSlEntry(label->owner + 0xFC, entry);
        }
    }
}
