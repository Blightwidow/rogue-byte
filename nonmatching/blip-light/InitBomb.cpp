#include "sly2.h"
struct BOMB { char pad0[0x40]; unsigned flags; char pad1[0x150 - 0x44]; int f150; float f154; float f158; float f15c; float f160; char pad2[0x1E0 - 0x164]; int f1E0; char pad3[8]; int f1EC; int f1F0; char pad4[0x200 - 0x1F4]; BOMB *self; };
extern "C" float D_FLT_002BC9C8;
extern "C" void InitSo(BOMB *);
extern "C" float RO_FLT_002A4B08;

extern "C" void InitBomb(BOMB *pbomb)
{
    InitSo(pbomb);
    unsigned flags = pbomb->flags;
    pbomb->f15c = D_FLT_002BC9C8;
    pbomb->f154 = RO_FLT_002A4B08;
    pbomb->f160 = D_FLT_002BC9C8;
    pbomb->f1E0 = 1;
    pbomb->f1EC = 0x100;
    pbomb->f150 = 0;
    pbomb->f1F0 = -10;
    if ((flags ^ 1) & 1)
        *(unsigned *)flags |= 2;
    else
        pbomb->flags = flags | 2;
    pbomb->self = pbomb;
}
