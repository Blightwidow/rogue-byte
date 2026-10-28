#include "sly2.h"
struct Varb { int cref; int pad4; int sym; char ref[8]; Varb *next; };
struct HV { Varb *p; int pad[3]; };
struct Owner { char pad[0x1C]; Varb *varb; };
extern "C" {
Varb *PvarbNew(void);
void func_00257430(HV *h, Varb *v);
void VarbPtr_Assign(void *h, Varb *v);
void VarbPtr_Destructor(void *h, int f);
void CRef_Destruct(void *r);
void SetTag__4CRef4TAGK(void *r, int tag);
void UnlinkVarbNode(Varb *v);
void FreeSlotheapPv(void *heap, void *p);
void *__as__4CRefRC4CRef(void *dst, void *src);
extern char B_004520D0[];
}
extern "C" void *CFrame_RefAddBinding(void *pref, Owner *powner, int sym, void *pvalue)
{
    HV h;
    Varb **pvarbHead = &powner->varb;
    func_00257430(&h, PvarbNew());
    h.p->sym = sym;
    __as__4CRefRC4CRef(h.p->ref, pvalue);
    VarbPtr_Assign(&h.p->next, *pvarbHead);
    VarbPtr_Assign(pvarbHead, h.p);
    SetTag__4CRef4TAGK(pref, 0x24);
    Varb *t = h.p;
    if (t && --t->cref == 0) {
        VarbPtr_Destructor(&t->next, 2);
        CRef_Destruct(t->ref);
        UnlinkVarbNode(t);
        FreeSlotheapPv(B_004520D0, t);
    }
    return pref;
}
