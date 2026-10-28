// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; union { int n; float *pg; float g; }; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct CFrame;
extern "C" {
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_RefCoerceF32(CRef *, CRef *);
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
}
extern "C" CRef *RefOpVector(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refVector;
    SetTag__4CRef4TAGK(&refVector, 0x1A);
    float *pvec = refVector.pg;
    CPair *ppair;
    if (carg > 0) ppair = (CPair *)aref[0].n;
    switch (carg) {
    case 0:
        pvec[2] = 0.0f;
        pvec[1] = 0.0f;
        pvec[0] = 0.0f;
        break;
    case 1: {
        CRef refTemp;
        CRef_RefCoerceF32(&refTemp, &ppair->ref);
        float g = refTemp.g;
        pvec[2] = g;
        pvec[1] = g;
        pvec[0] = g;
        CRef_Destruct(&refTemp);
        break;
    }
    case 3: {
        for (int index = 0; index < 3; index++) {
            CRef refTemp;
            CRef_RefCoerceF32(&refTemp, &ppair->ref);
            pvec[index] = refTemp.g;
            ppair = ppair->next;
            CRef_Destruct(&refTemp);
        }
        break;
    }
    }
    CRef_CopyConstruct(pret, &refVector);
    CRef_Destruct(&refVector);
    return pret;
}
