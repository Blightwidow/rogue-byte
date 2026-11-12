#include "sly2.h"
struct TARGET;
struct LOOKJT { u8 unknown_00[0x1A8]; float sRange; u8 unknown_1AC[0xF0C]; void *field_0x10B8; };
struct RIGENTRY { float wOld; u8 unknown_04[8]; float wNew; u8 unknown_10[8]; void *paseg; };
struct LOOKRIG {
    LOOKJT *pjt;
    s32 state;
    s32 iHigh;
    s32 unknown_0C;
    s32 fSnap;
    s32 unknown_14;
    float tBlend;
    float gTarget;
    QW vecTarget;
    float rMin;
    float rMax;
    RIGENTRY aentry[6];
    void *phandle;
    void *palo;
};
extern "C" {
void ApplyAsegToHandle(void *, void *, int, void *, float, float);
void ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(void *, int, void *, float, float, float, TARGET **, QW *);
QW ConvertAloPos(void *, void *, QW);
void FixStepAngularVelocity__FP4STEP(void *);
void ReblendAsegbl(void *);
void SetStepRadTargetDir(void *, QW);
void func_00131A90(void *, float);
void func_00131B10(void *, void *, void *);
extern QW g_2a2dd0;
extern float g_2dded0;
}
static inline float GClamp(float g, float lo, float hi)
{
    if (g < lo)
        return lo;
    if (hi < g)
        return hi;
    return g;
}
extern "C" void SetLookRigState(LOOKRIG *prig, int state)
{
    struct { QW dir; QW vecPos; TARGET *ptarget; } l;
    void *paseg;
    float rBlend;
    if (state == prig->state)
        return;
    if (prig->state == -1) {
        prig->unknown_0C = 0;
        prig->tBlend = g_2dded0;
        prig->fSnap = 0;
        prig->unknown_14 = 0;
        float radMax = state == 0 ? 3.15f : 1.5f;
        ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(prig->pjt, 2, &prig->vecTarget, prig->pjt->sRange, 0.15f, radMax, &l.ptarget, &l.dir);
        if (l.ptarget != 0) {
            float rLo = prig->rMin;
            prig->gTarget = GClamp((((float *)&l.dir)[2] - rLo) / (prig->rMax - rLo), 0.0f, 1.0f);
        } else {
            prig->gTarget = 0.5f;
        }
        l.vecPos = ConvertAloPos(prig->palo, prig->pjt, g_2a2dd0);
        prig->iHigh = ((float *)&l.vecPos)[1] > 0.0f ? 1 : 0;
        if (state == 0 && l.ptarget != 0) {
            SetStepRadTargetDir(prig->pjt, l.dir);
            FixStepAngularVelocity__FP4STEP(prig->pjt);
        }
    }
    prig->state = state;
    rBlend = 0.0f;
    if (state == -1) {
        paseg = 0;
    } else {
        if (state < -1) {
        } else if (state < 3) {
            RIGENTRY *pentry = &prig->aentry[state * 2 + prig->iHigh];
            rBlend = 0.06666667f;
            pentry->wOld = 1.0f - prig->gTarget;
            paseg = pentry->paseg;
            pentry->wNew = prig->gTarget;
            ReblendAsegbl(paseg);
        }
    }
    ApplyAsegToHandle(paseg, prig->pjt, 1, &prig->phandle, g_2dded0 - prig->tBlend, 1.0f);
    if (prig->phandle != 0) {
        if (prig->fSnap != 0)
            func_00131B10(prig->phandle, prig->pjt, prig->pjt->field_0x10B8);
        if (prig->phandle != 0) {
            if (rBlend != 0.0f)
                func_00131A90(prig->phandle, g_2dded0 + rBlend);
        }
    }
}
