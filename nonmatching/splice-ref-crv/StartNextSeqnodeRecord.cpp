// SPDX-License-Identifier: GPL-3.0-or-later
/* StartNextSeqnodeRecord 0x1E1E30 */
#include "sly2.h"
#include "vu0inline.h"

/* record fields: one 0x50-byte record per sequence step */
struct REC { int kind; int fChild; char pad[0x48]; };
#define RI(p, off) (*(int *)((char *)(p) + (off)))
#define RF(p, off) (*(float *)((char *)(p) + (off)))
#define RQ(p, off) (*(QW *)((char *)(p) + (off)))
#define RP(p, off) (*(void **)((char *)(p) + (off)))

/* virtual call through the vtable at +0xC: a delta (short) and a function per 8-byte slot */
#define VT(p) (*(char **)((char *)(p) + 0xC))
#define VFN(p, off, F) ((F) * (void **)(VT(p) + (off) + 4))
#define VTHIS(p, off) ((char *)(p) + *(short *)(VT(p) + (off)))

struct LO;
struct SEQVT { char pad[8]; short deltaAddRef; short idxAddRef; void (*fnAddRef)(void *); short deltaRelease; short idxRelease; void (*fnRelease)(void *); };
struct SEQNODE {
    char pad0[0xC]; SEQVT *vt; int pad10;
    LO *psw;        /* 0x14 */
    LO *ploCtx;     /* 0x18 */
    LO *plo1C;      /* 0x1C */
    LO *plo20;      /* 0x20 */
    LO *psubject;   /* 0x24 */
    REC *precFirst; /* 0x28 */
    REC *precLast;  /* 0x2C */
    REC *precCur;   /* 0x30 */
    float rClock;   /* 0x34 */
    char pad38[0x4C - 0x38];
    LO *pasega;     /* 0x4C */
    LO *pjsg;       /* 0x50 */
    LO *pjtPose;    /* 0x54 */
    LO *psma;       /* 0x58 */
    int fSmaCur;    /* 0x5C */
    LO *ploShown;   /* 0x60 */
    LO *ploSw;      /* 0x64 */
    REC *precStream;/* 0x68 */
    char pad6C[0x78 - 0x6C];
    float sCrv78;   /* 0x78 */
    float sCrv7C;   /* 0x7C */
    float tCam;     /* 0x80 */
    char pad84[0x9C - 0x84];
    int fCamMove;   /* 0x9C */
    LO *pjtBinoc;   /* 0xA0 */
    char padA4[0xD8 - 0xA4];
    LO *ploD8;      /* 0xD8 */
    LO *ploDC;      /* 0xDC */
    int fE0;        /* 0xE0 */
    char padE4[0xEC - 0xE4];
    void *pamb;     /* 0xEC */
};

struct REF {
    SEQNODE *p;
    REF(SEQNODE *q) { p = q; p->vt->fnAddRef((char *)p + p->vt->deltaAddRef); }
    ~REF() { p->vt->fnRelease((char *)p + p->vt->deltaRelease); }
};

struct BEAT { float t; int n; char pad[0x28]; };
struct WARP { LO *plo; void *pmember; int pad[2]; VECTOR pos; };
struct MAT3 { QW a, b, c; };
struct CLOCK { float dt; char pad[0x38]; float dtReal; };
struct CM { char pad[0x90]; QW pos; };

extern char B_003DD490[], B_002DE460[], B_002DEB30[], B_002DFC00[], B_003DA0C0[], B_003DA530[], B_003DD040[], B_004435F0[];
extern CM B_002DDF40;
extern void *B_002DE570;
extern int B_004435F8;
extern CLOCK g_2dded0;
extern QW g_2a2dc0, g_2a2dd0;

extern "C" {
LO *PloFindSeqnodeObject(SEQNODE *, int);
int FIsBasicDerivedFrom(LO *, int);
SEQNODE *PseqnodeNew(LO *, REC *, SEQNODE *);
void RunSeqnode(SEQNODE *);
SEQNODE *PseqnodeFind(LO *, int, int);
void StopSeqnode(SEQNODE *);
void EnsureSggAlarm__FP3SGGP5ALARM(LO *, void *);
void StopJsg(LO *);
void JT_StartPose(LO *, int, int, int);
LO *PasegaApplyAseg(LO *, LO *, float, float, int);
void StartJsg(LO *, LO *);
void TriggerRsmgEntry(void *, int *, LO *, int, SEQNODE *, LO **);
int FSmaRetracted(LO *);
int GetSmaCur(LO *);
LO *PloFindSwObject_thunk(void *, int, int, LO *);
void SetClockRate(CLOCK *, int, float);
void ApplyTaskStateRequests(void *, int, void *, LO *);
void SetSeqnodeHandsOff(SEQNODE *, int, int);
int func_00210B68(void);
void func_00228170(LO *);
void StartAttach(void *, int, LO *, int);
void SetAttachSubstate(void *, int);
void SetSeqnodeDrive(SEQNODE *, REC *, LO *);
void GetSeqnodeObjectPosRad(SEQNODE *, LO *, VECTOR *, float *);
void SetStepRadTarget(LO *, float);
void LoadRotateMatrixRad(MAT3 *, QW, float);
void SetJmpState(void *, int, int, int);
void DiscardSoXps(LO *);
void SetResetFlag__FP2CM(CM *);
void func_001E4F20(SEQNODE *, LO *);
void func_001E5000(SEQNODE *, LO *);
void FindCrvClosestPointAll(void *, QW, int, int, int, float *, float *);
void SetJtJtcs(LO *, int);
void SetJtState(LO *, int, int);
void SetJtAttach5(LO *, LO *);
void StartJtCarry(LO *, LO *, LO *);
void SetJtAttach9(LO *, LO *);
void func_001421A0(LO *, LO *);
void func_001421F8(LO *, LO *);
QW PosLoWorld(LO *);
void SetStepRadTargetDir(LO *, QW);
void func_001424E0(LO *, LO *, LO *, int);
void FAttachGroundTarget(void *, int, LO *);
LO *func_00205438(LO *, int);
void GoalFollowCrv_SetCrv(LO *, LO *, int);
void GoalGotoPos_SetPos(LO *, QW);
void *PmemberFromLo(LO *);
void FFindSurfaceAlongUp(VECTOR *, int, int, float, float);
void WarpJtToSafePoint(LO *, WARP *);
void func_00141968(LO *, QW, float, float);
LO *ShowHideLo(void *, int, int, float, LO *, LO *);
void ShowHideLoGlob(void *, int, int, int, int, LO *, LO *);
void EnableDisableLoPart(void *, int, int, int, int, LO *, LO *);
void JoltCm(CM *, int);
void TriggerJoyRumbleRumk__FP3JOY4RUMKf(void *, int, float);
void func_00210538(void *, int, int, int, LO *, LO *, float);
void SetEyesClosedByOid(void *, int, int, LO *, LO *, float);
void StartSwAmbSfx(void *, int, int, int, int, float, float, float, int, LO *, LO *, void *);
void StopSwAmbSfx(void *, int, LO *, void *);
float DtSeqnodeRecord(SEQNODE *, REC *);
void StartSeqnodeCameraMove(SEQNODE *, REC *, REC *, float);
void StopSeqnodeCameraMove(SEQNODE *, int);
void StartBinoc(void *, int, LO *, LO *);
void ReleaseSeqnodeBinoc(SEQNODE *);
void ReleaseSeqnodeSma(SEQNODE *);
void bevy_classes_k30_cam_set(void *, LO *);
void func_00150E60(void *, LO *);
void func_00150EA0(void *, QW, QW, float);
void func_00150EE8(void *, float);
void bevy_classes_k30_cam_150ef0(void *);
void func_001DD820(void *);
void StartStream(void *, int, int);
void func_00227788(void *);
void AttachSeqnodeObject(SEQNODE *, LO *, int, int);
void DetachSeqnodeObject(SEQNODE *, LO *, int, int);
void SetRhythmBeats(void *, int, unsigned int, BEAT *);
void QueueRhythmCue(void *, LO *, int, int, float);
void PlayDancerAnim(LO *, LO *, int);
void QueueStream(void *, int);
void DequeueStream(void *, int);
void *PsmaFindAlo(LO *, int);
void StartMurrayMash(LO *, void *, int, int, int);
void ShowHudLabel(void *, int, float);
void ClearHudLabel(void *, int);
void func_00171CF8(LO *, LO *);
void func_00171D58(LO *, LO *);
void func_001B9880(LO *);
void func_00220508(void *, LO *);
}

static inline LO *PloSubject(SEQNODE *psn, int oid)
{
    if (oid == -1) {
        LO *plo = psn->plo20;
        if (plo == 0) {
            plo = psn->plo1C;
            if (plo == 0)
                plo = (LO *)RP(psn->psw, 0x6C);
        }
        return plo;
    }
    return PloFindSeqnodeObject(psn, oid);
}

static inline LO *PsggFind(SEQNODE *psn, int oid)
{
    if (oid == -1)
        return psn->psw;
    LO *psgg = PloFindSeqnodeObject(psn, oid);
    if (psgg != 0 && FIsBasicDerivedFrom(psgg, 0x72) != 0)
        return psgg;
    return 0;
}

static inline REC *PrecFindLabel(SEQNODE *psn, REC *prec)
{
    REC *precEnd = psn->precLast;
    REC *precFound = 0;
    int depth = 0;
    for (REC *p = psn->precFirst + 1; p < precEnd; p++) {
        switch (p->kind) {
        case 0: depth++; break;
        case 1: depth--; break;
        case 0x13:
            if (depth == 0 && RI(p, 0x10) == RI(prec, 0x10)) {
                precFound = p;
                p = precEnd;
            }
            break;
        }
    }
    return precFound;
}

static inline unsigned GrfSw(LO *psw)
{
    unsigned grf = RI(psw, 0x40);
    unsigned grfT;
    if (!(grf & 1))
        grfT = *(unsigned *)grf;
    else
        grfT = grf;
    return grfT;
}

static inline MAT3 MatFromRad(float rad)
{
    MAT3 mat;
    LoadRotateMatrixRad(&mat, g_2a2dc0, rad);
    return mat;
}

extern "C" void StartNextSeqnodeRecord(SEQNODE *pseqnode)
{
    pseqnode->precCur++;
    if (pseqnode->precCur > pseqnode->precLast)
        return;
    REF ref(pseqnode);
    REC *prec = pseqnode->precCur;
    int oid;
    switch (prec->kind) {
    case 0x16: case 0x1A: case 0x1C: case 0x1E: case 0x23:
        oid = RI(prec, 0x18);
        break;
    case 0x27: case 0x28:
        oid = RI(prec, 0x20);
        break;
    case 0x22: case 0x24: case 0x29: case 0x2A: case 0x2B: case 0x4A:
        oid = RI(prec, 0x1C);
        break;
    case 0x1B: case 0x47: case 0x48: case 0x4F: case 0x50: case 0x51: case 0x57:
        oid = RI(prec, 0x10);
        break;
    case 0xB: case 0x18: case 0x19: case 0x1D: case 0x1F: case 0x20: case 0x21: case 0x43: case 0x4B: case 0x58: case 0x59: case 0x5A:
        oid = RI(prec, 0x14);
        break;
    default:
        oid = -1;
        break;
    }
    LO *plo;
    if (oid == -1) {
        if (pseqnode->plo20 != 0)
            plo = pseqnode->plo20;
        else if (pseqnode->plo1C != 0)
            plo = pseqnode->plo1C;
        else
            plo = (LO *)RP(pseqnode->psw, 0x6C);
    } else {
        plo = PloFindSeqnodeObject(pseqnode, oid);
    }
    pseqnode->psubject = plo;

    switch (prec->kind) {
    case 0: {
        SEQNODE *pnew = PseqnodeNew(pseqnode->psw, prec, pseqnode);
        pseqnode->precCur = pnew->precLast;
        RunSeqnode(pnew);
        break;
    }
    case 2: {
        int oidT = RI(prec, 0x10);
        SEQNODE *psn;
        if (oidT == -1)
            psn = pseqnode;
        else
            psn = PseqnodeFind(pseqnode->psw, oidT, 0);
        if (psn != 0)
            StopSeqnode(psn);
        break;
    }
    case 5: {
        LO *psgg = PsggFind(pseqnode, RI(prec, 0x14));
        if (psgg != 0)
            EnsureSggAlarm__FP3SGGP5ALARM(psgg, RP(prec, 0x10));
        break;
    }
    case 6: {
        LO *psgg = PsggFind(pseqnode, RI(prec, 0x10));
        if (psgg != 0)
            StopJsg(psgg);
        break;
    }
    case 7: {
        LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        if (pso != 0 && FIsBasicDerivedFrom(pso, 0x32) != 0)
            VFN(pso, 0x278, void (*)(void *, int))(VTHIS(pso, 0x278), 1);
        break;
    }
    case 8:
        pseqnode->plo20 = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        break;
    case 9: {
        void *pparams = &RI(prec, 0x10);
        RP(pseqnode->psw, 0x68) = pseqnode;
        LO *psw = pseqnode->psw;
        VFN(psw, 0x18, void (*)(void *, int, int, int, void **, int))(VTHIS(psw, 0x18), 4, 0, 1, &pparams, 0);
        RP(pseqnode->psw, 0x68) = 0;
        break;
    }
    case 0xA: {
        LO *palo = PloFindSeqnodeObject(pseqnode, RI(prec, 0x14));
        if (palo != 0) {
            if (FIsBasicDerivedFrom(palo, 0x34) != 0) {
                JT_StartPose(palo, RI(prec, 0x10), RI(prec, 0x18) | 1, 5);
                if (prec->fChild == 0)
                    pseqnode->pjtPose = palo;
                break;
            }
            if (FIsBasicDerivedFrom(palo, 0x30) == 0)
                palo = 0;
        }
        LO *pasegd = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        if (pasegd != 0 && FIsBasicDerivedFrom(pasegd, 0x6D) != 0) {
            LO *pasega = PasegaApplyAseg(pasegd, palo, 0.0f, 1.0f, RI(prec, 0x18));
            if (prec->fChild == 0) {
                pseqnode->pasega = pasega;
                VFN(pasega, 0x8, void (*)(void *))(VTHIS(pasega, 0x8));
            }
        }
        break;
    }
    case 0xB: {
        LO *pjsg = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        if (pjsg != 0 && FIsBasicDerivedFrom(pjsg, 0x72) != 0) {
            StartJsg(pjsg, plo);
            if (prec->fChild == 0)
                pseqnode->pjsg = pjsg;
        }
        break;
    }
    case 0xC: {
        LO *pctx = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        pseqnode->ploCtx = pctx;
        if (pctx == 0)
            pseqnode->ploCtx = pseqnode->psw;
        break;
    }
    case 0xD: {
        int aentry[4];
        aentry[0] = RI(prec, 0x10);
        aentry[1] = RI(prec, 0x14);
        aentry[2] = RI(prec, 0x18);
        aentry[3] = -1;
        int mode = 1;
        if (RI(prec, 0x1C) != 0)
            mode = 3;
        TriggerRsmgEntry(B_003DD490, aentry, pseqnode->ploCtx, mode, pseqnode, &pseqnode->psma);
        if (prec->fChild != 0) {
            ReleaseSeqnodeSma(pseqnode);
        } else {
            LO *psma = pseqnode->psma;
            if (psma != 0 && pseqnode->fSmaCur == 0 && FSmaRetracted(psma) == 0 && GetSmaCur(pseqnode->psma) == RI(prec, 0x18))
                pseqnode->fSmaCur = 1;
        }
        break;
    }
    case 0xE:
    case 0xF: {
        LO *pso = PloFindSwObject_thunk(B_003DD490, 0x405, RI(prec, 0x10), 0);
        if (pso != 0 && FIsBasicDerivedFrom(pso, 0x7E) != 0) {
            if (prec->kind == 0xE) {
                VFN(pso, 0x188, void (*)(void *, int))(VTHIS(pso, 0x188), RI(prec, 0x14));
                if (prec->fChild == 0)
                    pseqnode->ploSw = pso;
            } else {
                VFN(pso, 0x190, void (*)(void *))(VTHIS(pso, 0x190));
            }
        }
        break;
    }
    case 0x10: {
        SetClockRate(&g_2dded0, 6, RF(prec, 0x10));
        if (RF(prec, 0x10) == 0.0f) {
            LO *psw = pseqnode->psw;
            int grf = RI(psw, 0x40);
            if ((grf ^ 1) & 1)
                *(int *)grf |= 0x100;
            else
                RI(psw, 0x40) = grf | 0x100;
        } else {
            LO *psw = pseqnode->psw;
            int grf = RI(psw, 0x40);
            if ((grf ^ 1) & 1)
                *(int *)grf &= ~0x100;
            else
                RI(psw, 0x40) = grf & ~0x100;
        }
        break;
    }
    case 0x11:
        ApplyTaskStateRequests(B_002DEB30, 1, &RI(prec, 0x10), pseqnode->ploCtx);
        break;
    case 0x12:
        SetSeqnodeHandsOff(pseqnode, RI(prec, 0x10), RI(prec, 0x14));
        break;
    case 0x14:
    case 0x15:
        if (prec->kind != 0x15 || func_00210B68() == RI(prec, 0x14)) {
            REC *precGoto = prec;
            REC *precLabel = 0;
            int depth = 0;
            for (prec = pseqnode->precFirst + 1; prec < pseqnode->precLast; prec++) {
                switch (prec->kind) {
                case 0: depth++; break;
                case 1: depth--; break;
                case 0x13:
                    if (depth == 0 && RI(prec, 0x10) == RI(precGoto, 0x10)) {
                        precLabel = prec;
                        prec = pseqnode->precLast;
                    }
                    break;
                }
            }
            if (precLabel != 0)
                pseqnode->precCur = precLabel;
        }
        break;
    case 0x16: {
        LO *ptarget = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        if (ptarget != 0 && FIsBasicDerivedFrom(ptarget, 0x29) != 0) {
            func_00228170(ptarget);
            break;
        }
        if (pseqnode->psubject == 0)
            break;
        if (ptarget != 0 && FIsBasicDerivedFrom(ptarget, 0x1B) != 0) {
            if (FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
                char *pattach = (char *)pseqnode->psubject + 0x4C0;
                StartAttach(pattach, 8, ptarget, 0);
                SetAttachSubstate(pattach, 9);
                SetSeqnodeDrive(pseqnode, 0, 0);
            }
            break;
        }
        VECTOR pos;
        float rad;
        GetSeqnodeObjectPosRad(pseqnode, ptarget, &pos, &rad);
        int fStep = FIsBasicDerivedFrom(pseqnode->psubject, 0x33);
        if (fStep != 0) {
            QW posT = *(QW *)&pos;
            LO *pstep = pseqnode->psubject;
            char *pvt = VT(pstep);
            QW posStep = RQ(pstep, 0x240);
            QW dpos = VectorSub(posT, posStep);
            ((void (*)(void *, QW)) * (void **)(pvt + 0xEC))((char *)pstep + *(short *)(pvt + 0xE8), dpos);
            SetStepRadTarget(pstep, rad);
        } else {
            LO *psubj = pseqnode->psubject;
            VFN(psubj, 0xE8, void (*)(void *, QW))(VTHIS(psubj, 0xE8), *(QW *)&pos);
        }
        MAT3 matT = MatFromRad(rad);
        LO *psubj = pseqnode->psubject;
        VFN(psubj, 0xF0, void (*)(void *, MAT3 *))(VTHIS(psubj, 0xF0), &matT);
        if (FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            QW up = *(QW *)&g_2a2dc0;
            QW height = VectorFromWord(*(u32 *)((char *)pjt + 0x1048));
            VECTOR scale;
            *(QW *)&scale = height;
            QW posT2 = *(QW *)&pos;
            QW result = ScaleAddX(posT2, up, height);
            RQ(pjt, 0x1060) = result;
            if (RI(prec, 0x14) == 0 && RI(pjt, 0x12F4) == 0) {
                SetJmpState((char *)pjt + 0x2C0, 0xB, 0, 0);
                DiscardSoXps(pjt);
            }
            SetSeqnodeDrive(pseqnode, 0, 0);
        }
        psubj = pseqnode->psubject;
        VFN(psubj, 0x118, void (*)(void *, QW))(VTHIS(psubj, 0x118), g_2a2dd0);
        psubj = pseqnode->psubject;
        VFN(psubj, 0x120, void (*)(void *, QW))(VTHIS(psubj, 0x120), g_2a2dd0);
        break;
    }
    case 0x17:
        SetResetFlag__FP2CM(&B_002DDF40);
        break;
    case 0x18: {
        LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        if (pso != 0 && FIsBasicDerivedFrom(pso, 0xF) != 0)
            func_001E4F20(pseqnode, pso);
        break;
    }
    case 0x19:
        func_001E5000(pseqnode, PloFindSeqnodeObject(pseqnode, RI(prec, 0x10)));
        break;
    case 0x1A:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            if (RI(pjt, 0xF54) != -1) {
                VECTOR pos;
                GetSeqnodeObjectPosRad(pseqnode, PloFindSeqnodeObject(pseqnode, RI(prec, 0x10)), &pos, 0);
                FindCrvClosestPointAll(RP(pjt, 0xF5C), *(QW *)&pos, 0, 0, 0, 0, &pseqnode->sCrv7C);
                SetSeqnodeDrive(pseqnode, prec, pjt);
            }
        }
        break;
    case 0x1C:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x35) != 0) {
            LO *pjt = pseqnode->psubject;
            switch (RI(prec, 0x14)) {
            case 2: SetJtJtcs(pjt, 3); break;
            case 4: SetJtState(pjt, 0xD, -1); break;
            case 8: SetJtState(pjt, 9, -1); break;
            }
        }
        break;
    case 0x1D:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            SetJtAttach5(pjt, PloFindSeqnodeObject(pseqnode, RI(prec, 0x10)));
            SetSeqnodeDrive(pseqnode, prec, pjt);
        }
        break;
    case 0x1E:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            LO *pcarry = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
            StartJtCarry(pjt, pcarry, PloFindSeqnodeObject(pseqnode, RI(prec, 0x14)));
            SetSeqnodeDrive(pseqnode, prec, pjt);
        }
        break;
    case 0x1F:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            SetJtAttach9(pjt, PloFindSeqnodeObject(pseqnode, RI(prec, 0x10)));
            SetSeqnodeDrive(pseqnode, prec, pjt);
        }
        break;
    case 0x20:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            func_001421A0(pjt, PloFindSeqnodeObject(pseqnode, RI(prec, 0x10)));
        }
        break;
    case 0x21:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            func_001421F8(pjt, PloFindSeqnodeObject(pseqnode, RI(prec, 0x10)));
            SetSeqnodeDrive(pseqnode, prec, pjt);
        }
        break;
    case 0x22:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            LO *pso = PloFindSwObject_thunk(B_003DD490, 1, RI(prec, 0x10), pjt);
            int oidT = RI(prec, 0x14);
            LO *pother;
            if (oidT == 3) {
                QW posCm = B_002DDF40.pos;
                QW posJt = PosLoWorld(pjt);
                QW dir = VectorSub(posCm, posJt);
                SetStepRadTargetDir(pjt, dir);
                pother = 0;
            } else {
                pother = PloFindSeqnodeObject(pseqnode, oidT);
            }
            func_001424E0(pjt, pso, pother, RI(prec, 0x18));
            SetSeqnodeDrive(pseqnode, prec, pjt);
        }
        break;
    case 0x23:
        if (PloFindSeqnodeObject(pseqnode, RI(prec, 0x14)) != 0 && pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0)
            SetSeqnodeDrive(pseqnode, prec, pseqnode->psubject);
        break;
    case 0x24:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            if (RI(prec, 0x20) != -1)
                JT_StartPose(pjt, RI(prec, 0x20), 9, 6);
            LO *pground = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
            if (pground != 0) {
                if (FIsBasicDerivedFrom(pground, 0x22) != 0 || FIsBasicDerivedFrom(pground, 0xC) != 0 || FIsBasicDerivedFrom(pground, 0x26) != 0 ||
                    FIsBasicDerivedFrom(pground, 0x58) != 0 || FIsBasicDerivedFrom(pground, 0xB) != 0 || FIsBasicDerivedFrom(pground, 0x13) != 0) {
                    int grf;
                    if (FIsBasicDerivedFrom(pjt, 0x35) != 0)
                        grf = 0xFFFF;
                    else
                        grf = FIsBasicDerivedFrom(pjt, 0x37) != 0 ? 0xF8FE : 0xF8FA;
                    FAttachGroundTarget((char *)pjt + 0x4C0, grf, pground);
                }
                if (RI(pjt, 0x4CC) != -1 && RI(pjt, 0x4C8) == 3) {
                    void *pcrv = RP(pjt, 0x4D4);
                    VECTOR pos;
                    GetSeqnodeObjectPosRad(pseqnode, pground, &pos, 0);
                    FindCrvClosestPointAll(pcrv, *(QW *)&pos, 0, 0, 0, &pseqnode->sCrv78, 0);
                }
            }
            SetSeqnodeDrive(pseqnode, prec, pjt);
        }
        break;
    case 0x25:
        pseqnode->fE0 = 1;
        break;
    case 0x26:
        pseqnode->fE0 = 0;
        break;
    case 0x27:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pcrv = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
            if (pcrv != 0 && FIsBasicDerivedFrom(pcrv, 0xA) != 0) {
                LO *pjt = pseqnode->psubject;
                if (RI(prec, 0x24) != -1)
                    JT_StartPose(pjt, RI(prec, 0x24), 9, 6);
                LO *pgoal = func_00205438(pjt, 0xA8);
                RI(pgoal, 0x40) = pseqnode->fE0;
                RI(pgoal, 0xCC) = RI(prec, 0x18);
                RF(pgoal, 0xD0) = RF(prec, 0x1C);
                GoalFollowCrv_SetCrv(pgoal, pcrv, RI(prec, 0x14) == 0);
                VFN(pgoal, 0x40, void (*)(void *))(VTHIS(pgoal, 0x40));
            }
        }
        break;
    case 0x28:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            VECTOR pos;
            GetSeqnodeObjectPosRad(pseqnode, PloFindSeqnodeObject(pseqnode, RI(prec, 0x10)), &pos, 0);
            if (RI(prec, 0x24) != -1)
                JT_StartPose(pjt, RI(prec, 0x24), 9, 6);
            LO *pgoal = func_00205438(pjt, 0xC1);
            RI(pgoal, 0x30) = pseqnode->fE0;
            RF(pgoal, 0x34) = RF(prec, 0x14);
            RI(pgoal, 0x38) = RI(prec, 0x18);
            RF(pgoal, 0x3C) = RF(prec, 0x1C);
            GoalGotoPos_SetPos(pgoal, *(QW *)&pos);
            VFN(pgoal, 0x40, void (*)(void *))(VTHIS(pgoal, 0x40));
        }
        break;
    case 0x29:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            if (RI(pjt, 0x4CC) != -1 && RI(pjt, 0x4C8) == 8)
                SetSeqnodeDrive(pseqnode, prec, pjt);
        }
        break;
    case 0x2A:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pjt = pseqnode->psubject;
            LO *pdest = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
            WARP warp;
            memset(&warp, 0, sizeof(warp));
            if (pdest == 0) {
                QW posJt = PosLoWorld(pjt);
                QW posLo = RQ(pjt, 0x240);
                QW sum = VectorAdd(posJt, posLo);
                *(QW *)&warp.pos = sum;
            } else {
                void *pmember = PmemberFromLo(pdest);
                warp.pmember = pmember;
                if (pmember != 0) {
                    if (RI(pjt, 0xF54) != -1 && RP(pjt, 0xF5C) == pdest)
                        break;
                    char *pvt = *(char **)((char *)pmember + 0x20);
                    ((void (*)(void *, LO *, VECTOR *))*(void **)(pvt + 0x14))((char *)pmember + *(short *)(pvt + 0x10), pjt, &warp.pos);
                    warp.plo = pdest;
                } else {
                    GetSeqnodeObjectPosRad(pseqnode, pdest, &warp.pos, 0);
                    FFindSurfaceAlongUp(&warp.pos, 0, 0, 100.0f, -150.0f);
                }
            }
            WarpJtToSafePoint(pjt, &warp);
            if (RI(prec, 0x14) == 1)
                RI(pjt, 0x2E8) = RI(prec, 0x14);
            if (FIsBasicDerivedFrom(pjt, 0x35) != 0)
                RI(pjt, 0x18F0) = RI(prec, 0x18);
            SetSeqnodeDrive(pseqnode, prec, pjt);
        }
        break;
    case 0x2B:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0) {
            LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
            LO *pjt = pseqnode->psubject;
            VECTOR pos;
            GetSeqnodeObjectPosRad(pseqnode, pso, &pos, 0);
            func_00141968(pjt, *(QW *)&pos, RF(prec, 0x14), RF(prec, 0x18));
        }
        break;
    case 0x2C:
    case 0x2D: {
        LO *pso = ShowHideLo(B_003DD490, prec->kind == 0x2C, RI(prec, 0x10), RF(prec, 0x14), pseqnode->ploCtx, pseqnode->psw);
        if (pso != 0 && prec->fChild == 0 && FIsBasicDerivedFrom(pso, 0x30) != 0)
            pseqnode->ploShown = pso;
        break;
    }
    case 0x2E:
    case 0x2F:
        ShowHideLoGlob(B_003DD490, prec->kind == 0x2E, RI(prec, 0x10), RI(prec, 0x14), 0, pseqnode->ploCtx, pseqnode->psw);
        break;
    case 0x30:
    case 0x31:
        EnableDisableLoPart(B_003DD490, prec->kind == 0x30, RI(prec, 0x10), RI(prec, 0x14), 0, pseqnode->ploCtx, pseqnode->psw);
        break;
    case 0x32:
        JoltCm(&B_002DDF40, RI(prec, 0x10));
        break;
    case 0x33:
        TriggerJoyRumbleRumk__FP3JOY4RUMKf(B_002DFC00, RI(prec, 0x14), RF(prec, 0x10));
        break;
    case 0x34:
        func_00210538(B_003DD490, RI(prec, 0x10), RI(prec, 0x14), RI(prec, 0x18), pseqnode->ploCtx, pseqnode->psw, RF(prec, 0x1C));
        break;
    case 0x35:
        SetEyesClosedByOid(B_003DD490, RI(prec, 0x10), RI(prec, 0x14), pseqnode->ploCtx, pseqnode->psw, RF(prec, 0x18));
        break;
    case 0x36:
        StartSwAmbSfx(B_003DD490, RI(prec, 0x10), RI(prec, 0x14), RI(prec, 0x18), RI(prec, 0x1C), RF(prec, 0x20), RF(prec, 0x24), RF(prec, 0x28), 0,
                      pseqnode->ploCtx, pseqnode->psw, &pseqnode->pamb);
        break;
    case 0x37:
        StopSwAmbSfx(B_003DD490, RI(prec, 0x10), pseqnode->psw, &pseqnode->pamb);
        break;
    case 0x38: {
        float dt;
        int fAccum;
        if (RF(prec, 0x40) == 0.0f) {
            dt = 0.0f;
            fAccum = 1;
        } else {
            dt = RF(prec, 0x40);
            fAccum = 0;
        }
        REC *pmove = 0;
        int depth = 0;
        for (REC *p = prec + 1; p < pseqnode->precLast && pmove == 0; p++) {
            switch (p->kind) {
            case 0: depth++; break;
            case 1: depth--; break;
            case 0x39:
                if (depth == 0)
                    pmove = p;
                break;
            default:
                if (depth == 0 && fAccum != 0)
                    dt += DtSeqnodeRecord(pseqnode, p);
                break;
            }
        }
        if (pmove != 0)
            StartSeqnodeCameraMove(pseqnode, prec, pmove, dt);
        break;
    }
    case 0x39:
        if (pseqnode->tCam == 3.4028235e38f) {
            if (RI(prec, 0x40) != 0)
                StopSeqnodeCameraMove(pseqnode, RI(prec, 0x44));
            else
                pseqnode->fCamMove = 0;
        }
        break;
    case 0x3A:
        StopSeqnodeCameraMove(pseqnode, RI(prec, 0x10));
        break;
    case 0x3B: {
        LO *pfocus = PloFindSeqnodeObject(pseqnode, RI(prec, 0x14));
        if (pfocus != 0)
            FIsBasicDerivedFrom(pfocus, 0x33);
        LO *panchor = PloFindSwObject_thunk(B_003DD490, 0x405, RI(prec, 0x18), 0);
        LO *pjt = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        if (pjt != 0 && FIsBasicDerivedFrom(pjt, 0x34) != 0) {
            pseqnode->pjtBinoc = pjt;
            StartBinoc((char *)pjt + 0xF00, 1, pfocus, panchor);
        }
        break;
    }
    case 0x3C:
        ReleaseSeqnodeBinoc(pseqnode);
        break;
    case 0x3D:
    {
        LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        bevy_classes_k30_cam_set(B_002DE460, pso);
    }
        break;
    case 0x3E:
    {
        LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        func_00150E60(B_002DE460, pso);
    }
        break;
    case 0x3F:
        func_00150EA0(B_002DE460, RQ(prec, 0x10), RQ(prec, 0x20), RF(prec, 0x30));
        break;
    case 0x40:
        func_00150EE8(B_002DE460, RF(prec, 0x10));
        break;
    case 0x41:
        bevy_classes_k30_cam_150ef0(B_002DE460);
        break;
    case 0x42:
        B_004435F8 = RI(prec, 0x10) & 0xF0;
        break;
    case 0x44:
        func_001DD820(B_003DA530);
        break;
    case 0x45:
        StartStream(B_003DD040, RI(prec, 0x10), RI(prec, 0x14));
        pseqnode->precStream = prec;
        break;
    case 0x46:
        func_00227788(B_004435F0);
        break;
    case 0x47:
        if (plo != 0)
            AttachSeqnodeObject(pseqnode, plo, RI(prec, 0x14), RI(prec, 0x18));
        break;
    case 0x48:
        if (plo != 0)
            DetachSeqnodeObject(pseqnode, plo, RI(prec, 0x14), RI(prec, 0x18));
        break;
    case 0x49:
        if (B_002DE570 != 0) {
            BEAT abeat[6];
            unsigned int cbeat = 0;
            int depth = 0;
            for (REC *p = prec + 1; p < pseqnode->precLast; p++) {
                switch (p->kind) {
                case 0: depth++; break;
                case 1: depth--; break;
                case 0x4A:
                    if (depth == 0 && cbeat < 6) {
                        BEAT *pbeat = &abeat[cbeat++];
                        pbeat->t = RF(p, 0x10);
                        pbeat->n = RI(p, 0x14);
                    }
                    break;
                case 0x49:
                    if (depth == 0)
                        p = pseqnode->precLast;
                    break;
                }
            }
            SetRhythmBeats(B_002DE570, RI(prec, 0x10), cbeat, abeat);
        }
        break;
    case 0x4A:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x44) != 0 && B_002DE570 != 0)
            QueueRhythmCue(B_002DE570, pseqnode->psubject, RI(prec, 0x14), RI(prec, 0x18), RF(prec, 0x10));
        break;
    case 0x4B:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x44) != 0) {
            LO *pdancer = pseqnode->psubject;
            int oidT = RI(prec, 0x10);
            LO *pso;
            if (oidT == -1)
                pso = 0;
            else
                pso = PloFindSwObject_thunk(B_003DD490, 4, oidT, pdancer);
            PlayDancerAnim(pdancer, pso, 0);
        }
        break;
    case 0x4C:
        QueueStream(B_003DD040, RI(prec, 0x10));
        break;
    case 0x4D:
        DequeueStream(B_003DD040, RI(prec, 0x10));
        break;
    case 0x4F:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x36) != 0) {
            LO *pmurray = pseqnode->psubject;
            LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x14));
            if (pso != 0) {
                void *psma = PsmaFindAlo(pso, -1);
                if (psma != 0)
                    StartMurrayMash(pmurray, psma, RI(prec, 0x1C), RI(prec, 0x18), RI(prec, 0x20));
            }
        }
        break;
    case 0x50:
    case 0x51:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x37) != 0)
            SetSeqnodeDrive(pseqnode, prec, pseqnode->psubject);
        break;
    case 0x53:
        ShowHudLabel(B_003DA0C0, RI(prec, 0x10), RF(prec, 0x14));
        break;
    case 0x54:
        ClearHudLabel(B_003DA0C0, RI(prec, 0x10));
        break;
    case 0x55: {
        LO *pa = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        LO *pb = PloFindSeqnodeObject(pseqnode, RI(prec, 0x14));
        func_00171CF8(pa, pb);
        if (prec->fChild == 0) {
            pseqnode->ploD8 = pa;
            pseqnode->ploDC = pb;
        }
        break;
    }
    case 0x56: {
        LO *pa = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
        func_00171D58(pa, PloFindSeqnodeObject(pseqnode, RI(prec, 0x14)));
        break;
    }
    case 0x57:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x36) != 0)
            func_001B9880(pseqnode->psubject);
        break;
    case 0x58:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x37) != 0) {
            LO *pjt = pseqnode->psubject;
            LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
            if (pso != 0 && FIsBasicDerivedFrom(pso, 0x36) != 0) {
                SetJmpState((char *)pjt + 0x2C0, (RI(pjt, 0x2DC) == 0x11) ? 3 : 1, 0, 0);
                SetSeqnodeDrive(pseqnode, prec, pjt);
            }
        }
        break;
    case 0x59:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x36) != 0) {
            LO *pjt = pseqnode->psubject;
            int state = RI(pjt, 0x1914);
            if (state < 7) if (state >= 4) {
                LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
                if (pso != 0)
                    func_00220508((char *)pjt + 0x1910, pso);
            }
        }
        break;
    case 0x5A:
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x36) != 0) {
            LO *pjt = pseqnode->psubject;
            int state = RI(pjt, 0x1914);
            if (state < 7) if (state >= 4) {
                RI(prec, 0x18) = RI(pjt, 0x1910);
                LO *pso = PloFindSeqnodeObject(pseqnode, RI(prec, 0x10));
                if (pso != 0) {
                    func_00220508((char *)pjt + 0x1910, pso);
                    SetSeqnodeDrive(pseqnode, prec, pjt);
                }
            }
        }
        break;
    default:
        break;
    }

    if (GrfSw(pseqnode->psw) & 0x100)
        pseqnode->rClock = g_2dded0.dtReal;
    else
        pseqnode->rClock = g_2dded0.dt;
}
