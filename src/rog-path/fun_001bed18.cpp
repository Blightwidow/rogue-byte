#include "sly2.h"
struct OBJ;
struct VT {
    char pad0[0x18]; short delta18; short index18; void (*fn18)(void *, int, int, int, int, int);
    char pad1[0x48 - 0x20]; short delta48; short index48; void (*fn48)(void *);
    char pad2[0xA8 - 0x50]; short deltaA8; short indexA8; void (*fnA8)(void *, int);
};
struct OBJ { char pad[0xC]; VT *vt; };
struct SLOT { char pad[0x20]; int owner; };
struct RTALO {
    char pad[0xC]; VT *vt;
    char pad1[0xE0 - 0x10]; int count; OBJ *children[4]; unsigned flags[4];
    char pad2[0x128 - 0x104]; SLOT *slot;
};
void func_001BED18(RTALO *alo)
{
    SLOT *slot = alo->slot;
    if (slot) {
        slot->owner = 0;
        alo->slot = 0;
        for (int index = 0; index < alo->count; index++) {
            OBJ *child = alo->children[index];
            if (alo->flags[index] & 1)
                child->vt->fn48((char *)child + child->vt->delta48);
            if (alo->flags[index] & 2)
                child->vt->fnA8((char *)child + child->vt->deltaA8, 1);
        }
        alo->vt->fnA8((char *)alo + alo->vt->deltaA8, 0);
        alo->vt->fn18((char *)alo + alo->vt->delta18, 3, 0, 0, 0, 0);
    }
}
