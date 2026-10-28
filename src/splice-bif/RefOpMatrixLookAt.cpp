#include "sly2.h"
struct CRef { int tagk; int n; };
struct CPair { int cref; int pad4; CRef ref; };
struct CFrame;
struct LKM { QW row[3]; };
extern QW g_2a2dc0;
extern "C" {
void SetTag__4CRef4TAGK(CRef *, int);
MATRIX3 *BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(MATRIX3 *, QW, QW);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpMatrixLookAt(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    struct { QW direction; CRef refMatrix; int pad[2]; LKM mat; } l;
#define direction l.direction
#define refMatrix l.refMatrix
#define mat l.mat
    QW *pup;
    if (aref[2].tagk == 0) {
        pup = &g_2a2dc0;
    } else {
        pup = (QW *)((CPair *)aref[2].n)->ref.n;
    }
    register QW vb asm("vf1") = *(QW *)aref[1].n;
    register QW va asm("vf2") = *(QW *)aref[0].n;
    asm("vsub.xyzw vf1, vf1, vf2" : "+j" (vb) : "j" (va));
    direction = vb;
    CRef *pfirst;
    asm("addiu %0, $sp, 0x10" : "=r" (pfirst));
    SetTag__4CRef4TAGK(pfirst, 0x1B);
    QW *pout = (QW *)refMatrix.n;
    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3((MATRIX3 *)&mat, direction, *pup);
    pout[0] = mat.row[0];
    pout[1] = mat.row[1];
    pout[2] = mat.row[2];
    ((int *)pout)[3] = 0;
    ((int *)pout)[7] = 0;
    ((int *)pout)[11] = 0;
    CRef_CopyConstruct(pref, &refMatrix);
    CRef_Destruct(&refMatrix);
    return pref;
}
