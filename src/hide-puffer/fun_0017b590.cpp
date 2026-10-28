#include "sly2.h"
extern "C" void func_001EEF68(void *);
void func_0017B590(void *pgoal)
{
    func_001EEF68(pgoal);
    *(int *)((char *)pgoal + 0x30) = -1;
}
