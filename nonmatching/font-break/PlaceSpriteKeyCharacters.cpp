#include "sly2.h"
extern "C" void *MemsetPlain(void *, int, unsigned int) __asm__("memset");
struct AFF { float a, b, c, d, e, f, u6, u7; } __attribute__((aligned(16)));
struct RGBA4 { char b[4]; };
struct MOVIECHAR { unsigned id; };
struct LM { float lo; float hi; };
struct SLOT {
    RGBA4 rgbaAdd; RGBA4 rgbaMul; char pad08[8];
    AFF xf;
    MOVIECHAR *pchar; int maskMode; float tFrom; RGBA4 rgbaAddFrom; RGBA4 rgbaMulFrom; AFF *pxfFrom;
    float tTo; RGBA4 rgbaAddTo; RGBA4 rgbaMulTo; AFF *pxfTo; int iinst; float tUpdated;
    unsigned char fTween; unsigned char bAlpha; char pad62[2]; int idDepth; void *pslNext; char pad6c[4];
};
struct INST { int cslot; SLOT *aslot; short ilabel; short ikeyNext; float t; int fPaused; int pamb; };
struct SPRITE { char pad0[8]; INST *insts; };
struct KEYCOLOR { RGBA4 mul; RGBA4 add; };
struct PLACE {
    unsigned short idChar; unsigned short islot; unsigned short cmask; short icolor; char pad8[8];
    AFF xf; unsigned char fTween; unsigned char bAlpha; char pad32[2]; int idDepth; char pad38[8];
};
struct KEY { float t; unsigned char cplace; char pad5[7]; PLACE *aplace; KEYCOLOR *acolor; char pad14[0xC]; };
struct LABEL { unsigned short ckey; char pad2[2]; KEY *akey; char pad8[4]; char *pmovie; SPRITE *psprite; };
struct P16 { RGBA4 v; char pad[12]; };
struct TMP {
    union { AFF dummy; struct { RGBA4 t0; char p0[12]; RGBA4 t1; char p1[12]; } c; } v;
    union { AFF prod; struct { RGBA4 t2; char p2[12]; RGBA4 t3; char p3[12]; } c; } w;
    union { AFF lerped; RGBA4 lo; } x;
};
struct FRAME { AFF xf; P16 outAdd, outMul, s40, s50; TMP tmp; };
extern "C" void ClearSle(void *);
extern "C" void CombineColorTransforms(RGBA4 *, RGBA4 *, RGBA4 *, RGBA4 *, RGBA4 *, RGBA4 *);
extern "C" void func_00215850(MOVIECHAR *, SLOT *, float, AFF *, RGBA4 *, RGBA4 *);
extern "C" void func_00215730(MOVIECHAR *, SLOT *, AFF *, RGBA4 *, RGBA4 *);
extern "C" void func_002158C0(MOVIECHAR *, SLOT *);
float GLimitLm(LM *, float);

static inline float ItoF(int v) { float r; asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (r) : "r" (v)); return r; }
static inline unsigned char LerpByte(int from, int to, float u)
{
    if (from == to) return to;
    if (from < to) return from + (int)(u * (ItoF(to) + 0.999f - ItoF(from)));
    float inv = 1.0f - u;
    asm volatile("" : : "f" (inv));
    return to + (int)(inv * (ItoF(from) + 0.999f - ItoF(to)));
}
extern "C" void PlaceSpriteKeyCharacters(float tKey, float gAdvance, LABEL *label, int ikey, int iinst, AFF *pxf, RGBA4 *prgbaAdd, RGBA4 *prgbaMul)
{
    FRAME fr;
    SLOT *aslot;
    KEY *pkey = &label->akey[ikey];
    aslot = (label->psprite->insts + iinst)->aslot;
    if (pkey->cplace == 0) return;
    unsigned defAdd = 0x7F7F7F7F;
    unsigned defMul = 0xFFFFFFFF;
    int iplace = 0;
    do {
        PLACE *pplace = &pkey->aplace[iplace];
        int islot = pplace->islot;
        int cmask = pplace->cmask;
        int idChar = pplace->idChar;
        SLOT *slot = &aslot[islot];
        KEYCOLOR *pcolor = 0;
        if (pplace->icolor >= 0) pcolor = pkey->acolor + pplace->icolor;
        *(unsigned *)&fr.s40.v = *(unsigned *)&slot->rgbaAddFrom = defAdd;
        *(unsigned *)&fr.s50.v = *(unsigned *)&slot->rgbaMulFrom = defMul;
        if (pcolor) {
            fr.s40.v = slot->rgbaAddFrom = pcolor->add;
            fr.s50.v = slot->rgbaMulFrom = pcolor->mul;
        }
        slot->pxfFrom = &pplace->xf;
        slot->pxfTo = 0;
        slot->tFrom = pkey->t;
        slot->tTo = 0.0f;
        if (pplace->fTween != 0) {
            int ikeyNext = ikey + 1;
            if (ikeyNext < label->ckey) {
                do {
                    KEY *pkeyNext = &label->akey[ikeyNext];
                    if (pkeyNext->cplace != 0) {
                        int iplaceNext = 0;
                        do {
                            PLACE *pplaceNext = &pkeyNext->aplace[iplaceNext];
                            if (pplaceNext->islot == islot) {
                                slot->pxfTo = &pplaceNext->xf;
                                slot->tTo = pkeyNext->t;
                                if (pplaceNext->icolor >= 0) {
                                    KEYCOLOR *pcolorNext = pkeyNext->acolor + pplaceNext->icolor;
                                    slot->rgbaAddTo = pcolorNext->add;
                                    slot->rgbaMulTo = pcolorNext->mul;
                                } else {
                                    slot->rgbaAddTo = slot->rgbaAddFrom;
                                    slot->rgbaMulTo = slot->rgbaMulFrom;
                                }
                                break;
                            }
                        } while (++iplaceNext < pkeyNext->cplace);
                    }
                } while (++ikeyNext < label->ckey && slot->pxfTo == 0);
            }
        }
        if (pplace->fTween != 0 && slot->pxfTo != 0 && slot->tFrom < slot->tTo) {
            MemsetPlain(&fr.tmp.v.c.t1, 0, 8);
            ((float *)&fr.tmp.v.c.t1)[0] = slot->tFrom;
            ((float *)&fr.tmp.v.c.t1)[1] = slot->tTo;
            *(LM *)&fr.tmp.v.c.t0 = *(LM *)&fr.tmp.v.c.t1;
            float u = (GLimitLm((LM *)&fr.tmp.v.c.t0, gAdvance) - slot->tFrom) / (slot->tTo - slot->tFrom);
            const float *from = &slot->pxfFrom->a;
            const float *to = &slot->pxfTo->a;
            float *out = &fr.tmp.x.lerped.a;
            for (int ig = 0; ig < 6; ig++) {
                out[ig] = (1.0f - u) * from[ig] + u * to[ig];
            }
            fr.tmp.w.prod = fr.tmp.x.lerped;
            fr.xf = fr.tmp.x.lerped;
            fr.tmp.w.c.t2 = slot->rgbaAddFrom;
            fr.tmp.w.c.t3 = slot->rgbaAddTo;
            fr.tmp.x.lo.b[0] = LerpByte((unsigned char)fr.tmp.w.c.t2.b[0], (unsigned char)fr.tmp.w.c.t3.b[0], u);
            fr.tmp.x.lo.b[1] = LerpByte((unsigned char)fr.tmp.w.c.t2.b[1], (unsigned char)fr.tmp.w.c.t3.b[1], u);
            fr.tmp.x.lo.b[2] = LerpByte((unsigned char)fr.tmp.w.c.t2.b[2], (unsigned char)fr.tmp.w.c.t3.b[2], u);
            fr.tmp.x.lo.b[3] = LerpByte((unsigned char)fr.tmp.w.c.t2.b[3], (unsigned char)fr.tmp.w.c.t3.b[3], u);
            fr.tmp.v.c.t1 = fr.tmp.x.lo;
            fr.s40.v = fr.tmp.v.c.t1;
            fr.tmp.w.c.t2 = slot->rgbaMulFrom;
            fr.tmp.w.c.t3 = slot->rgbaMulTo;
            fr.tmp.x.lo.b[0] = LerpByte((unsigned char)fr.tmp.w.c.t2.b[0], (unsigned char)fr.tmp.w.c.t3.b[0], u);
            fr.tmp.x.lo.b[1] = LerpByte((unsigned char)fr.tmp.w.c.t2.b[1], (unsigned char)fr.tmp.w.c.t3.b[1], u);
            fr.tmp.x.lo.b[2] = LerpByte((unsigned char)fr.tmp.w.c.t2.b[2], (unsigned char)fr.tmp.w.c.t3.b[2], u);
            fr.tmp.x.lo.b[3] = LerpByte((unsigned char)fr.tmp.w.c.t2.b[3], (unsigned char)fr.tmp.w.c.t3.b[3], u);
            fr.tmp.v.c.t1 = fr.tmp.x.lo;
            fr.s50.v = fr.tmp.v.c.t1;
        } else {
            fr.xf = *slot->pxfFrom;
            fr.s40.v = slot->rgbaAddFrom;
            fr.s50.v = slot->rgbaMulFrom;
        }
        fr.tmp.w.prod.a = fr.xf.a * pxf->a + fr.xf.b * pxf->c;
        fr.tmp.w.prod.b = fr.xf.a * pxf->b + fr.xf.b * pxf->d;
        fr.tmp.w.prod.c = fr.xf.c * pxf->a + fr.xf.d * pxf->c;
        fr.tmp.w.prod.d = fr.xf.c * pxf->b + fr.xf.d * pxf->d;
        fr.tmp.w.prod.e = fr.xf.e * pxf->a + fr.xf.f * pxf->c + pxf->e;
        fr.tmp.w.prod.f = fr.xf.e * pxf->b + fr.xf.f * pxf->d + pxf->f;
        fr.xf = fr.tmp.w.prod;
        fr.tmp.v.dummy = fr.tmp.w.prod;
        fr.tmp.v.c.t0 = *prgbaMul;
        fr.tmp.v.c.t1 = *prgbaAdd;
        fr.tmp.w.c.t2 = fr.s50.v;
        fr.tmp.w.c.t3 = fr.s40.v;
        CombineColorTransforms(&fr.tmp.v.c.t0, &fr.tmp.v.c.t1, &fr.tmp.w.c.t2, &fr.tmp.w.c.t3, &fr.outMul.v, &fr.outAdd.v);
        if (idChar > 0) {
            MOVIECHAR *pcharOld = slot->pchar;
            MOVIECHAR *pcharNew = (MOVIECHAR *)(*(char **)(label->pmovie + 0x54) + idChar * 0x40);
            if (pcharOld == 0) {
                fr.tmp.v.c.t0 = fr.outAdd.v;
                fr.tmp.v.c.t1 = fr.outMul.v;
                func_00215730(pcharNew, slot, &fr.xf, &fr.tmp.v.c.t0, &fr.tmp.v.c.t1);
            } else if (pcharOld->id == idChar) {
                fr.tmp.v.c.t0 = fr.outAdd.v;
                fr.tmp.v.c.t1 = fr.outMul.v;
                func_00215850(pcharOld, slot, gAdvance, &fr.xf, &fr.tmp.v.c.t0, &fr.tmp.v.c.t1);
            } else {
                func_002158C0(pcharOld, slot);
                fr.tmp.v.c.t0 = fr.outAdd.v;
                fr.tmp.v.c.t1 = fr.outMul.v;
                func_00215730(pcharNew, slot, &fr.xf, &fr.tmp.v.c.t0, &fr.tmp.v.c.t1);
            }
        } else {
            fr.tmp.v.c.t0 = fr.outAdd.v;
            fr.tmp.v.c.t1 = fr.outMul.v;
            func_00215850(slot->pchar, slot, gAdvance, &fr.xf, &fr.tmp.v.c.t0, &fr.tmp.v.c.t1);
        }
        slot->tUpdated = tKey;
        slot->xf = fr.xf;
        slot->rgbaAdd = fr.outAdd.v;
        slot->rgbaMul = fr.outMul.v;
        slot->fTween = pplace->fTween;
        slot->bAlpha = pplace->bAlpha;
        slot->idDepth = pplace->idDepth;
        ClearSle(&slot->pslNext);
        if (cmask == 0) {
            if (slot->maskMode != 4) slot->maskMode = 0;
        } else {
            slot->maskMode = 1;
            aslot[islot + cmask].maskMode = 4;
        }
    } while (++iplace < pkey->cplace);
}
