#include "sly2.h"
struct CRef { int tagk; float g; };
struct CFrame;
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void CRef_RefCoerceF32(CRef *, CRef *);
extern "C" float g_2dded0;

CRef *RefOpDeferObjectUpdate(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    CRef refVoid;
    SetTag__4CRef4TAGK(&refVoid, 0x24);
    float *pobject = (float *)((int *)aref)[1];
    CRef refDt;
    CRef_RefCoerceF32(&refDt, &aref[1]);
    float dt = refDt.g;
    CRef_Destruct(&refDt);
    pobject[0x30 / 4] = g_2dded0 + dt;
    CRef_CopyConstruct(pref, &refVoid);
    CRef_Destruct(&refVoid);
    return pref;
}
