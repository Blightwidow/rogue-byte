#include "sly2.h"
struct ELEM_1F68A8 { char pad0[0x10]; long flags; char pad1[0xB0 - 0x18]; };
struct SO_1F68A8 { char pad0[0xE0]; int count; ELEM_1F68A8 *elems; };
extern "C" {
void func_001F68A8(SO_1F68A8 *so, int value)
{
    for (int index = 0; index < so->count; index++) {
        ELEM_1F68A8 *elem = (ELEM_1F68A8 *)(index * 0xB0 + (unsigned)so->elems);
        elem->flags = (elem->flags & ~(1L << 48)) | ((long)(value & 1) << 48);
    }
}
}
