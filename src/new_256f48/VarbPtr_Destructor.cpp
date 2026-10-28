// SPDX-License-Identifier: GPL-3.0-or-later
struct Varb;
struct VarbPtr { Varb *p; };
struct Varb { int count; char pad4[8]; char ref[8]; VarbPtr next; };
extern "C" {
void VarbPtr_Destructor(VarbPtr *, int);
void CRef_Destruct(void *);
void UnlinkVarbNode(Varb *);
void FreeSlotheapPv(void *, void *);
void __builtin_delete(void *);
extern char B_004520D0[];
}
void VarbPtr_Destructor(VarbPtr *self, int flags)
{
    Varb *varb = self->p;
    if (varb != 0) {
        if (--varb->count == 0) {
            VarbPtr_Destructor(&varb->next, 2);
            CRef_Destruct(varb->ref);
            UnlinkVarbNode(varb);
            FreeSlotheapPv(B_004520D0, varb);
        }
    }
    if (flags & 1)
        __builtin_delete(self);
}
