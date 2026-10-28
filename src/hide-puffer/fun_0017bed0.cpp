#include "sly2.h"
extern "C" void func_001EEF68(void *);
extern "C" void AddGuardSgs(int, int);
void func_0017BED0(void *pgoal)
{
    func_001EEF68(pgoal);
    AddGuardSgs(*(int *)((char *)pgoal + 0x10), 0x19);
    *(int *)((char *)pgoal + 0x30) = -1;
}
