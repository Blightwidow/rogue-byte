#include "dl.h"
struct JSG { char pad0[0x40]; unsigned grf; char pad1[0x18]; DL dlSeqnode; char pad2[8]; float tRun; int fRunning; };
extern "C" {
void UpdateLo(JSG *);
void RunSeqnode(void *);
int FIsDlEmpty__FP2DL(DL *);
void StopJsg(JSG *);
}
extern float g_2ddf10;
extern float g_2dded4;

// Retail computes &pjsg->dlSeqnode once in $v0 for the iterator stores (ppv at 4, pdl at 0, both kept) and copies it
// to $s1 for FIsDlEmpty after the loop: the address is written out at both uses and CSE joins them. A named local for
// the list let the ppv = list store die and changed the setup order (score 14). The tRun update is one whole-expression
// ternary because retail reloads tRun in each branch.
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
    PushDli(&dli, &pjsg->dlSeqnode);
    for (char *pseqnode = (char *)PvStep(&dli); pseqnode != 0; pseqnode = (char *)PvStep(&dli))
        RunSeqnode(pseqnode);
    if (FIsDlEmpty__FP2DL(&pjsg->dlSeqnode) != 0)
        StopJsg(pjsg);
    PopDli(&dli);
}
