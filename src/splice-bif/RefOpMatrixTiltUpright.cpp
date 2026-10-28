#include "sly2.h"
struct CRef { int tagk; int n; };
struct CFrame;
struct Rows { QW row[3]; };
extern "C" {
void TiltMatUpright__FP7MATRIX3N20(void *, void *, void *);
void SetTag__4CRef4TAGK(CRef *, int);
void *__as__6VECTORG9VU_VECTOR(void *, QW);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpMatrixTiltUpright(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    struct { Rows upright; CRef refMatrix; int pad[2]; } l;
    TiltMatUpright__FP7MATRIX3N20((void *)aref[0].n, 0, &l.upright);
    CRef *pfirst;
    asm("addiu %0, $sp, 0x30" : "=r" (pfirst));
    SetTag__4CRef4TAGK(pfirst, 0x1B);
    QW *pout = (QW *)l.refMatrix.n;
    __as__6VECTORG9VU_VECTOR(&pout[3], ((QW *)aref[0].n)[3]);
    pout[0] = l.upright.row[0];
    pout[1] = l.upright.row[1];
    pout[2] = l.upright.row[2];
    ((int *)pout)[7] = 0;
    ((int *)pout)[11] = 0;
    ((int *)pout)[3] = 0;
    ((float *)pout)[15] = 1.0f;
    CRef_CopyConstruct(pref, &l.refMatrix);
    CRef_Destruct(&l.refMatrix);
    return pref;
}
