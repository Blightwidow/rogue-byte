#include "sly2.h"
struct CRef { int tagk; int n; };
struct CFrame;
struct SW { char pad[0x3F0C]; int scope; };
struct LO { char pad[0x3C]; int scope; };
struct CPair { int pad0; int pad4; CRef ref; };
extern SW B_003DD490;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" int CRef_SetBasic(CRef *, int);
extern "C" int PloFindSwObject(SW *, int, int, LO *, int);

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
    int scope;
    if (scopeObject != 0)
        scope = scopeObject->scope;
    else
        scope = psw->scope;
    int found = PloFindSwObject(psw, grffso, id, basis, scope);
    CRef_SetBasic(&refResult, found);
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}
