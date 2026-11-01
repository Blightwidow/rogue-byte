#include "sly2.h"
struct XFM { char pad0[0x60]; MATRIX4 matLocal; };
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);
extern "C" void InvalidateXfmMatWorld(XFM *);

extern "C" void ApplyXfmProxy(XFM *pxfm, const MATRIX4 *pmat)
{
    pxfm->matLocal = *pmat * pxfm->matLocal;
    InvalidateXfmMatWorld(pxfm);
}
