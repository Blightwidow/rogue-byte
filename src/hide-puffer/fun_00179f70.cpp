#include "sly2.h"
extern "C" void func_00174920(void *);
void func_00179F70(void *pgoal)
{
    func_00174920(pgoal);
    *(int *)((char *)pgoal + 0x3C) = 0xF;
}
