#include "sly2.h"
struct SW; struct LO;
extern "C" int CploFindSwObjectsByClass(SW *, unsigned, int, LO *, int, LO **);
extern "C" LO *PloFindSwObjectByClass(SW *sw, unsigned flags, int cid, LO *context)
{
    LO *found;
    if (CploFindSwObjectsByClass(sw, flags | 0x200, cid, context, 1, &found) != 0)
        return found;
    return 0;
}
