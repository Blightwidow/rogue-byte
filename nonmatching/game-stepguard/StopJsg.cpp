struct DL { void *pfirst; void *plast; int ibDle; };
struct DLI { DL *pdl; char *ppv; int ibDle; DLI *pdliNext; };
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
extern DLI *g_2dd2fc;
inline void PushDli(DLI *it, DL *list)
{
    it->pdl = list;
    it->ppv = (char *)list;
    it->ibDle = list->ibDle;
    it->pdliNext = g_2dd2fc;
    g_2dd2fc = it;
}
inline char *PvFirst(DLI *it)
{
    char *item = (char *)it->pdl->pfirst;
    it->ppv = item + it->pdl->ibDle;
    return item;
}
inline char *PvStep(DLI *it)
{
    char *item = *(char **)it->ppv;
    it->ppv = item + it->ibDle;
    return item;
}
extern "C" {
void StopSeqnode(void *);
void func_001E0120(JSG *);
void func_001A6CA8(JSG *, int);
}

void StopJsg(JSG *pjsg)
{
    if (pjsg->fRunning == 0)
        return;
    pjsg->psoSubject = 0;
    pjsg->tRun = 0.0f;
    pjsg->fRunning = 0;
    DLI dli;
    PushDli(&dli, &pjsg->dlSeqnode);
    char *pseqnode = PvFirst(&dli);
    while (pseqnode != 0) {
        StopSeqnode(pseqnode);
        pseqnode = PvStep(&dli);
    }
    func_001E0120(pjsg);
    if (pjsg->fLatched != 0) {
        func_001A6CA8(pjsg, 2);
        unsigned grf = pjsg->grf;
        if (((grf ^ 1) & 1) != 0)
            *(int *)grf &= -3;
        else
            pjsg->grf = (int)grf & -3;
    }
    pjsg->vt->fn((char *)pjsg + pjsg->vt->delta, 6, 0, 0, 0, 0);
    g_2dd2fc = dli.pdliNext;
}
