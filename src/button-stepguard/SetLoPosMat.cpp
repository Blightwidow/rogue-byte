/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int QW __attribute__((mode(TI)));
struct LO_1A6BE8;
struct VT_1A6BE8 {
    char pad[0xE8];
    short deltaPos; short unusedPos; void (*SetPos)(void *, QW);
    short deltaMat; short unusedMat; void (*SetMat)(void *, void *);
};
struct LO_1A6BE8 { char pad[0xC]; VT_1A6BE8 *vt; };
struct XF_1A6BE8 { char mat[0x30]; QW pos; };
extern "C" void SetLoPosMat(LO_1A6BE8 *plo, XF_1A6BE8 *pxf) {
    plo->vt->SetPos((char *)plo + plo->vt->deltaPos, pxf->pos);
    plo->vt->SetMat((char *)plo + plo->vt->deltaMat, pxf);
}
