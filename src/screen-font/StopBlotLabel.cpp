#include "sly2.h"
struct BLOT;
struct VEnt { short delta; short idx; void (*fn)(void*, int, int, int, int, int); };
struct VEnt2 { short delta; short idx; void (*fn)(void*, int); };
struct VTab { char pad0[0x18]; VEnt e18; char pad1[0xA8 - 0x20]; VEnt2 eA8; };
struct BLOT {
    char pad0[0xC]; VTab* vt; char pad1[0x7C - 0x10];
    int unk7C; void* unk80; void* sprite84; int unk88;
    char pad2[0xAC - 0x8C]; int modal;
};
extern "C" void StopRootSprite(void*);
extern "C" void SetBlotModal(BLOT*, int);
extern "C" void StopBlotLabel(BLOT* pblot)
{
    StopRootSprite(pblot->sprite84);
    if (pblot->modal != 0)
        SetBlotModal(pblot, -1);
    pblot->vt->eA8.fn((char*)pblot + pblot->vt->eA8.delta, 0);
    pblot->vt->e18.fn((char*)pblot + pblot->vt->e18.delta, 6, 0, 0, 0, 0);
    pblot->unk88 = 0;
    pblot->unk7C = -1;
}
