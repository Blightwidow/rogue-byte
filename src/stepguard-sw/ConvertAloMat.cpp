// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct M4 { QW row[4]; };
struct VT { char pad[0xF8]; short delta; short index; M4 *(*fn)(void *); };
struct ALO { char pad[0xC]; VT *vptr; };
extern "C" {
M4 InvertMatrix4Affine(M4 *);
M4 __ml__FRC7MATRIX4T0(const M4 &, const M4 &);
}
M4 ConvertAloMat(ALO *paloFrom, ALO *paloTo, M4 *pmat)
{
    M4 matCur;
    if (paloFrom) {
        VT *vt = paloFrom->vptr;
        matCur = __ml__FRC7MATRIX4T0(*vt->fn((char *)paloFrom + vt->delta), *pmat);
    } else {
        matCur = *pmat;
    }
    if (paloTo) {
        VT *vt = paloTo->vptr;
        matCur = __ml__FRC7MATRIX4T0(InvertMatrix4Affine(vt->fn((char *)paloTo + vt->delta)), matCur);
    }
    return matCur;
}
