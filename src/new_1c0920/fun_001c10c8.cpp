#include "sly2.h"
struct ALLOCREQ_1C10C8 { int cb; int cbAlign; };
struct PLOHOLDER_1C10C8 { char pad[0x45C8]; int plo; int pzgraph; };
extern "C" int PloNew(int, int, int, int);
extern "C" void SetupDefaultPathzone(int);
extern "C" int PvAllocSwClearImpl__Fi(ALLOCREQ_1C10C8 *);
extern "C" void HookupPzgraph(int);
extern "C" void func_001C10C8(PLOHOLDER_1C10C8 *self)
{
    if (self->pzgraph == 0) {
        self->plo = PloNew(0x11, 0, 0x2CA, -1);
        SetupDefaultPathzone(self->plo);
        ALLOCREQ_1C10C8 req;
        req.cb = 0x30;
        req.cbAlign = 0x10;
        self->pzgraph = PvAllocSwClearImpl__Fi(&req);
    }
    HookupPzgraph(self->pzgraph);
}
