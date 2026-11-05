struct CRef { int tagk; union { int n; float g; void *pv; }; void operator=(const CRef &); };
struct CPAIR { int pad[2]; CRef ref; CPAIR *next; };
struct CFrame;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
}
extern "C" CRef *RefOpMaximum(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef best;
    CRef_CopyConstruct(&best, &aref[0]);
    if (aref[1].tagk != 0)
        aref = (CRef *)aref[1].pv;
    else
        aref = 0;
    CPAIR *pair = (CPAIR *)aref;
    for (; pair != 0; pair = pair->next) {
        if (best.tagk == 0x15) {
            if (pair->ref.tagk == 0x15) {
                CRef *pref = &pair->ref;
                if (best.n < pref->n)
                    best = *pref;
            } else {
                CRef *pref = &pair->ref;
                if ((float)best.n < pref->g)
                    best = *pref;
            }
        } else {
            if (pair->ref.tagk == 0x15) {
                CRef *pref = &pair->ref;
                if (best.g < (float)pref->n)
                    best = *pref;
            } else {
                CRef *pref = &pair->ref;
                if (best.g < pref->g)
                    best = *pref;
            }
        }
    }
    CRef_CopyConstruct(pret, &best);
    CRef_Destruct(&best);
    return pret;
}
