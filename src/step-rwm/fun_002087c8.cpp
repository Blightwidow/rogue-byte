#include "sly2.h"
struct B { char pad[0xFC]; int f; };
struct A { char pad[0x394]; int f394; char pad2[0xC]; int f3A4; char pad3[0xF64 - 0x3A8]; B* p; };
void func_002087C8(A* a)
{
    B* b = a->p;
    b->f -= a->f3A4;
    a->f394 = 0;
    a->f3A4 = 0;
}
