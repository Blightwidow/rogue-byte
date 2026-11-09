#include "sly2.h"
#include "so.h"
struct PHYS { char pad[0xDC]; int link; };
extern "C" {
void func_001CB4E0(void *, void *);
void func_001F7A68(void *, int);
QW PosLoWorld(void *);
void *PpathzoneFindPos(QW, int);
void func_001F37C8(void *, void *);
}
extern "C" void func_001CB518(SO *so, void *pool)
{
    func_001CB4E0(so, pool);
    func_001F7A68(so, 0);
    so->islot = -1;
    int link = 0;
    if (so->pphys != 0)
        link = so->pphys->link;
    if (link != 0) {
        QW pos = PosLoWorld(so);
        func_001F37C8(so, PpathzoneFindPos(pos, 1));
    }
    for (LO *child = so->ploChildFirst; child != 0; child = child->ploNext)
        child->Slot26(pool);
}
