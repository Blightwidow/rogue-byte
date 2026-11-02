#include "sly2.h"
struct REQ { int size; int align; };
struct PATHZONE { char pad[0x124]; int ipathzone; };
struct PZLINK { char pad[0x128]; PATHZONE *ppzDest; char pad2[4]; VECTOR posEnter; VECTOR posExit; };
struct NODE;
struct DLE { NODE *pnodeNext; NODE *pnodePrev; };
struct NODE { PATHZONE *ppz; PZLINK *ppzlink; NODE *pnodeParent; float g; float f; int state; DLE dle; };
struct DL { NODE *pnodeFirst; NODE *pnodeLast; int ibDle; int pad; };
struct PZLINKLIST { int cpzlink; int *aipzlink; };
struct LO;
struct PZSET { char pad[0x10]; int cpathzone; char pad2[8]; PZLINKLIST *apzll; int cpzlink; PZLINK **appzlink; };

extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackClearImpl__Fi(REQ *);
extern "C" void *PvAllocStackImpl__Fi(REQ *);
extern "C" QW PosLoWorld(LO *);
extern "C" PATHZONE *PpathzoneFindPos(QW, int);
void ClearDl(DL *);
void InitDl(DL *, int);
extern "C" void AppendDlEntry(DL *, NODE *);
extern "C" void RemoveDlEntry(DL *, NODE *);
extern "C" void InsertDlEntryBefore(DL *, NODE *, NODE *);
int FIsDlEmpty(DL *);
extern "C" int FPzlinkUsable(PZSET *, PZLINK *, LO *);
extern "C" int FPosInPathzone(PATHZONE *, QW, int);

/* Lengths |posCur - posEnter| and |posEnter - posExit| (VU0); leaves posExit in vf3 for GDistFromExit. */
static inline void GDistLink(VECTOR *pposCur, VECTOR *pposEnter, VECTOR *pposExit, float *pg1, float *pg2, int *pfence)
{
    float g1;
    float g2;
    int fence;
    asm("lqc2 vf1, %4\n\tlqc2 vf4, %3\n\tlqc2 vf3, %5\n\tvsub.xyzw vf2, vf4, vf1\n\tvsub.xyzw vf1, vf1, vf3\n\t"
        "vmul.xyz vf2, vf2, vf2\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z\n\t"
        "vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf5, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf5, vf1z\n\t"
        "vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\t"
        "qmfc2.ni %0, vf2\n\tqmfc2.ni %1, vf1"
        : "=r" (g1), "=r" (g2), "=r" (fence) : "m" (*pposCur), "m" (*pposEnter), "m" (*pposExit));
    *pg1 = g1;
    *pg2 = g2;
    *pfence = fence;
}

/* |posExit - posGoal| with posExit still in vf3 from GDistLink (the fence orders the two). */
static inline float GDistFromExit(VECTOR *pposGoal, int fence)
{
    float g;
    asm("lqc2 vf1, %1\n\tvsub.xyzw vf3, vf3, vf1\n\tvmul.xyz vf3, vf3, vf3\n\tvaddw.x vf1, vf0, vf0w\n\t"
        "vadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf1, vf3z\n\tvsqrt Q, vf3x\n\tvwaitq\n\tvaddq.x vf3, vf0, Q\n\tqmfc2.ni %0, vf3"
        : "=r" (g) : "m" (*pposGoal), "r" (fence));
    return g;
}

/* Distance between two points (VU0). */
static inline float GDist(VECTOR *pposA, VECTOR *pposB)
{
    float g;
    asm("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tvsub.xyzw vf1, vf2, vf3\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\t"
        "vadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
        : "=r" (g) : "m" (*pposA), "m" (*pposB));
    return g;
}

int CpzlinkFindPath(PZSET *ppzset, LO *plo, QW posGoalArg, int fExact, int cpzlinkMax, PZLINK **apzlink)
{
    char frame[0x10];
    DL dlOpen;
    DL dlClosed;
    VECTOR posStart;
    VECTOR posGoal;
    VECTOR posCur;
    NODE *pnode;
    int cpzlink;

    *(QW *)&posGoal = posGoalArg;
    CStackFrame_Construct(frame);
    NODE *anode;
    int *afUsable;
    {
        REQ req;
        REQ *preq = &req;
        int align = 0x10;
        req.size = ppzset->cpathzone * sizeof(NODE);
        preq->align = align;
        anode = (NODE *)PvAllocStackClearImpl__Fi(preq);
        req.size = ppzset->cpzlink * sizeof(int);
        preq->align = align;
        afUsable = (int *)PvAllocStackImpl__Fi(preq);
    }
    memset(afUsable, 0xFF, ppzset->cpzlink * sizeof(int));
    *(QW *)&posStart = PosLoWorld(plo);
    PATHZONE *ppzStart = PpathzoneFindPos(*(QW *)&posStart, 0);
    PATHZONE *ppzGoal = PpathzoneFindPos(*(QW *)&posGoal, 0);
    if (!ppzStart || !ppzGoal) {
        CStackFrame_Destructor(frame, 2);
        return 0;
    }
    ClearDl(&dlOpen);
    InitDl(&dlOpen, 0x18);
    ClearDl(&dlClosed);
    InitDl(&dlClosed, 0x18);
    pnode = &anode[ppzStart->ipathzone];
    pnode->ppz = ppzStart;
    pnode->f = GDist(&posStart, &posGoal);
    pnode->state = 2;
    AppendDlEntry(&dlOpen, pnode);
    while (!FIsDlEmpty(&dlOpen)) {
        pnode = dlOpen.pnodeFirst;
        if (fExact) {
            if (pnode->ppz == ppzGoal)
                break;
        } else if (FPosInPathzone(pnode->ppz, *(QW *)&posGoal, 1)) {
            break;
        }
        RemoveDlEntry(&dlOpen, pnode);
        pnode->state = 1;
        AppendDlEntry(&dlClosed, pnode);
        if (pnode->ppzlink)
            posCur = pnode->ppzlink->posExit;
        else
            posCur = posStart;
        PZLINKLIST *ppzll = &ppzset->apzll[pnode->ppz->ipathzone];
        for (int i = 0; i < ppzll->cpzlink; i++) {
            int ipzlink = ppzll->aipzlink[i];
            int *pfUsable = &afUsable[ipzlink];
            PZLINK *ppzlink = ppzset->appzlink[ipzlink];
            if (*pfUsable == -1)
                *pfUsable = FPzlinkUsable(ppzset, ppzlink, plo);
            if (!*pfUsable)
                continue;
            float g1;
            float g2;
            int fence;
            GDistLink(&posCur, &ppzlink->posEnter, &ppzlink->posExit, &g1, &g2, &fence);
            PATHZONE *ppzNext = ppzlink->ppzDest;
            float g = pnode->g + (g1 + g2);
            float f = g + GDistFromExit(&posGoal, fence);
            NODE *pnodeNext = &anode[ppzNext->ipathzone];
            int state = pnodeNext->state;
            if (state != 0 && pnodeNext->f <= f)
                continue;
            switch (state) {
            case 0:
                break;
            case 1:
                RemoveDlEntry(&dlClosed, pnodeNext);
                break;
            case 2:
                RemoveDlEntry(&dlOpen, pnodeNext);
                break;
            }
            pnodeNext->ppz = ppzNext;
            pnodeNext->ppzlink = ppzlink;
            pnodeNext->g = g;
            pnodeNext->pnodeParent = pnode;
            pnodeNext->f = f;
            pnodeNext->state = 2;
            NODE *pnodeBefore = dlOpen.pnodeFirst;
            if (pnodeBefore) {
                if (f < pnodeBefore->f)
                    goto LInsert;
                for (pnodeBefore = pnodeBefore->dle.pnodeNext; pnodeBefore; pnodeBefore = pnodeBefore->dle.pnodeNext) {
                    if (pnodeNext->f < pnodeBefore->f)
                        break;
                }
            }
        LInsert:
            InsertDlEntryBefore(&dlOpen, pnodeBefore, pnodeNext);
        }
    }
    cpzlink = 0;
    if (!FIsDlEmpty(&dlOpen)) {
        if (!fExact && !pnode->pnodeParent) {
            apzlink[0] = 0;
            cpzlink = 1;
        } else {
            int c = 0;
            NODE *pnodeT;
            for (pnodeT = pnode; pnodeT->pnodeParent; pnodeT = pnodeT->pnodeParent)
                c++;
            cpzlink = c;
            if (c >= cpzlinkMax)
                cpzlink = cpzlinkMax;
            for (NODE *pnodeLink = pnode; pnodeLink->pnodeParent; pnodeLink = pnodeLink->pnodeParent) {
                if (c <= cpzlinkMax)
                    apzlink[c - 1] = pnodeLink->ppzlink;
                c--;
            }
        }
    }
    CStackFrame_Destructor(frame, 2);
    return cpzlink;
}
