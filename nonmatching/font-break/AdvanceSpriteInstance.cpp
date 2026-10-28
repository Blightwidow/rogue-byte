#include "sly2.h"
struct AFF { float a, b, c, d, e, f, u6, u7; } __attribute__((aligned(16)));
struct RGBA4 { char b[4]; };
struct MOVIECHAR;
struct P16 { RGBA4 v; char pad[12]; };
struct TMP { union { AFF dummy; struct { RGBA4 t0; char p0[12]; RGBA4 t1; char p1[12]; } c; } v; union { AFF lerped; struct { RGBA4 t2; char p2[12]; RGBA4 t3; } c; } u; };
struct FRAME { AFF xf; P16 outAdd, outMul, s40, s50, s60; TMP tmp; };
struct SLOT {
    RGBA4 rgbaAdd; RGBA4 rgbaMul; char pad08[8];
    AFF xf;
    MOVIECHAR *pchar; int maskMode; float tFrom; RGBA4 rgbaAddFrom; RGBA4 rgbaMulFrom; AFF *pxfFrom;
    float tTo; RGBA4 rgbaAddTo; RGBA4 rgbaMulTo; AFF *pxfTo; int iinst; float tUpdated;
    unsigned char fTween; char pad61[0x68 - 0x61]; void *pslNext; char pad6c[4];
};
struct INST { int cslot; SLOT *aslot; short ilabel; short ikeyNext; float t; int fPaused; int pamb; };
struct SPRITE { char pad0[8]; INST *insts; };
struct KEY { float t; char pad[0x1C]; };
struct LABEL { unsigned short ckey; char pad2[2]; KEY *akey; char pad0[8]; SPRITE *psprite; };
extern "C" void ClearSle(void *);
extern "C" void ApplySpriteKeySounds(LABEL *, int, int);
extern "C" void func_002190F8(LABEL *, int, int);
extern "C" void ClearSpriteKeySlots(LABEL *, int, int);
extern "C" void PlaceSpriteKeyCharacters(float, float, LABEL *, int, int, AFF *, RGBA4 *, RGBA4 *);
extern "C" void func_002158C0(MOVIECHAR *, SLOT *);
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
extern "C" void AdvanceSpriteInstance(float dt, LABEL *label, int iinst, AFF *pxf, RGBA4 *prgbaAdd, RGBA4 *prgbaMul)
{
    FRAME fr;
    INST *inst = (INST *)(iinst * sizeof(INST) + (unsigned)label->psprite->insts);
    int cslot;
    SLOT *aslot = inst->aslot;
    cslot = inst->cslot;
    float tNow = inst->t;
    int ikey = (unsigned short)inst->ikeyNext;
    int firstPass = (ikey == 0);
    float tLast = tNow;
    do {
        if (ikey < label->ckey) {
            KEY *key = &label->akey[ikey];
            float tKey = key->t;
            if (tKey <= tNow) {
                tLast = tKey;
                ApplySpriteKeySounds(label, ikey, iinst);
                func_002190F8(label, ikey, iinst);
                ClearSpriteKeySlots(label, ikey, iinst);
                fr.s40.v = *prgbaAdd;
                fr.s50.v = *prgbaMul;
                PlaceSpriteKeyCharacters(tKey, dt, label, ikey, iinst, pxf, &fr.s40.v, &fr.s50.v);
                ikey++;
                inst = (INST *)(iinst * sizeof(INST) + (unsigned)label->psprite->insts);
                inst->ikeyNext = inst->ikeyNext + 1;
                inst = (INST *)(iinst * sizeof(INST) + (unsigned)label->psprite->insts);
                if (label->ckey < (unsigned short)inst->ikeyNext) {
                    inst->ikeyNext = label->ckey;
                }
            }
        }
        for (int islot = 0; islot < cslot; islot++) {
            SLOT *slot = &aslot[islot];
            if (slot->pchar == 0 || slot->tUpdated == tLast) continue;
            if (firstPass) {
                func_002158C0(slot->pchar, slot);
                continue;
            }
            if (slot->fTween != 0 && slot->pxfTo != 0) {
                float u = (tLast - slot->tFrom) / (slot->tTo - slot->tFrom);
                const float *from = &slot->pxfFrom->a;
                const float *to = &slot->pxfTo->a;
                float *out = &fr.tmp.u.lerped.a;
                for (int ig = 0; ig < 6; ig++) {
                    out[ig] = (1.0f - u) * from[ig] + u * to[ig];
                }
                fr.tmp.v.dummy = fr.tmp.u.lerped;
                fr.xf = fr.tmp.u.lerped;
                fr.tmp.v.c.t1 = slot->rgbaAddFrom;
                fr.tmp.u.c.t2 = slot->rgbaAddTo;
                fr.tmp.u.c.t3.b[0] = LerpByte((unsigned char)fr.tmp.v.c.t1.b[0], (unsigned char)fr.tmp.u.c.t2.b[0], u);
                fr.tmp.u.c.t3.b[1] = LerpByte((unsigned char)fr.tmp.v.c.t1.b[1], (unsigned char)fr.tmp.u.c.t2.b[1], u);
                fr.tmp.u.c.t3.b[2] = LerpByte((unsigned char)fr.tmp.v.c.t1.b[2], (unsigned char)fr.tmp.u.c.t2.b[2], u);
                fr.tmp.u.c.t3.b[3] = LerpByte((unsigned char)fr.tmp.v.c.t1.b[3], (unsigned char)fr.tmp.u.c.t2.b[3], u);
                fr.tmp.v.c.t0 = fr.tmp.u.c.t3;
                fr.s40.v = fr.tmp.v.c.t0;
                fr.tmp.v.c.t1 = slot->rgbaMulFrom;
                fr.tmp.u.c.t2 = slot->rgbaMulTo;
                fr.tmp.u.c.t3.b[0] = LerpByte((unsigned char)fr.tmp.v.c.t1.b[0], (unsigned char)fr.tmp.u.c.t2.b[0], u);
                fr.tmp.u.c.t3.b[1] = LerpByte((unsigned char)fr.tmp.v.c.t1.b[1], (unsigned char)fr.tmp.u.c.t2.b[1], u);
                fr.tmp.u.c.t3.b[2] = LerpByte((unsigned char)fr.tmp.v.c.t1.b[2], (unsigned char)fr.tmp.u.c.t2.b[2], u);
                fr.tmp.u.c.t3.b[3] = LerpByte((unsigned char)fr.tmp.v.c.t1.b[3], (unsigned char)fr.tmp.u.c.t2.b[3], u);
                fr.tmp.v.c.t0 = fr.tmp.u.c.t3;
                fr.s60.v = fr.tmp.v.c.t0;
            } else {
                fr.xf = *slot->pxfFrom;
                fr.s40.v = slot->rgbaAddFrom;
                fr.s60.v = slot->rgbaMulFrom;
            }
            fr.tmp.u.lerped.a = fr.xf.a * pxf->a + fr.xf.b * pxf->c;
            fr.tmp.u.lerped.b = fr.xf.a * pxf->b + fr.xf.b * pxf->d;
            fr.tmp.u.lerped.c = fr.xf.c * pxf->a + fr.xf.d * pxf->c;
            fr.tmp.u.lerped.d = fr.xf.c * pxf->b + fr.xf.d * pxf->d;
            fr.tmp.u.lerped.e = fr.xf.e * pxf->a + fr.xf.f * pxf->c + pxf->e;
            fr.tmp.u.lerped.f = fr.xf.e * pxf->b + fr.xf.f * pxf->d + pxf->f;
            fr.tmp.v.dummy = fr.tmp.u.lerped;
            fr.xf = fr.tmp.u.lerped;
            fr.tmp.v.c.t0 = *prgbaMul;
            fr.tmp.v.c.t1 = *prgbaAdd;
            fr.tmp.u.c.t2 = fr.s60.v;
            fr.tmp.u.c.t3 = fr.s40.v;
            CombineColorTransforms(&fr.tmp.v.c.t0, &fr.tmp.v.c.t1, &fr.tmp.u.c.t2, &fr.tmp.u.c.t3, &fr.outMul.v, &fr.outAdd.v);
            fr.tmp.v.c.t0 = fr.outAdd.v;
            fr.tmp.v.c.t1 = fr.outMul.v;
            func_00215850(slot->pchar, slot, dt, &fr.xf, &fr.tmp.v.c.t0, &fr.tmp.v.c.t1);
            slot->tUpdated = tLast;
            slot->xf = fr.xf;
            slot->rgbaAdd = fr.outAdd.v;
            slot->rgbaMul = fr.outMul.v;
            ClearSle(&slot->pslNext);
        }
        firstPass = 0;
    } while (ikey < label->ckey && label->akey[ikey].t <= tNow);
}
