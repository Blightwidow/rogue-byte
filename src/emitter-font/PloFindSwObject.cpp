#include "sly2.h"
struct SW; struct LO;
extern "C" int CploFindSwObjects(SW *, unsigned, int, LO *, void *, int, LO **);
extern "C" LO *PloFindSwObject(SW *sw, unsigned flags, int oid, LO *context, void *ownerContext)
{
    LO *found;
    if (CploFindSwObjects(sw, flags | 0x200, oid, context, ownerContext, 1, &found) != 0)
        return found;
    return 0;
}
