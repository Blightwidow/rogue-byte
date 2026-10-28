#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[5]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_00207C48(BASIC *, CRef *, int, int, int, int);
extern const AOT RO_002A3B30;

CRef *func_00102C38(CRef *result, BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3B30;
    CRef crefArg;
    crefArg.tagk = -1;
    int oid0, oid1, oid2, oid3;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 5, args, &aotyp, &crefArg, &oid0, &oid1, &oid2, &oid3);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    func_00207C48(object, &crefArg, oid0, oid1, oid2, oid3);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    CRef_Destruct(&crefArg);
    return result;
}
