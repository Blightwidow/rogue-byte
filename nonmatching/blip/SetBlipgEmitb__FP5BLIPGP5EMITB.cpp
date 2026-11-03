#include "sly2.h"
struct CLQ { float c0, c1, c2; };
struct EMITB {
    char pad0[0x58]; float f58; char pad1[0x60 - 0x5C]; QW dir; char pad2[0x80 - 0x70]; float f80; char pad3[0x8C - 0x84]; float dt;
    char pad4[0xB0 - 0x90]; CLQ clqB; char pad5[0xC0 - 0xBC]; int mode; int fStatic; char pad6[0xCC - 0xC8]; int c8; int shader;
    char pad7[0xD8 - 0xD4]; float fD8; int *pdata; CLQ clqE; char pad8[0xF0 - 0xEC]; float fF0;
};
struct EMITDV { char pad[0x30]; };
struct BLIPG {
    char pad0[0x110]; CLQ clqA; char pad1[0x120 - 0x11C]; float peak; char pad2[0x130 - 0x124]; CLQ clqC; char pad3[0x140 - 0x13C]; float zero[4];
    CLQ clqD; char pad4[0x160 - 0x15C]; int fStatic; char pad5[0x170 - 0x164]; EMITDV dv;
    int nSamples; char pad6[0x3B0 - 0x1A4]; int count; unsigned char bytes[0x80]; int c8; char pad7[0x43C - 0x438]; int mode; float scale;
};
extern "C" int FFloatsNear__Ffff(float, float, float);
// lane 0 of a QW into a float (mtc1)
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
// lane 1 rotated to lane 0 (prot3w)
static inline QW Rot1(QW q) { QW r; asm("prot3w %0, %1" : "=r"(r) : "r"(q)); return r; }
// lane 2 moved to lane 0 (pextuw)
static inline QW Rot2(QW q) { QW r; asm("pextuw %0, $zero, %1" : "=r"(r) : "r"(q)); return r; }
static inline QW Rot1Into(QW q, QW prev) { QW t; asm("prot3w %0, %1" : "=r"(t) : "r"(q), "0"(prev)); return t; }
static inline QW Rot2Into(QW q, QW prev) { QW t; asm("pextuw %0, $zero, %1" : "=r"(t) : "r"(q), "0"(prev)); return t; }
static inline float EvalClq(CLQ *pclq, float c0, float t) { return c0 + t * (pclq->c1 + t * pclq->c2); }
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
extern "C" {
extern QW g_2a2dd0;
void PrescaleClq__FP3CLQffT0(CLQ *, float, float, CLQ *);
void PropagateBlipgShader__FP5BLIPG(BLIPG *, int);
void SetEmitdvEmitb__FP6EMITDVP5EMITB(EMITDV *, EMITB *);
void SetBlipgEmitb__FP5BLIPGP5EMITB(BLIPG *pblipg, EMITB *pemitb)
{
    float scale = 1.0f;
    int mode = pemitb->mode;
    pblipg->mode = mode;
    if (mode == 1)
        scale = pemitb->fF0;
    pblipg->scale = scale;
    float *pzero = pblipg->zero;
    CLQ *pclqB = &pemitb->clqB;
    CLQ *pclqC = &pblipg->clqC;
    CLQ *pclqE = &pemitb->clqE;
    CLQ *pclqA = &pblipg->clqA;
    CLQ *pclqD = &pblipg->clqD;
    EMITDV *pdv = &pblipg->dv;
    int *pdata = pemitb->pdata;
    if (pdata != 0) {
        pblipg->count = *pdata;
        for (int index = 0; index < pblipg->count; index++) {
            unsigned char *srcBase = (unsigned char *)(pdata + 1);
            unsigned char *dstBase = pblipg->bytes;
            unsigned char *src = srcBase + index * 4;
            unsigned char *dst = dstBase + (pblipg->count - index - 1) * 4;
            for (int lane = 3; lane >= 0; lane--)
                *dst++ = (*src++ + 1) >> 1;
        }
        pblipg->c8 = pemitb->c8;
    }
    PropagateBlipgShader__FP5BLIPG(pblipg, pemitb->shader);
    memset(pzero, 0, 0x10);
    if (pblipg->nSamples >= 2) {
        float dtSample = pemitb->fD8;
        float cSamples;
        if (dtSample != 0.0f) {
            cSamples = (float)pblipg->nSamples;
        } else {
            dtSample = pemitb->dt;
            cSamples = (float)pblipg->nSamples;
        }
        pblipg->zero[1] = cSamples / dtSample;
    }
    PrescaleClq__FP3CLQffT0(pclqB, 1.0f / pemitb->dt, 0.0f, pclqC);
    PrescaleClq__FP3CLQffT0(pclqE, 1.0f / pemitb->dt, 0.0f, pclqA);
    float peak;
    if (pblipg->clqA.c1 == 0.0f && pblipg->clqA.c2 == 0.0f) {
        peak = __builtin_fabsf(pblipg->clqA.c0);
    } else {
        float dt = pemitb->dt;
        float vals[3];
        vals[1] = 0.0f;
        vals[0] = pblipg->clqA.c0;
        vals[2] = EvalClq(pclqA, vals[0], dt);
        if (pblipg->clqA.c2 != vals[1]) {
            float t = -pblipg->clqA.c1 / (2.0f * pblipg->clqA.c2);
            if (vals[1] < t && t < dt)
                vals[1] = EvalClq(pclqA, vals[0], t);
        }
        float a = __builtin_fabsf(vals[0]);
        float b = __builtin_fabsf(vals[1]);
        peak = __builtin_fabsf(vals[2]);
        if (b < a && peak < a)
            peak = a;
        else if (peak < b)
            peak = b;
    }
    pblipg->peak = peak;
    float dtD = pemitb->dt;
    int fIdentity = 0;
    pblipg->clqD.c0 = 0.0f;
    pclqD->c2 = 0.0f;
    pclqD->c1 = 1.0f / dtD;
    int fStatic = pemitb->fStatic;
    pblipg->fStatic = fStatic;
    if (fStatic == 0) {
        QW dir = pemitb->dir;
        QW origin = g_2a2dd0;
        int fNear = 0;
        if (Near(Lane0(origin), Lane0(dir))) {
            QW ty = Rot1(origin);
            float oy = Lane0(ty);
            if (Near(oy, Lane0(Rot1Into(dir, ty)))) {
                QW tz = Rot2(origin);
                float oz = Lane0(tz);
                fNear = Near(oz, Lane0(Rot2Into(dir, tz))) != 0;
            }
        }
        if (fNear != 0 && pemitb->f58 == 0.0f && pemitb->f80 == 0.0f)
            fIdentity = 1;
    }
    if (fIdentity != 0)
        pblipg->fStatic = 1;
    memset(pdv, 0, 0x30);
    if (pblipg->fStatic == 0)
        SetEmitdvEmitb__FP6EMITDVP5EMITB(pdv, pemitb);
}
}
