#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[6]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_00207E08(BASIC *, CRef *, int, float, float, float, float);
extern const AOT RO_002A3B48;

CRef *func_00102F38(CRef *result, BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3B48;
    CRef crefArg;
    crefArg.tagk = -1;
    int oid;
    float g0, g1, g2, g3;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 6, args, &aotyp, &crefArg, &oid, &g0, &g1, &g2, &g3);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    func_00207E08(object, &crefArg, oid, g0, g1, g2, g3);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    CRef_Destruct(&crefArg);
    return result;
}
