#include "sly2.h"

void RemoveSoLoHierarchy(void *);
void ApplyAsegToHandle(int, void *, int, void *, float, float);
void func_0012E460(void *);

void func_001B1E38(char *arg0)
{
    RemoveSoLoHierarchy(arg0);
    ApplyAsegToHandle(0, arg0, 0, arg0 + 0x234, 0.0f, 1.0f);
    func_0012E460(arg0 + 0x268);
}
