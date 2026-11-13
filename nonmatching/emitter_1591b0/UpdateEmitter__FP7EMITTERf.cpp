// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"

struct DL;
struct CM {
    char pad0[0x1C];
    float scale;     /* scales a source's radius into the camera's audible range */
    char pad20[0x90 - 0x20];
    QW pos;          /* the camera's position */
};
struct SRC_159C80 {  /* an object in the emitter's source list */
    char pad0[0x10];
    void *psoParent;
    char pad14[0x38 - 0x14];
    float radius;
    char pad3C[0x128 - 0x3C];
    SRC_159C80 *pNext;
};
struct EMITHOLD_159C80 {
    void *pemitterOwner;
    int c;
};
struct EMITB {
    char pad0[4];
    int fPerSource;
    EMITHOLD_159C80 *phold;
};
struct EMITG {
    void *p150;
    void *p14C;
    void *pemitter;
};
struct EMITTER {
    char pad0[0x10];
    void *psoParent;
    char pad14[0x38 - 0x14];
    float radius;
    char pad3C[0xE0 - 0x3C];
    int fValuesChanged;
    EMITB *pemitb;
    char padE8[0xF0 - 0xE8];
    int emitk;
    int cParticlesLeft;
    float tPauseMin;
    float tPauseMax;
    char pad100[0x104 - 0x100];
    float uPause;
    float dtPauseMin;
    float dtPauseMax;
    float cMax;
    int fPauseIndefinite;
    int stateOn;
    SRC_159C80 *psrcFirst;  /* the source list (a DL) */
    char pad120[0x130 - 0x120];
    float rate;
    float dtReset;
    float tReset;
    float svRate;
    char pad140[0x144 - 0x140];
    float fracParticles;
    char pad148[0x14C - 0x148];
    char *pv14C;
    char *p150;
};
struct CLOCK_159C80 { float t; float dt; };

extern "C" {
void OnEmitterValuesChanged__FP7EMITTER(EMITTER *);
void PauseEmitterIndefinite__FP7EMITTER(EMITTER *);
void PauseEmitter__FP7EMITTERf(EMITTER *, float);
int FPausedEmitter__FP7EMITTER(EMITTER *);
void ModifyEmitterParticles__FP7EMITTER(EMITTER *);
void EmitParticles__FiP5EMITBP5EMITG(int, EMITB *, EMITG *);
void UpdateLo(void *);
QW PosLoWorld(void *);
int FIsLoInWorld(void *);
int FIsDlEmpty__FP2DL(void *);
int CPvDl__FP2DL(void *);
float GRandInRange(float, float);
extern CM B_002DDF40;
extern CLOCK_159C80 g_2dded0;
}

extern "C" void UpdateEmitter__FP7EMITTERf(EMITTER *pemitter, float dt)
{
    if (pemitter->fValuesChanged)
        OnEmitterValuesChanged__FP7EMITTER(pemitter);
    UpdateLo(pemitter);
    if (pemitter->stateOn != -1)
        return;
    if (!FIsDlEmpty__FP2DL(&pemitter->psrcFirst)) {
        SRC_159C80 *psrc;
        for (psrc = pemitter->psrcFirst; psrc; psrc = psrc->pNext) {
            if (!FIsLoInWorld(psrc))
                continue;
            if (!psrc->psoParent)
                goto LActive;
            float radius = psrc->radius * B_002DDF40.scale;
            QW delta = VectorSub(PosLoWorld(psrc), B_002DDF40.pos);
            int fNear = LaneX(SquaredLength(delta)) < radius * radius;
            if (fNear)
                goto LActive;
        }
        return;
    } else if (pemitter->psoParent) {
        float radius = pemitter->radius * B_002DDF40.scale;
        QW delta = VectorSub(PosLoWorld(pemitter), B_002DDF40.pos);
        int fFar = radius * radius < LaneX(SquaredLength(delta));
        if (fFar)
            return;
    }
LActive:
    if (FPausedEmitter__FP7EMITTER(pemitter))
        return;
    int cParticles = 0;
    switch (pemitter->emitk) {
    case 3: {
        float c = pemitter->fracParticles + pemitter->rate * pemitter->svRate * g_2dded0.dt;
        cParticles = (int)c;
        pemitter->fracParticles = c - cParticles;
        if (cParticles > 1.0f) {
            int cLeft = pemitter->cParticlesLeft;
            if (cLeft >= 0) {
                if (cParticles >= cLeft)
                    cParticles = cLeft;
                pemitter->cParticlesLeft = cLeft - cParticles;
            }
            if (pemitter->fPauseIndefinite) {
                PauseEmitterIndefinite__FP7EMITTER(pemitter);
                pemitter->rate = GRandInRange(pemitter->tPauseMin, pemitter->tPauseMax) * 60.0f;
            } else if (GRandInRange(0.0f, 1.0f) <= pemitter->uPause) {
                PauseEmitter__FP7EMITTERf(pemitter, GRandInRange(pemitter->dtPauseMin, pemitter->dtPauseMax));
                pemitter->rate = GRandInRange(pemitter->tPauseMin, pemitter->tPauseMax) * 60.0f;
            }
        }
        break;
    }
    case 2: {
        int cLeft = pemitter->cParticlesLeft;
        cParticles = (int)pemitter->rate;
        if (cLeft >= 0) {
            if (cParticles >= cLeft)
                cParticles = cLeft;
            pemitter->cParticlesLeft = cLeft - cParticles;
        }
        if (pemitter->fPauseIndefinite)
            PauseEmitterIndefinite__FP7EMITTER(pemitter);
        else if (GRandInRange(0.0f, 1.0f) <= pemitter->uPause)
            PauseEmitter__FP7EMITTERf(pemitter, GRandInRange(pemitter->dtPauseMin, pemitter->dtPauseMax));
        pemitter->rate = GRandInRange(pemitter->tPauseMin, pemitter->tPauseMax);
        break;
    }
    case 0: {
        float c = pemitter->fracParticles + pemitter->rate * pemitter->svRate * g_2dded0.dt;
        cParticles = (int)c;
        pemitter->fracParticles = c - cParticles;
        if (cParticles) {
            int cLeft = pemitter->cParticlesLeft;
            if (cLeft >= 0) {
                if (cParticles >= cLeft)
                    cParticles = cLeft;
                pemitter->cParticlesLeft = cLeft - cParticles;
            }
        }
        break;
    }
    case 1: {
        int cWanted = (int)(pemitter->cMax * pemitter->svRate);
        int cExisting;
        if (!pemitter->pemitb->fPerSource) {
            char *p = pemitter->p150;
            cExisting = p ? *(int *)(p + 0x444) : 0;
        } else {
            char *pv = pemitter->pv14C;
            cExisting = pv ? CPvDl__FP2DL(pv + 0x15C) : 0;
        }
        int cMissing = cWanted - cExisting;
        if (cMissing > 0)
            cParticles = cMissing;
        else
            cParticles = 0;
        break;
    }
    }
    if (cParticles) {
        VECTOR posEmit;
        EMITG emitg;
        memset(&emitg, 0, sizeof(emitg));
        emitg.pemitter = pemitter;
        emitg.p150 = &pemitter->p150;
        emitg.p14C = &pemitter->pv14C;
        EMITHOLD_159C80 *phold = pemitter->pemitb->phold;
        void *pemitterOwner = phold->pemitterOwner;
        if (!pemitterOwner && !phold->c)
            phold->pemitterOwner = pemitter;
        EmitParticles__FiP5EMITBP5EMITG(cParticles, pemitter->pemitb, &emitg);
        pemitter->pemitb->phold->pemitterOwner = pemitterOwner;
    }
    if (g_2dded0.t >= pemitter->tReset) {
        pemitter->rate = GRandInRange(pemitter->tPauseMin, pemitter->tPauseMax);
        pemitter->tReset = g_2dded0.t + pemitter->dtReset;
    }
    ModifyEmitterParticles__FP7EMITTER(pemitter);
}
