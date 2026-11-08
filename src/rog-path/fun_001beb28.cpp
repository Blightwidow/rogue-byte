#include "sly2.h"
struct VT {
    char pad0[0x18]; short delta18; short index18; void (*fn18)(void *, int, int, int, int, int);
    char pad1[0x40 - 0x20]; short delta40; short index40; void (*fn40)(void *);
    short delta48; short index48; void (*fn48)(void *);
    char pad2[0xA8 - 0x50]; short deltaA8; short indexA8; void (*fnA8)(void *, int);
    char pad3[0xB8 - 0xB0]; short deltaB8; short indexB8; void (*fnB8)(void *);
};
struct ROOT { char pad[0xC]; VT *vt; };
struct OBJ { char pad[0xC]; VT *vt; char pad1[0x14 - 0x10]; ROOT *root; char pad2[0x28 - 0x18]; unsigned long grf; char pad3[0x40 - 0x30]; unsigned *pgrf; };
struct SLOT { char pad[0x20]; void *owner; char pad2[4]; };
struct RTALO {
    char pad[0xC]; VT *vt;
    char pad1[0xE0 - 0x10]; int count; OBJ *children[4]; unsigned flags[4];
    char pad2[0x128 - 0x104]; SLOT *slot;
};
extern "C" {
extern SLOT B_003E1A78[];
extern char B_003DD4BC[];
int FIsLoInWorld(void *);
void AppendDlEntry(void *, void *);
}
SLOT *func_001BEB28(RTALO *alo)
{
    if (alo->slot == 0) {
        for (unsigned slotIndex = 0; slotIndex < 2; slotIndex++) {
            SLOT *candidate = (SLOT *)((char *)B_003E1A78 + slotIndex * 0x28);
            if (candidate->owner == 0) {
                alo->slot = candidate;
                break;
            }
        }
        if (alo->slot != 0) {
            alo->slot->owner = alo;
            for (int index = 0; index < alo->count; index++) {
                unsigned *pflag = &alo->flags[index];
                OBJ *child = *(OBJ **)((char *)pflag - 0x10);
                *pflag = 0;
                if (((child->grf >> 60) & 1) == 0) {
                    *pflag = 1;
                    child->vt->fn40((char *)child + child->vt->delta40);
                    if (FIsLoInWorld(child) == 0) {
                        AppendDlEntry(B_003DD4BC, child->root);
                        ROOT *inner = *(ROOT **)child->root;
                        inner->vt->fnB8((char *)inner + inner->vt->deltaB8);
                    }
                }
                unsigned flags = (unsigned)child->pgrf;
                if (((flags ^ 1) & 1) != 0)
                    flags = *child->pgrf;
                if ((flags & 8) != 0) {
                    *pflag |= 2;
                    child->vt->fnA8((char *)child + child->vt->deltaA8, 0);
                }
            }
            alo->vt->fnA8((char *)alo + alo->vt->deltaA8, 1);
            alo->vt->fn18((char *)alo + alo->vt->delta18, 2, 0, 0, 0, 0);
        }
    }
    return alo->slot;
}
