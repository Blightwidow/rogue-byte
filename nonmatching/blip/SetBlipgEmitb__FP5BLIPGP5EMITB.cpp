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
static inline int FNear(float a, float b) { return FFloatsNear__Ffff(a, b, 1e-4f); }
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float Lane1(QW q) { float f; int t; asm("prot3w %1, %2\n\tmtc1 %1, %0" : "=f" (f), "=r" (t) : "r" (q)); return f; }
static inline float Lane2(QW q) { float f; asm("pextuw %0, $zero, %1" : "=r" (f) : "r" (q)); return f; }
extern "C" {
extern QW g_2a2dd0;
void PrescaleClq__FP3CLQffT0(CLQ *, float, float, CLQ *);
void PropagateBlipgShader__FP5BLIPG(BLIPG *, int);
void SetEmitdvEmitb__FP6EMITDVP5EMITB(EMITDV *, EMITB *);
void SetBlipgEmitb__FP5BLIPGP5EMITB(BLIPG *self, EMITB *pemitb)
{
    CLQ *pclqA = &self->clqA;
    CLQ *pclqD = &self->clqD;
    EMITDV *pdv = pdv;
    int mode = pemitb->mode;
    self->mode = mode;
    self->scale = mode == 1 ? pemitb->fF0 : 1.0f;
    int *pdata = pemitb->pdata;
    if (pdata != 0) {
        int count = *pdata;
        self->count = count;
        unsigned char *srcBase = (unsigned char *)(pdata + 1);
        unsigned char *dstBase = self->bytes;
        for (int index = 0; index < self->count; index++) {
            unsigned char *src = index * 4 + srcBase;
            unsigned char *dst = (self->count - index - 1) * 4 + dstBase;
            for (int lane = 0; lane < 4; lane++)
                *dst++ = (*src++ + 1) >> 1;
        }
        self->c8 = pemitb->c8;
    }
    PropagateBlipgShader__FP5BLIPG(self, pemitb->shader);
    memset(self->zero, 0, 0x10);
    if (self->nSamples >= 2) {
        float dtScale = pemitb->fD8;
        float fCount;
        if (dtScale != 0.0f) {
            fCount = (float)self->nSamples;
        } else {
            dtScale = pemitb->dt;
            fCount = (float)self->nSamples;
        }
        self->zero[1] = fCount / dtScale;
    }
    PrescaleClq__FP3CLQffT0(&pemitb->clqB, 1.0f / pemitb->dt, 0.0f, &self->clqC);
    PrescaleClq__FP3CLQffT0(&pemitb->clqE, 1.0f / pemitb->dt, 0.0f, pclqA);
    float peak;
    if (self->clqA.c1 == 0.0f && self->clqA.c2 == 0.0f) {
        peak = __builtin_fabsf(self->clqA.c0);
    } else {
        float dt = pemitb->dt;
        float vals[3];
        vals[1] = 0.0f;
        vals[0] = self->clqA.c0;
        vals[2] = vals[0] + dt * (pclqA->c1 + dt * pclqA->c2);
        if (self->clqA.c2 != vals[1]) {
            float t = -self->clqA.c1 / (2.0f * self->clqA.c2);
            if (vals[1] < t && t < dt)
                vals[1] = vals[0] + t * (pclqA->c1 + t * pclqA->c2);
        }
        float a = __builtin_fabsf(vals[0]);
        float b = __builtin_fabsf(vals[1]);
        peak = __builtin_fabsf(vals[2]);
        if (b < a && peak < a)
            peak = a;
        else if (peak < b)
            peak = b;
    }
    self->peak = peak;
    int fIdentity = 0;
    self->clqD.c0 = 0.0f;
    pclqD->c2 = 0.0f;
    pclqD->c1 = 1.0f / pemitb->dt;
    int fStatic = pemitb->fStatic;
    self->fStatic = fStatic;
    if (fStatic == 0) {
        QW qa = pemitb->dir;
        QW qb = g_2a2dd0;
        int fNear = 0;
        if (FNear(Lane0(qb), Lane0(qa)) != 0 && FNear(Lane1(qb), Lane1(qa)) != 0)
            fNear = FNear(Lane2(qb), Lane2(qa)) != 0;
        if (fNear != 0 && pemitb->f58 == 0.0f && pemitb->f80 == 0.0f)
            fIdentity = 1;
    }
    if (fIdentity != 0)
        self->fStatic = 1;
    memset(pdv, 0, 0x30);
    if (self->fStatic == 0)
        SetEmitdvEmitb__FP6EMITDVP5EMITB(pdv, pemitb);
}
}
