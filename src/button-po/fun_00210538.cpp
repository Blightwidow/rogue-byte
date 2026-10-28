#include "sly2.h"
struct REQ { unsigned grf; void *target; float g; char pad[0x24]; void *extra; };
struct VT { char pad[0x198]; short delta; short index; void (*fn)(void *, REQ *); };
struct OBJ { int a, b, c; VT *vt; };
extern "C" OBJ *PloFindSwObject_thunk(void *, int, int, int);
void func_00210538(void *sw, int oid, int oidTarget, int oidExtra, int context, float g)
{
    OBJ *object = PloFindSwObject_thunk(sw, 4, oid, context);
    if (!object)
        return;
    REQ request;
    request.grf = 0;
    if (oidTarget != -1) {
        OBJ *target = PloFindSwObject_thunk(sw, 4, oidTarget, context);
        if (target) {
            request.target = target;
            request.grf |= 1;
        }
    }
    if (((request.grf ^ 1) & 1) != 0) {
        request.grf |= 1;
        request.target = object;
    }
    if (oidExtra != -1) {
        OBJ *extra = PloFindSwObject_thunk(sw, 4, oidExtra, context);
        if (extra) {
            request.extra = extra;
            request.grf |= 0x20;
        }
    }
    float one = 1.0f;
    asm volatile("nop");
    if (g != one) {
        request.grf |= 0x18;
        request.g = g;
    }
    object->vt->fn((char *)object + object->vt->delta, &request);
}
