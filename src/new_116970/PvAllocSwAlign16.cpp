#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
void *PvAllocSwImpl(int);
void *PvAllocSwAlign16(void *, int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwImpl((int)&req);
}
