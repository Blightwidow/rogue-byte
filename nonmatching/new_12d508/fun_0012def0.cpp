#include "sly2.h"
struct M4 { QW row[4]; };
struct XF { char pad0[0x40]; M4 mat; char pad1[0x9A - 0x80]; short kind; char pad2[0xA0 - 0x9C]; XF *pxfParent; char pad3[0xC0 - 0xA4]; QW goal; QW goalVel; };
struct ACTFOLLOW { char pad0[8]; XF *pxf; char pad1[0x1C - 0xC]; XF *pxfTarget; M4 matOffset; };
extern QW g_2a2dd0;
extern "C" {
void InvertMatrix4Affine(M4 *, const M4 *);
M4 __ml__FRC7MATRIX4T0(const M4 &, const M4 &);
QW GetXfDofValue(XF *, M4);
}
void func_0012DEF0(ACTFOLLOW *pact)
{
    M4 matResult;
    M4 matTarget;
    M4 matInverse;
    XF *pxfParent = pact->pxf->pxfParent;
    if (pxfParent) {
        InvertMatrix4Affine(&matInverse, &pxfParent->mat);
        matTarget = __ml__FRC7MATRIX4T0(matInverse, pact->pxfTarget->mat);
        matResult = __ml__FRC7MATRIX4T0(matTarget, pact->matOffset);
    } else {
        matResult = __ml__FRC7MATRIX4T0(pact->pxfTarget->mat, pact->matOffset);
    }
    XF *pxf = pact->pxf;
    pxf->goal = GetXfDofValue(pxf, matResult);
    pact->pxf->goalVel = g_2a2dd0;
    pact->pxf->kind = 3;
}
