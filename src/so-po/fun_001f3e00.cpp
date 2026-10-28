#include "sly2.h"
struct VT {
    char pad[0xB0]; short delta; short index; void (*fn)(void *);
    char pad2[0xD0]; short delta2; short index2; void (*fn2)(void *);
};
struct OXA { char pad[0x60]; void *owner; };
struct SOX {
    char pad0[0xC]; VT *vt; char pad1[0x54]; SOX *first; char pad2[0x8]; SOX *end;
    char pad3[0x78]; OXA *oxa;
};
extern "C" void RemoveAloHierarchy(void *);
extern "C" void RemoveAloFromRenderTree(void *);
extern "C" void RemoveDlEntry(void *, void *);
extern char B_003E11AC[];
struct CH { char pad0[0xC]; VT *vt; char pad1[0x14]; CH *next; };
extern "C" void func_001F3E00(SOX *so)
{
    RemoveAloHierarchy(so);
    int pad; asm volatile("" : : "m"(pad)); // reserves the original's 16-byte local area
    RemoveAloFromRenderTree(so);
    CH *child = (CH *)so->first;
    if (child != (CH *)so->end) {
        do {
            VT *vt = child->vt;
            vt->fn((char *)child + vt->delta);
            child = child->next;
        } while (child != (CH *)so->end);
    }
    if (so->oxa) {
        if (so->oxa->owner == so) {
            so->vt->fn2((char *)so + so->vt->delta2);
            RemoveDlEntry(B_003E11AC, so->oxa);
        }
    }
}
