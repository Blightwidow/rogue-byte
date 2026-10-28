#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CRefF { int tagk; float g; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; };
struct SLOTHEAP;
struct CFrame;
struct SWW;
struct TIMEDCALL { float tFire; void *powner; CPair *ppair; int idCall; };
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(CPair **, CPair *);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
void CRef_SetProc(CRef *, void *);
void CRef_SetS32(CRef *, int);
void CRef_RefCoerceF32(CRefF *, CRef *);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
TIMEDCALL *AddSwTimedCall(SWW *, void *, CPair *, float);
extern SLOTHEAP B_004520A8;
extern SWW B_003DD490;
extern float g_2dded0;
}
struct Locals {
    CRef refId; int padA[2];
    PairHandle handle; int padB[3];
    CRefF refDt; int padC[2];
    CRef *pref; int padD[3];
};
extern "C" CRef *RefOpScheduleCallback(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    Locals l;
    l.refId.n = -1;
    l.pref = pref;
    l.refId.tagk = 0x15;
    void *pproc = (void *)aref[1].n;
    CPair *pairNew = PpairNew();
    PairHandle_Init(&l.handle, pairNew);
    bevy_splice_value_list_ref(&l.handle.p->ref, PpairNew());
    CPair *form = (CPair *)l.handle.p->ref.n;
    CRef_SetProc(&form->ref, pproc);
    if (carg > 2) {
        CPair *tail = form;
        for (CPair *arg = (CPair *)aref[2].n; arg != 0; arg = arg->next) {
            CPair *tmp = PpairNew();
            PairHandle_Assign(&tail->next, tmp);
            tail = tail->next;
            CRef *prefTail = &tail->ref;
            bevy_splice_value_list_ref(prefTail, PpairNew());
            CPair *quote = (CPair *)prefTail->n;
            CRef *prefQuote = &quote->ref;
            CRef_Destruct(prefQuote);
            SetTag__4CRef4TAGK(prefQuote, 0x12);
            tmp = PpairNew();
            PairHandle_Assign(&quote->next, tmp);
            quote->next->ref = arg->ref;
        }
    }
    float tNow = g_2dded0;
    SWW *psw = &B_003DD490;
    CRef_RefCoerceF32(&l.refDt, aref);
    TIMEDCALL *pcall = AddSwTimedCall(psw, 0, l.handle.p, tNow + l.refDt.g);
    CRef_Destruct((CRef *)&l.refDt);
    CRef_SetS32(&l.refId, pcall->idCall);
    CRef_CopyConstruct(l.pref, &l.refId);
    CPair *held = l.handle.p;
    if (held) {
        if (--held->cref == 0) {
            CPairPtr_Destructor(&held->next, 2);
            CRef_Destruct(&held->ref);
            UnlinkPairNode(held);
            FreeSlotheapPv(&B_004520A8, held);
        }
    }
    CRef_Destruct(&l.refId);
    return l.pref;
}
