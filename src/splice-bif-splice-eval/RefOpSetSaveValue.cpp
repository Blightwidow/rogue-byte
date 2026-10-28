#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct SAVEPATH { char b[0x10]; };
struct CFrame;
extern "C" char B_003E0EA8[];
extern "C" char B_003D4A60[];
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void ConvertListToSavePath(int, SAVEPATH *);
extern "C" void RefSetSaveValue(CRef *, void *, SAVEPATH *, CRef *, void *);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);

extern "C" CRef *RefOpSetSaveValue(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    char frame[0x10];
    SAVEPATH path;
    CRef refValue;
    refResult.tagk = -1;
    CStackFrame_Construct(frame);
    ConvertListToSavePath(aref[0].n, &path);
    RefSetSaveValue(&refValue, B_003E0EA8, &path, &aref[1], B_003D4A60);
    refResult = refValue;
    CRef_Destruct(&refValue);
    CRef_CopyConstruct(pref, &refResult);
    CStackFrame_Destructor(frame, 2);
    CRef_Destruct(&refResult);
    return pref;
}
