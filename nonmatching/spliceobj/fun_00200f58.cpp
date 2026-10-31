struct RefT { int tagk; int n; };
struct CPair { int cref; int pad4; RefT ref; CPair *next; };
struct SLOTHEAP;
struct HP { CPair *p; int pad[3]; };
struct EOPID { int otyp; int grf; int ibGet; char pad[0x24]; };
extern "C" {
CPair *PpairNew(void);
HP *PairHandle_Init(HP *, int);
void PairHandle_Assign(CPair **);
void CRef_Destruct(RefT *);
void SetTag__4CRef4TAGK(RefT *, int);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void *memset(void *, int, unsigned);
void RefGetPeopid(RefT *, void *, EOPID *);
void __as__4CRefRC4CRef(void *dst, void *src);
void CRef_ConstructPair(RefT *, CPair *);
extern SLOTHEAP B_004520A8;
}
struct LOC { EOPID eopid; HP head; HP handle; RefT element; };
extern "C" RefT *func_00200F58(RefT *pret, int count, int otyp, void *pbasic)
{
    EOPID eopid;
    HP head;
    if (count == 0) {
        SetTag__4CRef4TAGK(pret, 0);
        return pret;
    }
    HP *tail;
    head.p = 0;
    memset(&eopid, 0, 0x28);
    PairHandle_Assign(&head.p);
    eopid.grf = 2;
    eopid.otyp = otyp;
    int index;
    for (index = 0, tail = &head; index < count; index++) {
        eopid.ibGet = index * 4;
        HP handle;
        RefT element;
        PairHandle_Init(&handle, count);
        RefT *dst = &handle.p->ref;
        RefGetPeopid(&element, pbasic, &eopid);
        __as__4CRefRC4CRef(dst, &element);
        CRef_Destruct(&element);
        PairHandle_Assign(&tail->p);
        CPair *held = handle.p;
        tail = (HP *)&held->next;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode(held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
    }
    CRef_ConstructPair(pret, head.p);
    CPair *held = head.p;
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
