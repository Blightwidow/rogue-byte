#include "sly2.h"
extern "C" void func_00174920(void *);
void func_001796A0(void *pgoal)
{
    func_00174920(pgoal);
    *(int *)((char *)pgoal + 0x3C) = 5;
}
