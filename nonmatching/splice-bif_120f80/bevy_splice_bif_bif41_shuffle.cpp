struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; int pad[3]; };
struct SLOTHEAP;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(CPair **, CPair *);
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_ConstructPair(CRef *, CPair *);
int NRandInRange(int, int);
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
extern "C" CRef *bevy_splice_bif_bif41_shuffle(CRef *pret, int carg, CRef *aref)
{
    CRef *items[0x80];
    PairHandle head;
    PairHandle second;
    CRef refTag;
    if (aref->tagk == 0 || aref->tagk != 0x1F) {
        SetTag__4CRef4TAGK(pret, 0);
        return pret;
    }
    int count = 0;
    int zeroIndex = -1;
    for (CPair *node = (CPair *)aref->n; node != 0; node = node->next) {
        if (node->ref.tagk == 0)
            zeroIndex = count;
        else
            items[count++] = &node->ref;
    }
    int fshuffle = 0;
    if (count >= 2)
        fshuffle = zeroIndex < 1;
    if (fshuffle) {
        CRef *first = items[0];
        for (int round = 0; round < count; round++) {
            int pick = NRandInRange(0, count - 1);
            CRef *held = items[pick];
            items[pick] = items[round];
            items[round] = held;
        }
        zeroIndex = count;
        if (items[0] == first) {
            items[0] = items[count - 1];
            items[count - 1] = first;
        }
    }
    head.p = 0;
    CPair **pslot = &head.p;
    CPair *target = 0;
    for (int index = 0; index < count; index++) {
        PairHandle_Assign(pslot, PpairNew());
        CPair *node = *pslot;
        pslot = &node->next;
        node->ref = *items[index];
        if (index == zeroIndex - 1)
            target = node;
    }
    if (target != 0 && target != head.p) {
        if (!fshuffle) {
            PairHandle_Init(&second, head.p);
            PairHandle_Assign(&head.p, head.p->next);
            PairHandle_Assign(&second.p->next, target->next);
            PairHandle_Assign(&target->next, second.p);
            ReleasePair(second.p);
        }
        if (head.p != target) {
            PairHandle_Init(&second, PpairNew());
            SetTag__4CRef4TAGK(&refTag, 0);
            second.p->ref = refTag;
            CRef_Destruct(&refTag);
            PairHandle_Assign(&second.p->next, target->next);
            PairHandle_Assign(&target->next, second.p);
            ReleasePair(second.p);
        }
    }
    CRef_ConstructPair(pret, head.p);
    ReleasePair(head.p);
    return pret;
}
