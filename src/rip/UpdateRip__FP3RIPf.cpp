#include "sly2.h"
extern "C" float g_2dded0;
extern "C" void RemoveRip(void *);

struct VT1 { char pad[0x248]; short delta; short index; int (*fn)(void *, QW); };
struct VT2 { char pad[0x38]; short delta; short index; void (*fn)(void *, int); };
struct SO {
    char pad0[0xC];
    VT1 *vt;
    char pad1[0x28 - 0x10];
    unsigned long grf;
    char pad2[0xE8 - 0x30];
    int pphys;
};
struct GRP { char pad[0x150]; int kind; };
struct RIP {
    char pad0[8];
    GRP *grp;
    char pad1[0x14 - 0xC];
    float created;
    float lifetime;
    char pad2[0x70 - 0x1C];
    QW pos;
    char pad3[0xE0 - 0x80];
    SO *touch;
    int unkE4;
    int unkE8;
    VT2 *vt;
};

void UpdateRip(RIP *rip, float dt)
{
    if (rip->lifetime < g_2dded0 - rip->created) {
        RemoveRip(rip);
        return;
    }
    if (rip->grp->kind == 1)
        return;
    SO *touch = rip->touch;
    if (touch == 0)
        return;
    if (touch->pphys == 0)
        return;
    int touching = 0;
    if ((int)(touch->grf >> 60) & 1) {
        VT1 *vt = touch->vt;
        if (vt->fn((char *)touch + vt->delta, rip->pos) != 0)
            touching = 1;
    }
    VT2 *vt2 = rip->vt;
    vt2->fn((char *)rip + vt2->delta, touching);
}
