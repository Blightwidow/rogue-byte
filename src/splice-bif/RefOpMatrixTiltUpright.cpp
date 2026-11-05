// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CRef { int tagk; void *pv; CRef(int tag); ~CRef(); };
struct Rows { QW row[3]; };
extern "C" {
void CRef_Destruct(CRef *);
void TiltMatUpright__FP7MATRIX3N20(void *, void *, void *);
void SetTag__4CRef4TAGK(CRef *, int);
}
inline CRef::CRef(int tag) { SetTag__4CRef4TAGK(this, tag); }
inline CRef::~CRef() { CRef_Destruct(this); }
extern "C" {
void *__as__6VECTORG9VU_VECTOR(void *, QW);
void CRef_CopyConstruct(CRef *, CRef *);
CRef *RefOpMatrixTiltUpright(CRef *result, int count, CRef *args)
{
    Rows upright;
    TiltMatUpright__FP7MATRIX3N20(args[0].pv, 0, &upright);
    CRef temp(0x1B);
    QW *dest = (QW *)temp.pv;
    __as__6VECTORG9VU_VECTOR(&dest[3], ((QW *)args[0].pv)[3]);
    dest[0] = upright.row[0];
    dest[1] = upright.row[1];
    dest[2] = upright.row[2];
    ((int *)dest)[7] = 0;
    ((int *)dest)[11] = 0;
    ((int *)dest)[3] = 0;
    ((float *)dest)[15] = 1.0f;
    CRef_CopyConstruct(result, &temp);
    return result;
}
}
