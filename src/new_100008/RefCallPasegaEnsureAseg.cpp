#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" BASIC *PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(BASIC *, int, int, float, float, int);
extern const struct B20 { char b[16]; int w; } RO_002A3AE0;

CRef RefCallPasegaEnsureAseg(BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    int a;
    int b;
    float d;
    float e;
    int c;
    aotyp = RO_002A3AE0;
    CRef ref = RefSetArgsFromSplice(5, args, &aotyp, &a, &b, &d, &e, &c);
    ref.SetBasic(PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(object, a, b, d, e, c));
    return ref;
}
