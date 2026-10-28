// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef;
struct Pair;
struct CPairPtr { Pair *p; };
struct Pair { int count; int pad4; char ref[8]; CPairPtr next; };
extern "C" {
void CPairPtr_Destructor(CPairPtr *, int);
void CRef_Destruct(void *);
void UnlinkPairNode(Pair *);
void FreeSlotheapPv(void *, void *);
void __builtin_delete(void *);
extern char B_004520A8[];
}
void CPairPtr_Destructor(CPairPtr *self, int flags)
{
    Pair *pair = self->p;
    if (pair != 0) {
        if (--pair->count == 0) {
            CPairPtr_Destructor(&pair->next, 2);
            CRef_Destruct(pair->ref);
            UnlinkPairNode(pair);
            FreeSlotheapPv(B_004520A8, pair);
        }
    }
    if (flags & 1)
        __builtin_delete(self);
}
