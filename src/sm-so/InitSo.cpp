#include "sly2.h"
#include "so.h"
extern "C" void InitLo(SO *);
extern "C" void func_001A6CA8(SO *, int);
void InitDl(DL *, int);
extern float D_FLT_002C3B90;
void InitSo(SO *so)
{
    InitLo(so);
    func_001A6CA8(so, 0);
    InitDl(&so->dlChild, 0x24);
    *(char *)&so->grfso = -10;
    *((char *)&so->grfso + 1) = -20;
    so->uFade = 1.0f;
    so->field_0x13C = D_FLT_002C3B90;
    unsigned long bit;
    if (so->psoParent) bit = (so->psoParent->grfso >> 35) & 1;
    else bit = 1;
    so->field_0x140 = -1;
    so->grfso = (so->grfso & ~(1UL << 35)) | (bit << 35);
}
