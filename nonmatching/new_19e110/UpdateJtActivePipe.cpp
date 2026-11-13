// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"
struct SMP { float a; float b; float c; };
struct PIPEV { char pad[0x28]; unsigned long grf; char pad2[0xE4 - 0x30]; int closed; };
struct JTV { char pad0[0xC]; char *vptr; };
struct JTPIPE {
    JTV *pjt; int state; int pad8; PIPEV *pipe; float s; float vS; int fReverse; float gStick; int nStick;
    char pad24[0x50 - 0x24]; float w0; char pad54[0x5C - 0x54]; float sv0; float w1; char pad64[0x6C - 0x64]; float sv1; void *pasegbl;
};
struct VTV { char pad[0x318]; short delta; short index; int (*fn)(void *, int); };

extern float g_2dded0[];
extern QW g_2a2dd0;
extern QW g_2a2dc0;
extern char D_002BF928[];
extern "C" QW PosSmooth(float, QW, QW, void *, int);
extern "C" void SetJmpState(void *, int, int, int);
extern "C" int FButtonPressedWithin(float, void *, int);
extern "C" int GrfbtnVjoyPressedWithin(float, void *, int);
extern "C" void ClearVjoyPresses(void *, int);
extern "C" void StartBinoc(void *, int, int, int);
extern "C" int FAsegaGone(void *);
extern "C" void SetJtPipeState(JTPIPE *, int);
extern "C" float func_001E6728(PIPEV *, float);
extern "C" void GetPathPosFromS(float, PIPEV *, QW *, int);
extern "C" QW bevy_player_p14_1c4768(void *, QW);
extern "C" void bevy_player_p14_19e110(JTPIPE *, float *);
float GSmooth(float, float, float, SMP *, float *);
float GModPositive(float, float);
extern "C" float SMaxCrv(PIPEV *);
extern "C" void func_001F4BF8(void *);
extern "C" void ReblendAsegbl(void *);

/* v scaled to unit length, or `fallback` when v is shorter than 0.0001 */
static inline QW NormalizeOr(QW v, QW fallback)
{
    QW length = SqrtX(SquaredLength(v));
    if (LaneX(length) < 0.0001f)
        return fallback;
    return ScaleByReciprocalX(v, length);
}

static inline float GClamp(float g, float lo, float hi)
{
    if (g < lo)
        return lo;
    if (hi < g)
        return hi;
    return g;
}

#define NOPF(name, value) float name = value

extern "C" void UpdateJtActivePipe(JTPIPE *pjtpipe)
{
    struct { QW pos0; QW pos1; union { QW stick; SMP smp; }; float lm[4]; float out[4]; } l;
    float dt = g_2dded0[1];
    char *pjt0 = (char *)pjtpipe->pjt;
    *(QW *)(pjt0 + 0x1010) = PosSmooth(dt, *(QW *)(pjt0 + 0x1010), g_2a2dd0, D_002BF928, 0);
    void *pjoy;
    {
        PIPEV *pipe0 = pjtpipe->pipe;
        pjoy = *(void **)((char *)pjtpipe->pjt + 0x150);
        if (((pipe0->grf >> 60) & 1) == 0) {
            SetJmpState((char *)pjtpipe->pjt + 0x2c0, 0, 0, 0);
            return;
        }
    }
    if (pjtpipe->state != 0) {
        if (FButtonPressedWithin(0.25f, pjoy, 0x40)) {
            SetJmpState((char *)pjtpipe->pjt + 0x2c0, 2, 0, 0);
            return;
        }
    }
    if (GrfbtnVjoyPressedWithin(0.15f, pjoy, 0x400)) {
        JTV *pjt = pjtpipe->pjt;
        VTV *vt = (VTV *)pjt->vptr;
        if (vt->fn((char *)pjt + vt->delta, 3)) {
            ClearVjoyPresses(pjoy, 0x400);
            StartBinoc((char *)pjtpipe->pjt + 0xF00, 0, 0, 0);
        }
    }
    int stateBefore;
    int stateNow;
    do {
        stateBefore = pjtpipe->state;
        if (stateBefore == 0 || stateBefore == 4) {
            if (FAsegaGone(*(void **)((char *)pjtpipe->pjt + 0x1030)))
                SetJtPipeState(pjtpipe, 1);
        }
        stateNow = pjtpipe->state;
    } while (stateNow != stateBefore);
    if (stateNow == 0 || stateNow == 4)
        return;

    GetPathPosFromS(func_001E6728(pjtpipe->pipe, pjtpipe->s + 50.0f), pjtpipe->pipe, &l.pos0, 0);
    GetPathPosFromS(func_001E6728(pjtpipe->pipe, pjtpipe->s - 50.0f), pjtpipe->pipe, &l.pos1, 0);
    QW tangent = NormalizeOr(VectorSub(l.pos0, l.pos1), g_2a2dc0);
    {
        float half = 0.5f;
        float z = LaneZ(tangent);
        float zero = 0.0f;
        if (half < __builtin_fabsf(z)) {
            if (zero < z) {
                if (pjtpipe->fReverse != 0) goto turn;
            } else {
                if (pjtpipe->fReverse == 0) goto turn;
            }
        }
    }
    {
        float high = 0.4f;
        if (high < pjtpipe->gStick) {
            if (pjtpipe->fReverse != 0) {
                float low = -0.3f;
                float zz = LaneZInGeneralRegister(tangent);
                if (low < zz) goto turn;
            }
        }
        float low2 = -0.4f;
        if (pjtpipe->gStick < low2) {
            if (pjtpipe->fReverse == 0) {
                float high2 = 0.3f;
                float zz = LaneZInGeneralRegister(tangent);
                if (zz < high2) goto turn;
            }
        }
    }
    if (0) {
turn:
        SetJtPipeState(pjtpipe, 4);
        return;
    }
    {
    QW screen = bevy_player_p14_1c4768(pjoy, VectorSub(l.pos0, l.pos1));
    float joyx = *(float *)((char *)pjoy + 0x10);
    float joyy = *(float *)((char *)pjoy + 0x14);
    QW stick = JoinLowDoublewords(0.0f, InterleaveLowWords(joyy, joyx));
    float sStick = *(float *)((char *)pjoy + 0x1C);
    float zero = 0.0f;
    l.stick = stick;
    float gAlong = LaneX(DotProduct(screen, stick));
    switch (pjtpipe->nStick) {
    case 0: {
        NOPF(quarter, 0.25f);
        if (sStick < quarter) pjtpipe->nStick = -1;
        else {
            NOPF(minus7, -0.7f);
            if (gAlong < minus7) pjtpipe->nStick = 1;
        }
        break;
    }
    case 1: {
        NOPF(quarter, 0.25f);
        if (sStick < quarter) pjtpipe->nStick = -1;
        else {
            NOPF(plus7, 0.7f);
            if (plus7 < gAlong) pjtpipe->nStick = 0;
        }
        break;
    }
    case -1: {
        NOPF(third, 0.35f);
        if (third < sStick) {
            if (zero <= gAlong)
                pjtpipe->nStick = 0;
            else
                pjtpipe->nStick = 1;
        }
        break;
    }
    }
    int stateNew = -1;
    float gSpeed = gAlong;
    switch (pjtpipe->nStick) {
    case 0:
        stateNew = pjtpipe->fReverse != 0 ? 3 : 2;
        gSpeed = sStick;
        break;
    case 1:
        stateNew = pjtpipe->fReverse != 0 ? 2 : 3;
        gSpeed = sStick;
        break;
    case -1:
        stateNew = 1;
        gSpeed = 0.0f;
        break;
    }
    float vTarget;
    NOPF(hundredth, 0.01f);
    if (hundredth < gSpeed) {
        vTarget = (1.0f - gSpeed) * pjtpipe->sv0 + gSpeed * pjtpipe->sv1;
        if (stateNew == 3) vTarget = -vTarget;
    } else {
        vTarget = 0.0f;
        stateNew = 1;
    }
    if (pjtpipe->fReverse != 0) vTarget = -vTarget;
    l.smp.a = __builtin_fabsf(pjtpipe->sv1);
    l.smp.b = 0.0f;
    l.smp.c = 0.2f;
    dt = g_2dded0[1];
    pjtpipe->gStick = (-dt * vTarget) / l.smp.a + (1.0f - dt) * pjtpipe->gStick;
    if (pjtpipe->pipe->closed == 0) {
        bevy_player_p14_19e110(pjtpipe, l.lm);
        GSmooth(pjtpipe->s, l.lm[0], g_2dded0[1], &l.smp, &l.out[0]);
        GSmooth(pjtpipe->s, l.lm[1], g_2dded0[1], &l.smp, &l.out[1]);
        if (vTarget < -l.out[1]) vTarget = -l.out[1];
        else if (-l.out[0] < vTarget) vTarget = -l.out[0];
    }
    pjtpipe->vS = -vTarget;
    if (vTarget != 0.0f) {
        pjtpipe->s = pjtpipe->s + pjtpipe->vS * g_2dded0[1];
        func_001F4BF8(pjtpipe->pjt);
    }
    if (pjtpipe->pipe->closed != 0)
        pjtpipe->s = GModPositive(pjtpipe->s, SMaxCrv(pjtpipe->pipe));
    NOPF(hundredth2, 0.01f);
    if (__builtin_fabsf(vTarget) < hundredth2) {
        stateNew = 1;
    } else {
        float gBlend = (__builtin_fabsf(vTarget) - __builtin_fabsf(pjtpipe->sv0)) / (__builtin_fabsf(pjtpipe->sv1) - __builtin_fabsf(pjtpipe->sv0));
        gBlend = GClamp(gBlend, 0.0f, 1.0f);
        pjtpipe->w1 = gBlend;
        pjtpipe->w0 = 1.0f - gBlend;
        ReblendAsegbl(pjtpipe->pasegbl);
    }
    SetJtPipeState(pjtpipe, stateNew);
    }
}
