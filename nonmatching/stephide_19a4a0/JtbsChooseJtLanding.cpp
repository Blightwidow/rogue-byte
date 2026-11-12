// SPDX-License-Identifier: GPL-3.0-or-later
// JtbsChooseJtLanding: pick the best landing target for a jump among every kind of landable object.
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"

union V_19B110 { QW q; float f[4]; };
struct TRI_19B110 { int a; int b; int c; };
struct PHYS_19B110 { char pad[0x80]; V_19B110 grav; };
struct JTS_19B110 { char pad0[0xA8]; float tLand; char pad1[0xC0 - 0xAC]; QW posAim; QW vAim; };
struct VT108_19B110 { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct JT_19B110 {
    char pad0[0xC];
    VT108_19B110 *vt;
    char pad1[0x58 - 0x10];
    JTS_19B110 *pjts;
    char pad2[0xE8 - 0x5C];
    PHYS_19B110 *pphys;
    void *poxa;
    char pad3[0x218 - 0xF0];
    QW *pposSearch;
    char pad4[0x240 - 0x21C];
    QW posOffset;
    char pad5[0x2C0 - 0x250];
    char jmp[0x4C0 - 0x2C0];
    char attach[0x1000 - 0x4C0];
    unsigned grfTarget;
    char pad6[0x1F30 - 0x1004];
    float gravSurface;
};
struct JMP_19B110 { JT_19B110 *pjt; char pad[0xC]; float u; float s; };
struct VT18_19B110 { char pad[0x18]; short delta; short index; void (*fn)(void *, JT_19B110 *, QW *, int, float); };
struct SUB_19B110 { char pad[0x20]; VT18_19B110 *vt; };

// spots, handle points, other point targets: list linked at 0x104
struct SPOT_19B110 {
    char pad0[0xE0];
    union {
        SUB_19B110 sub;
        struct { char pad[8]; float dzMax; char pad1[0x1C - 0xC]; unsigned grf; VT18_19B110 *vtSub; } f;
    } u;
    SPOT_19B110 *next;
    char pad2[4];
    float scale;
};
// rails, pipes, hshapes: curves linked at 0x1B4
struct CRV_19B110 {
    char pad0[0x190];
    union {
        SUB_19B110 sub;
        struct { char pad[8]; float dzMax; char pad1[0x1C - 0xC]; unsigned grf; VT18_19B110 *vtSub; } f;
    } u;
    CRV_19B110 *next;
};
struct OBJ_19B110 {
    char pad0[0xE0];
    OBJ_19B110 *next;
    char pad1[0xE8 - 0xE4];
    unsigned flags;
    char pad2[0x108 - 0xEC];
    float dzMax;
    char pad3[0x11C - 0x10C];
    unsigned grf;
};
struct SPIRE_19B110 { char pad0[0x100]; SPIRE_19B110 *next; char pad1[4]; float dzMax; };
struct MURRAY_19B110 {
    char pad0[0xEC];
    void *poxa;
    char pad1[0x13D0 - 0xF0];
    int murrays;
    char pad2[0x1914 - 0x13D4];
    int fCarryBusy;
    char pad3[4];
    void *pcarry;
};

struct MJR_19B110 { void *pattach; void *pjmp; void *pobj; int pad; QW vLaunch; };
struct MJT_19B110 { JMP_19B110 *pjmp; void *pobj; int pad[2]; QW pos; };
struct FILTER_19B110 { int c; void **apoxa; };
struct LOCALS_19B110 {
    V_19B110 posJt;      // 0x10
    V_19B110 vJt;        // 0x20
    V_19B110 posAim;     // 0x30
    V_19B110 posAimBest; // 0x40
    V_19B110 vAim;       // 0x50
    V_19B110 vAimBest;   // 0x60
    TRI_19B110 triBest;  // 0x70
    int padTri;
    V_19B110 vLaunch;    // 0x80
    V_19B110 posTarget;  // 0x90
    union {              // 0xA0
        MJR_19B110 mjr;
        MJT_19B110 mjt;
        struct { TRI_19B110 tri; int pad; MJT_19B110 mjs; } spire;
        struct { void *apoxa[4]; FILTER_19B110 filter; } murray;
        struct { MJT_19B110 mjp; } pipe;
        struct { int pad[4]; MJT_19B110 mjt; } pipe2;
    } u;
    V_19B110 vTarget;    // 0xD0 (0xC0 in the union for some kinds)
    float dt;            // 0xE0
    float g;             // 0xE4
    float uKnot;         // 0xE8
    float uRail;         // 0xEC
    float gSpire;        // 0xF0
    float sPipe;         // 0xF4
    float sPipeBest;     // 0xF8
    float gPipe;         // 0xFC
    float radHpnt;       // 0x100
    float sHshape;       // 0x104
    float sHshapeBest;   // 0x108
};

extern "C" {
extern SPOT_19B110 *B_003E13D8;
extern CRV_19B110 *B_003E13CC;
extern OBJ_19B110 *B_003E13B4;
extern SPIRE_19B110 *B_003E142C;
extern CRV_19B110 *B_003E13C0;
extern SPOT_19B110 *B_003E13FC;
extern CRV_19B110 *B_003E13F0;
extern SPOT_19B110 *B_003E1408;
extern MURRAY_19B110 *g_2f7900;
extern QW g_2a2dd0;
extern float g_2dded0;
extern float D_002BF8E0, D_002BF8E4, D_002BF8E8, D_002BF8EC, D_002BF8F0, D_002BF8F4, D_002BF8F8, D_002BF8FC;
extern float D_002BF904, D_002BF908, D_002BF90C, D_002BF914, D_002BF918;
QW PosLoWorld(void *);
QW GetJmpLaunchVelocity(JMP_19B110 *, int);
int FIsBasicDerivedFrom(void *, int);
float GAdjustJtLandingScore(JMP_19B110 *, void *, float, float);
void MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(JMP_19B110 *, QW, void *, QW, QW, float *, float *, QW *, QW *);
void MeasureJtJumpToTargetAtTime(JMP_19B110 *, void *, QW, float, float *, QW *, QW *);
int FFindJtObstruction(JMP_19B110 *, float, void *, void *, QW, QW, QW, QW, void *);
int FFilterOxa(void *, void *);
int func_0019B0A8(void *, void *);
float GMeasureJumpRail__FP3MJRf(void *, float);
float GMeasureJumpTargetTime(void *, float);
float GMeasureJumpSpire(void *, float);
float GMeasureJumpPipe(void *, float);
float GMeasureJumpHpnt(void *, float);
float GMeasureJumpToHshape(void *, float);
void FindCrvClosestPointAll(void *, QW, int, QW *, int, int, float *);
void Spire_FindClosestPoint(void *, QW, int, int, QW *, int);
void bevy_player_p5_target_1e7410(void *, void *, void *, int, int, float *, int);
float bevy_player_p5_target_1e77e8(void *);
float UFromCrvS(void *, float);
float SMaxCrv(void *);
float SFromCrvU(void *, float);
void GetAttachRopeSlide(void *, void *, float, QW *, QW *);
void PredictSurfaceLanding(void *, QW, QW, QW, float, float, TRI_19B110 *, QW *, QW *);
void GetPathPosFromS(float, void *, QW *, void *);
QW ConvertAloPos(void *, void *, QW);
float atan2f(float, float);
void SetJmpBodyState(JMP_19B110 *, int, void *);
}
float MinimizeRange(float (*)(void *, float), void *, float, float, float, float, float *, float *);

static inline QW VAdd_19B110(QW a, QW b)
{
    return VectorAdd(a, b);
}

static inline QW VSub_19B110(QW a, QW b)
{
    return VectorSub(a, b);
}

// squared distance (VU0 dot product); result moved to an FPR
static inline float DistSq_19B110(QW a, QW b)
{
    return LaneX(SquaredLength(VectorSub(a, b)));
}

// distance (VU0 dot product and square root)
static inline float Dist_19B110(QW a, QW b)
{
    return LaneX(SqrtX(SquaredLength(VectorSub(a, b))));
}

extern "C" void JtbsChooseJtLanding(JMP_19B110 *pjmp, void *ploForce)
{
    LOCALS_19B110 l;
    float sJump = 0.0f;
    float uJump = sJump;
    void *pobjBest = 0;
    int jtbsBest = -1;
    l.posJt.q = PosLoWorld(pjmp->pjt);
    {
        JT_19B110 *pjt = pjmp->pjt;
        l.vJt.q = pjt->vt->fn((char *)pjt + pjt->vt->delta);
    }
    unsigned grfTarget = pjmp->pjt->grfTarget;
    memset(&l.triBest, 0, sizeof(l.triBest));
    float gBest = ploForce ? -3.402823466e+38f : 3.402823466e+38f;
    l.vLaunch.q = GetJmpLaunchVelocity(pjmp, 4);
    float dtBest = 0.0f;

    if (FIsBasicDerivedFrom(pjmp->pjt, 0x35)) {
        for (SPOT_19B110 *pobj = B_003E13D8; pobj; pobj = pobj->next) {
            if (!(pobj->u.f.grf & grfTarget))
                continue;
            SUB_19B110 *psub = &pobj->u.sub;
            pobj->u.f.vtSub->fn((char *)psub + pobj->u.f.vtSub->delta, pjmp->pjt, &l.posTarget.q, 0, 0.0f);
            if (pobj != ploForce && l.posJt.f[2] - l.posTarget.f[2] > pobj->u.f.dzMax)
                continue;
            MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(pjmp, l.vLaunch.q, pobj, l.posTarget.q, g_2a2dd0,
                                                                 &l.dt, &l.g, &l.posAim.q, &l.vAim.q);
            l.vAim.f[2] = l.vLaunch.f[2] + l.dt * pjmp->pjt->pphys->grav.f[2];
            if (pobj != ploForce) {
                if (l.g >= D_002BF8E0)
                    continue;
                l.g = GAdjustJtLandingScore(pjmp, pobj, l.g, D_002BF8E4);
                if (gBest <= l.g)
                    continue;
                if (FFindJtObstruction(pjmp, l.dt, FFilterOxa, pjmp->pjt->poxa, l.posJt.q, l.vLaunch.q, l.posAim.q, l.vAim.q, 0))
                    continue;
            }
            l.posAimBest = l.posAim;
            jtbsBest = 9;
            l.vAimBest = l.vAim;
            pobjBest = pobj;
            gBest = l.g < gBest ? l.g : gBest;
            dtBest = l.dt;
        }

        for (CRV_19B110 *pobj = B_003E13CC; pobj; pobj = pobj->next) {
            if (!(pobj->u.f.grf & grfTarget))
                continue;
            if (pobj != ploForce) {
                FindCrvClosestPointAll(pobj, *pjmp->pjt->pposSearch, 0, &l.posTarget.q, 0, 0, 0);
                if (l.posJt.f[2] - l.posTarget.f[2] > pobj->u.f.dzMax)
                    continue;
            }
            l.u.mjr.pattach = pjmp->pjt->attach;
            l.u.mjr.pjmp = pjmp->pjt->jmp;
            l.u.mjr.vLaunch = l.vLaunch.q;
            l.u.mjr.pobj = pobj;
            bevy_player_p5_target_1e7410(pobj, (void *)GMeasureJumpRail__FP3MJRf, &l.u.mjr, 0, 0, &l.uKnot, 0);
            float uKnot = l.uKnot;
            float uFirst = bevy_player_p5_target_1e77e8(pobj);
            float uLow = UFromCrvS(pobj, 50.0f);
            float uHigh = UFromCrvS(pobj, SMaxCrv(pobj) - 50.0f);
            MinimizeRange(GMeasureJumpRail__FP3MJRf, &l.u.mjr, uKnot, uFirst, uLow, uHigh, &l.uRail, &l.g);
            if (pobj != ploForce) {
                if (l.g >= D_002BF8E0)
                    continue;
                l.g = GAdjustJtLandingScore(pjmp, pobj, l.g, D_002BF8E8);
                if (gBest <= l.g)
                    continue;
            }
            GetAttachRopeSlide(l.u.mjr.pattach, pobj, l.uRail, &l.posTarget.q, (QW *)((char *)&l + 0xB0));
            MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(pjmp, l.vLaunch.q, pobj, l.posTarget.q,
                                                                 *(QW *)((char *)&l + 0xB0), &l.dt, 0, &l.posAim.q, &l.vAim.q);
            l.vAim.f[2] = l.vLaunch.f[2] + l.dt * pjmp->pjt->pphys->grav.f[2];
            if (pobj != ploForce &&
                FFindJtObstruction(pjmp, l.dt, FFilterOxa, pjmp->pjt->poxa, l.posJt.q, l.vLaunch.q, l.posAim.q, l.vAim.q, 0))
                continue;
            pobjBest = pobj;
            gBest = l.g < gBest ? l.g : gBest;
            uJump = l.uRail;
            jtbsBest = 10;
            l.posAimBest = l.posAim;
            l.vAimBest = l.vAim;
            dtBest = l.dt;
            sJump = SFromCrvU(pobjBest, uJump);
        }

        for (OBJ_19B110 *pobj = B_003E13B4; pobj; pobj = pobj->next) {
            if (pobj != ploForce) {
                if (ploForce)
                    continue;
                if ((pobj->flags & 1) == 0)
                    continue;
                if (!FIsBasicDerivedFrom(pobj, 0x13))
                    continue;
            }
            if (!(pobj->grf & grfTarget))
                continue;
            QW vTarget = PosLoWorld(pobj);
            l.posTarget.q = vTarget;
            if (pobj != ploForce) {
                if (l.posJt.f[2] - l.posTarget.f[2] > pobj->dzMax)
                    continue;
                if (DistSq_19B110(vTarget, l.posJt.q) > 1000000.0f)
                    continue;
            }
            l.u.mjt.pos = g_2a2dd0;
            l.u.mjt.pjmp = pjmp;
            l.u.mjt.pobj = pobj;
            MinimizeRange(GMeasureJumpTargetTime, &l.u.mjt, 0.5f, 0.25f, 0.25f, 3.0f, &l.dt, &l.g);
            MeasureJtJumpToTargetAtTime(l.u.mjt.pjmp, l.u.mjt.pobj, l.u.mjt.pos, l.dt, 0, &l.posAim.q, &l.vAim.q);
            if (pobj != ploForce) {
                if (l.g >= D_002BF8E0)
                    continue;
                l.g = GAdjustJtLandingScore(pjmp, pobj, l.g, D_002BF8EC);
                if (gBest <= l.g)
                    continue;
                if (FFindJtObstruction(pjmp, l.dt, FFilterOxa, pjmp->pjt->poxa, l.posJt.q, l.vJt.q, l.posAim.q, l.vAim.q, &l.posTarget))
                    continue;
            }
            jtbsBest = 14;
            pobjBest = pobj;
            l.posAimBest.q = VAdd_19B110(l.posAim.q, pjmp->pjt->posOffset);
            l.vAimBest = l.vAim;
            gBest = gBest < l.g ? gBest : l.g;
            dtBest = l.dt;
        }

        for (SPIRE_19B110 *pobj = B_003E142C; pobj; pobj = pobj->next) {
            Spire_FindClosestPoint(pobj, l.posJt.q, 0, 0, &l.posTarget.q, 0);
            if (pobj != ploForce) {
                if (l.posJt.f[2] - l.posTarget.f[2] > pobj->dzMax)
                    continue;
                if (Dist_19B110(l.posTarget.q, l.posJt.q) > 1000.0f)
                    continue;
            }
            l.u.spire.mjs.pos = l.vLaunch.q;
            l.u.spire.mjs.pjmp = pjmp;
            l.u.spire.mjs.pobj = pobj;
            MinimizeRange(GMeasureJumpSpire, &l.u.spire.mjs, 1.0f, 0.25f, 0.25f, 2.0f, &l.dt, &l.gSpire);
            if (pobj != ploForce) {
                if (l.gSpire >= D_002BF8E0)
                    continue;
                l.gSpire = GAdjustJtLandingScore(pjmp, pobj, l.gSpire, D_002BF908);
                if (gBest <= l.gSpire)
                    continue;
            }
            PredictSurfaceLanding(pobj, l.posJt.q, l.vLaunch.q, pjmp->pjt->pphys->grav.q, pjmp->pjt->gravSurface, l.dt,
                                  &l.u.spire.tri, &l.posAim.q, &l.vAim.q);
            if (pobj != ploForce &&
                FFindJtObstruction(pjmp, l.dt, FFilterOxa, pjmp->pjt->poxa, l.posJt.q, l.vJt.q, l.posAim.q, l.vAim.q, 0))
                continue;
            jtbsBest = 16;
            pobjBest = pobj;
            l.posAimBest.q = VAdd_19B110(l.posAim.q, pjmp->pjt->posOffset);
            l.vAimBest = l.vAim;
            gBest = gBest < l.gSpire ? gBest : l.gSpire;
            dtBest = l.dt;
            l.triBest = l.u.spire.tri;
        }
    }

    if (FIsBasicDerivedFrom(pjmp->pjt, 0x37)) {
        MURRAY_19B110 *pmurray = g_2f7900;
        if (pmurray && pmurray->murrays == 15 && !pmurray->fCarryBusy) {
            QW posCarry = PosLoWorld(pmurray->pcarry);
            l.posTarget.q = posCarry;
            MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(pjmp, l.vLaunch.q, g_2f7900->pcarry, posCarry, g_2a2dd0,
                                                                 &l.dt, &l.g, &l.posAim.q, &l.vAim.q);
            l.vAim.f[2] = l.vLaunch.f[2] + l.dt * pjmp->pjt->pphys->grav.f[2];
            if (g_2f7900->pcarry != ploForce) {
                if (l.g >= D_002BF8E0)
                    goto LCarryDone;
                l.g = GAdjustJtLandingScore(pjmp, g_2f7900, l.g, D_002BF904);
                if (gBest <= l.g)
                    goto LCarryDone;
                l.u.murray.apoxa[0] = pjmp->pjt->poxa;
                l.u.murray.apoxa[1] = g_2f7900->poxa;
                l.u.murray.filter.c = 2;
                l.u.murray.filter.apoxa = l.u.murray.apoxa;
                if (FFindJtObstruction(pjmp, l.dt, func_0019B0A8, &l.u.murray.filter, l.posJt.q, l.vLaunch.q, l.posAim.q, l.vAim.q, 0))
                    goto LCarryDone;
            }
            l.posAimBest = l.posAim;
            jtbsBest = 18;
            l.vAimBest = l.vAim;
            pobjBest = g_2f7900->pcarry;
            dtBest = l.dt;
            gBest = l.g < gBest ? l.g : gBest;
        }
    }
LCarryDone:

    for (CRV_19B110 *pobj = B_003E13C0; pobj; pobj = pobj->next) {
        if (!(pobj->u.f.grf & pjmp->pjt->grfTarget))
            continue;
        FindCrvClosestPointAll(pobj, l.posJt.q, 0, &l.posTarget.q, 0, 0, &l.sPipe);
        if (pobj != ploForce) {
            if (l.posJt.f[2] - l.posTarget.f[2] > pobj->u.f.dzMax)
                continue;
            if (Dist_19B110(l.posTarget.q, l.posJt.q) > 1000.0f)
                continue;
        }
        float sPipe = l.sPipe;
        l.u.pipe.mjp.pjmp = pjmp;
        l.u.pipe.mjp.pobj = pobj;
        MinimizeRange(GMeasureJumpPipe, &l.u.pipe.mjp, sPipe, 100.0f, 50.0f, SMaxCrv(pobj) - 50.0f, &l.sPipeBest, &l.gPipe);
        if (pobj != ploForce) {
            if (l.gPipe >= D_002BF8E0)
                continue;
            l.gPipe = GAdjustJtLandingScore(pjmp, pobj, l.gPipe, D_002BF8F0);
            if (gBest <= l.gPipe)
                continue;
        }
        l.u.pipe2.mjt.pjmp = pjmp;
        l.u.pipe2.mjt.pobj = pobj;
        GetPathPosFromS(l.sPipeBest, pobj, &l.posTarget.q, 0);
        l.u.pipe2.mjt.pos = ConvertAloPos(0, pobj, l.posTarget.q);
        MinimizeRange(GMeasureJumpTargetTime, &l.u.pipe2.mjt, 0.5f, 0.25f, 0.25f, 3.0f, &l.dt, 0);
        MeasureJtJumpToTargetAtTime(l.u.pipe2.mjt.pjmp, l.u.pipe2.mjt.pobj, l.u.pipe2.mjt.pos, l.dt, 0, &l.posAim.q, &l.vAim.q);
        if (pobj != ploForce &&
            FFindJtObstruction(pjmp, l.dt, FFilterOxa, pjmp->pjt->poxa, l.posJt.q, l.vJt.q, l.posAim.q, l.vAim.q, &l.posTarget))
            continue;
        jtbsBest = 15;
        pobjBest = pobj;
        l.posAimBest.q = VAdd_19B110(l.posAim.q, pjmp->pjt->posOffset);
        l.vAimBest = l.vAim;
        gBest = gBest < l.gPipe ? gBest : l.gPipe;
        dtBest = l.dt;
        sJump = l.sPipeBest;
    }

    for (SPOT_19B110 *pobj = B_003E13FC; pobj; pobj = pobj->next) {
        if (!(pobj->u.f.grf & grfTarget))
            continue;
        QW vTarget = PosLoWorld(pobj);
        l.posTarget.q = vTarget;
        if (l.posJt.f[2] - l.posTarget.f[2] > pobj->u.f.dzMax)
            continue;
        *(QW *)((char *)&l + 0xB0) = VSub_19B110(l.posJt.q, vTarget);
        l.u.mjt.pos = l.vJt.q;
        l.u.mjt.pjmp = pjmp;
        l.u.mjt.pobj = pobj;
        float rad = atan2f(((float *)((char *)&l + 0xB0))[1], ((float *)((char *)&l + 0xB0))[0]);
        MinimizeRange(GMeasureJumpHpnt, &l.u.mjt, rad * pobj->scale, D_002BF914, -3.402823466e+38f, 3.402823466e+38f,
                      &l.radHpnt, &l.g);
        l.g = l.g * D_002BF90C;
        if (pobj != ploForce) {
            if (l.g >= D_002BF8E0)
                continue;
            l.g = GAdjustJtLandingScore(pjmp, pobj, l.g, D_002BF8F8);
            if (gBest <= l.g)
                continue;
        }
        SUB_19B110 *psub = &pobj->u.sub;
        pobj->u.f.vtSub->fn((char *)psub + pobj->u.f.vtSub->delta, pjmp->pjt, &l.vTarget.q, 0, l.radHpnt);
        MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(pjmp, l.vJt.q, pobj, l.vTarget.q, g_2a2dd0,
                                                             &l.dt, 0, &l.posAim.q, &l.vAim.q);
        l.vAim.f[2] = l.vJt.f[2] + l.dt * pjmp->pjt->pphys->grav.f[2];
        if (pobj != ploForce &&
            FFindJtObstruction(pjmp, l.dt, FFilterOxa, pjmp->pjt->poxa, l.posJt.q, l.vJt.q, l.posAim.q, l.vAim.q, 0))
            continue;
        jtbsBest = 12;
        pobjBest = pobj;
        l.posAimBest = l.posAim;
        l.vAimBest = l.vAim;
        gBest = gBest < l.g ? gBest : l.g;
        dtBest = l.dt;
        sJump = l.radHpnt;
    }

    for (CRV_19B110 *pobj = B_003E13F0; pobj; pobj = pobj->next) {
        if (!(pobj->u.f.grf & grfTarget))
            continue;
        FindCrvClosestPointAll(pobj, l.posJt.q, 0, &l.posTarget.q, 0, 0, &l.sHshape);
        if (l.posJt.f[2] - l.posTarget.f[2] > pobj->u.f.dzMax)
            continue;
        float sHshape = l.sHshape;
        l.u.mjt.pos = l.vJt.q;
        l.u.mjt.pjmp = pjmp;
        l.u.mjt.pobj = pobj;
        MinimizeRange(GMeasureJumpToHshape, &l.u.mjt, sHshape, D_002BF918, 30.0f, SMaxCrv(pobj) - 30.0f, &l.sHshapeBest, &l.g);
        l.g = l.g * D_002BF90C;
        if (pobj != ploForce) {
            if (l.g >= D_002BF8E0)
                continue;
            l.g = GAdjustJtLandingScore(pjmp, pobj, l.g, D_002BF8F4);
            if (gBest <= l.g)
                continue;
        }
        SUB_19B110 *psub = &pobj->u.sub;
        pobj->u.f.vtSub->fn((char *)psub + pobj->u.f.vtSub->delta, pjmp->pjt, (QW *)((char *)&l + 0xB0), 0, l.sHshapeBest);
        MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(pjmp, l.vJt.q, pobj, *(QW *)((char *)&l + 0xB0), g_2a2dd0,
                                                             &l.dt, 0, &l.posAim.q, &l.vAim.q);
        l.vAim.f[2] = l.vJt.f[2] + l.dt * pjmp->pjt->pphys->grav.f[2];
        if (pobj != ploForce &&
            FFindJtObstruction(pjmp, l.dt, FFilterOxa, pjmp->pjt->poxa, l.posJt.q, l.vJt.q, l.posAim.q, l.vAim.q, 0))
            continue;
        jtbsBest = 11;
        pobjBest = pobj;
        l.posAimBest = l.posAim;
        l.vAimBest = l.vAim;
        gBest = gBest < l.g ? gBest : l.g;
        dtBest = l.dt;
        sJump = l.sHshapeBest;
    }

    for (SPOT_19B110 *pobj = B_003E1408; pobj; pobj = pobj->next) {
        if (!(pobj->u.f.grf & grfTarget))
            continue;
        SUB_19B110 *psub = &pobj->u.sub;
        pobj->u.f.vtSub->fn((char *)psub + pobj->u.f.vtSub->delta, pjmp->pjt, &l.posTarget.q, 0, 0.0f);
        if (pobj != ploForce && l.posJt.f[2] - l.posTarget.f[2] > pobj->u.f.dzMax)
            continue;
        MeasureJtJumpToTarget__FP2JTP6VECTORP3ALOT1T1PfT5T1T1(pjmp, l.vJt.q, pobj, l.posTarget.q, g_2a2dd0,
                                                             &l.dt, &l.g, &l.posAim.q, &l.vAim.q);
        l.vAim.f[2] = l.vJt.f[2] + l.dt * pjmp->pjt->pphys->grav.f[2];
        if (pobj != ploForce) {
            if (l.g >= D_002BF8E0)
                continue;
            l.g = GAdjustJtLandingScore(pjmp, pobj, l.g, D_002BF8FC);
            if (gBest <= l.g)
                continue;
            if (FFindJtObstruction(pjmp, l.dt, FFilterOxa, pjmp->pjt->poxa, l.posJt.q, l.vJt.q, l.posAim.q, l.vAim.q, 0))
                continue;
        }
        gBest = gBest < l.g ? gBest : l.g;
        jtbsBest = 13;
        pobjBest = pobj;
        l.posAimBest = l.posAim;
        l.vAimBest = l.vAim;
        dtBest = l.dt;
    }

    if (jtbsBest != -1) {
        JTS_19B110 *pjts = pjmp->pjt->pjts;
        pjts->tLand = g_2dded0 + dtBest;
        pjts->posAim = VSub_19B110(l.posAimBest.q, pjmp->pjt->posOffset);
        pjts->vAim = l.vAimBest.q;
        pjmp->u = uJump;
        pjmp->s = sJump;
        SetJmpBodyState(pjmp, jtbsBest, pobjBest);
    }
}
