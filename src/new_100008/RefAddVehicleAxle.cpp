#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 x; int y; };
struct RANGE { float v[4]; };
extern "C" void AddVehicleAxle(BASIC *, int, RANGE *);
extern const B8 RO_002A40D8;

CRef RefAddVehicleAxle(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    RANGE range;
    int oid;
    aotyp = RO_002A40D8;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &oid, &range);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddVehicleAxle(object, oid, &range);
    return ref;
}
