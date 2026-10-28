#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[7]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" int func_00142310(BASIC *, VECTOR *, QW, QW, float, float, float, float);
extern const AOT RO_002A3ED8;

CRef *func_0010B230(CRef *result, BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3ED8;
    VECTOR byPointer;
    VECTOR vecA;
    VECTOR vecB;
    float g0;
    float g1;
    float g2;
    float g3;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 7, args, &aotyp, &g0, &g1, &byPointer, &g2, &g3, &vecA, &vecB);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    func_00142310(object, &byPointer, *(QW *)&vecA, *(QW *)&vecB, g0, g1, g2, g3);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
