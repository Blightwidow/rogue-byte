#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };

struct Raw16 { B8 x; B8 y; };
extern "C" void AddVehicleGun(BASIC *, int, int, int, int);
extern "C" const Raw16 RO_002A4048;

CRef RefAddVehicleGun(BASIC *object, int count, CRef *args)
{
    Raw16 types;
    int a;
    int b;
    int c;
    int d;
    types = RO_002A4048;
    RefSetArgsFromSplice(4, args, &types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddVehicleGun(object, a, b, c, d);
    return ref;
}
