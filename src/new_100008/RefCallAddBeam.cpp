#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[10]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" int CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddLaserBeam(BASIC *, int, int, int, int, float, float, float, float, float, float);
extern const AOT RO_002A3C10;

CRef *RefCallAddBeam(CRef *result, BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3C10;
    int oid0;
    float u0, v0, d0;
    int mode0;
    int oid1;
    float u1, v1, d1;
    int mode1;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 10, args, &aotyp, &oid0, &u0, &v0, &d0, &mode0, &oid1, &u1, &v1, &d1, &mode1);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    AddLaserBeam(object, oid0, mode0, oid1, mode1, u0, v0, d0, u1, v1, d1);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
