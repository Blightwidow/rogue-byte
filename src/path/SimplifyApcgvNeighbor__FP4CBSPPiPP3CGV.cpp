#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct ALLOCREQ { int cb; int cbAlign; };
struct CBSP;
struct CGV { QW pos; };
extern "C" {
int CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
int FClipEdgeToCg(CBSP *, QW, QW, int);
}
void SimplifyApcgvNeighbor(CBSP *pbsp, int *pcpcgv, CGV **apcgv);

void SimplifyApcgvNeighbor(CBSP *pbsp, int *pcpcgv, CGV **apcgv)
{
    char frame[16];
    CStackFrame_Construct(frame);
    int cpcgv = *pcpcgv;
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    preq->cb = cpcgv * 4;
    preq->cbAlign = 0x10;
    CGV **kept = (CGV **)PvAllocStackImpl__Fi(preq);
    kept[0] = apcgv[0];
    int ckept = 1;
    CGV **last = apcgv;
    CGV **cur = apcgv + 1;
    CGV **next = apcgv + 2;
    CGV **end = apcgv + cpcgv;
    while (next < end) {
        if (FClipEdgeToCg(pbsp, (*last)->pos, (*next)->pos, 0)) {
            kept[ckept] = *cur;
            ckept++;
            last = cur;
            cur = next;
            next++;
        } else {
            cur = next;
            next++;
        }
    }
    kept[ckept] = apcgv[cpcgv - 1];
    ckept++;
    if (ckept < cpcgv) {
        if (ckept > 2) SimplifyApcgvNeighbor(pbsp, &ckept, kept);
    }
    CopyAb__FPvT0Ui(apcgv, kept, ckept * 4);
    *pcpcgv = ckept;
    CStackFrame_Destructor(frame, 2);
}
