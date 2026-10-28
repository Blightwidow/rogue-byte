// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CFrame { int PrefFindBinding(unsigned, int); };
struct VT { char pad[24]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct LoObj {
    CFrame *frame;
    char pad04[8];
    VT *vptr;
    char pad10[0x18];
    long flags;
    float f30;
    char pad34[12];
    unsigned f40;
};
extern "C" void func_001A5D98(LoObj *);
extern "C" void func_001A6CA8(LoObj *, int);
extern "C" const float RO_FLT_002A6A40;
void PostLoLoad(LoObj *self) {
    func_001A5D98(self);
    VT *vt = self->vptr;
    vt->fn((char *)self + vt->delta, 0, 1, 0, 0, 0);
    CFrame *frame = self->frame;
    if (frame && frame->PrefFindBinding(1, 1)) {
        if (((self->flags << 8) >> 60) == 2) func_001A6CA8(self, 0);
        unsigned p = self->f40;
        if ((p ^ 1) & 1) *(unsigned *)p |= 2;
        else self->f40 = p | 2;
    } else {
        self->f30 = RO_FLT_002A6A40;
    }
}
