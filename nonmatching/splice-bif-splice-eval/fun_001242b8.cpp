#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CFrame;
struct SW { char pad[0x3F0C]; int scope; };
struct LO { char pad[0x3C]; int scope; };
struct SLOTHEAP;
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; };
extern SW B_003DD490;
extern SLOTHEAP B_004520A8;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(CPair **, CPair *);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void CRef_ConstructPair(CRef *, CPair *);
int CRef_SetBasic(CRef *, int);
int PloFindSwObject(SW *, int, int, LO *, int);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
}
struct Locals {
    CRef refResult; int padA[2];
    PairHandle head; int padB[3];
    PairHandle node; int padC[3];
    CRef refList;
};
extern "C" CRef *func_001242B8(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    Locals l;
    l.refResult.tagk = -1;
    if (aref[0].tagk == 0) {
        CRef_CopyConstruct(pref, &aref[0]);
        CRef_Destruct(&l.refResult);
        asm volatile("");
        return pref;
    }
    LO *basis = (LO *)aref[1].n;
    LO *scopeObject;
    if (aref[2].tagk != 0)
        scopeObject = (LO *)((CPair *)aref[2].n)->ref.n;
    else
        scopeObject = basis;
    CPair *fresh = PpairNew();
    PairHandle_Init(&l.head, fresh);
    CPair *tail;
    CPair *oid = (CPair *)aref[0].n;
    CRef *prefList = &l.refList;
    if (oid != 0) {
        SW *psw = &B_003DD490;
        int grffso = 5;
        if (basis != 0)
            grffso = 1;
        do {
            fresh = PpairNew();
            PairHandle_Init(&l.node, fresh);
            CRef *prefNode = &l.node.p->ref;
            int scope;
            if (scopeObject != 0)
                scope = scopeObject->scope;
            else
                scope = psw->scope;
            int found = PloFindSwObject(psw, grffso, oid->ref.n, basis, scope);
            CRef_SetBasic(prefNode, found);
            if (l.head.p->ref.tagk != 0x1F)
                bevy_splice_value_list_ref(&l.head.p->ref, l.node.p);
            else
                PairHandle_Assign(&tail->next, l.node.p);
            tail = l.node.p;
            oid = oid->next;
            CPair *held = l.node.p;
            if (held) {
                if (--held->cref == 0) {
                    CPairPtr_Destructor(&held->next, 2);
                    CRef_Destruct(&held->ref);
                    UnlinkPairNode(held);
                    FreeSlotheapPv(&B_004520A8, held);
                }
            }
        } while (oid != 0);
    }
    CRef_ConstructPair(prefList, (CPair *)l.head.p->ref.n);
    l.refResult = *prefList;
    CRef_Destruct(prefList);
    CRef_CopyConstruct(pref, &l.refResult);
    CPair *held = l.head.p;
    if (held) {
        if (--held->cref == 0) {
            CPairPtr_Destructor(&held->next, 2);
            CRef_Destruct(&held->ref);
            UnlinkPairNode(held);
            FreeSlotheapPv(&B_004520A8, held);
        }
    }
    CRef_Destruct(&l.refResult);
    return pref;
}
