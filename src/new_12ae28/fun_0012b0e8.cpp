#include "sly2.h"
struct Varb { int cref; int pad4; int symid; char ref[8]; Varb *next; };
struct HV { Varb *p; int pad[3]; };
extern "C" {
Varb *PvarbNew(void);
void func_00257430(HV *h, Varb *p);
void CRef_RefClone(void *out, void *src, void *frame, unsigned long arg);
void __as__4CRefRC4CRef(void *dst, void *src);
void CRef_Destruct(void *r);
void VarbPtr_Assign(void *h, Varb *v);
void VarbPtr_Destructor(void *h, int f);
void UnlinkVarbNode(Varb *v);
void FreeSlotheapPv(void *heap, void *p);
extern char B_004520D0[];
HV *VarbClone(HV *result, Varb *src, void *frame, unsigned long arg);
}
extern "C" HV *func_0012B0E8(HV *result, Varb *src, void *frame, unsigned long arg)
{
    HV h;
    func_00257430(&h, PvarbNew());
    h.p->symid = src->symid;
    {
        char refClone[16];
        char *dst = h.p->ref;
        CRef_RefClone(refClone, src->ref, frame, arg);
        __as__4CRefRC4CRef(dst, refClone);
        CRef_Destruct(refClone);
    }
    if (src->next) {
        HV next;
        Varb *cur = h.p;
        VarbClone(&next, src->next, frame, arg);
        VarbPtr_Assign(&cur->next, next.p);
        Varb *t = next.p;
        if (t && --t->cref == 0) {
            VarbPtr_Destructor(&t->next, 2);
            CRef_Destruct(t->ref);
            UnlinkVarbNode(t);
            FreeSlotheapPv(B_004520D0, t);
        }
    }
    func_00257430(result, h.p);
    Varb *t = h.p;
    if (t && --t->cref == 0) {
        VarbPtr_Destructor(&t->next, 2);
        CRef_Destruct(t->ref);
        UnlinkVarbNode(t);
        FreeSlotheapPv(B_004520D0, t);
    }
    return result;
}
