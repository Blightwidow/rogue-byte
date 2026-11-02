#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct AC { void *vtable; };
struct CHN { unsigned grf; AC *pac; };
struct ASEG { char pad[0x5C]; int cchn; CHN *achn; };
struct XF { MATRIX4 matLocal; char pad[0x94 - 0x40]; int dof; char pad2[0xA0 - 0x98]; XF *pxfParent; };
struct VTSLOT { char pad[0x18]; short delta; short index; void (*fn)(void *, float, float, QW *, QW *); };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void BindAsegChn(ASEG *, void *, CHN *, void *, void *);
MATRIX4 BuildXfLocalMatrix(XF *, QW);
MATRIX4 BuildXfAngularRateMatrix(XF *, MATRIX4 *, QW, QW);
MATRIX4 BuildXfLinearRateMatrix(XF *, QW);
}
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);

static inline void AddMatrix(MATRIX4 &sum, const MATRIX4 &first, const MATRIX4 &second)
{
    QW *psum = (QW *)&sum;
    const QW *pfirst = (const QW *)&first;
    const QW *psecond = (const QW *)&second;
    for (int irow = 0; irow < 4; irow++, psum++, pfirst++, psecond++) {
        asm("lqc2 vf1, %0" : : "m" (*pfirst));
        asm("lqc2 vf2, %0" : : "m" (*psecond));
        asm("vadd.xyzw vf1, vf1, vf2");
        asm("sqc2 vf1, %0" : "=m" (*psum));
    }
}

extern "C" void PredictAsegEffect(ASEG *paseg, void *paloRoot, float t, float svt, XF *pxfLeaf, XF *pxfBasis, MATRIX4 *pmat, MATRIX4 *pmatRate)
{
    MATRIX4 matLocal;
    MATRIX4 matLocalRate;
    MATRIX4 matAccum;
    MATRIX4 matAccumRate;
    char frame[0x10];
    QW avec[2];
    XF **apxfChn;
    CStackFrame_Construct(frame);
    memset(&matAccumRate, 0, sizeof(matAccumRate));
    memset(&matAccum, 0, sizeof(matAccum));
    ((float *)&matAccum)[0] = ((float *)&matAccum)[5] = ((float *)&matAccum)[10] = ((float *)&matAccum)[15] = 1.0f;
    {
        int align = 0x10;
        ALLOCREQ allocreq;
        ALLOCREQ *preq = &allocreq;
        allocreq.cb = paseg->cchn * 4;
        preq->cbAlign = align;
        apxfChn = (XF **)PvAllocStackImpl__Fi(preq);
    }
    for (int ichn = 0; ichn < paseg->cchn; ichn++) {
        CHN *pchn = &paseg->achn[ichn];
        if ((pchn->grf & 0x40000000) == 0) {
            int paloIgnored;
            BindAsegChn(paseg, paloRoot, pchn, &paloIgnored, &apxfChn[ichn]);
        } else {
            apxfChn[ichn] = 0;
        }
    }
    for (XF *pxf = pxfLeaf; pxf != pxfBasis; pxf = pxf->pxfParent) {
        for (int ichn = 0; ichn < paseg->cchn; ichn++) {
            CHN *pchn = &paseg->achn[ichn];
            if (apxfChn[ichn] == pxf && (pchn->grf & 0x80000000) == 0) {
                AC *pac = pchn->pac;
                VTSLOT *vt = (VTSLOT *)pac->vtable;
                vt->fn((char *)pac + vt->delta, t, svt, &avec[0], &avec[1]);
                matLocal = BuildXfLocalMatrix(pxf, avec[0]);
                if (pxf->dof < 8) {
                    if (pxf->dof > 5)
                        matLocalRate = BuildXfAngularRateMatrix(pxf, &matLocal, avec[0], avec[1]);
                    else
                        matLocalRate = BuildXfLinearRateMatrix(pxf, avec[1]);
                } else {
                    matLocalRate = BuildXfLinearRateMatrix(pxf, avec[1]);
                }
                goto accumulate;
            }
        }
        matLocal = pxf->matLocal;
        memset(&matLocalRate, 0, sizeof(matLocalRate));
    accumulate:
        MATRIX4 sum;
        AddMatrix(sum, matLocal * matAccumRate, matLocalRate * matAccum);
        matAccumRate = sum;
        matAccum = matLocal * matAccum;
    }
    if (pmat != 0)
        *pmat = matAccum;
    if (pmatRate != 0)
        *pmatRate = matAccumRate;
    CStackFrame_Destructor(frame, 2);
}
