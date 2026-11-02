struct CRef;
struct CFrame;
struct SWW;
struct SLOTHEAP;
struct CPair;
extern "C" {
void CRef_CopyConstruct(CRef *, const CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk;
    union {
        int n;
        float g;
    };
    CRef(int tag, int value) { n = value; tagk = tag; }
    CRef() {}
    CRef(const CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
    CRef &operator=(const CRef &);
};
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct TIMEDCALL { float tFire; void *powner; CPair *ppair; int idCall; };
struct PairHandle;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(CPair **, CPair *);
CRef *bevy_splice_value_list_ref(CRef *, CPair *);
void CRef_SetProc(CRef *, void *);
void CRef_SetS32(CRef *, int);
CRef CRef_RefCoerceF32(CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
TIMEDCALL *AddSwTimedCall(SWW *, void *, CPair *, float);
extern SLOTHEAP B_004520A8;
extern SWW B_003DD490;
extern float g_2dded0;
}
struct PairHandle {
    CPair *p;
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
extern "C" CRef RefOpScheduleCallback(int carg, CRef *aref, CFrame *pframe)
{
    CRef refId;
    refId.n = -1;
    refId.tagk = 0x15;
    void *pproc = (void *)aref[1].n;
    PairHandle handle(PpairNew());
    bevy_splice_value_list_ref(&handle.p->ref, PpairNew());
    CPair *form = (CPair *)handle.p->ref.n;
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
    SWW *psw = &B_003DD490;
    float tNow = g_2dded0;
    TIMEDCALL *pcall = AddSwTimedCall(psw, 0, handle.p, tNow + CRef_RefCoerceF32(aref).g);
    CRef_SetS32(&refId, pcall->idCall);
    return refId;
}
