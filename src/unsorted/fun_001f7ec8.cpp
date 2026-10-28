#include "sly2.h"
struct A { char pad[0x148]; unsigned long f148; };
void func_001F7EC8(A* a, int v)
{
    a->f148 = (a->f148 & ~0xF0000UL) | ((v & 0xF) << 16);
}
