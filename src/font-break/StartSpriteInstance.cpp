#include "sly2.h"
struct XF { float a, b, c, d, e, f; float pad[2]; } __attribute__((aligned(16)));
struct INST { char pad0[8]; short ilabel; short pause; float t; int key; int unk; };
struct LABEL { char pad[0x18]; };
struct SPRITE { int unk0; LABEL *labels; INST *insts; char pad[0x20]; XF *pxf; };
struct B4 { char b[4]; };
struct L { XF composed; QW add; QW mul; };
extern "C" void AdvanceSpriteInstance(LABEL *plabel, int iinst, XF *pxf, QW *padd, QW *pmul, float t);
void StartSpriteInstance(float t, SPRITE *psprite, int ilabel, int iinst, XF *pxf, B4 *padd, B4 *pmul)
{
    INST *pinst = psprite->insts + iinst;
    pinst->ilabel = ilabel;
    pinst->key = 0;
    pinst->t = t;
    pinst->pause = 0;
    L l;
    XF *pxfcall;
    if (psprite->pxf) {
        XF *pv = psprite->pxf;
        XF tmp;
        float xa = pxf->a, xb = pxf->b, xc = pxf->c, xd = pxf->d, xe = pxf->e, xf = pxf->f;
        tmp.a = xa * pv->a + xb * pv->c;
        tmp.b = xa * pv->b + xb * pv->d;
        tmp.c = xc * pv->a + xd * pv->c;
        tmp.d = xc * pv->b + xd * pv->d;
        tmp.e = xe * pv->a + xf * pv->c + pv->e;
        tmp.f = xe * pv->b + xf * pv->d + pv->f;
        l.add = ((QW *)&tmp)[0];
        l.mul = ((QW *)&tmp)[1];
        l.composed = tmp;
        pxfcall = &l.composed;
    } else {
        pxfcall = pxf;
    }
    *(B4 *)&l.add = *padd;
    *(B4 *)&l.mul = *pmul;
    AdvanceSpriteInstance(psprite->labels + pinst->ilabel, iinst, pxfcall, &l.add, &l.mul, t);
}
