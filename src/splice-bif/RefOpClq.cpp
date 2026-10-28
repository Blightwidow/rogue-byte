// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; union { int n; float *pg; float g; }; };
struct CFrame;
extern "C" {
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_RefCoerceF32(CRef *, CRef *);
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
}
extern "C" CRef *RefOpClq(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef ref;
    SetTag__4CRef4TAGK(&ref, 0x1C);
    float *pvec = ref.pg;
    for (int index = 0; index < 3; index++) {
        CRef refTemp;
        CRef_RefCoerceF32(&refTemp, &aref[index]);
        pvec[index] = refTemp.g;
        CRef_Destruct(&refTemp);
    }
    CRef_CopyConstruct(pret, &ref);
    CRef_Destruct(&ref);
    return pret;
}
