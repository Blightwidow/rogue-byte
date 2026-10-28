#include "sly2.h"
struct VT { char pad[336]; short delta; short index; void (*fn)(void *, float); };
struct SO {
    char pad0[0xC]; VT *vptr; int unk10; int unk14; char pad18[0xC]; SO *next; unsigned long flags; char pad30[8];
    float f38; char pad3c[0x64 - 0x3c]; SO *child;
};
extern "C" void RemoveAloFromRenderTree(SO *);
extern "C" void AddAloToRenderTree(SO *);
extern "C" void ReinsertSwRoot(void *, int);
extern "C" char B_003DD490[];
struct SO2 : SO { char pad[0x140 - 0x68]; int gen; };

void func_001F3118(SO2 *so, float value)
{
    volatile char scratch[16];
    so->f38 = value;
    if (so->gen != -1) {
        RemoveAloFromRenderTree(so);
        AddAloToRenderTree(so);
    }
    if (so->unk10 == 0 && ((unsigned)(so->flags >> 60) & 1)) {
        ReinsertSwRoot(B_003DD490, so->unk14);
    }
    SO *child = so->child;
    while (child) {
        if (value < child->f38) {
            VT *vtable = child->vptr;
            vtable->fn((char *)child + vtable->delta, value);
        }
        child = child->next;
    }
}
