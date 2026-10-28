struct CRef { int tagk; union { int n; float g; void *pv; }; void operator=(const CRef &); };
struct CPAIR { int pad[2]; CRef ref; CPAIR *next; };
struct CFrame;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
}
static inline int FRefLess(CRef *a, CRef *b)
{
    if (a->tagk == 0x15) {
        if (b->tagk == 0x15)
            return a->n < b->n;
        return (float)a->n < b->g;
    }
    if (b->tagk == 0x15)
        return a->g < (float)b->n;
    return a->g < b->g;
}
extern "C" CRef *RefOpMaximum(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef best;
    CRef_CopyConstruct(&best, &aref[0]);
    CPAIR *pair = aref[1].tagk == 0 ? 0 : (CPAIR *)aref[1].pv;
    for (; pair != 0; pair = pair->next) {
        if (FRefLess(&best, &pair->ref))
            best = pair->ref;
    }
    CRef_CopyConstruct(pret, &best);
    CRef_Destruct(&best);
    return pret;
}
