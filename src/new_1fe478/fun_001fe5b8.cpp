#include "sly2.h"
struct A { char pad[0x68]; unsigned flags; };
void func_001FE5B8(A* a, unsigned mask, int on)
{
    if (on) a->flags |= mask;
    else a->flags &= ~mask;
}
