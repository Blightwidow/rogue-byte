#include "sly2.h"
struct OXF { char pad[0x60]; void *pself; };
struct SOB { char pad0[0xEC]; OXF *poxf; char pad1[0x1C4 - 0xF0]; float f1C4; int f1C8; };
struct SOBF { char pad0[0x1C0]; float f1C0; float f1C4; int f1C8; };
struct OXFFILTER;
extern "C" OXFFILTER B_003DD490;
extern "C" float g_2a5654;
extern "C" float g_2dded0;
extern "C" void RecalcSwOxfFilterForObject(OXFFILTER *, void *);
struct SO2 { char pad0[0xEC]; OXF *poxf; char pad1[0x1C0 - 0xF0]; float f1C0; float f1C4; int f1C8; };

extern "C" void func_00180478(SO2 *pso, int value)
{
    if (value != pso->f1C8) {
        pso->f1C8 = value;
        if (pso->poxf->pself == pso)
            RecalcSwOxfFilterForObject(&B_003DD490, pso);
    }
    float f = pso->f1C4;
    float zero;
    asm volatile("mtc1 $0, %0\n\tnop" : "=f" (zero) : "f" (f));
    if (f != zero)
        pso->f1C0 = g_2dded0 + f;
    else
        pso->f1C0 = g_2a5654;
}
