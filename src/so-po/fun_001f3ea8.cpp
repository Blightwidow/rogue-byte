#include "sly2.h"
struct VT {
    char pad[0xB8]; short delta; short index; void (*fn)(void *);
    char pad2[0xC8]; short delta2; short index2; void (*fn2)(void *);
};
struct OXA { char pad[0x60]; void *owner; };
struct SO {
    char pad0[0xC]; VT *vt; char pad1[0x30]; unsigned grfTag; char pad2[0x20]; SO *first; char pad3[0x8]; SO *end;
    char pad4[0x78]; OXA *oxa; char pad5[0x58]; unsigned long flags;
};
struct CH { char pad0[0xC]; VT *vt; char pad1[0x14]; CH *next; };
extern "C" void func_001A6178(SO *);
extern "C" void AddAloToRenderTree(SO *);
extern "C" int FFindDlEntry(void *, void *);
extern "C" void AppendDlEntry(void *, void *);
extern char B_003E11AC[];

void func_001F3EA8(SO *pso)
{
    func_001A6178(pso);
    int pad; asm volatile("" : : "m"(pad));
    if ((pso->flags & 0x800000000UL) != 0) {
        unsigned tag = pso->grfTag;
        unsigned grf = tag;
        if (((tag ^ 1) & 1) != 0)
            grf = *(unsigned *)tag;
        if ((grf & 8) != 0)
            AddAloToRenderTree(pso);
    }
    CH *child = (CH *)pso->first;
    if (child != (CH *)pso->end) {
        do {
            VT *vt = child->vt;
            vt->fn((char *)child + vt->delta);
            child = child->next;
        } while (child != (CH *)pso->end);
    }
    if (pso->oxa) {
        if (pso->oxa->owner == pso) {
            if (!FFindDlEntry(B_003E11AC, pso->oxa))
                AppendDlEntry(B_003E11AC, pso->oxa);
            VT *vt = pso->vt;
            vt->fn2((char *)pso + vt->delta2);
        }
    }
}
