// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; };
struct CPair;
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; };
struct SLOTHEAP;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(CPair **, CPair *);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
void CRef_Destruct(CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
}
extern "C" PairHandle *func_00121578(PairHandle *pret, CRef **pprefCallee, CRef **pprefArg)
{
    PairHandle outer;
    CPair *tmp;
    PairHandle_Init(&outer, PpairNew());
    CRef *prefOuter = &outer.p->ref;
    bevy_splice_value_list_ref(prefOuter, PpairNew());
    CPair *call = (CPair *)((CRef*)((char*)outer.p+8))->n;
    CRef *prefCall = &call->ref;
    bevy_splice_value_list_ref(prefCall, PpairNew());
    tmp = PpairNew(); PairHandle_Assign(&call->next, tmp);
    CPair *callee = (CPair *)prefCall->n;
    CRef *prefCallee = &callee->ref;
    CRef_Destruct(prefCallee);
    SetTag__4CRef4TAGK(prefCallee, 0x12);
    tmp = PpairNew(); PairHandle_Assign(&callee->next, tmp);
    *pprefCallee = &((CPair *)*(int *)((char *)callee + 0x10))->ref;
    CRef *prefArgForm = &call->next->ref;
    bevy_splice_value_list_ref(prefArgForm, PpairNew());
    CPair *arg = (CPair *)prefArgForm->n;
    CRef *prefArg = &arg->ref;
    CRef_Destruct(prefArg);
    SetTag__4CRef4TAGK(prefArg, 0x12);
    tmp = PpairNew(); PairHandle_Assign(&arg->next, tmp);
    *pprefArg = &arg->next->ref;
    PairHandle_Init(pret, outer.p);
    CPair *held = outer.p;
    if (held) {
        if (--held->cref == 0) {
            CPairPtr_Destructor(&held->next, 2);
            CRef_Destruct(&held->ref);
            UnlinkPairNode(held);
            FreeSlotheapPv(&B_004520A8, held);
        }
    }
    return pret;
}
