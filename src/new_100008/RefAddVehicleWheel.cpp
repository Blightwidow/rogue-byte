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
extern "C" void AddVehicleWheel(BASIC *, int, RANGE *, float);
extern const B12 RO_002A40C8;

CRef *RefAddVehicleWheel(CRef *result, BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    RANGE range;
    CRef ref;
    int oid;
    float radius;
    aotyp = RO_002A40C8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 3, args, (const int *)&aotyp, &oid, &radius, &range);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddVehicleWheel(object, oid, &range, radius);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
