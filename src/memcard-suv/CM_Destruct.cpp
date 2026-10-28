// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x10]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct CM { char pad[0x484]; OBJ *p484; OBJ *p488; char pad2[0x5E0 - 0x48C]; OBJ *p5E0; OBJ *p5E4; };
extern "C" void BASIC_Destruct(void *, int);
static inline void Release(OBJ *object)
{
    if (object != 0) {
        VT *vt = object->vt;
        vt->fn((char *)object + vt->delta);
    }
}
void CM_Destruct(CM *cm, int flags)
{
    Release(cm->p5E4);
    Release(cm->p5E0);
    Release(cm->p488);
    Release(cm->p484);
    BASIC_Destruct(cm, flags);
}
