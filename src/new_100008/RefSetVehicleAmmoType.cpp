#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 x; int y; };
struct RANGE { float v[4]; };
extern "C" void func_001D4CE0(BASIC *, int, int, float);
extern const B12 RO_002A40E8;

CRef RefSetVehicleAmmoType(BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    int a;
    int b;
    float c;
    aotyp = RO_002A40E8;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001D4CE0(object, a, b, c);
    return ref;
}
