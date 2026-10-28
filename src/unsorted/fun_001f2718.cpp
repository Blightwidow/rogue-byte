#include "sly2.h"
struct A { char pad[0x148]; unsigned long f148; };
void func_001F2718(A* a, int v)
{
    a->f148 = (a->f148 & ~0xF00000UL) | ((v & 0xF) << 20);
}
