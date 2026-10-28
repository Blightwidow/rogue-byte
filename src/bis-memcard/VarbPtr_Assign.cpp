// SPDX-License-Identifier: GPL-3.0-or-later
struct Varb;
struct CVarbPtr { Varb *p; };
struct Varb { int count; char pad4[8]; char ref[8]; CVarbPtr next; };
extern "C" {
void VarbPtr_Destructor(CVarbPtr *, int);
void CRef_Destruct(void *);
void UnlinkVarbNode(Varb *);
void FreeSlotheapPv(void *, void *);
extern char B_004520D0[];
}
void VarbPtr_Assign(CVarbPtr *self, Varb *pair)
{
    if (pair != 0)
        pair->count++;
    Varb *old = self->p;
    if (old != 0) {
        if (--old->count == 0) {
            VarbPtr_Destructor(&old->next, 2);
            CRef_Destruct(old->ref);
            UnlinkVarbNode(old);
            FreeSlotheapPv(B_004520D0, old);
        }
    }
    self->p = pair;
}
