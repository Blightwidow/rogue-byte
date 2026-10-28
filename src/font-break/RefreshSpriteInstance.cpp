#include "sly2.h"
struct AFF { float a, b, c, d, e, f, u6, u7; } __attribute__((aligned(16)));
struct RGBA4 { char b[4]; };
struct MOVIECHAR;
struct TMP { union { AFF dummy; struct { RGBA4 t0; char p0[12]; RGBA4 t1; char p1[12]; } c; } v; union { AFF lerped; struct { RGBA4 t2; char p2[12]; RGBA4 t3; } c; } u; };
struct SLOT {
    RGBA4 rgbaAdd; RGBA4 rgbaMul; char pad08[8];
    AFF xf;
    MOVIECHAR *pchar; int maskMode; float tFrom; RGBA4 rgbaAddFrom; RGBA4 rgbaMulFrom; AFF *pxfFrom;
    float tTo; RGBA4 rgbaAddTo; RGBA4 rgbaMulTo; AFF *pxfTo; int iinst; float tUpdated;
    unsigned char fTween; char pad61[0x68 - 0x61]; void *pslNext; char pad6c[4];
};
struct INST { int cslot; SLOT *aslot; short ilabel; short ikeyNext; float t; int fPaused; int pamb; };
struct SPRITE { char pad0[8]; INST *insts; };
struct LABEL { char pad0[0x10]; SPRITE *psprite; };
extern "C" void ClearSle(void *);
extern "C" void CombineColorTransforms(RGBA4 *, RGBA4 *, RGBA4 *, RGBA4 *, RGBA4 *, RGBA4 *);
extern "C" void func_00215850(MOVIECHAR *, SLOT *, float, AFF *, RGBA4 *, RGBA4 *);

static inline AFF Mult(const AFF &child, const AFF &parent)
{
    AFF product;
    float ca = child.a, cb = child.b, cc = child.c, cd = child.d, ce = child.e, cf = child.f;
    product.a = ca * parent.a + cb * parent.c;
    product.b = ca * parent.b + cb * parent.d;
    product.c = cc * parent.a + cd * parent.c;
    product.d = cc * parent.b + cd * parent.d;
    product.e = ce * parent.a + cf * parent.c + parent.e;
    product.f = ce * parent.b + cf * parent.d + parent.f;
    return product;
}
static inline float ItoF(int v) { float r; asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (r) : "r" (v)); return r; }
static inline unsigned char LerpByte(int from, int to, float u)
{
    if (from == to) return to;
    if (from < to) return from + (int)(u * (ItoF(to) + 0.999f - ItoF(from)));
    float inv = 1.0f - u;
    asm volatile("" : : "f" (inv));
    return to + (int)(inv * (ItoF(from) + 0.999f - ItoF(to)));
}
extern "C" void RefreshSpriteInstance(float dt, LABEL *label, int iinst, AFF *pxf, RGBA4 *prgbaAdd, RGBA4 *prgbaMul)
{
    INST *inst = (INST *)(iinst * sizeof(INST) + (unsigned)label->psprite->insts);
    SLOT *aslot = inst->aslot;
    int cslot = inst->cslot;
    float t = inst->t;
    for (int islot = 0; islot < cslot; islot++) {
        SLOT *slot = &aslot[islot];
        if (slot->pchar == 0) {
            slot->tUpdated = t;
            ClearSle(&slot->pslNext);
            continue;
        }
        AFF xf;
        RGBA4 outAdd, outMul;
        RGBA4 mulSlot, addSlot;
        TMP tmp;
        if (slot->fTween != 0 && slot->pxfTo != 0) {
            float u = (t - slot->tFrom) / (slot->tTo - slot->tFrom);
            const float *from = &slot->pxfFrom->a;
            const float *to = &slot->pxfTo->a;
            float *out = &tmp.u.lerped.a;
            for (int ig = 0; ig < 6; ig++) {
                out[ig] = (1.0f - u) * from[ig] + u * to[ig];
            }
            tmp.v.dummy = tmp.u.lerped;
            xf = tmp.u.lerped;
            tmp.v.c.t1 = slot->rgbaAddFrom;
            tmp.u.c.t2 = slot->rgbaAddTo;
            tmp.u.c.t3.b[0] = LerpByte((unsigned char)tmp.v.c.t1.b[0], (unsigned char)tmp.u.c.t2.b[0], u);
            tmp.u.c.t3.b[1] = LerpByte((unsigned char)tmp.v.c.t1.b[1], (unsigned char)tmp.u.c.t2.b[1], u);
            tmp.u.c.t3.b[2] = LerpByte((unsigned char)tmp.v.c.t1.b[2], (unsigned char)tmp.u.c.t2.b[2], u);
            tmp.u.c.t3.b[3] = LerpByte((unsigned char)tmp.v.c.t1.b[3], (unsigned char)tmp.u.c.t2.b[3], u);
            tmp.v.c.t0 = tmp.u.c.t3;
            addSlot = tmp.v.c.t0;
            tmp.v.c.t1 = slot->rgbaMulFrom;
            tmp.u.c.t2 = slot->rgbaMulTo;
            tmp.u.c.t3.b[0] = LerpByte((unsigned char)tmp.v.c.t1.b[0], (unsigned char)tmp.u.c.t2.b[0], u);
            tmp.u.c.t3.b[1] = LerpByte((unsigned char)tmp.v.c.t1.b[1], (unsigned char)tmp.u.c.t2.b[1], u);
            tmp.u.c.t3.b[2] = LerpByte((unsigned char)tmp.v.c.t1.b[2], (unsigned char)tmp.u.c.t2.b[2], u);
            tmp.u.c.t3.b[3] = LerpByte((unsigned char)tmp.v.c.t1.b[3], (unsigned char)tmp.u.c.t2.b[3], u);
            tmp.v.c.t0 = tmp.u.c.t3;
            mulSlot = tmp.v.c.t0;
        } else {
            xf = *slot->pxfFrom;
            addSlot = slot->rgbaAddFrom;
            mulSlot = slot->rgbaMulFrom;
        }
        tmp.u.lerped.a = xf.a * pxf->a + xf.b * pxf->c;
        tmp.u.lerped.b = xf.a * pxf->b + xf.b * pxf->d;
        tmp.u.lerped.c = xf.c * pxf->a + xf.d * pxf->c;
        tmp.u.lerped.d = xf.c * pxf->b + xf.d * pxf->d;
        tmp.u.lerped.e = xf.e * pxf->a + xf.f * pxf->c + pxf->e;
        tmp.u.lerped.f = xf.e * pxf->b + xf.f * pxf->d + pxf->f;
        tmp.v.dummy = tmp.u.lerped;
        xf = tmp.u.lerped;
        tmp.v.c.t0 = *prgbaMul;
        tmp.v.c.t1 = *prgbaAdd;
        tmp.u.c.t2 = mulSlot;
        tmp.u.c.t3 = addSlot;
        CombineColorTransforms(&tmp.v.c.t0, &tmp.v.c.t1, &tmp.u.c.t2, &tmp.u.c.t3, &outMul, &outAdd);
        if (slot->pchar != 0) {
            tmp.v.c.t0 = outAdd;
            tmp.v.c.t1 = outMul;
            func_00215850(slot->pchar, slot, dt, &xf, &tmp.v.c.t0, &tmp.v.c.t1);
        }
        slot->tUpdated = t;
        slot->xf = xf;
        slot->rgbaAdd = outAdd;
        slot->rgbaMul = outMul;
        ClearSle(&slot->pslNext);
    }
}
