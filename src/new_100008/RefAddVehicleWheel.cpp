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
extern "C" void AddVehicleWheel(BASIC *, int, RANGE *, float);
extern const B12 RO_002A40C8;

CRef *RefAddVehicleWheel(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B12 aotyp; int pad; RANGE range; CRef ref; int oid; float radius; } l;
    l.aotyp = RO_002A40C8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 3, args, (const int *)&l.aotyp, &l.oid, &l.radius, &l.range);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddVehicleWheel(object, l.oid, &l.range, l.radius);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
