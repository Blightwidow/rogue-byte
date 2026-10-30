#include "sly2.h"
struct LINK_1F6978 { char pad0[0x10]; long flags; };
struct ELEM_1F6978 { int oid; char pad0[0xC - 4]; int flags; char pad1[0x24 - 0x10]; LINK_1F6978 *link; char pad2[0x28 - 0x28]; };
struct SO_1F6978 { char pad0[0xB8]; int count; char padc[4]; ELEM_1F6978 *elems; };
extern "C" {
void func_001F6978(SO_1F6978 *so, int oid)
{
    for (int index = 0; index < so->count; index++) {
        ELEM_1F6978 *elem = &so->elems[index];
        if (elem->oid == oid) {
            LINK_1F6978 *link = elem->link;
            elem->flags &= ~0x800;
            if (link) link->flags &= ~(1L << 50);
        }
    }
}
}
