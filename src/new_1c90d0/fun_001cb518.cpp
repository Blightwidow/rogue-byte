#include "sly2.h"
struct VT { char pad[0xD0]; short delta; short idx; void (*fn)(void *, void *); };
struct LO { char pad[0xC]; VT *vt; char pad1[0x24 - 0x10]; LO *next; };
struct PHYS { char pad[0xDC]; int link; };
struct SO { char pad[0x64]; LO *child; };
struct SOP { char pad0[0xCC]; int slot; char pad[0xE8 - 0xD0]; PHYS *phys; };
extern "C" {
void func_001CB4E0(void *, void *);
void func_001F7A68(void *, int);
QW PosLoWorld(void *);
void *PpathzoneFindPos(QW, int);
void func_001F37C8(void *, void *);
}
extern "C" void func_001CB518(SOP *so, void *pool)
{
    func_001CB4E0(so, pool);
    func_001F7A68(so, 0);
    so->slot = -1;
    int link = 0;
    if (so->phys != 0)
        link = so->phys->link;
    if (link != 0) {
        QW pos = PosLoWorld(so);
        func_001F37C8(so, PpathzoneFindPos(pos, 1));
    }
    for (LO *child = ((SO *)so)->child; child != 0; child = child->next) {
        VT *vt = child->vt;
        vt->fn((char *)child + vt->delta, pool);
    }
}
