#include "sly2.h"
#include "sw.h"
struct OBJ { char pad[0xC]; LO *plo; };
struct CRef { int tagk; int n; int pad8; LO *plo; };
extern SW B_003DD490;
extern "C" void *PloFindSwObject(SW *, int, int, LO *, SCOPE *);
extern "C" CRef *CRef_SetBasic(CRef *, void *);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);

CRef *RefOpFindNearestObject(CRef *result, int count, CRef *args, void *frame)
{
    CRef refResult;
    refResult.tagk = -1;
    LO *ploContext = args[0].plo;
    LO *pfound;
    if (args[1].tagk != 0)
        pfound = ((OBJ *)args[1].n)->plo;
    else
        pfound = ploContext;
    SW *psw = &B_003DD490;
    int oid = args[0].n;
    SCOPE *pscope;
    if (pfound != 0)
        pscope = pfound->pscope;
    else
        pscope = psw->pscopeDefault;
    CRef_SetBasic(&refResult, PloFindSwObject(psw, 4, oid, ploContext, pscope));
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
