#include "sly2.h"
extern "C" void func_00174920(void *);
void func_0017A4B0(void *pgoal)
{
    func_00174920(pgoal);
    *(int *)((char *)pgoal + 0x3C) = 0x10;
    *(int *)((char *)pgoal + 0x50) = -1;
}
