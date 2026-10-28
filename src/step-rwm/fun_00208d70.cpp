#include "sly2.h"
struct GUARD { char pad[0x2C0]; unsigned long grf; char pad2[0xE64 - 0x2C8]; int sensing; };
extern "C" unsigned long GrfsgsFromSgs(int);
extern "C" int func_00208D70(GUARD *pguard)
{
    unsigned long blind = GrfsgsFromSgs(0xB) | GrfsgsFromSgs(0x1D) | GrfsgsFromSgs(7) |
                          GrfsgsFromSgs(5) | GrfsgsFromSgs(6) | GrfsgsFromSgs(0x10) |
                          GrfsgsFromSgs(1) | GrfsgsFromSgs(0x16) | GrfsgsFromSgs(0x2A);
    if ((blind & pguard->grf) != 0)
        return 0;
    return pguard->sensing;
}
