struct CRef { int tagk; int n; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; int pad[3]; };
struct SLOTHEAP;
struct CFrame;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Assign(CPair **, CPair *);
void PpairClone(PairHandle *, CPair *, CFrame *, unsigned long);
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_ConstructPair(CRef *, CPair *);
void CRef_CopyConstruct(CRef *, CRef *);
void bevy_splice_value_list_ref(CRef *, CPair *);
extern SLOTHEAP B_004520A8;
}
static inline void ReleasePair(CPair *held)
{
    if (held) {
        if (--held->cref == 0) {
            CPairPtr_Destructor(&held->next, 2);
            CRef_Destruct(&held->ref);
            UnlinkPairNode(held);
            FreeSlotheapPv(&B_004520A8, held);
        }
    }
}
extern "C" CRef *RefOpAppend(CRef *pret, int carg, CRef *aref)
{
    PairHandle result;
    PairHandle copy;
    PairHandle clone;
    if (aref->tagk == 0) {
        CRef_CopyConstruct(pret, aref);
        return pret;
    }
    CPair *tail;
    result.p = 0;
    for (CPair *node = (CPair *)aref->n; node != 0; node = node->next) {
        if (node->ref.tagk == 0x1F) {
            copy.p = 0;
            if (node->next != 0) {
                PpairClone(&clone, (CPair *)node->ref.n, 0, 0);
                PairHandle_Assign(&copy.p, clone.p);
                ReleasePair(clone.p);
            } else {
                PairHandle_Assign(&copy.p, (CPair *)node->ref.n);
            }
            if (result.p == 0) {
                PairHandle_Assign(&result.p, PpairNew());
                bevy_splice_value_list_ref(&result.p->ref, copy.p);
            } else {
                PairHandle_Assign(&tail->next, copy.p);
            }
            tail = copy.p;
            CPair *held = copy.p;
            while (tail->next != 0)
                tail = tail->next;
            ReleasePair(held);
        }
    }
    if (result.p == 0) {
        SetTag__4CRef4TAGK(pret, 0);
        ReleasePair(result.p);
    } else {
        CRef_ConstructPair(pret, (CPair *)result.p->ref.n);
        ReleasePair(result.p);
    }
    return pret;
}
