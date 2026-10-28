#include "sly2.h"
struct Varb { int cref; int pad4; int pad8; char ref[8]; char vp[8]; };
struct Frame { int cref; int pad4; int count; Frame *parent[4]; Varb *varb; };
struct HF { Frame *p; int pad[3]; };
struct HV { Varb *p; int pad[3]; };
extern "C" {
Frame *PframeNew(void);
void func_00257058(void *h, Frame *f);
void CFramePtr_Assign(void *h, Frame *f);
void func_0012B0E8(void *out, Varb *src, Frame *nf, unsigned long arg);
void VarbPtr_Assign(void *h, Varb *v);
void VarbPtr_Destructor(void *h, int f);
void CRef_Destruct(void *r);
void UnlinkVarbNode(Varb *v);
void FreeSlotheapPv(void *heap, void *p);
void CFrame_DeletingDestructor(Frame *f, int flag);
extern char B_004520D0[];
}
Frame **PframeClone(Frame **result, Frame *src, unsigned long arg)
{
    register int i asm("$16") = 0;
    HF h;
    HV clone;
    func_00257058(&h, PframeNew());
    h.p->count = src->count;
    if (src->count > 0) {
        register int c asm("$2");
        register Frame **sp asm("$17") = src->parent;
        do {
            CFramePtr_Assign((char *)((i << 2) + (int)h.p) + 0xC, *sp);
            sp++;
            i++;
            c = src->count;
        } while (i < c);
    }
    if (src->varb) {
        Frame *nf = h.p;
        func_0012B0E8(&clone, src->varb, nf, arg);
        VarbPtr_Assign(&nf->varb, clone.p);
        Varb *t = clone.p;
        if (t && --t->cref == 0) {
            VarbPtr_Destructor((char *)t + 0x14, 2);
            CRef_Destruct((char *)t + 0xC);
            UnlinkVarbNode(t);
            FreeSlotheapPv(B_004520D0, t);
        }
    }
    func_00257058(result, h.p);
    Frame *t = h.p;
    if (t && --t->cref == 0)
        CFrame_DeletingDestructor(t, 3);
    return result;
}
