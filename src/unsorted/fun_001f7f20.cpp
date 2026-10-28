#include "sly2.h"
struct A { char pad[0x148]; unsigned long f148; };
void func_001F7F20(A* a, int v)
{
    a->f148 = (a->f148 & ~0x20000000UL) | ((v & 1) << 29);
}
