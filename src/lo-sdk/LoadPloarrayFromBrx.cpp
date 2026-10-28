// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x128]; short delta; short index; void (*fn)(void *, void *); };
struct LO { char pad[0xC]; VT *vt; };
struct PLOARRAY { char pad[8]; int cplo; LO **aplo; };
struct XFM { char pad[0x10]; void *parent; char pad2[0x3C]; void *xf; char pad3[0xC]; char matLocal[1]; };
extern "C" void func_0022D670(void *);
extern "C" void func_0022D698(void *);
void LoadSwObjectsFromBrx(void *, void *, PLOARRAY *);
void LoadPloarrayFromBrx(XFM *xfm, void *bis, PLOARRAY *sink)
{
    func_0022D670(xfm->xf);
    LoadSwObjectsFromBrx(xfm->parent, bis, sink);
    func_0022D698(xfm->xf);
    for (int index = 0; index < sink->cplo; index++) {
        LO *object = sink->aplo[index];
        VT *vt = object->vt;
        vt->fn((char *)object + vt->delta, xfm->matLocal);
    }
}
