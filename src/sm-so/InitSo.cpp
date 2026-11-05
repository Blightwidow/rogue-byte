#include "sly2.h"
struct SO { char pad[0x10]; SO *parent; char pad2[0x50]; char dl[0xC8]; float f12c; char pad3[0xC]; float f13c; int n140; char pad4[4]; unsigned long flags; };
extern "C" void InitLo(SO *);
extern "C" void func_001A6CA8(SO *, int);
void InitDl__FP2DLi(void *, int);
extern float D_FLT_002C3B90;
void InitSo(SO *so)
{
    InitLo(so);
    func_001A6CA8(so, 0);
    InitDl__FP2DLi(so->dl, 0x24);
    *(char *)&so->flags = -10;
    *((char *)&so->flags + 1) = -20;
    so->f12c = 1.0f;
    so->f13c = D_FLT_002C3B90;
    unsigned long bit;
    if (so->parent) bit = (so->parent->flags >> 35) & 1;
    else bit = 1;
    so->n140 = -1;
    so->flags = (so->flags & ~(1UL << 35)) | (bit << 35);
}
