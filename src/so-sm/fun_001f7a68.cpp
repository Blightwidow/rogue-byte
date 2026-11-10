#include "sly2.h"
#include "so.h"
struct GEOM { char pad[0x14]; short dmg; int grftak; char pad1c[0xB0 - 0x1C]; };

void func_001F7A68(SO *so, long kind, int unused2, int unused3, int to, int damage, int from)
{
    if (kind == (((int)(so->grfso >> 24)) & 3)) return;
    switch (kind) {
    case 3:
    case 1:
    case 0:
        from = 0x10000;
        to = 0;
        damage = -10;
        break;
    case 2:
        damage = *(char *)&so->grfso;
        from = 0;
        to = 0x10000;
        break;
    }
    for (int index = 0; index < so->cgeom; index++) {
        GEOM *part = &so->ageom[index];
        if (part->grftak == from) {
            part->grftak = to;
            part->dmg = damage;
        }
    }
    so->grfso = (so->grfso & ~0x3000000L) | ((long)((((unsigned long)kind << 32 >> 32) & 3) << 24));
}
