#include "sly2.h"
struct Frame;
struct Pair;
struct CRef { int tagk; Pair *pv; CRef &operator=(const CRef &); };
struct Pair { int cref; int pad4; CRef ref; Pair *next; };
struct HP { Pair *p; int pad[3]; };
struct ArgBlock { CRef first; int hasExtra; Pair *head; };
struct SLOTHEAP;
extern "C" {
Pair *PpairNew(void);
HP *PairHandle_Init(HP *h, Pair *p);
void PairHandle_Assign(void *h, Pair *p);
void CRef_Destruct(void *r);
void CRef_CopyConstruct(void *, void *);
void CRef_ConstructPair(void *, Pair *);
void *bevy_splice_value_list_ref(void *, Pair *);
void RefEval(void *, Pair *, Frame *);
void CPairPtr_Destructor(void *h, int f);
void UnlinkPairNode(Pair *p);
void FreeSlotheapPv(void *heap, void *p);
extern char B_004520A8[];
HP *func_00121578(HP *, CRef **, CRef **);
}
struct RN { Pair *next; };
extern "C" CRef *RefOpMap(CRef *pref, int unused, ArgBlock *aref, Frame *frame)
{
    if (aref->hasExtra == 0) {
        CRef_CopyConstruct(pref, &aref->hasExtra);
        return pref;
    }
    struct L { HP holder; HP call; HP value; CRef temp; int p8, pc; CRef *callee; CRef *arg; } l;
    Pair *tail;
#define holder l.holder
#define call l.call
#define value l.value
#define temp l.temp
#define callee l.callee
#define arg l.arg
    PairHandle_Init(&holder, PpairNew());
    func_00121578(&call, &callee, &arg);
    *callee = aref->first;
    for (Pair *element = aref->head; element != 0; element = element->next) {
        *arg = element->ref;
        PairHandle_Init(&value, PpairNew());
        CRef *pvalueRef = &value.p->ref;
        RefEval(&temp, call.p, frame);
        *pvalueRef = temp;
        CRef_Destruct(&temp);
        if (holder.p->ref.tagk != 0x1F)
            bevy_splice_value_list_ref(&holder.p->ref, value.p);
        else
            PairHandle_Assign(&tail->next, value.p);
        Pair *t = value.p;
        tail = t;
        if (t && --t->cref == 0) {
            CPairPtr_Destructor(&t->next, 2);
            CRef_Destruct(&t->ref);
            UnlinkPairNode(t);
            FreeSlotheapPv(B_004520A8, t);
        }
    }
    CRef_ConstructPair(pref, holder.p->ref.pv);
    Pair *t = call.p;
    if (t && --t->cref == 0) {
        CPairPtr_Destructor(&t->next, 2);
        CRef_Destruct(&t->ref);
        UnlinkPairNode(t);
        FreeSlotheapPv(B_004520A8, t);
    }
    t = holder.p;
    if (t && --t->cref == 0) {
        CPairPtr_Destructor(&t->next, 2);
        CRef_Destruct(&t->ref);
        UnlinkPairNode(t);
        FreeSlotheapPv(B_004520A8, t);
    }
    return pref;
}
