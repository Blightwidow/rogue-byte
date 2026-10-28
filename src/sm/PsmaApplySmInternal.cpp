struct SM;
struct BASIC {
    char pad0[0xC];
    virtual void v0(); virtual void v1(); virtual void v2();
};
struct SM : BASIC { int fld; };
struct VT { char pad[8]; short d8; short i8; void (*f8)(char *); short d10; short i10; void (*f10)(char *); short d18; short i18; void (*f18)(char *, int, int, int, int, int); };
struct SMA { char pad[0xC]; VT *vt; };
struct SMAHEAP { int dl[3]; int heap; };
struct Hold {
    SM *p;
    Hold(SM *s) { p = s; s->v0(); }
    ~Hold() { p->v1(); }
};
extern "C" {
extern SMAHEAP B_003E126C;
extern VT D_002D9768;
void *PvAllocSlotheapImpl(void *);
void *memset(void *, int, unsigned);
void AppendDlEntry(void *, void *);
void CFramePtr_Assign(void *, void *);
int FSmaRetracted(void *);
int IsmsFindSmRequired__FP2SM3OID(SM *, int);
void NotifySmaSpliceOnEnterState(void *, int, int);
void ChooseSmaTransition(void *, int);
}

void PsmaApplySmInternal(SM *psm, int paloRoot, int oidInitial, int grfapl, unsigned mask, void **ppsma)
{
    char *psma = (char *)PvAllocSlotheapImpl(&B_003E126C.heap);
    *ppsma = psma;
    memset(psma, 0, 0x50);
    *(int *)(psma + 0x28) = paloRoot;
    *(int *)(psma + 0x2C) = grfapl;
    *(unsigned *)(psma + 0x48) = mask;
    *(int *)(psma + 0x0) = 0;
    *(int *)(psma + 0x4) = 0;
    *(SM **)(psma + 0x24) = psm;
    *(int *)(psma + 0x38) = -1;
    ((SMA *)psma)->vt = &D_002D9768;
    *(float *)(psma + 0x44) = 1.0f;
    AppendDlEntry(&B_003E126C, psma);
    AppendDlEntry((char *)psm + 0x68, psma);
    SMA *sma = (SMA *)psma;
    sma->vt->f8(psma + sma->vt->d8);
    Hold hold(psm);
    CFramePtr_Assign(psma, *(void **)psm);
    sma->vt->f18(psma + sma->vt->d18, 2, 0, 0, 0, 0);
    if (FSmaRetracted(psma) != 0)
        return;
    if (oidInitial != -1) {
        int isms = IsmsFindSmRequired__FP2SM3OID(psm, oidInitial);
        *(int *)(psma + 0x34) = isms;
        *(int *)(psma + 0x3C) = isms;
        NotifySmaSpliceOnEnterState(psma, -1, isms);
    }
    ChooseSmaTransition(psma, 0);
}
