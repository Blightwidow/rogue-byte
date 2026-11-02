#include "sly2.h"
// SetJumperState: state switch of a jumper (launch an SO along a ballistic arc).
// Behaviour (case 1, launch): vGrav = pjmpt->vGravity * speed^2; dpos = pjmpr->posTarget - so->palo->pos;
// t = fGuided ? DtSolveJumpLaunch(dpos, vGrav, ...) : pjmpt->dtFlight / speed; t = max(pjmpt->dtMin / speed, t);
// so->SetVelocity(dpos / t - vGrav * t / 2); tLand = now + t; tLand - dtMin / speed stored; when guided,
// predicts the landing point/velocity in the parent frame and registers it, then sets the SO gravity to vGrav.
struct VTSO { char pad[0x118]; short delta; short index; void (*SetVelocity)(void *, QW); };
struct ALOP { char pad[0x70]; QW pos; char pad80[0xA0 - 0x80]; void *pxf; };
struct SO { char pad0[0xC]; VTSO *vptr; char pad10[0x58 - 0x10]; ALOP *paloParent; char pad5C[0x148 - 0x5C]; unsigned long grf; };
struct GUARD { char pad[0x498]; void *pfall; };
struct ASEG { char pad[4]; void *paseg; char pad8[4]; float tSeek2; float tSeek3; float dtFlight; float dtMin; QW vGravity; };
struct ASEGA { char pad[0x40]; float speed; };
struct JMPR {
    char pad0[0x10];
    int js;
    float tState;
    char pad18[8];
    QW vGravity;
    ASEG *pjmpt;
    SO *pso;
    ASEGA *pasega;
    void *pv3C;
    QW posTarget;
    float tLand;
    float tPeak;
    void *pvTarget;
    void *pvTarget2;
    int fGuided;
    int fFar;
    int iPredict;
};
extern float g_2dded0;
extern char D_3DD490[];
extern "C" {
int FIsBasicDerivedFrom(void *, int);
void SubscribeLoObject(void *, void *);
void ClearGuardPathMode(void *);
void DisableFallCheck(void *);
void EnableFallCheck(void *);
void EndJumperFlight(JMPR *);
void RecalcSwOxfFilterForObject(char *, SO *);
int func_0012DE58(SO *, ALOP *, int, QW, QW, float);
}
void ApplyAsegToHandle(void *, SO *, void *, ASEGA **, float, float);
QW GetSoDvGravity(SO *);
void SetSoDvGravity(SO *, QW);
float DtSolveJumpLaunch(QW, QW, float, float, float, float);
void SeekAsega(ASEGA *, int, float, float);
void SetGuardPathTarget(SO *, void *, void *);
QW ConvertXfPos(int, void *, QW);
QW ConvertXfVec(int, void *, QW);

static inline QW Scale(QW v, float s)
{
    QW r;
    asm("qmtc2.ni %2, $vf3\n\tqmtc2.ni %1, $vf1\n\tvmulx.xyzw $vf2, $vf1, $vf3x\n\tqmfc2.ni %0, $vf2" : "=r" (r) : "r" (v), "r" (s));
    return r;
}
static inline QW Sub(QW a, QW b)
{
    QW r;
    asm("qmtc2.ni %1, $vf2\n\tqmtc2.ni %2, $vf4\n\tvsub.xyzw $vf1, $vf2, $vf4\n\tqmfc2.ni %0, $vf1" : "=r" (r) : "r" (a), "r" (b));
    return r;
}
static inline QW Combine(QW a, float sa, QW b, float sb)
{
    QW r;
    asm("qmtc2.ni %1, $vf3\n\tqmtc2.ni %3, $vf4\n\tqmtc2.ni %2, $vf1\n\tqmtc2.ni %4, $vf2\n\t"
        "vmulax.xyzw $ACC, $vf3, $vf1x\n\tvmaddx.xyzw $vf3, $vf4, $vf2x\n\tqmfc2.ni %0, $vf3"
        : "=r" (r) : "r" (a), "r" (sa), "r" (b), "r" (sb));
    return r;
}
static inline QW AddScaled(QW a, QW b, float s)
{
    QW r;
    asm("qmtc2.ni %1, $vf2\n\tqmtc2.ni %2, $vf3\n\tqmtc2.ni %3, $vf1\n\t"
        "vadda.xyzw $ACC, $vf0, $vf2\n\tvmaddx.xyzw $vf2, $vf3, $vf1x\n\tqmfc2.ni %0, $vf2"
        : "=r" (r) : "r" (a), "r" (b), "r" (s));
    return r;
}

void SetJumperState(JMPR *pjmpr, int js)
{
    if (js == pjmpr->js)
        return;
    pjmpr->js = js;
    pjmpr->tState = g_2dded0;
    switch (js) {
    case 0:
        ApplyAsegToHandle(pjmpr->pjmpt->paseg, pjmpr->pso, pjmpr->pv3C, &pjmpr->pasega, 0.0f, 1.0f);
        SubscribeLoObject(pjmpr->pasega, pjmpr);
        pjmpr->vGravity = GetSoDvGravity(pjmpr->pso);
        break;
    case 1: {
        if (FIsBasicDerivedFrom(pjmpr->pso, 0x38)) {
            SO *pso = pjmpr->pso;
            ClearGuardPathMode(pso);
            DisableFallCheck(((GUARD *)pso)->pfall);
        }
        float speed = pjmpr->pasega->speed;
        QW vGrav = Scale(pjmpr->pjmpt->vGravity, speed * speed);
        QW dpos = Sub(pjmpr->posTarget, pjmpr->pso->paloParent->pos);
        float dt;
        if (pjmpr->fGuided != 0) {
            if (pjmpr->pvTarget != 0 && (FIsBasicDerivedFrom(pjmpr->pvTarget, 0x13) || FIsBasicDerivedFrom(pjmpr->pvTarget, 0xB)))
                dt = DtSolveJumpLaunch(dpos, vGrav, 1250.0f, 0.0f, 1.1f, 50.0f);
            else if (pjmpr->fFar != 0)
                dt = DtSolveJumpLaunch(dpos, vGrav, 1500.0f, -1500.0f, 1.33f, -1.33f);
            else
                dt = DtSolveJumpLaunch(dpos, vGrav, 1250.0f, -1250.0f, 1.1f, -1.1f);
        } else {
            dt = pjmpr->pjmpt->dtFlight / speed;
        }
        float dtMin = pjmpr->pjmpt->dtMin / speed;
        dt = dtMin > dt ? dtMin : dt;
        SO *pso = pjmpr->pso;
        QW v = Combine(dpos, 1.0f / dt, vGrav, dt * -0.5f);
        pso->vptr->SetVelocity((char *)pso + pso->vptr->delta, v);
        float tLand = g_2dded0 + dt;
        pjmpr->tLand = tLand;
        pjmpr->tPeak = tLand - pjmpr->pjmpt->dtMin / speed;
        if (pjmpr->fGuided != 0) {
            QW vLand = AddScaled(v, vGrav, dt);
            QW pos = ConvertXfPos(0, pjmpr->pso->paloParent->pxf, pjmpr->posTarget);
            QW vel = ConvertXfVec(0, pjmpr->pso->paloParent->pxf, vLand);
            pjmpr->iPredict = func_0012DE58(pjmpr->pso, pjmpr->pso->paloParent, 5, pos, vel, pjmpr->tLand);
            pjmpr->pso->grf |= 0x4000000;
            RecalcSwOxfFilterForObject(D_3DD490, pjmpr->pso);
        }
        SetSoDvGravity(pjmpr->pso, vGrav);
        break;
    }
    case 2:
        SeekAsega(pjmpr->pasega, 0, pjmpr->pjmpt->tSeek2, 1.0f);
        break;
    case 3:
        SeekAsega(pjmpr->pasega, 0, pjmpr->pjmpt->tSeek3, 1.0f);
        if (pjmpr->pvTarget != 0)
            SetGuardPathTarget(pjmpr->pso, pjmpr->pvTarget, pjmpr->pvTarget2);
        break;
    case 4:
        if (pjmpr->fGuided != 0)
            EndJumperFlight(pjmpr);
        SetSoDvGravity(pjmpr->pso, pjmpr->vGravity);
        if (FIsBasicDerivedFrom(pjmpr->pso, 0x38))
            EnableFallCheck(((GUARD *)pjmpr->pso)->pfall);
        break;
    }
}
