struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; int pad; };
struct CFrame;
struct SLOTHEAP;
extern "C" {
PairHandle *func_00121578(PairHandle *, CRef **, CRef **);
CRef *RefEval(CRef *, CPair *, CFrame *);
void CRef_Destruct(CRef *);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_ConstructPair(CRef *, CPair *);
void SetTag__4CRef4TAGK(CRef *, int);
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(CPair **, CPair *);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
}
extern "C" CRef *RefOpFilter(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    if (aref[1].tagk == 0) {
        CRef_CopyConstruct(pref, &aref[1]);
        return pref;
    }
    PairHandle call;
    PairHandle result;
    CRef refCondition;
    PairHandle item;
    CRef *prefCallee;
    CRef *prefArg;
    func_00121578(&call, &prefCallee, &prefArg);
    *prefCallee = aref[0];
    CPair *element = (CPair *)aref[1].n;
    result.p = 0;
    CPair *tail;
    if (element) {
        do {
            *prefArg = element->ref;
            RefEval(&refCondition, call.p, pframe);
            if (refCondition.tagk == 0x17 && refCondition.n != 0) {
                PairHandle_Init(&item, PpairNew());
                item.p->ref = element->ref;
                if (result.p == 0) {
                    PairHandle_Assign(&result.p, PpairNew());
                    bevy_splice_value_list_ref(&result.p->ref, item.p);
                } else {
                    PairHandle_Assign(&tail->next, item.p);
                }
                tail = item.p;
                CPair *held = item.p;
                if (held) {
                    if (--held->cref == 0) {
                        CPairPtr_Destructor(&held->next, 2);
                        CRef_Destruct(&held->ref);
                        UnlinkPairNode(held);
                        FreeSlotheapPv(&B_004520A8, held);
                    }
                }
            }
            element = element->next;
            CRef_Destruct(&refCondition);
        } while (element);
    }
    if (result.p != 0) {
        CRef_ConstructPair(pref, (CPair *)result.p->ref.n);
        CPair *held = result.p;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode(held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
        held = call.p;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode(held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
    } else {
        SetTag__4CRef4TAGK(pref, 0);
        CPair *held = result.p;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode(held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
        held = call.p;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode(held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
    }
    return pref;
}
