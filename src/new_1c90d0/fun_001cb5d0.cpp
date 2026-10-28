#include "sly2.h"
struct VT { char pad[0xD8]; short delta; short idx; void (*fn)(void *, void *); };
struct LO { char pad[0xC]; VT *vt; char pad1[0x24 - 0x10]; LO *next; };
struct PHYS { char pad[0xDC]; int link; };
struct SO { char pad[0x64]; LO *child; };
struct SOP { char pad[0xE8]; PHYS *phys; };
void func_001CB5C8();
void func_001F37C8(void *, int);
void func_001CB5D0(SOP *so, void *pool)
{
    func_001CB5C8();
    int link = 0;
    if (so->phys != 0)
        link = so->phys->link;
    if (link != 0)
        func_001F37C8(so, 0);
    for (LO *child = ((SO *)so)->child; child != 0; child = child->next) {
        VT *vt = child->vt;
        vt->fn((char *)child + vt->delta, pool);
    }
}
