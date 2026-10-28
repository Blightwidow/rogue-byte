#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CFrame;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefAddOption__FP5BASICiP4CRef(CRef *, int, int, CRef *);
extern "C" void RefEnsureOption__FP5BASICiP4CRef(CRef *, int, int, CRef *);
extern "C" void RefSetOption__FP5BASICiP4CRef(CRef *, int, int, CRef *);
extern "C" void RefGetOption(CRef *, int, int);

extern "C" CRef *RefOpObjectOption__FiP4CRefP6CFrame4BIFK(CRef *pref, int carg, CRef *aref, CFrame *pframe, int bifk)
{
    int pbasic = aref[0].n;
    int oid = aref[1].n;
    CRef refResult;
    CRef refOption;
    refResult.tagk = -1;
    switch (bifk) {
    case 0x6c:
        RefAddOption__FP5BASICiP4CRef(&refOption, pbasic, oid, &aref[2]);
        refResult = refOption;
        CRef_Destruct(&refOption);
        break;
    case 0x6d:
        RefEnsureOption__FP5BASICiP4CRef(&refOption, pbasic, oid, &aref[2]);
        refResult = refOption;
        CRef_Destruct(&refOption);
        break;
    case 0x6e:
        RefSetOption__FP5BASICiP4CRef(&refOption, pbasic, oid, &aref[2]);
        refResult = refOption;
        CRef_Destruct(&refOption);
        break;
    case 0x6f:
        RefGetOption(&refOption, pbasic, oid);
        refResult = refOption;
        CRef_Destruct(&refOption);
        break;
    }
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}
