#include "sly2.h"
struct CRef { int tagk; int n; };
struct Frame;
struct Pair;
struct SLOTHEAP;
struct HP { Pair *p; int pad[3]; };
struct Proc { int cref; };
extern "C" {
void CRef_ConstructVector(CRef *, void *);
void CRef_ConstructMatrix(CRef *, void *);
void CRef_ConstructClq(CRef *, void *);
void CRef_ConstructLm(CRef *, void *);
void CRef_ConstructSmp(CRef *, void *);
void CRef_ConstructPair(CRef *, Pair *);
void CRef_ConstructProc(CRef *, Proc *);
void CRef_ConstructBasic(CRef *, void *);
void CRef_CopyConstruct(CRef *, CRef *);
void PpairClone(HP *, void *, Frame *, unsigned long);
void PprocClone(Proc **, void *, Frame *);
void CPairPtr_Destructor(Pair **, int);
void CRef_Destruct(CRef *);
void UnlinkPairNode(Pair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void CProc_DeletingDestructor(Proc *, int);
extern SLOTHEAP B_004520A8;
}
struct PairView { int cref; int pad4; CRef ref; Pair *next; };
extern "C" CRef *CRef_RefClone(CRef *pref, CRef *ref, Frame *pframe, unsigned long ulArg)
{
    switch (ref->tagk) {
    case 0x1A:
        CRef_ConstructVector(pref, (void *)ref->n);
        return pref;
    case 0x1B:
        CRef_ConstructMatrix(pref, (void *)ref->n);
        return pref;
    case 0x1C:
        CRef_ConstructClq(pref, (void *)ref->n);
        return pref;
    case 0x1D:
        CRef_ConstructLm(pref, (void *)ref->n);
        return pref;
    case 0x1E:
        CRef_ConstructSmp(pref, (void *)ref->n);
        return pref;
    case 0x1F: {
        HP clone;
        PpairClone(&clone, (void *)ref->n, pframe, ulArg);
        CRef_ConstructPair(pref, clone.p);
        PairView *held = (PairView *)clone.p;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode((Pair *)held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
        return pref;
    }
    case 0x20: {
        struct { Proc *p; int pad[3]; } cloneBox;
        PprocClone(&cloneBox.p, (void *)ref->n, pframe);
        CRef_ConstructProc(pref, cloneBox.p);
        Proc *held = cloneBox.p;
        if (held) {
            if (--held->cref == 0)
                CProc_DeletingDestructor(held, 3);
        }
        return pref;
    }
    case 0x21:
        CRef_ConstructBasic(pref, (void *)ref->n);
        return pref;
    default:
        CRef_CopyConstruct(pref, ref);
        return pref;
    }
}
