#include "sly2.h"
struct CRef { int tagk; int n; };
struct CRefLarge { int tagk; int pad[3]; };
struct CFrame;
extern "C" void CRef_SetS32(CRefLarge *, int);
extern "C" void CRef_SetF32(CRefLarge *, float);
extern "C" void CRef_CopyConstruct(CRef *, CRefLarge *);
extern "C" void CRef_Destruct(CRefLarge *);

extern "C" CRef *RefOpAbs(CRef *result, int count, CRef *args, CFrame *frame)
{
    CRefLarge refAbs;
    refAbs.tagk = -1;
    if (args[0].tagk == 0x15) {
        int value = args[0].n;
        value = value < 0 ? -value : value;
        CRef_SetS32(&refAbs, value);
    } else {
        float value = *(float *)&args[0].n;
        float zero;
        asm("mtc1 $0,%0\n\tnop" : "=f"(zero));
        if (value < zero) value = -value;
        CRef_SetF32(&refAbs, value);
    }
    CRef_CopyConstruct(result, &refAbs);
    CRef_Destruct(&refAbs);
    return result;
}
