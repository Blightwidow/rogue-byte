#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC { int unk0; struct CSidebag *psidebag; };
struct CSidebag { int FFindBinding(int, CRef *); };
void *PeopidFind(BASIC *, int);
extern "C" void RefGetPeopid(CRef *, BASIC *, void *);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);

CRef *RefGetOption(CRef *result, BASIC *pbasic, int optid)
{
    if (optid < 0x4D1) {
        void *peopid = PeopidFind(pbasic, optid);
        RefGetPeopid(result, pbasic, peopid);
    } else {
        CRef found;
        found.tagk = -1;
        pbasic->psidebag->FFindBinding(optid, &found);
        CRef_CopyConstruct(result, &found);
        CRef_Destruct(&found);
    }
    return result;
}
