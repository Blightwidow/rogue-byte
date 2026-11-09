#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 x; int y; };
struct RANGE { float v[4]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddVehicleAxle(BASIC *, int, RANGE *);
extern const B8 RO_002A40D8;

CRef *RefAddVehicleAxle(CRef *result, BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    RANGE range;
    CRef ref;
    int oid;
    aotyp = RO_002A40D8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, (const int *)&aotyp, &oid, &range);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddVehicleAxle(object, oid, &range);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
