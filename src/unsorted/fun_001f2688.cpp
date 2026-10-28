#include "sly2.h"
struct B { B* owner; char pad[0x1C]; float f20; };
struct A { char pad[0x134]; B* p134; float f138; float f13C; };
void func_001F2688(A* a, float v)
{
    a->f13C = v;
    B* b = a->p134;
    if (b && (void*)b->owner == (void*)a) b->f20 = v;
}
