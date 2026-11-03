typedef int QW __attribute__((mode(TI)));
struct CRef {
    int tagk; union { int n; QW *pv; };
    CRef() { tagk = -1; }
    CRef(const CRef &) asm("CRef_CopyConstruct");
    inline ~CRef();
    CRef &operator=(const CRef &);
};
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle;
struct SLOTHEAP;
struct CLIP { QW pos; QW normal; QW rest[4]; };
struct ELEM { char pad0[0x10]; long flags; char pad18[0xB0 - 0x18]; };
struct OBJ { char pad0[0xE0]; int count; ELEM *elems; };
struct CNode { int pad0; int pad4; CRef ref; CNode *next; };
struct CRefList { int tagk; CNode *pnode; CRef start; CRef end; };
extern "C" {
CPair *PpairNew(void);
void PairHandle_Assign(CPair **, CPair *);
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void CRef_SetBasic(CRef *, void *);
void CRef_SetVectorPtr(CRef *, QW *);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
int ClsgClipEdgeToObject(ELEM *, QW, QW, int, CLIP *);
extern SLOTHEAP B_004520A8;
}
CRef::~CRef() { CRef_Destruct(this); }
static inline void ReleasePair_1249A8(CPair *held)
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
struct PairHandle {
    CPair *p;
    int pad[3];
    PairHandle(CPair *) asm("PairHandle_Init");
    ~PairHandle() { ReleasePair_1249A8(p); }
};
extern "C" CRef RefOpHitTestObjectsImpl(int op, int unused, CRefList *aref)
{
    CRef result;
    if (aref->tagk == 0) {
        result = *(CRef *)aref;
    } else {
        PairHandle first(0);
        PairHandle last(0);
        CLIP clip;
        for (CNode *node = aref->pnode; node != 0; node = node->next) {
            CRef *pend = &aref->end;
            OBJ *pobj = (OBJ *)node->ref.n;
            if (pobj != 0) {
                for (int index = 0; index < pobj->count; index++) {
                    ELEM *pelem = &pobj->elems[index];
                    CRef *pstart = &aref->start;
                    if (!(pelem->flags & (0x8000L << 35)) &&
                        ClsgClipEdgeToObject(pelem, *pstart->pv, *pend->pv, 1, &clip) > 0) {
                        CPair *pnewA = PpairNew();
                        PairHandle pairA(pnewA);
                        CPair *pnewB = PpairNew();
                        PairHandle pairB(pnewB);
                        CRef_SetBasic(&pairA.p->ref, pobj);
                        PairHandle_Assign(&pairA.p->next, pairB.p);
                        if (op == 0x7B) {
                            CPair *pnewC = PpairNew();
                        PairHandle pairC(pnewC);
                            CPair *pnewD = PpairNew();
                        PairHandle pairD(pnewD);
                            CRef_SetVectorPtr(&pairB.p->ref, &clip.pos);
                            PairHandle_Assign(&pairB.p->next, pairC.p);
                            CRef_SetVectorPtr(&pairC.p->ref, &clip.normal);
                            bevy_splice_value_list_ref(&pairD.p->ref, pairA.p);
                            if (first.p != 0)
                                PairHandle_Assign(&last.p->next, pairD.p);
                            else
                                PairHandle_Assign(&first.p, pairD.p);
                            PairHandle_Assign(&last.p, pairD.p);
                        } else {
                            CRef_SetVectorPtr(&pairB.p->ref, &clip.normal);
                            bevy_splice_value_list_ref(&result, pairA.p);
                            return result;
                        }
                    }
                }
            }
        }
        if (first.p != 0)
            bevy_splice_value_list_ref(&result, first.p);
        else
            result.tagk = 0;
    }
    return result;
}
