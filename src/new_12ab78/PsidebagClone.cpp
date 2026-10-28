#include "sly2.h"
struct Varb { int cref; int pad4; int pad8; char ref[8]; char vp[8]; };
struct Sidebag { int cref; int pad4; Varb *first; };
struct HS { Sidebag *p; int pad[3]; };
struct HV { Varb *p; int pad[3]; };
extern "C" {
Sidebag *PsidebagNew(void);
void func_00257E68(void *h, Sidebag *s);
void func_0012B0E8(void *out, Varb *src, void *nf, unsigned long arg);
void VarbPtr_Assign(void *h, Varb *v);
void VarbPtr_Destructor(void *h, int f);
void CRef_Destruct(void *r);
void UnlinkVarbNode(Varb *v);
void UnlinkSidebagNode(Sidebag *s);
void FreeSlotheapPv(void *heap, void *p);
extern char B_004520D0[];
extern char B_00452148[];
}
HS *PsidebagClone(HS *result, Sidebag *src, unsigned long arg)
{
    HS h;
    HV clone;
    func_00257E68(&h, PsidebagNew());
    if (src->first) {
        Sidebag *cur = h.p;
        func_0012B0E8(&clone, src->first, 0, arg);
        VarbPtr_Assign(&cur->first, clone.p);
        Varb *t = clone.p;
        if (t && --t->cref == 0) {
            VarbPtr_Destructor((char *)t + 0x14, 2);
            CRef_Destruct((char *)t + 0xC);
            UnlinkVarbNode(t);
            FreeSlotheapPv(B_004520D0, t);
        }
    }
    func_00257E68(result, h.p);
    Sidebag *s = h.p;
    if (s && --s->cref == 0) {
        Varb *t = s->first;
        if (t && --t->cref == 0) {
            VarbPtr_Destructor((char *)t + 0x14, 2);
            CRef_Destruct((char *)t + 0xC);
            UnlinkVarbNode(t);
            FreeSlotheapPv(B_004520D0, t);
        }
        UnlinkSidebagNode(s);
        FreeSlotheapPv(B_00452148, s);
    }
    return result;
}
