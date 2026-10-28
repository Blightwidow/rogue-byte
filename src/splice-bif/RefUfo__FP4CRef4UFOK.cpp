#include "sly2.h"
struct CRef { int tagk; int n; };
struct CRefLarge { int tagk; int pad[3]; };
extern "C" void CRef_SetF32(CRefLarge *, float);
extern "C" void CRef_CopyConstruct(CRef *, CRefLarge *);
extern "C" void CRef_Destruct(CRefLarge *);
extern float (*D_002BBB70[])(float);

extern "C" CRef *RefUfo(CRef *result, CRef *ref, int ufok)
{
    CRefLarge refResult;
    refResult.tagk = -1;
    float value;
    if (ref->tagk == 0x16) {
        value = *(float *)&ref->n;
    } else {
        value = (float)ref->n;
    }
    CRef_SetF32(&refResult, D_002BBB70[ufok](value));
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
