#include "sly2.h"
struct CRef;
extern "C" int CRef_CopyConstruct(CRef *, const CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" int SetTag__4CRef4TAGK(CRef *, int);
struct CRef {
    int tagk;
    int n;
    CRef() { tagk = -1; }
    CRef(const CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
    CRef &operator=(const CRef &);
};
struct BINDING_12AA70 { char pad[8]; int sym; CRef ref; BINDING_12AA70 *next; };
struct CSidebag_12AA70 { char pad[8]; BINDING_12AA70 *head; };

extern "C" CRef CSidebag_RefSetBinding(CSidebag_12AA70 *psidebag, int sym, CRef *pvalue)
{
    for (BINDING_12AA70 *pbinding = psidebag->head; pbinding != 0; pbinding = pbinding->next) {
        if (pbinding->sym == sym) {
            CRef ref;
            pbinding->ref = *pvalue;
            CRef_Destruct(&ref);
            SetTag__4CRef4TAGK(&ref, 0x24);
            return ref;
        }
    }
    CRef ref;
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    return ref;
}
