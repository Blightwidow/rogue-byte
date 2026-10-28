struct CRef { int tagk; union { int n; float g; void *pv; }; void operator=(const CRef &); };
struct CPAIR { int pad[2]; CRef ref; CPAIR *next; };
struct CFrame;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
}
extern "C" CRef *RefOpMinimum(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef best;
    CRef_CopyConstruct(&best, &aref[0]);
    CPAIR *pair = aref[1].tagk == 0 ? 0 : (CPAIR *)aref[1].pv;
    for (; pair != 0; pair = pair->next) {
        CRef *other = &pair->ref;
        if (best.tagk == 0x15) {
            if (other->tagk == 0x15) {
                if (other->n < best.n)
                    best = *other;
            } else {
                if (other->g < (float)best.n)
                    best = *other;
            }
        } else {
            if (other->tagk == 0x15) {
                if ((float)other->n < best.g)
                    best = *other;
            } else {
                if (other->g < best.g)
                    best = *other;
            }
        }
    }
    CRef_CopyConstruct(pret, &best);
    CRef_Destruct(&best);
    return pret;
}
