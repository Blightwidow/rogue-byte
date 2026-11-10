#include "sly2.h"
#include "alloc.h"
// One render tree entry (0x20 bytes). Its signed 4-bit field at bit 32 of the doubleword at +0x10 is the entry's state:
// AddSphereToRenderTree reads it with dsll 28 / dsra32 28 and treats -1 as a free entry; RemoveAloFromRenderTree frees one
// by or-ing 0xF << 32 in.
struct RTE {
    char field0[0x10];
    long field10 : 32;
    long rtet : 4;
    char field18[8];
};
struct RTN { RTE arte[4]; };
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);

// Retail loads the four state doublewords, stores them in the order 0x70, 0x50, 0x30, 0x10, and only the 0x70 entry
// gets a bare `or` of 0xF << 32: the others get `and ~(0xF << 32)` then `or`. That is one chained bitfield assignment:
// the innermost store (arte[3]) sees the constant -1 and gcc writes all ones with a single or; each outer store gets the
// previous assignment's value in a register and goes through the general mask-and-insert path.
RTN *AllocRenderTreeNode()
{
    ALLOCREQ request;
    request.cb = 0x80;
    request.cbAlign = 0x10;
    RTN *node = (RTN *)PvAllocSwClearImpl__Fi(&request);
    node->arte[0].rtet = node->arte[1].rtet = node->arte[2].rtet = node->arte[3].rtet = -1;
    return node;
}
