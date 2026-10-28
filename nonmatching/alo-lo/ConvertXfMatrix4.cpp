#include "sly2.h"
struct XF { char pad0[0x40]; MATRIX4 matWorld; };
extern "C" void MulMatrix4__FP7MATRIX4PC7MATRIX4T1(MATRIX4 *, const MATRIX4 *, const MATRIX4 *);
extern "C" void InvertMatrix4Affine(MATRIX4 *, const MATRIX4 *);

extern "C" MATRIX4 *ConvertXfMatrix4(MATRIX4 *pmatResult, XF *pxfFrom, XF *pxfTo, const MATRIX4 *pmat)
{
    MATRIX4 matResult;
    MATRIX4 matFromTo;
    MATRIX4 matInverse;
    const MATRIX4 *pmatFromTo = 0;
    if (pxfFrom != 0) {
        if (pxfTo != 0) {
            InvertMatrix4Affine(&matInverse, &pxfTo->matWorld);
            MulMatrix4__FP7MATRIX4PC7MATRIX4T1(&matFromTo, &matInverse, &pxfFrom->matWorld);
            pmatFromTo = &matFromTo;
        } else {
            pmatFromTo = &pxfFrom->matWorld;
        }
    } else if (pxfTo != 0) {
        InvertMatrix4Affine(&matFromTo, &pxfTo->matWorld);
        pmatFromTo = &matFromTo;
    }
    if (pmatFromTo != 0) {
        MulMatrix4__FP7MATRIX4PC7MATRIX4T1(&matResult, pmatFromTo, pmat);
        memcpy(pmatResult, &matResult, 0x40);
    } else {
        memcpy(pmatResult, pmat, 0x40);
    }
    return pmatResult;
}
