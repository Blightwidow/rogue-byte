// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int pad0; int pad4; CRef ref; };
struct LO { char pad[0x3C]; int scope; };
struct SW { char pad[0x3F0C]; int scope; };
struct CFrame;
extern SW B_003DD490;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
int CploFindSwObjects(SW *, int, int, LO *, int, int, int *);
void RefFromAplo(CRef *, int, int *);
}
extern "C" CRef *RefOpFindNearestObjects(CRef *pret, int carg, CRef *aref, CFrame *pframe)
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
    int id = aref[0].n;
    int scope;
    if (scopeObject != 0)
        scope = scopeObject->scope;
    else
        scope = psw->scope;
    int aplo[0x40];
    int cplo = CploFindSwObjects(psw, 4, id, basis, scope, 0x40, aplo);
    CRef refList;
    RefFromAplo(&refList, cplo, aplo);
    refResult = refList;
    CRef_Destruct(&refList);
    CRef_CopyConstruct(pret, &refResult);
    CRef_Destruct(&refResult);
    return pret;
}
