// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x108]; short delta; short index; QW (*pfnVelocity)(void *); };
struct JTO { char pad0[0xC]; VT *pvt; char pad1[0xD0 - 0x10]; float alpha; char pad3[0x1A8 - 0xD4]; float rad; char pad2[0x208 - 0x1AC]; int fLanded; };
struct ZAP { JTO *pjt; int state; float tState; char pad[0x90 - 0xC]; int flash; float tPulseStart; float tFlash; float dtFlash; };
struct SMP;
struct LM { float lo; float hi; };
extern "C" {
struct CLOCK { float t; float dt; };
extern CLOCK g_2dded0;
extern LM g_2bbb60;
extern const float D_002BFAA0[3];
extern const float D_002BFAB0[3];
extern SMP D_002BFAC0;
float cosf(float);
float atan2f(float, float);
void func_001F4BF8(JTO *);
void SetStepRadTarget(JTO *, float);
int FJtStuck(JTO *, void *, float);
void ZapContinue(ZAP *);
}
float RadSmooth(float, float, float, SMP *, float *);

// Same clamp as RenderLoot: retail loads lo and hi before the two compares.
static inline float GLimitLm(LM *plm, float g)
{
    float lo = plm->lo;
    float hi = plm->hi;
    if (g < lo)
        return lo;
    if (hi < g)
        return hi;
    return g;
}

// Retail clamps both quadratics with the same lo/hi pair at g_2bbb60 (each
// clamp reloads it), so both go through one inline GLimitLm. ZapContinue
// takes the zap in $a0 (its own disassembly), and FJtStuck takes
// (jt, vector, time): $a0 = jt, $a1 = 0, $f12 = tState.
void UpdateZapPost(ZAP *pzap)
{
    if (pzap->flash != -1) {
        float uFade;
        if (pzap->state == -1) {
            float dtElapsed = g_2dded0.t - pzap->tFlash;
            float dtFlash = pzap->dtFlash;
            if (dtFlash < dtElapsed) {
                pzap->flash = -1;
                pzap->pjt->alpha = 0.0f;
                func_001F4BF8(pzap->pjt);
                goto after_flash;
            }
            uFade = dtElapsed / dtFlash;
        } else {
            uFade = 0.0f;
        }
        float cosine = cosf((g_2dded0.t - pzap->tPulseStart) * 10.0f);
        float alpha = GLimitLm(&g_2bbb60, D_002BFAA0[0] + uFade * (D_002BFAA0[1] + uFade * D_002BFAA0[2]));
        float pulse = GLimitLm(&g_2bbb60, D_002BFAB0[0] + cosine * (D_002BFAB0[1] + cosine * D_002BFAB0[2]));
        pzap->pjt->alpha = alpha * pulse;
    }
after_flash:
    if (pzap->state == -1)
        return;
    if (pzap->state != 7)
        return;
    JTO *pjt = pzap->pjt;
    QW velocity = pjt->pvt->pfnVelocity((unsigned char *)pjt + pjt->pvt->delta);
    float *pvelocity = (float *)&velocity;
    float radHeading = atan2f(pvelocity[1], pvelocity[0]);
    float radTarget = RadSmooth(pzap->pjt->rad, radHeading + 3.1415927f, g_2dded0.dt, &D_002BFAC0, 0);
    SetStepRadTarget(pzap->pjt, radTarget);
    if (0.25f < g_2dded0.t - pzap->tState) {
        if (pzap->pjt->fLanded != 0) {
            ZapContinue(pzap);
            return;
        }
    }
    if (FJtStuck(pzap->pjt, 0, pzap->tState) != 0)
        ZapContinue(pzap);
}
