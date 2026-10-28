struct DL { void *pfirst; void *plast; int ibDle; };
struct JSG;
struct JVT { char pad[0x18]; short delta; short index; void (*fn)(char *, int, int, int, int, int); };
struct JSG {
    char pad0[0xC];
    JVT *vt;
    char pad1[0x40 - 0x10];
    unsigned grf;
    char pad2[0x54 - 0x44];
    int ajsge;
    char pad3[0x5C - 0x58];
    DL dlSeqnode;
    char pad4[0x6C - 0x68];
    int psoSubject;
    float tRun;
    int fRunning;
    int fLatched;
    int fPendingCut;
};
extern "C" {
void AddSeqRecordEndThread(JSG *);
void *PseqnodeNew(JSG *, int, int);
void RunSeqnode(void *);
int FIsDlEmpty__FP2DL(DL *);
void StopJsg(JSG *);
void func_001A6CA8(JSG *, int);
}

void StartJsg(JSG *pjsg, int psoSubject)
{
    if (pjsg->fRunning != 0)
        return;
    pjsg->psoSubject = psoSubject;
    pjsg->fRunning = 1;
    pjsg->fLatched = 0;
    pjsg->vt->fn((char *)pjsg + pjsg->vt->delta, 5, 0, 0, 0, 0);
    if (pjsg->fRunning == 0)
        return;
    if (pjsg->fPendingCut != 0) {
        AddSeqRecordEndThread(pjsg);
        pjsg->fPendingCut = 0;
    }
    RunSeqnode(PseqnodeNew(pjsg, pjsg->ajsge, 0));
    if (pjsg->fRunning == 0)
        return;
    if (FIsDlEmpty__FP2DL(&pjsg->dlSeqnode) != 0) {
        StopJsg(pjsg);
        return;
    }
    unsigned grf = pjsg->grf;
    if (((grf ^ 1) & 1) != 0)
        grf = *(unsigned *)grf;
    if ((grf & 2) == 0) {
        func_001A6CA8(pjsg, 1);
        unsigned grf2 = pjsg->grf;
        if (((grf2 ^ 1) & 1) != 0)
            *(unsigned *)grf2 |= 2;
        else
            pjsg->grf = grf2 | 2;
        pjsg->fLatched = 1;
    }
}
