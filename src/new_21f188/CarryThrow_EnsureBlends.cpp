#include "sly2.h"
struct CARRY { void* owner; char pad[0x40 - 4]; char ablHold[0x18]; void* pasegblHold; char pad2[0x68 - 0x5C]; char ablAim[0x30]; void* pasegblAim; char pad3[0xA4 - 0x9C]; char ablThrow[0x18]; void* pasegblThrow; };
extern "C" void EnsureAsegBlendDynamic(void*, int, int, void*, int, const int*, const int*, void*);
extern "C" void CarryThrow_EnsureBlends(CARRY* pcarry)
{
    EnsureAsegBlendDynamic(pcarry->owner, 0xC, 2, pcarry->ablHold, 0, 0, 0, &pcarry->pasegblHold);
    EnsureAsegBlendDynamic(pcarry->owner, 0xC, 4, pcarry->ablAim, 0, 0, 0, &pcarry->pasegblAim);
    EnsureAsegBlendDynamic(pcarry->owner, 0xC, 2, pcarry->ablThrow, 0, 0, 0, &pcarry->pasegblThrow);
}
