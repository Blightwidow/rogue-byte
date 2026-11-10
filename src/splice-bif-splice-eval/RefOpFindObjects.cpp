// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int pad0; int pad4; CRef ref; };
#include "sw.h"
struct CFrame;
extern SW B_003DD490;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
int CploFindSwObjects(SW *, int, int, LO *, SCOPE *, int, int *);
void RefFromAplo(CRef *, int, int *);
}
extern "C" CRef *RefOpFindObjects(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    LO *basis = (LO *)aref[1].n;
    refResult.tagk = -1;
    LO *scopeObject;
    if (aref[2].tagk != 0)
        scopeObject = (LO *)((CPair *)aref[2].n)->ref.n;
    else
        scopeObject = basis;
    SW *psw = &B_003DD490;
    int grffso = 5;
    if (basis != 0)
        grffso = 1;
    int id = aref[0].n;
    SCOPE *pscope;
    if (scopeObject != 0)
        pscope = scopeObject->pscope;
    else
        pscope = psw->pscopeDefault;
    int aplo[0x40];
    int cplo = CploFindSwObjects(psw, grffso, id, basis, pscope, 0x40, aplo);
    CRef refList;
    RefFromAplo(&refList, cplo, aplo);
    refResult = refList;
    CRef_Destruct(&refList);
    CRef_CopyConstruct(pret, &refResult);
    CRef_Destruct(&refResult);
    return pret;
}
