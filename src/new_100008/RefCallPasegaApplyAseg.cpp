#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" BASIC *PasegaApplyAseg(BASIC *, int, float, float, int);
extern const struct B16 { char b[16]; } RO_002A3AC0;

CRef RefCallPasegaApplyAseg(BASIC *object, int count, CRef *args)
{
    B16 aotyp;
    int oid;
    float a;
    float b;
    int c;
    aotyp = RO_002A3AC0;
    CRef ref = RefSetArgsFromSplice(4, args, &aotyp, &oid, &a, &b, &c);
    ref.SetBasic(PasegaApplyAseg(object, oid, a, b, c));
    return ref;
}
