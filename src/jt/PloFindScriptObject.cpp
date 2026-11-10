struct Script { char pad[0x34]; int context; };
#include "sw.h"
extern "C" SW B_003DD490;
extern "C" void *PloFindSwObject_thunk(SW *, int, int, int);
void PloFindScriptObject(Script *script, int oid)
{
    int flags = script->context ? 4 : 5;
    PloFindSwObject_thunk(&B_003DD490, flags, oid, script->context);
}
