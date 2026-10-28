#include "sly2.h"
extern "C" void func_00174920(void *);
void func_00179750(void *pgoal)
{
    func_00174920(pgoal);
    *(int *)((char *)pgoal + 0x3C) = 6;
}
