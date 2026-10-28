// SPDX-License-Identifier: GPL-3.0-or-later
struct Pair;
struct CPairPtr { Pair *p; };
struct Pair { int count; int pad4; char ref[8]; CPairPtr next; };
extern "C" {
void CPairPtr_Destructor(CPairPtr *, int);
void CRef_Destruct(void *);
void UnlinkPairNode(Pair *);
void FreeSlotheapPv(void *, void *);
extern char B_004520A8[];
}
void PairHandle_Assign(CPairPtr *self, Pair *pair)
{
    if (pair != 0)
        pair->count++;
    Pair *old = self->p;
    if (old != 0) {
        if (--old->count == 0) {
            CPairPtr_Destructor(&old->next, 2);
            CRef_Destruct(old->ref);
            UnlinkPairNode(old);
            FreeSlotheapPv(B_004520A8, old);
        }
    }
    self->p = pair;
}
