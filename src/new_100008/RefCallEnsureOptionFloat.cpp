#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void EnsureOptionFloat(BASIC *, int, float);
extern const B8 RO_002A3A40;

CRef RefCallEnsureOptionFloat(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int oid;
    float arg;
    aotyp = RO_002A3A40;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &oid, &arg);
    CRef ref;
    ref.SetTag(TAGK_Void);
    EnsureOptionFloat(object, oid, arg);
    return ref;
}
