#include "sly2.h"
struct AFF { float a, b, c, d, e, f, u6, u7; } __attribute__((aligned(16)));
struct RGBA4 { char b[4]; };
struct LABEL { char pad0[8]; float dt; char pad1[0x18 - 0xC]; };
struct INST { char pad0[8]; short ilabel; short ikeyNext; float t; int fPaused; char pad1[0x18 - 0x14]; };
struct SPRITE { char pad0[4]; LABEL *labels; INST *insts; char pad1[0x2C - 0xC]; AFF *pxf; };
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
extern "C" void AdvanceSpriteInstance(float, LABEL *, int, AFF *, RGBA4 *, RGBA4 *);
extern "C" void RefreshSpriteInstance(float, LABEL *, int, AFF *, RGBA4 *, RGBA4 *);
extern "C" void UpdateSpriteInstance(float dt, SPRITE *sprite, int iinst, AFF *xf, RGBA4 *rgbaAdd, RGBA4 *rgbaMul)
{
    INST *inst = &sprite->insts[iinst];
    int ilabel = inst->ilabel;
    if (ilabel < 0) return;
    AFF composed;
    AFF *xfUse;
    if (sprite->pxf) {
        composed = Mult(*xf, *sprite->pxf);
        xfUse = &composed;
    } else {
        xfUse = xf;
    }
    if (inst->fPaused != 0) {
        RGBA4 add = *rgbaAdd;
        RGBA4 mul = *rgbaMul;
        RefreshSpriteInstance(dt, &sprite->labels[ilabel], iinst, xfUse, &add, &mul);
    } else {
        if (sprite->labels[ilabel].dt <= inst->t) {
            inst->t = 0.0f;
            inst->ikeyNext = 0;
        } else {
            inst->t = inst->t + dt;
        }
        RGBA4 add = *rgbaAdd;
        RGBA4 mul = *rgbaMul;
        AdvanceSpriteInstance(dt, &sprite->labels[ilabel], iinst, xfUse, &add, &mul);
    }
}
