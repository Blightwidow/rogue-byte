struct ALLOCREQ { int cb; int cbAlign; };
struct JSG { char pad0[0x50]; int cjsge; int ajsge; int cjsgeMax; char pad1[0x20]; int fPendingCut; };
extern "C" {
int CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
void AddJsgContext(JSG *, int);
void LoadLoFromBrx(JSG *, void *);
}

void CSeq_LoadFromBrx(JSG *pjsg, void *pbis)
{
    char frame[16];
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    preq->cb = 0xA000;
    preq->cbAlign = 0x10;
    pjsg->ajsge = (int)PvAllocStackImpl__Fi(preq);
    AddJsgContext(pjsg, -1);
    pjsg->fPendingCut = 1;
    LoadLoFromBrx(pjsg, pbis);

    void *ajsgeStack = (void *)pjsg->ajsge;
    int capacity = pjsg->cjsgeMax;
    if (pjsg->cjsge >= capacity)
        capacity = pjsg->cjsge;
    pjsg->cjsgeMax = capacity + 1;
    preq->cb = (capacity + 1) * 0x50;
    preq->cbAlign = 0x10;
    void *heap = PvAllocSwImpl__Fi(preq);
    pjsg->ajsge = (int)heap;
    CopyAb__FPvT0Ui(heap, ajsgeStack, pjsg->cjsge * 0x50);
    CStackFrame_Destructor(frame, 2);
}
