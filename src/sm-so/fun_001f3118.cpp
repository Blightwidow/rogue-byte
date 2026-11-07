// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x150]; short delta; short index; void (*fn)(void *, float); };
struct SoNode {
    char pad0[0xC]; VT *vptr; int unk10; int unk14; char pad18[0xC]; SoNode *next; unsigned long flags; char pad30[8];
    float f38; char pad3c[0x64 - 0x3c]; SoNode *child; char pad68[0x140 - 0x68]; int gen;
};
extern "C" void RemoveAloFromRenderTree(SoNode *);
extern "C" void AddAloToRenderTree(SoNode *);
extern "C" void ReinsertSwRoot(void *, int);
extern char B_003DD490;
extern "C" void func_001F3118(SoNode *so, float value)
{
    VECTOR vector;
    so->f38 = value;
    if (so->gen != -1) {
        RemoveAloFromRenderTree(so);
        AddAloToRenderTree(so);
    }
    if (so->unk10 == 0 && ((unsigned)(so->flags >> 60) & 1)) {
        ReinsertSwRoot(&B_003DD490, so->unk14);
    }
    SoNode *child = so->child;
    while (child) {
        if (value < child->f38) {
            VT *vtable = child->vptr;
            vtable->fn((char *)child + vtable->delta, value);
        }
        child = child->next;
    }
}
