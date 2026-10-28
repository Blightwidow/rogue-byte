#include "sly2.h"
struct Frame;
struct Pair { int cref; int pad4; char ref[8]; Pair *next; };
struct HP { Pair *p; int pad[3]; };
extern "C" {
Pair *PpairNew(void);
HP *PairHandle_Init(HP *h, Pair *p);
void CRef_RefClone(void *out, void *src, Frame *frame, unsigned long arg);
void __as__4CRefRC4CRef(void *dst, void *src);
void CRef_Destruct(void *r);
void PairHandle_Assign(void *h, Pair *p);
void CPairPtr_Destructor(void *h, int f);
void UnlinkPairNode(Pair *p);
void FreeSlotheapPv(void *heap, void *p);
extern char B_004520A8[];
HP *func_00128CB8(HP *result, Pair *src, Frame *frame, unsigned long arg);
}
extern "C" HP *PpairClone(HP *result, Pair *src, Frame *frame, unsigned long arg)
{
    HP h;
    PairHandle_Init(&h, PpairNew());
    {
        char refClone[16];
        char *dst = h.p->ref;
        CRef_RefClone(refClone, src->ref, frame, arg);
        __as__4CRefRC4CRef(dst, refClone);
        CRef_Destruct(refClone);
    }
    if (src->next) {
        HP next;
        Pair *cur = h.p;
        func_00128CB8(&next, src->next, frame, arg);
        PairHandle_Assign(&cur->next, next.p);
        Pair *t = next.p;
        if (t && --t->cref == 0) {
            CPairPtr_Destructor(&t->next, 2);
            CRef_Destruct(t->ref);
            UnlinkPairNode(t);
            FreeSlotheapPv(B_004520A8, t);
        }
    }
    PairHandle_Init(result, h.p);
    Pair *t = h.p;
    if (t && --t->cref == 0) {
        CPairPtr_Destructor(&t->next, 2);
        CRef_Destruct(t->ref);
        UnlinkPairNode(t);
        FreeSlotheapPv(B_004520A8, t);
    }
    return result;
}
