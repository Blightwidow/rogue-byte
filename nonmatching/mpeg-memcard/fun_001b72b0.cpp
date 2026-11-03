#include "sly2.h"
struct M4 { QW row[4]; };
struct XF { M4 local; char pad[0xA0 - 0x40]; XF *parent; };
struct Bone { char pad[0x58]; XF *xfA; XF *xfB; };
struct Chain { char pad0[0x50]; XF *start; char pad1[0x60 - 0x54]; M4 mat; };
struct Joint { char pad[0x180]; Bone *bone; int pad2; Chain *chain; };
struct Obj { char pad[0x13F0]; Joint *pjt; };
extern M4 RO_002A2D30;
extern "C" {
void ConvertXfMat(void *, XF *, XF *, M4 *);
void ConvertXfMatrix4(M4 *, XF *, XF *, M4 *);
QW ConvertXfPos(XF *, XF *, QW);
QW DecomposeRotateMatrixEuler(void *);
void InvertMatrix4Affine(M4 *, M4 *);
void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(void *, QW);
void *__as__6VECTORG9VU_VECTOR(void *, QW);
void __ml__FRC7MATRIX4T0(M4 *, const M4 *, const M4 *);
}
static inline void MulStep(M4 *acc, M4 *tmp, M4 *step)
{
    __ml__FRC7MATRIX4T0(tmp, acc, step);
    *acc = *tmp;
}
extern "C" void func_001B72B0(Obj *obj, XF *xfEnd, M4 *mat, QW *outEuler, QW *outPos)
{
    struct LOCALS {
        union { XF *xfs[12]; QW tmp[3]; };
        QW rot[3];
        M4 inv, mA, mE, mW, mR, mI, mT, mQ, mZ;
    } l;
    if (obj->pjt->chain == 0) {
        ConvertXfMat(l.rot, xfEnd, obj->pjt->bone->xfB->parent, mat);
        l.tmp[0] = l.rot[0];
        l.tmp[1] = l.rot[1];
        l.tmp[2] = l.rot[2];
        *outEuler = DecomposeRotateMatrixEuler(l.tmp);
        *outPos = ConvertXfPos(xfEnd, obj->pjt->bone->xfA->parent, mat->row[3]);
        return;
    }
    Bone *bone = obj->pjt->bone;
    InvertMatrix4Affine(&l.inv, mat);
    int count = 0;
    int idxA = -1;
    int idxB = -1;
    M4 *paZ = &l.mZ;
    QW *pbPos = &l.mW.row[3];
    M4 *pcE = &l.mE;
    M4 *pdQ = &l.mQ;
    M4 *pmA = &l.mA;
    M4 *pmW = &l.mW;
    M4 *pmR = &l.mR;
    M4 *pmI = &l.mI;
    M4 *pmT = &l.mT;
    XF *cur = obj->pjt->chain->start;
    if (cur != xfEnd) {
        do {
            l.xfs[count] = cur;
            idxA = cur == bone->xfA ? count : idxA;
            idxB = cur == bone->xfB ? count : idxB;
            cur = cur->parent;
            count++;
        } while (cur != xfEnd);
    }
    count--;
    int idxAm1 = idxA - 1;
    ConvertXfMatrix4(pmA, obj->pjt->chain->start, bone->xfB, &RO_002A2D30);
    ConvertXfMatrix4(pcE, bone->xfB->parent, xfEnd, &RO_002A2D30);
    __ml__FRC7MATRIX4T0(pmW, pmA, &obj->pjt->chain->mat);
    l.mA = l.mW;
    __ml__FRC7MATRIX4T0(pmI, pmA, &l.inv);
    __ml__FRC7MATRIX4T0(pmR, pmI, pcE);
    InvertMatrix4Affine(pmW, pmR);
    QW euler = DecomposeRotateMatrixEuler(pmW);
    l.rot[1] = euler;
    LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(pmR, euler);
    __as__6VECTORG9VU_VECTOR(pbPos, l.xfs[idxB]->local.row[3]);
    l.mW.row[0] = l.mR.row[0];
    l.mW.row[1] = l.mR.row[1];
    l.mW.row[2] = l.mR.row[2];
    ((float *)&l.mW)[3] = 0;
    ((float *)&l.mW)[7] = 0;
    ((float *)&l.mW)[11] = 0;
    ((float *)&l.mW)[15] = 1.0f;
    l.mR = l.mI = RO_002A2D30;
    for (; idxA < count; count--) {
        M4 *step = count != idxB ? &l.xfs[count]->local : pmW;
        MulStep(pmR, pmT, step);
    }
    for (int index = idxAm1; index >= 0; index--) {
        M4 *step = index != idxB ? &l.xfs[index]->local : pmW;
        MulStep(pmI, pmT, step);
    }
    MulStep(pmI, pmT, &obj->pjt->chain->mat);
    __ml__FRC7MATRIX4T0(paZ, pmI, &l.inv);
    __ml__FRC7MATRIX4T0(pdQ, paZ, pmR);
    InvertMatrix4Affine(pmT, pdQ);
    l.rot[2] = l.mT.row[3];
    if (outEuler)
        *outEuler = l.rot[1];
    if (outPos)
        *outPos = l.rot[2];
}
