#include "sly2.h"
struct FRM { char pad0[8]; QW *p8; int cC; char pad10[8]; QW *p18; int c1C; char pad20[4]; int f24; char pad28[4]; int f2c; int f30; char pad34[0x18]; int f4c; };
struct DMAS;
extern int B_003D3980;
extern int g_2deb1c;
extern unsigned B_002DEB10;
extern char B_002DEA50[];
extern FRM *g_2dea4c;
extern int g_2ddf54;
extern char B_002DEA00[];
extern char g_2dea28[];
extern char B_002DF740[];
extern "C" void func_001C2A78(int);
extern "C" void WaitSema(int);
void ClearPendingFrame(FRM *);
void AllocStatic__4DMASiP2QW(void *, int, QW *);
void AddDmaRefs__4DMASiP2QW(void *, int, QW *);
void AddDmaCnt__4DMAS(void *);
void OpenFrame__Fv()
{
    if (B_003D3980 == 0) func_001C2A78(3);
    WaitSema(g_2deb1c);
    unsigned i = B_002DEB10;
    B_002DEB10 = i + 1;
    g_2dea4c = (FRM *)(B_002DEA50 + i * 0x50);
    if (B_002DEB10 >= 2) B_002DEB10 = 0;
    ClearPendingFrame(g_2dea4c);
    FRM *f = g_2dea4c;
    f->f4c = g_2ddf54;
    f->f30 = 1;
    f->f2c = 0;
    f->f24 = 0;
    AllocStatic__4DMASiP2QW(B_002DEA00, f->cC, f->p8);
    AllocStatic__4DMASiP2QW(g_2dea28, g_2dea4c->c1C, g_2dea4c->p18);
    AddDmaRefs__4DMASiP2QW(B_002DEA00, 12, (QW *)B_002DF740);
    AddDmaCnt__4DMAS(B_002DEA00);
}
