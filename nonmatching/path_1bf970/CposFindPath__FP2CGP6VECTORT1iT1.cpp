#include "sly2.h"
struct REQ { int size; int align; };
struct CGV;
struct CGVL { CGV *pcgv; float g; };
struct CGV { QW pos; int ccgvl; CGVL *acgvl; int pad[2]; };
struct CGT { CGV *apcgv[3]; };
struct CG { char pad[0x14]; void *pbsp; };
extern float D_002C0C04;
extern VECTOR g_2a2da0;
extern "C" CGT *PcgtPointInCgSafe(CG *, void *, QW, int);
extern "C" QW PosClosestOnCgt(CGT *, QW);
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackImpl__Fi(REQ *);
int FindPathAStar(CG *, CGV *, CGV *, int, int *, CGV **);
struct CBSP;
void SimplifyApcgvNeighbor(CBSP *, int *, CGV **);

/* Planar (xy) distance between two points, VU0. */
static inline float GDistXy(QW *pposA, QW *pposB)
{
    float g;
    asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf2, vf1\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\t"
        "vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
        : "=r" (g) : "m" (*pposA), "m" (*pposB));
    return g;
}

/* pos + vec * g, VU0 (vadda/vmaddx). */
static inline QW PosAddScaled(QW *ppos, VECTOR *pvec, float g, QW *ptmp)
{
    QW pos;
    asm("lqc2 vf2, %2\n\tqmtc2.ni %3, vf3\n\tsqc2 vf3, %1\n\tlqc2 vf1, %4\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf1, vf3x\n\tqmfc2.ni %0, vf2"
        : "=r" (pos), "=m" (*ptmp) : "m" (*ppos), "r" (g), "m" (*pvec));
    return pos;
}

extern "C" int CposFindPath__FP2CGP6VECTORT1iT1(CG *pcg, QW pos0, QW pos1, int cposMax, QW *apos)
{
    char frame[0x10];
    REQ req;
    CGV cgvStart;
    CGV cgvEnd;
    int ccgv;
    QW *pposOut;
    int cpos;
    CGT *pcgt0 = PcgtPointInCgSafe(pcg, pcg->pbsp, pos0, 1);
    if (!pcgt0)
        return 0;
    QW posStart = PosClosestOnCgt(pcgt0, pos0);
    CGT *pcgt1 = PcgtPointInCgSafe(pcg, pcg->pbsp, pos1, 1);
    if (!pcgt1)
        return 0;
    QW posEnd = PosClosestOnCgt(pcgt1, pos1);
    if (pcgt0 == pcgt1) {
        apos[0] = pos0;
        pposOut = &apos[1];
        apos[1] = posStart;
        cpos = 3;
        apos[2] = posEnd;
    } else {
        CStackFrame_Construct(frame);
        pposOut = &apos[1];
        REQ *preq = &req;
        req.size = 0x200;
        preq->align = 0x10;
        CGV **apcgv = (CGV **)PvAllocStackImpl__Fi(preq);
        req.size = 0x18;
        cgvStart.ccgvl = 3;
        cgvStart.pos = posStart;
        preq->align = 0x10;
        cgvStart.acgvl = (CGVL *)PvAllocStackImpl__Fi(preq);
        int i;
        for (i = 0; i < 3; i++) {
            CGV *pcgv = pcgt0->apcgv[i];
            cgvStart.acgvl[i].pcgv = pcgv;
            cgvStart.acgvl[i].g = GDistXy(&cgvStart.pos, &pcgv->pos);
        }
        cgvEnd.pos = posEnd;
        cgvEnd.ccgvl = 0;
        cgvEnd.acgvl = 0;
        for (i = 0; i < 3; i++) {
            CGV *pcgv = pcgt1->apcgv[i];
            CGVL *pcgvl = &pcgv->acgvl[pcgv->ccgvl++];
            pcgvl->pcgv = &cgvEnd;
            pcgvl->g = GDistXy(&pcgv->pos, &cgvEnd.pos);
        }
        FindPathAStar(pcg, &cgvStart, &cgvEnd, 0x80, &ccgv, apcgv);
        if (ccgv >= 3)
            SimplifyApcgvNeighbor((CBSP *)pcg, &ccgv, apcgv);
        cpos = cposMax < ccgv ? cposMax : ccgv;
        for (i = 0; i < cpos; i++)
            apos[i] = apcgv[i]->pos;
        for (i = 0; i < 3; i++)
            pcgt1->apcgv[i]->ccgvl--;
        CStackFrame_Destructor(frame, 2);
    }
    {
        QW *pposEnd = &apos[cpos];
        QW *ppos;
        QW *pposPrev = apos;
        for (ppos = pposOut; ppos < pposEnd; ppos++) {
            if (D_002C0C04 < GDistXy(ppos, pposPrev)) {
                *pposOut = *ppos;
                pposPrev = pposOut;
                pposOut++;
            }
        }
    }
    cpos = pposOut - apos;
    if (cpos == 1) {
        apos[1] = apos[0];
        cpos = 2;
        apos[0] = PosAddScaled(&apos[0], &g_2a2da0, D_002C0C04, (QW *)&req);
    }
    return cpos;
}
