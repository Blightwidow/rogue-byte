#include "sly2.h"
struct Varb { int cref; int pad4; int symid; char ref[8]; Varb *next; };
struct CFrame { int cref; char pad4[4]; int slotCount; void *slots[4]; Varb *varbs; };
struct HV { Varb *p; int pad[3]; };
struct HFrame { CFrame *p; int pad[3]; };
extern "C" {
CFrame *PframeNew(void);
void func_00257058(HFrame *h, CFrame *p);
void CFramePtr_Assign(void *dst, void *src);
void VarbPtr_Assign(void *h, Varb *v);
void VarbPtr_Destructor(void *h, int f);
void CRef_Destruct(void *r);
void UnlinkVarbNode(Varb *v);
void FreeSlotheapPv(void *heap, void *p);
void CFrame_DeletingDestructor(CFrame *p, int flags);
void func_0012B0E8(HV *result, Varb *src, CFrame *frame, unsigned long arg);
extern char B_004520D0[];
}

extern "C" HFrame *PframeClone(HFrame *result, CFrame *src, unsigned long arg)
{
    HFrame h;
    int i = 0;
    func_00257058(&h, PframeNew());
    h.p->slotCount = src->slotCount;
    for (i = 0; i < src->slotCount; i++) {
        CFramePtr_Assign((char *)(i * 4) + (int)h.p + 0xC, src->slots[i]);
    }
    if (src->varbs != 0) {
        HV varbs;
        CFrame *pframeNew = h.p;
        func_0012B0E8(&varbs, src->varbs, pframeNew, arg);
        VarbPtr_Assign(&pframeNew->varbs, varbs.p);
        Varb *t = varbs.p;
        if (t && --t->cref == 0) {
            VarbPtr_Destructor(&t->next, 2);
            CRef_Destruct(t->ref);
            UnlinkVarbNode(t);
            FreeSlotheapPv(B_004520D0, t);
        }
    }
    func_00257058(result, h.p);
    CFrame *t = h.p;
    if (t && --t->cref == 0) {
        CFrame_DeletingDestructor(t, 3);
    }
    return result;
}
