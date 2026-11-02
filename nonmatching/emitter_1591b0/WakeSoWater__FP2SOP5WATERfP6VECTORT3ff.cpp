#include "sly2.h"
/* lane 0 of a QW into a float register */
static inline float Lane0(QW v) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (v)); return f; }
static inline float GClamp(float g, float lo, float hi)
{
    if (g < lo)
        return lo;
    if (hi < g)
        return hi;
    return g;
}
struct Emitrip { QW q[4]; };
struct Emitv { QW q[7]; };
union Work { int i[16]; float f[16]; QW q[4]; };
struct EmitvU { float f[4]; QW q1; QW q2; float g[16]; };
struct Frame {
    Emitrip ripArg;
    Work w;
    Emitv emitvArg;
    EmitvU ev;
    QW vCurrent;
};
struct SO { char pad[0xC]; char *vtable; };
struct RipVT { char pad[8]; short delta; short unused; void (*fn)(void *, QW, float, int); };
struct Rip { char pad[0xEC]; RipVT *vt; };
struct Puffer { char pad[0x170]; float tRipple; int amb; };
struct Water { char pad[0x18]; int oid; char pad2[0x15C]; int rip178; int rip17C; int f180; };
extern "C" {
extern float g_2dded0;
extern QW g_2a2dc0;
extern int D_002BDEB0[];
extern char B_003DD490[];
float GRandInRange(float, float);
int NRandInRange(int, int);
int FIsBasicDerivedFrom(void *, int);
void SetAmbVolume(int, float);
void StopAmb(int, float);
int NewEmitter(int);
void SetEmitterUnpositioned(int, void *);
void SetAmbRange(int, float, float);
void VirtualRefPtr_Assign(int *, int);
Rip *PripNewRipg(void *, int, int);
void EmitRipsSphere__FP6VECTORT0iP7EMITRIPP5EMITVPP4RIPGP2LO(QW, QW, int, void *, void *, void *, int, int);
void WakeSoWater__FP2SOP5WATERfP6VECTORT3ff(SO *pso, Water *pwater, float dt, QW vCurrent, QW posSurface, float dtWakeMin, float gScale)
{
    Frame f;
    int tokA;
    asm("qmtc2.ni %1, vf1" : "=r"(tokA) : "r"(vCurrent));
    short deltaV = *(short *)(pso->vtable + 0x108);
    QW (*fnV)(void *) = *(QW (**)(void *))(pso->vtable + 0x10C);
    asm("sqc2 vf1, %0" : "=m"(f.vCurrent) : "r"(tokA));
    QW vSo = fnV((char *)pso + deltaV);
    float vRelative;
    QW qRel;
    int tok1, tok2, tok3;
    asm("qmtc2.ni %1, vf2" : "=r"(tok1) : "r"(vSo));
    asm("lqc2 vf1, %1" : "=r"(tok2) : "m"(f.vCurrent), "r"(tok1));
    asm("vsub.xyzw vf1, vf1, vf2" : "=r"(tok3) : "r"(tok2));
    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(qRel) : "r"(tok3));
    vRelative = Lane0(qRel);
    float gWakeInterval = GRandInRange(0.0f, 3.0f);
    int fLate = gWakeInterval < dt;
    Puffer *ppuffer = FIsBasicDerivedFrom(pso, 0x32) ? (Puffer *)pso : 0;
    if (10.0f < vRelative || fLate != 0) {
    float gWake = GClamp((vRelative - 10.0f) * 0.0012658228f, 0.0f, 1.0f);
    if (ppuffer != 0 && pwater->f180 != 0) {
        int *pamb = &ppuffer->amb;
        float volume = gWake * 0.9f + 0.1f;
        if (*pamb != 0) {
            SetAmbVolume(*pamb, volume);
        } else {
            int amb = NewEmitter(D_002BDEB0[NRandInRange(0, 3)]);
            SetEmitterUnpositioned(amb, ppuffer);
            SetAmbRange(amb, 100.0f, 1000.0f);
            SetAmbVolume(amb, volume);
            VirtualRefPtr_Assign(pamb, amb);
        }
    }
    if (!fLate) {
        float dtInterval = 1.0f - gWake * (1.0f - dtWakeMin);
        if (ppuffer != 0) {
            fLate = dtInterval < g_2dded0 - ppuffer->tRipple;
        } else {
            int iA = (int)(g_2dded0 / dtInterval);
            int iB = (int)((g_2dded0 + dt) / dtInterval);
            fLate = iA != iB;
        }
        if (!fLate)
            return;
    }
    if (pwater->rip17C == 0)
        return;
    Rip *prip = PripNewRipg(B_003DD490, 7, 0);
    if (prip == 0)
        return;
    prip->vt->fn((char *)prip + prip->vt->delta, posSurface, gScale, 0);
    *(float *)((char *)prip + 0x20) = gScale;
    *(float *)((char *)prip + 0x24) = gScale * 0.6f;
    *(int *)((char *)prip + 0x1C) = pwater->rip17C;
    if (ppuffer != 0)
        ppuffer->tRipple = g_2dded0;
    if (500.0f < vRelative && pwater->rip178 != 0) {
        memset(&f.w, 0, 0x40);
        f.w.i[0] = 1;
        f.w.i[2] = *(int *)(pwater->rip178 + 0x18);
        f.w.i[3] = *(int *)(pwater->rip17C + 0x18);
        f.w.i[4] = pwater->oid;
        f.w.f[6] = 8.0f;
        f.w.f[7] = 12.0f;
        f.w.f[8] = 1.0f;
        f.ripArg = *(Emitrip *)&f.w;
        memset(&f.ev, 0, 0x70);
        f.ev.f[0] = vRelative * 0.5f;
        f.ev.f[1] = vRelative * 0.75f;
        f.ev.f[3] = 1.0f;
        f.ev.q1 = *(QW *)(*(char **)((char *)pso + 0xE8) + 0x80);
        f.ev.q2 = g_2a2dc0;
        f.ev.g[4] = 0.3926991f;
        f.ev.g[5] = 1.0471976f;
        f.ev.g[12] = 1.0f;
        f.ev.g[3] = 5.0f;
        f.ev.g[2] = 1.0f;
        f.ev.g[14] = -1.0f;
        f.emitvArg = *(Emitv *)&f.ev;
        memset(&f.w, 0, 0x14);
        f.w.q[2] = posSurface;
        f.w.f[10] = f.w.f[10] + 30.0f;
        QW posDroplet = f.w.q[2];
        QW up = g_2a2dc0;
        f.w.i[2] = pwater->rip178;
        f.w.i[3] = pwater->rip17C;
        f.w.i[4] = (int)pwater;
        int c = NRandInRange(4, 6);
        EmitRipsSphere__FP6VECTORT0iP7EMITRIPP5EMITVPP4RIPGP2LO(posDroplet, up, c, &f.ripArg, &f.emitvArg, &f.w, 0, 0);
    }
    } else {
        if (ppuffer != 0) {
            int *pamb = &ppuffer->amb;
            if (pamb != 0 && *pamb != 0) {
                StopAmb(*pamb, 0.0f);
                VirtualRefPtr_Assign(pamb, 0);
            }
        }
    }
}
}
