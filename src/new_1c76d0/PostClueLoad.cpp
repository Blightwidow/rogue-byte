#include "sly2.h"
struct VT_1C8030 { char pad[0x48]; short delta; short pad2; void (*fn)(void *); };
struct OBJ_1C8030 { char pad0[0xC]; VT_1C8030 *vt; char pad1[0x100 - 0x10]; int serial; };
struct GLOBALS_1C8030 { char pad[0x4760]; int serialCounter; };
extern GLOBALS_1C8030 B_003DD490;
extern "C" void PostLoLoad();
extern "C" int FClueFound(int);
extern "C" void PostClueLoad(OBJ_1C8030 *self)
{
    PostLoLoad();
    self->serial = B_003DD490.serialCounter++;
    if (FClueFound(self->serial) != 0)
        self->vt->fn((char *)self + self->vt->delta);
}
