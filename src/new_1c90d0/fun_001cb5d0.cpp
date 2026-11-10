#include "sly2.h"
#include "so.h"
struct PHYS { char pad[0xDC]; int link; };
void func_001CB5C8();
void func_001F37C8(void *, int);
void func_001CB5D0(SO *so, void *pool)
{
    func_001CB5C8();
    int link = 0;
    if (so->pphys != 0)
        link = so->pphys->link;
    if (link != 0)
        func_001F37C8(so, 0);
    for (LO *child = (LO *)so->dlChild.head; child != 0; child = child->ploNext)
        child->Slot27(pool);
}
