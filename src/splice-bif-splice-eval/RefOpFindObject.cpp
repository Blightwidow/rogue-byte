#include "sly2.h"
struct CRef { int tagk; int n; };
struct CFrame;
#include "sw.h"
struct CPair { int pad0; int pad4; CRef ref; };
extern SW B_003DD490;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" int CRef_SetBasic(CRef *, int);
extern "C" int PloFindSwObject(SW *, int, int, LO *, SCOPE *);

CRef *RefOpFindObject(CRef *pref, int carg, CRef *aref, CFrame *pframe)
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
    int found = PloFindSwObject(psw, grffso, id, basis, pscope);
    CRef_SetBasic(&refResult, found);
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}
