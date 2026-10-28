#include "sly2.h"
struct END { int oid; int kind; char pad0[8]; QW pos; char pad1[0x80]; };
struct BEAM { END aend[2]; };
struct LASER { char pad[0x60]; void *pxfRoot; };
extern "C" void GetPathPosFromS(void *, float, QW *, void *);
extern "C" QW ConvertXfPos(void *, void *, QW);

void GetLaserBeamPoints(LASER *plaser, BEAM *pbeam, QW *apos, float *psLength)
{
    for (unsigned iend = 0; iend < 2; iend++) {
        END *pend = &pbeam->aend[iend];
        switch (pend->kind) {
        case 0:
            apos[iend] = ConvertXfPos(plaser->pxfRoot, 0, pend->pos);
            break;
        case 1:
            {
                float along = *(float *)((char *)pend + 0x14);
                void *pcrv = *(void **)((char *)pend + 0x10);
                GetPathPosFromS(pcrv, along, &apos[iend], 0);
            }
            break;
        }
    }
    if (psLength != 0) {
        int length;
        asm("lqc2 vf1, %0" : : "m" (apos[1]));
        asm("lqc2 vf2, %0" : : "m" (apos[0]));
        asm("vsub.xyzw vf2, vf2, vf1\n\tvmul.xyz vf2, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q");
        asm("qmfc2.ni %0, vf2" : "=r" (length));
        *(int *)psLength = length;
    }
}
