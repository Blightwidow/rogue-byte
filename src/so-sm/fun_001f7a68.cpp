#include "sly2.h"
struct PART { char pad[0x14]; short dmg; int grftak; char pad1c[0xB0 - 0x1C]; };
struct SO { char pad[0xE0]; int cpart; PART *parts; char pad0[0x148 - 0xE8]; long flags; };

void func_001F7A68(SO *so, long kind, int unused2, int unused3, int to, int damage, int from)
{
    if (kind == (((int)(so->flags >> 24)) & 3)) return;
    switch (kind) {
    case 3:
    case 1:
    case 0:
        from = 0x10000;
        to = 0;
        damage = -10;
        break;
    case 2:
        damage = *(char *)&so->flags;
        from = 0;
        to = 0x10000;
        break;
    }
    for (int index = 0; index < so->cpart; index++) {
        PART *part = &so->parts[index];
        if (part->grftak == from) {
            part->grftak = to;
            part->dmg = damage;
        }
    }
    so->flags = (so->flags & ~0x3000000L) | ((long)((((unsigned long)kind << 32 >> 32) & 3) << 24));
}
