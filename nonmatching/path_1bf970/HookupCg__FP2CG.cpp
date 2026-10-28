#include "sly2.h"
struct CGV;
struct CGN { CGV *pcgv; int s; };
struct CGV { VECTOR pos; int cneighbor; CGN *aneighbor; char pad[8]; };
struct CG { int ccgv; CGV *acgv; };
void HookupCg(CG *pcg)
{
    for (int icgv = 0; icgv < pcg->ccgv; icgv++) {
        CGV *pcgv = &pcg->acgv[icgv];
        for (int ineighbor = 0; ineighbor < pcgv->cneighbor; ineighbor++) {
            CGN *pneighbor = &pcgv->aneighbor[ineighbor];
            int length;
            asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (length) : "m" (pcgv->pos), "m" (pneighbor->pcgv->pos));
            pneighbor->s = length;
        }
    }
}
