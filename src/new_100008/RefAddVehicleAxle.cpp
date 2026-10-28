#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
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
    struct L { B8 aotyp; int pad[2]; RANGE range; CRef ref; int oid; } l;
    l.aotyp = RO_002A40D8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 2, args, (const int *)&l.aotyp, &l.oid, &l.range);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddVehicleAxle(object, l.oid, &l.range);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
