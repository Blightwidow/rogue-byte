#include "sly2.h"
extern "C" void func_00174920(void *);
void func_0017A9D0(void *pgoal)
{
    func_00174920(pgoal);
    *(int *)((char *)pgoal + 0x3C) = 0x17;
    *(int *)((char *)pgoal + 0x50) = -1;
}
