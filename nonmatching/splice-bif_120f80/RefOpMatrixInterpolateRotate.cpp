#include "sly2.h"
struct CRef { int tagk; union { int n; float g; QW *pv; }; };
struct CFrame;
struct Rows { QW row[3]; };
struct MATRIX3;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
void MatMulMatTransMat(Rows *, Rows *, Rows *);
void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(Rows *, float *, QW *);
void LoadRotateMatrixRad(Rows *, float, QW);
}
void *memset(void *, int, unsigned int);
extern "C" CRef *RefOpMatrixInterpolateRotate(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    struct Frame { Rows matBetween; QW axis; CRef refResult; int pad[2]; Rows junkA; Rows matRotate; Rows junkB; float radBetween; } f;
    MatMulMatTransMat(&f.matBetween, (Rows *)aref[0].pv, (Rows *)aref[1].pv);
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(&f.matBetween, &f.radBetween, &f.axis);
    SetTag__4CRef4TAGK(&f.refResult, 0x1B);
    float *result = (float *)f.refResult.pv;
    memset(result, 0, 0x40);
    result[0] = 1.0f;
    result[15] = 1.0f;
    result[10] = 1.0f;
    result[5] = 1.0f;
    LoadRotateMatrixRad(&f.matRotate, f.radBetween * aref[2].g, f.axis);
    result = (float *)f.refResult.pv;
    Rows *resultRows = (Rows *)result;
    Rows *source = (Rows *)aref[0].pv;
    asm("lqc2 vf4, %0" : : "m" (f.matRotate.row[0]));
    asm("lqc2 vf5, %0" : : "m" (source->row[0]));
    asm("lqc2 vf6, %0" : : "m" (f.matRotate.row[1]));
    asm("lqc2 vf3, %0" : : "m" (f.matRotate.row[2]));
    asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf6, vf5y\n\tvmaddz.xyz vf5, vf3, vf5z");
    asm("sqc2 vf5, %0" : "=m" (f.junkA.row[0]));
    asm("sqc2 vf5, %0" : "=m" (f.junkB.row[0]));
    asm("lqc2 vf1, %0" : : "m" (source->row[1]));
    asm("vmulax.xyz ACC, vf4, vf1x\n\tvmadday.xyz ACC, vf6, vf1y\n\tvmaddz.xyz vf1, vf3, vf1z");
    asm("sqc2 vf1, %0" : "=m" (f.junkA.row[1]));
    asm("sqc2 vf1, %0" : "=m" (f.junkB.row[1]));
    asm("lqc2 vf2, %0" : : "m" (source->row[2]));
    asm("vmulax.xyz ACC, vf4, vf2x\n\tvmadday.xyz ACC, vf6, vf2y\n\tvmaddz.xyz vf4, vf3, vf2z");
    asm("sqc2 vf4, %0" : "=m" (f.junkA.row[2]));
    asm("sqc2 vf4, %0" : "=m" (f.junkB.row[2]));
    asm("sqc2 vf5, %0" : "=m" (resultRows->row[0]));
    resultRows->row[1] = f.junkA.row[1];
    resultRows->row[2] = f.junkA.row[2];
    CRef *refLate = &f.refResult;
    asm("" : "+r" (refLate));
    CRef_CopyConstruct(pret, refLate);
    CRef_Destruct(refLate);
    return pret;
}
