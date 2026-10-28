#include "sly2.h"
struct CPTN { char pad[0x10]; int ptn; int ptnfn; };
extern "C" void DeactivateCplcy(CPTN *);
extern "C" void DeactivateCptn(CPTN *pcptn)
{
    pcptn->ptn = 0;
    pcptn->ptnfn = 0;
    DeactivateCplcy(pcptn);
}
