#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPAIR { int refcount; int pad4; char ref[8]; CPAIR *next; };
struct EOPID { int otyp; int grfeopid; char rest[0x20]; };
struct LOCALS {
    EOPID eopid;
    char pad0x28[8];
    CPAIR *ppairHead;
    char pad0x34[0xC];
    CPAIR *ppairHandle;
    char pad0x44[0xC];
    CRef refElement;
};
extern "C" {
void SetTag__4CRef4TAGK(CRef *, int);
CPAIR *PpairNew(void);
void PairHandle_Init(CPAIR **, CPAIR *);
void RefGetPeopid(CRef *, void *, EOPID *);
CRef *CRef_Destruct(CRef *);
void PairHandle_Assign(CPAIR **, CPAIR *);
void CPairPtr_Destructor(CPAIR **, int);
void UnlinkPairNode(CPAIR *);
void FreeSlotheapPv(void *, void *);
void CRef_ConstructPair(CRef *, CPAIR *);
extern char B_004520A8;
}
static inline void ReleasePairNode(CPAIR *ppair)
{
    if (ppair != 0) {
        ppair->refcount = ppair->refcount - 1;
        if (ppair->refcount == 0) {
            CPairPtr_Destructor(&ppair->next, 2);
            CRef_Destruct((CRef *)ppair->ref);
            UnlinkPairNode(ppair);
            FreeSlotheapPv(&B_004520A8, ppair);
        }
    }
}
CRef *RefSetArgListFromPvs(CRef *prefResult, int cpv, const int *aotyp, void **apv)
{
    if (cpv == 0) {
        SetTag__4CRef4TAGK(prefResult, 0);
        return prefResult;
    }
    LOCALS locals;
    locals.ppairHead = 0;
    memset(&locals.eopid, 0, 0x28);
    locals.eopid.grfeopid = 2;
    CPAIR **pppairTail = &locals.ppairHead;
    for (int ipv = 0; ipv < cpv; ipv++) {
        locals.eopid.otyp = aotyp[ipv];
        void *pv = apv[ipv];
        CPAIR *ppairNew = PpairNew();
        PairHandle_Init(&locals.ppairHandle, ppairNew);
        RefGetPeopid(&locals.refElement, pv, &locals.eopid);
        ((CRef *)locals.ppairHandle->ref)->operator=(locals.refElement);
        CRef_Destruct(&locals.refElement);
        PairHandle_Assign(pppairTail, locals.ppairHandle);
        pppairTail = &locals.ppairHandle->next;
        ReleasePairNode(locals.ppairHandle);
    }
    CRef_ConstructPair(prefResult, locals.ppairHead);
    ReleasePairNode(locals.ppairHead);
    return prefResult;
}
