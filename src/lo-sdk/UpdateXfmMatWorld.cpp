#include "sly2.h"
struct XF { char pad0[0x40]; MATRIX4 matWorld; char pad1[0xA4 - 0x80]; int generation; };
struct XFM { char pad0[0x50]; XF *pxf; int generation; char pad1[8]; MATRIX4 matLocal; MATRIX4 matWorld; };
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);

extern "C" void UpdateXfmMatWorld(XFM *pxfm)
{
    XF *pxf = pxfm->pxf;
    if (pxf) {
        if (pxfm->generation < pxf->generation) {
            pxfm->generation = pxf->generation;
            pxfm->matWorld = pxf->matWorld * pxfm->matLocal;
        }
    } else if (pxfm->generation < 0) {
        pxfm->matWorld = pxfm->matLocal;
    }
}
