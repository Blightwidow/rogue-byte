// 0x129598 CRef_SetBool
#include "sly2.h"

extern "C" void CRef_Destruct(void* pref);
extern "C" const int TAGK2_Bool = 0x17;

void CRef_SetBool(void* pref, int f)
{
    CRef_Destruct(pref);
    ((int*)pref)[1] = f;
    ((int*)pref)[0] = TAGK2_Bool;
}