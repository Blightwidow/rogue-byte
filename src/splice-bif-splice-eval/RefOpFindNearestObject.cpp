#include "sly2.h"
struct SCOPE { char pad[0x3C]; void *value; };
struct OBJ { char pad[0xC]; SCOPE *pscope; };
struct CRef { int tagk; int n; int pad8; SCOPE *pscope; };
struct SW { char pad[0x3F0C]; void *pdefault; };
extern SW B_003DD490;
extern "C" void *PloFindSwObject(SW *, int, int, SCOPE *, void *);
extern "C" CRef *CRef_SetBasic(CRef *, void *);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);

CRef *RefOpFindNearestObject(CRef *result, int count, CRef *args, void *frame)
{
    CRef refResult;
    refResult.tagk = -1;
    SCOPE *pscope = args[0].pscope;
    SCOPE *pfound;
    if (args[1].tagk != 0)
        pfound = ((OBJ *)args[1].n)->pscope;
    else
        pfound = pscope;
    SW *psw = &B_003DD490;
    int oid = args[0].n;
    void *pvScope;
    if (pfound != 0)
        pvScope = pfound->value;
    else
        pvScope = psw->pdefault;
    CRef_SetBasic(&refResult, PloFindSwObject(psw, 4, oid, pscope, pvScope));
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
