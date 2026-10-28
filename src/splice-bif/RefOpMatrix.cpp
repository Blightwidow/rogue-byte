#include "sly2.h"
struct CRef { int tagk; union { int n; float g; float *pg; QW *pq; }; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct CFrame;
extern "C" {
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_RefCoerceF32(CRef *, CRef *);
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
}
void *memset(void *, int, unsigned int);
extern "C" CRef *RefOpMatrix(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refMatrix;
    SetTag__4CRef4TAGK(&refMatrix, 0x1B);
    float *pg = refMatrix.pg;
    CPair *ppair;
    if (carg > 0) ppair = (CPair *)aref[0].n;
    memset(pg, 0, 0x40);
    pg[15] = 1.0f;
    pg[10] = 1.0f;
    pg[5] = 1.0f;
    pg[0] = 1.0f;
    switch (carg) {
    case 0:
        break;
    case 1: {
        CRef refTemp;
        CRef_RefCoerceF32(&refTemp, &ppair->ref);
        float g = refTemp.g;
        pg[10] = g;
        pg[5] = g;
        pg[0] = g;
        CRef_Destruct(&refTemp);
        break;
    }
    case 3:
    case 4: {
        for (int irow = 0; irow < carg; irow++) {
            ((QW *)pg)[irow] = *ppair->ref.pq;
            ppair = ppair->next;
        }
        break;
    }
    case 9:
    case 16: {
        int cdim = (carg == 9) ? 3 : 4;
        for (int irow = 0; irow < cdim; irow++) {
            for (int icol = 0; icol < cdim; icol++) {
                CRef refTemp;
                CRef_RefCoerceF32(&refTemp, &ppair->ref);
                pg[irow * 4 + icol] = refTemp.g;
                ppair = ppair->next;
                CRef_Destruct(&refTemp);
            }
        }
        break;
    }
    }
    CRef_CopyConstruct(pret, &refMatrix);
    CRef_Destruct(&refMatrix);
    return pret;
}
