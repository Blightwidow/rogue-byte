#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct RTE { char pad[0x10]; unsigned long grf; char pad2[8]; };
struct RTN { RTE arte[4]; };
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
RTN *AllocRenderTreeNode()
{
    ALLOCREQ req;
    req.cb = 0x80;
    req.cbAlign = 0x10;
    RTN *node = (RTN *)PvAllocSwClearImpl__Fi(&req);
    node->arte[0].grf = (node->arte[0].grf & ~0xF00000000UL) | 0xF00000000UL;
    node->arte[1].grf = (node->arte[1].grf & ~0xF00000000UL) | 0xF00000000UL;
    node->arte[2].grf = (node->arte[2].grf & ~0xF00000000UL) | 0xF00000000UL;
    node->arte[3].grf = (node->arte[3].grf & ~0xF00000000UL) | 0xF00000000UL;
    return node;
}
