#include "sly2.h"
struct Ref { char pad[4]; QW *a; char pad2[4]; QW *b; };
struct CRef { QW q; };
extern "C" void CRef_ConstructVectorValue(CRef *, QW);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" CRef *RefOpVectorProjectNormal(CRef *result, void *unused, Ref *ref)
{
    CRef temp;
    QW product;
    QW *second = *(QW **)&ref->b;
    QW *first = *(QW **)&ref->a;
    asm("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvmul.xyz vf1, vf1, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tvmulx.xyzw vf3, vf2, vf1x\n\tqmfc2.ni %0, vf3" : "=r" (product) : "m" (*first), "m" (*second));
    CRef_ConstructVectorValue(&temp, product);
    CRef_CopyConstruct(result, &temp);
    CRef_Destruct(&temp);
    return result;
}
