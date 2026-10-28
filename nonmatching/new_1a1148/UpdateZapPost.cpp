// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct JTO { char pad0[0xC]; VT *vt; char pad1[0xD0 - 0x10]; float alpha; char pad3[0x1A8 - 0xD4]; float rad; char pad2[0x208 - 0x1AC]; int landed; };
struct ZAP { JTO *jt; int state; float tstate; char pad[0x90 - 0xC]; int flash; float tstart; float tflash; float dur; };
struct SMP;
extern "C" {
extern float g_2dded0;
extern float g_2bbb60[2];
extern float D_002BFAA0[3];
extern float D_002BFAB0[3];
extern char D_002BFAC0[];
float cosf(float);
float atan2f(float, float);
void func_001F4BF8(JTO *);
void SetStepRadTarget(JTO *, float);
int FJtStuck(float, JTO *, int);
void ZapContinue(ZAP *);
}
float RadSmooth(float, float, float, SMP *, float *);
void UpdateZapPost(ZAP *zap)
{
    int state;
    if (zap->flash != -1) {
        float fade;
        state = zap->state;
        if (state == -1) {
            float dt = g_2dded0 - zap->tflash;
            float dur = zap->dur;
            if (dur < dt) {
                zap->flash = state;
                zap->jt->alpha = 0.0f;
                func_001F4BF8(zap->jt);
                goto after;
            }
            fade = dt / dur;
        } else {
            fade = 0.0f;
        }
        float cosine = cosf((g_2dded0 - zap->tstart) * 10.0f);
        float alpha = D_002BFAA0[0] + fade * (D_002BFAA0[1] + fade * D_002BFAA0[2]);
        float low = g_2bbb60[0];
        float high = g_2bbb60[1];
        float clamped;
        if (alpha < low) {
            clamped = low;
        } else if (high < alpha) {
            clamped = high;
        } else {
            clamped = alpha;
        }
        float pulse = D_002BFAB0[0] + cosine * (D_002BFAB0[1] + cosine * D_002BFAB0[2]);
        if (pulse < g_2bbb60[0]) {
            pulse = g_2bbb60[0];
        } else if (g_2bbb60[1] < pulse) {
            pulse = g_2bbb60[1];
        }
        zap->jt->alpha = clamped * pulse;
    }
after:
    state = zap->state;
    if (state == -1)
        return;
    if (state != 7)
        return;
    QW vel = zap->jt->vt->fn((char *)zap->jt + zap->jt->vt->delta);
    float *v = (float *)&vel;
    float heading = atan2f(v[1], v[0]);
    float turn = RadSmooth(zap->jt->rad, heading + 3.1415927f, g_2dded0, (SMP *)D_002BFAC0, 0);
    SetStepRadTarget(zap->jt, turn);
    if (0.25f < g_2dded0 - zap->tstate) {
        if (zap->jt->landed != 0) {
            ZapContinue(zap);
            return;
        }
    }
    if (FJtStuck(zap->tstate, zap->jt, 0) != 0)
        ZapContinue(zap);
}
