#include "sly2.h"
struct Src { char pad[0x2C0]; int a; int b; };
struct Dst;
void func_00200F58(Dst *, int, int, int);
Dst *FGetVolbtnPushObjectsWithinList(Dst *self, Src *src)
{
    func_00200F58(self, src->a, 0x2002, src->b);
    return self;
}
