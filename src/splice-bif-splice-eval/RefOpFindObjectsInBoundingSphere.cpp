// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SW;
struct CRef { int tagk; union { QW *pv; int n; float g; }; CRef &operator=(const CRef &); };
struct CFrame;
extern SW B_003DD490;
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void IntersectSwBoundingSphere(SW *, QW, int, int, float, int *, int *);
void ExtractUniqueSosFromGeoms(int, int, int *, int *);
void RefFromAplo(CRef *, int, int);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpFindObjectsInBoundingSphere(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    char frame[0x10];
    CRef refList;
    int cgeom;
    int ageom;
    int cplo;
    int aplo;
    float radius;
    refResult.tagk = -1;
    if (aref[1].tagk == 0x15)
        radius = (float)aref[1].n;
    else
        radius = aref[1].g;
    CStackFrame_Construct(frame);
    IntersectSwBoundingSphere(&B_003DD490, *aref[0].pv, 0, 0, radius, &cgeom, &ageom);
    ExtractUniqueSosFromGeoms(cgeom, ageom, &cplo, &aplo);
    RefFromAplo(&refList, cplo, aplo);
    refResult = refList;
    CRef_Destruct(&refList);
    CRef_CopyConstruct(pret, &refResult);
    CStackFrame_Destructor(frame, 2);
    CRef_Destruct(&refResult);
    return pret;
}
