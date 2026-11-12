#include "sly2.h"
#include "vu0inline.h"
struct CRef { int tagk; void *pv; CRef(int tag); ~CRef(); };
struct Rows { QW row[3]; };
struct Vec { QW q; };
extern "C" {
void CRef_Destruct(CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_CopyConstruct(CRef *, CRef *);
Rows BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(QW vecY, QW vecZ);
extern QW g_2a2dc0;
}
inline CRef::CRef(int tag) { SetTag__4CRef4TAGK(this, tag); }
inline CRef::~CRef() { CRef_Destruct(this); }
extern "C" {
CRef *RefOpMatrixLookAt(CRef *result, int count, CRef *args)
{
    QW direction[1];
    QW *up;
    if (args[2].tagk == 0)
        up = &g_2a2dc0;
    else
        up = *(QW **)((char *)args[2].pv + 0xC);
    direction[0] = VectorSub(*(QW *)args[1].pv, *(QW *)args[0].pv);
    CRef temp(0x1B);
    QW *dest = (QW *)temp.pv;
    Rows rows = BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(direction[0], *up);
    dest[0] = rows.row[0];
    dest[1] = rows.row[1];
    dest[2] = rows.row[2];
    ((int *)dest)[3] = 0;
    ((int *)dest)[7] = 0;
    ((int *)dest)[11] = 0;
    CRef_CopyConstruct(result, &temp);
    return result;
}
}
