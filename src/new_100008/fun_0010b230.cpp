#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[7]; };
extern "C" int func_00142310(BASIC *, VECTOR *, QW, QW, float, float, float, float);
extern const AOT RO_002A3ED8;

CRef func_0010B230(BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3ED8;
    VECTOR byPointer;
    VECTOR vecA;
    VECTOR vecB;
    float g0;
    float g1;
    float g2;
    float g3;
    RefSetArgsFromSplice(7, args, &aotyp, &g0, &g1, &byPointer, &g2, &g3, &vecA, &vecB);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_00142310(object, &byPointer, *(QW *)&vecA, *(QW *)&vecB, g0, g1, g2, g3);
    return refResult;
}
