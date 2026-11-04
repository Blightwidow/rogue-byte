typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int n; };
struct CFrame;
struct Rows { QW row[3]; };
extern "C" {
void TiltMatUpright__FP7MATRIX3N20(void *, void *, void *);
void SetTag__4CRef4TAGK(CRef *, int);
void __as__6VECTORG9VU_VECTOR(void *, QW);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpMatrixTiltUpright(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    Rows upright;
    CRef refMatrix;
    TiltMatUpright__FP7MATRIX3N20((void *)aref[0].n, 0, &upright);
    SetTag__4CRef4TAGK(&refMatrix, 0x1B);
    QW *pout = (QW *)refMatrix.n;
    __as__6VECTORG9VU_VECTOR(&pout[3], ((QW *)aref[0].n)[3]);
    pout[0] = upright.row[0];
    pout[1] = upright.row[1];
    pout[2] = upright.row[2];
    ((int *)pout)[7] = 0;
    ((int *)pout)[11] = 0;
    ((int *)pout)[3] = 0;
    ((float *)pout)[15] = 1.0f;
    CRef_CopyConstruct(pret, &refMatrix);
    CRef_Destruct(&refMatrix);
    return pret;
}
