// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef;
struct CFrame;
struct SLOTHEAP;
struct CPair;
extern "C" {
void CRef_CopyConstruct(CRef *, const CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk;
    CPair *pv;
    CRef() {}
    CRef(const CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
    CRef &operator=(const CRef &);
};
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(CPair **, CPair *);
PairHandle *func_00121578(PairHandle *, CRef **, CRef **);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
CRef RefEval(CPair *, CFrame *);
void CRef_ConstructPair(CRef *, CPair *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
}
struct PairHandle {
    CPair *p;
    int pad[3];
    PairHandle() {}
    PairHandle(CPair *pair) { PairHandle_Init(this, pair); }
    ~PairHandle()
    {
        CPair *held = p;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode(held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
    }
};
extern "C" CRef RefOpMap(int carg, CRef *aref, CFrame *pframe) return result
{
    if (aref[1].tagk == 0) {
        CRef_CopyConstruct(&result, &aref[1]);
        return;
    }
    CPair *tail;
    CRef *prefCallee;
    CRef *prefArg;
    PairHandle holder(PpairNew());
    PairHandle call;
    func_00121578(&call, &prefCallee, &prefArg);
    *prefCallee = aref[0];
    CPair *element = (CPair *)aref[1].pv;
    while (element != 0) {
        *prefArg = element->ref;
        PairHandle value(PpairNew());
        CRef *pvalueRef = &value.p->ref;
        *pvalueRef = RefEval(call.p, pframe);
        if (holder.p->ref.tagk != 0x1F)
            bevy_splice_value_list_ref(&holder.p->ref, value.p);
        else
            PairHandle_Assign(&tail->next, value.p);
        CPair *t = value.p;
        element = element->next;
        tail = t;
    }
    CRef_ConstructPair(&result, holder.p->ref.pv);
    return;
}
