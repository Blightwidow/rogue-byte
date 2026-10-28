// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Obj {
    char pad0[0x50];
    int f50; float f54, f58, f5c, f60, f64, f68, f6c;
    char pad70[0xC];
    int f7c, f80, f84;
    char pad88[0x20];
    int fa8, faa_ac;
    char padb0[1];
};
extern "C" void InitLo(Obj *);
extern "C" void ResetAnimref(void *, int);
extern "C" const float RO_FLT_002A88C8;
void func_0020AD38(Obj *self) {
    InitLo(self);
    self->f50 = 0;
    self->f54 = 300.0f;
    self->f58 = -5000.0f;
    self->f5c = 5000.0f;
    self->f60 = 0.2f;
    self->f64 = 0.5f;
    self->f68 = 0.17453295f;
    self->fa8 = 1;
    self->f7c = -1;
    self->f80 = -1;
    self->f84 = -1;
    self->f6c = RO_FLT_002A88C8;
    ResetAnimref((char *)self + 0xB0, self->faa_ac);
}
