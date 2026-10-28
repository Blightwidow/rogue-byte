#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct BINDING { char pad[8]; int sym; CRef ref; BINDING *next; };
struct CSidebag { char pad[8]; BINDING *head; };
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);

extern "C" CRef *CSidebag_RefSetBinding(CRef *pref, CSidebag *psidebag, int sym, CRef *pvalue)
{
    for (BINDING *pbinding = psidebag->head; pbinding != 0; pbinding = pbinding->next) {
        if (pbinding->sym == sym) {
            CRef refVoid;
            refVoid.tagk = -1;
            pbinding->ref = *pvalue;
            asm volatile("");
            CRef_Destruct(&refVoid);
            SetTag__4CRef4TAGK(&refVoid, 0x24);
            CRef_CopyConstruct(pref, &refVoid);
            CRef_Destruct(&refVoid);
            return pref;
        }
    }
    CRef refVoid2;
    CRef &refVoid = refVoid2;
    refVoid.tagk = -1;
    CRef_Destruct(&refVoid);
    SetTag__4CRef4TAGK(&refVoid, 0x24);
    CRef_CopyConstruct(pref, &refVoid);
    CRef_Destruct(&refVoid);
    return pref;
}
