#include "sly2.h"
struct CRef { int tagk; int n; int pad8; int padc; };
struct ARG { int tagk; int n; };
struct JOY;
extern JOY B_002DFC00;
extern "C" CRef *CRef_RefCoerceF32(CRef *, ARG *);
extern "C" void TriggerJoyRumbleRumk__FP3JOY4RUMKf(JOY *, int, float);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);

CRef *RefOpStartRumble(CRef *result, int count, ARG *args, void *frame)
{
    JOY *pjoy = &B_002DFC00;
    int rumk = args[0].n;
    CRef refTemp;
    CRef_RefCoerceF32(&refTemp, args + 1);
    TriggerJoyRumbleRumk__FP3JOY4RUMKf(pjoy, rumk, *(float *)&refTemp.n);
    CRef_Destruct(&refTemp);
    SetTag__4CRef4TAGK(&refTemp, 0x24);
    CRef_CopyConstruct(result, &refTemp);
    CRef_Destruct(&refTemp);
    return result;
}
