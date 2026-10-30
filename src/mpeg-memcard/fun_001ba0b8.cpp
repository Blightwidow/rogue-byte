#include "sly2.h"
struct VT_1BA0B8 { char pad[0x48]; short delta; short pad2; void (*fn)(void *); };
struct OBJ_1BA0B8 { char pad[0xC]; VT_1BA0B8 *vt; };
struct GUARD_1BA0B8 { char pad[0x1050]; OBJ_1BA0B8 *obj; };
extern "C" void OnGuardAdd();
extern "C" void func_001BA0B8(GUARD_1BA0B8 *guard)
{
    OnGuardAdd();
    OBJ_1BA0B8 *obj = guard->obj;
    if (obj != 0)
        obj->vt->fn((char *)obj + obj->vt->delta);
}
