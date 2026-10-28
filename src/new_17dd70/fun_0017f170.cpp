#include "sly2.h"
extern "C" void func_001CB518(void *);
struct GOAL { char pad[0x180]; int a; int b; };
void func_0017F170(GOAL *pgoal)
{
    func_001CB518(pgoal);
    pgoal->b = pgoal->a;
}
