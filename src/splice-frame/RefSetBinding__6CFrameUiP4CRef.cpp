#include "sly2.h"
struct CRef { int tagk; int n; int pad8; int padc; CRef &operator=(const CRef &); };
struct CFrame;
extern "C" CRef *PrefFindBinding__6CFrameUii(CFrame *, int, int);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);

extern "C" CRef *RefSetBinding__6CFrameUiP4CRef(CRef *result, CFrame *frame, int binding, CRef *value)
{
    CRef refResult;
    refResult.tagk = -1;
    CRef *pref = PrefFindBinding__6CFrameUii(frame, binding, 1);
    if (pref != 0)
        *pref = *value;
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
