#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int pad0; int pad4; CRef ref; CPair *unk0x10; };
struct CFrame;
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);

CRef *RefOpNth(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    SetTag__4CRef4TAGK(&refResult, 0);
    if (aref[0].tagk == 0x1F) {
        CRef *pnth = &aref[1];
        int index = 0;
        CPair *ppair = (CPair *)aref[0].n;
        while (ppair != 0) {
            if (index == pnth->n) {
                refResult = ppair->ref;
                break;
            }
            index++;
            ppair = ppair->unk0x10;
        }
    }
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}
