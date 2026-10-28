#include "sly2.h"
struct SLOT { int oid; int unk; int def; };
struct SO { char pad0[0x40]; unsigned grf; char pad1[0x150 - 0x44]; float f150, f154, f158, f15c, f160, f164, f168; char pad2[0x17C - 0x16C]; SLOT slot[6]; char pad3[0x1CC - 0x17C - 6 * 12]; float f1cc, f1d0; char pad4[0x220 - 0x1D4]; int n220; char pad5[0x230 - 0x224]; int n230; };
extern "C" void InitSo(SO *);
extern int D_002C0230[6];
extern "C" void func_001B0B78(SO *pso)
{
    InitSo(pso);
    pso->f150 = 400.0f;
    pso->f154 = 800.0f;
    pso->f158 = 2.0f;
    pso->f15c = 6.0f;
    pso->f160 = 6.0f;
    pso->f164 = 10.0f;
    pso->f168 = 1.0f;
    SLOT *pslot = pso->slot;
    for (int islot = 0; islot < 6; islot++) {
        pslot->oid = -1;
        pslot->def = D_002C0230[islot];
        pslot++;
    }
    pso->f1cc = 300.0f;
    pso->f1d0 = 1000.0f;
    pso->n220 = -1;
    pso->n230 = -1;
    unsigned grf = pso->grf;
    if (((grf ^ 1) & 1) != 0)
        *(unsigned *)grf |= 2;
    else
        pso->grf = grf | 2;
}
