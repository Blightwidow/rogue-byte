struct DL { void *pfirst; void *plast; int ibDle; };
struct DLI { DL *pdl; char *ppv; int ibDle; DLI *pdliNext; };
struct JSG { char pad0[0x40]; unsigned grf; char pad1[0x18]; DL dlSeqnode; char pad2[8]; float tRun; int fRunning; };
extern "C" {
void UpdateLo(JSG *);
void RunSeqnode(void *);
int FIsDlEmpty__FP2DL(DL *);
void StopJsg(JSG *);
}
extern float g_2ddf10;
extern float g_2dded4;
extern DLI *g_2dd2fc;

void UpdateJsg(JSG *pjsg, float dt)
{
    UpdateLo(pjsg);
    if (pjsg->fRunning == 0)
        return;
    unsigned grf = pjsg->grf;
    if (((grf ^ 1) & 1) != 0)
        grf = *(unsigned *)grf;
    pjsg->tRun = ((grf & 0x100) != 0) ? pjsg->tRun + g_2ddf10 : pjsg->tRun + g_2dded4;

    DLI dli;
    DL *pdl = &pjsg->dlSeqnode;
    dli.ppv = (char *)pdl;
    dli.pdl = pdl;
    dli.ibDle = pdl->ibDle;
    dli.pdliNext = g_2dd2fc;
    g_2dd2fc = &dli;
    char *pseqnode = (char *)pdl->pfirst;
    dli.ppv = pseqnode + dli.ibDle;
    while (pseqnode != 0) {
        RunSeqnode(pseqnode);
        pseqnode = *(char **)dli.ppv;
        dli.ppv = pseqnode + dli.ibDle;
    }
    if (FIsDlEmpty__FP2DL(pdl) != 0)
        StopJsg(pjsg);
    g_2dd2fc = dli.pdliNext;
}
