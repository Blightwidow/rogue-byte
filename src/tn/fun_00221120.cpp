#include "sly2.h"
struct A { char pad[0x10C]; int f10C; };
int func_00221120(A* a, int** out)
{
    if (!a->f10C) return 0;
    *out = &a->f10C;
    return 1;
}
