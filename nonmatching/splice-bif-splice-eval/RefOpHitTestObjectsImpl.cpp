typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; union { int n; QW *pv; }; CRef &operator=(const CRef &); };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; int pad[3]; };
struct SLOTHEAP;
struct CLIP { QW pos; QW normal; QW rest[4]; };
struct ELEM { char pad0[0x10]; long flags; char pad18[0xB0 - 0x18]; };
struct OBJ { char pad0[0xE0]; int count; ELEM *elems; };
struct CNode { int pad0; int pad4; CRef ref; CNode *next; };
struct CRefList { int tagk; CNode *pnode; CRef start; CRef end; };
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(CPair **, CPair *);
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_SetBasic(CRef *, void *);
void CRef_SetVectorPtr(CRef *, QW *);
void bevy_splice_value_list_ref(CRef *, CPair *);
int ClsgClipEdgeToObject(ELEM *, QW, QW, int, CLIP *);
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
extern "C" CRef *RefOpHitTestObjectsImpl(CRef *pret, int op, int unused, CRefList *aref)
{
    CRef result;
    result.tagk = -1;
    if (aref->tagk == 0) {
        result = *(CRef *)aref;
    } else {
        PairHandle first;
        PairHandle last;
        CLIP clip;
        PairHandle pairA;
        PairHandle pairB;
        PairHandle pairC;
        PairHandle pairD;
        PairHandle_Init(&first, 0);
        PairHandle_Init(&last, 0);
        CRef *pstart = &aref->start;
        CRef *pend = &aref->end;
        for (CNode *node = aref->pnode; node != 0; node = node->next) {
            OBJ *pobj = (OBJ *)node->ref.n;
            if (pobj != 0 && pobj->count > 0) {
                for (int index = 0; index < pobj->count; index++) {
                    ELEM *pelem = &pobj->elems[index];
                    if (!(pelem->flags & (0x8000L << 35)) &&
                        ClsgClipEdgeToObject(pelem, *pstart->pv, *pend->pv, 1, &clip) > 0) {
                        PairHandle_Init(&pairA, PpairNew());
                        PairHandle_Init(&pairB, PpairNew());
                        CRef_SetBasic(&pairA.p->ref, pobj);
                        PairHandle_Assign(&pairA.p->next, pairB.p);
                        if (op == 0x7B) {
                            PairHandle_Init(&pairC, PpairNew());
                            PairHandle_Init(&pairD, PpairNew());
                            CRef_SetVectorPtr(&pairB.p->ref, &clip.pos);
                            PairHandle_Assign(&pairB.p->next, pairC.p);
                            CRef_SetVectorPtr(&pairC.p->ref, &clip.normal);
                            bevy_splice_value_list_ref(&pairD.p->ref, pairA.p);
                            if (first.p != 0)
                                PairHandle_Assign(&last.p->next, pairD.p);
                            else
                                PairHandle_Assign(&first.p, pairD.p);
                            PairHandle_Assign(&last.p, pairD.p);
                            ReleasePair(pairD.p);
                            ReleasePair(pairC.p);
                        } else {
                            CRef_SetVectorPtr(&pairB.p->ref, &clip.normal);
                            bevy_splice_value_list_ref(&result, pairA.p);
                            CRef_CopyConstruct(pret, &result);
                            ReleasePair(pairB.p);
                            ReleasePair(pairA.p);
                            ReleasePair(last.p);
                            ReleasePair(first.p);
                            CRef_Destruct(&result);
                            return pret;
                        }
                        ReleasePair(pairB.p);
                        ReleasePair(pairA.p);
                    }
                }
            }
        }
        if (first.p != 0)
            bevy_splice_value_list_ref(&result, first.p);
        ReleasePair(last.p);
        ReleasePair(first.p);
    }
    CRef_CopyConstruct(pret, &result);
    CRef_Destruct(&result);
    return pret;
}
