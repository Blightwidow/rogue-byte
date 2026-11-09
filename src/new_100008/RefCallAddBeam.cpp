#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[10]; };
extern "C" void AddLaserBeam(BASIC *, int, int, int, int, float, float, float, float, float, float);
extern const AOT RO_002A3C10;

CRef RefCallAddBeam(BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3C10;
    int oid0;
    float u0, v0, d0;
    int mode0;
    int oid1;
    float u1, v1, d1;
    int mode1;
    RefSetArgsFromSplice(10, args, &aotyp, &oid0, &u0, &v0, &d0, &mode0, &oid1, &u1, &v1, &d1, &mode1);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddLaserBeam(object, oid0, mode0, oid1, mode1, u0, v0, d0, u1, v1, d1);
    return refResult;
}
