typedef int QW __attribute__((mode(TI)));
struct TGT { int pso; int f4; float g8; int iC; int pad[8]; };
struct HUDOBJ { char pad[0x14]; int label; };
struct POOL { char pad[0x18]; int kind; };
struct SW {
    char pad0[0x4678]; int fTarget; char pad467C[0x4684 - 0x467C]; HUDOBJ *phud; int pad4688[2]; void *ploClone; float t;
    char pad4698[0x46A0 - 0x4698]; QW posTarget; char pad46B0[0x4740 - 0x46B0]; int label;
};
struct CRV { char pad[0x1B4]; CRV *pnext; };
struct LO { char pad[0x104]; LO *pnext; };
struct BRK { char pad[0x154]; BRK *pnext; };
struct ALO { char pad[0xE0]; ALO *pnext; int pad2; int grf; };
extern "C" {
int FIsPoSwFocusBase(void *);
int FIsBasicDerivedFrom(void *, int);
void InsertTargetCandidate(void *, void *, QW, void *, void *, int, TGT *);
QW PosLoWorld(void *);
void EmitTargetSparkles(SW *, void *, int, TGT *);
void UpdateSwTargetList(SW *, void *, int, TGT *);
int func_001DA5B0(void *);
POOL *PpoolFromLoClone(void *);
void ClearHudLabel(void *, int);
void ShowHudLabel(void *, int, float);
void *memset(void *, int, unsigned int);
extern SW B_003DD490;
extern char B_003DA0C0[];
extern CRV *B_003E13F0;
extern LO *B_003E13FC;
extern LO *B_003E1414;
extern BRK *B_003E1438;
extern LO *B_003E13D8;
extern CRV *B_003E13CC;
extern CRV *B_003E13C0;
extern ALO *B_003E13B4;
extern LO *B_003E1408;
extern float D_002BF660;
extern float D_002BF664;
extern float D_002BF70C;
}

extern "C" void BuildJtTargetList(void *pjt, void *pso, int grf)
{
    TGT atgt[4];
    QW pos;
    if (FIsPoSwFocusBase(pso) == 0)
        return;
    int fLo1408 = grf & 0x20;
    memset(atgt, 0, sizeof(atgt));
    int fCrv13F0 = grf & 8;
    int fLo13FC = grf & 0x10;
    int fCrv13C0 = grf & 2;
    int fLo1414 = grf & 0x80;
    int fBrk = grf & 4;
    int fLo13D8 = grf & 0x400;
    int fCrv13CC = grf & 0x200;
    int fAlo = grf & 1;
    for (TGT *ptgt = atgt; ptgt < &atgt[4]; ptgt++) {
        ptgt->iC = -1;
        ptgt->g8 = D_002BF664;
    }
    pos = PosLoWorld(pso);
    if (fCrv13F0)
        for (CRV *p = B_003E13F0; p != 0; p = p->pnext)
            InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0x190 : 0, 4, atgt);
    if (fLo13FC)
        for (LO *p = B_003E13FC; p != 0; p = p->pnext)
            InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0xE0 : 0, 4, atgt);
    if (fLo1414)
        for (LO *p = B_003E1414; p != 0; p = p->pnext)
            InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0xE0 : 0, 4, atgt);
    if (fBrk)
        for (BRK *p = B_003E1438; p != 0; p = p->pnext)
            InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0x130 : 0, 4, atgt);
    if (fLo13D8)
        for (LO *p = B_003E13D8; p != 0; p = p->pnext)
            InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0xE0 : 0, 4, atgt);
    if (fCrv13CC)
        for (CRV *p = B_003E13CC; p != 0; p = p->pnext)
            InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0x190 : 0, 4, atgt);
    if (fCrv13C0)
        for (CRV *p = B_003E13C0; p != 0; p = p->pnext)
            InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0x190 : 0, 4, atgt);
    if (fAlo)
        for (ALO *p = B_003E13B4; p != 0; p = p->pnext)
            if ((p->grf & 1) && FIsBasicDerivedFrom(p, 0x13))
                InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0x100 : 0, 4, atgt);
    if (fLo1408)
        for (LO *p = B_003E1408; p != 0; p = p->pnext)
            InsertTargetCandidate(pjt, pso, pos, p, p ? (char *)p + 0xE0 : 0, 4, atgt);

    int ctgt = 4;
    while (ctgt > 0 && atgt[ctgt - 1].pso == 0)
        ctgt--;
    EmitTargetSparkles(&B_003DD490, pso, ctgt, atgt);
    UpdateSwTargetList(&B_003DD490, pso, ctgt, atgt);
    int label = func_001DA5B0(B_003DA0C0);
    if (label != -1 && label != B_003DD490.label)
        return;
    int labelNew;
    int fence;
    // fence tokens: the subtraction reads vf2 that the first block loads
    asm("lqc2 vf2, %1" : "=r"(fence) : "m"(pos));
    if (B_003DD490.fTarget != 0) {
        asm("lqc2 vf1, %1\n\tvsub.xyzw vf1, vf2, vf1\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z"
            : "=r"(fence) : "m"(B_003DD490.posTarget), "r"(fence));
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r"(fence) : "r"(fence));
        int distanceBits;
        asm("qmfc2.ni %0, vf1" : "=r"(distanceBits) : "r"(fence));
        float distance;
        asm("mtc1 %1, %0" : "=f"(distance) : "r"(distanceBits));
        int fFar = D_002BF660 < distance;
        if (!fFar) {
            POOL *ppool = 0;
            if (B_003DD490.ploClone != 0)
                ppool = PpoolFromLoClone(B_003DD490.ploClone);
            if (ppool != 0 && ppool->kind == 0x624 && D_002BF70C < B_003DD490.t)
                labelNew = 0x125;
            else
                labelNew = B_003DD490.phud->label;
        } else {
            labelNew = -1;
        }
    } else {
        labelNew = -1;
    }
    if (labelNew != label) {
        if (labelNew == -1)
            ClearHudLabel(B_003DA0C0, B_003DD490.label);
        else
            ShowHudLabel(B_003DA0C0, labelNew, -1.0f);
        B_003DD490.label = labelNew;
    }
}
