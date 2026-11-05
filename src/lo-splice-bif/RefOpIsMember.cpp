// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef {
    int tagk;
    int n;
    CRef() { tagk = -1; }
    CRef &operator=(const CRef &);
};
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct CFrame;
CRef RefOpEqual(int, CRef *, CFrame *);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" CRef *RefOpIsMember(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    CRef arefPair[2];
    CRef refFound;
    CRef *pfound = &refFound;
    refFound.tagk = 0x17;
    refFound.n = 0;
    if (aref[1].tagk == 0x1F) {
        arefPair[0] = aref[0];
        CPair *ppair = (CPair *)aref[1].n;
        if (ppair) do {
            arefPair[1] = ppair->ref;
            {
                CRef refTest = RefOpEqual(2, arefPair, pframe);
                refResult = refTest;
                CRef_Destruct(&refTest);
            }
            if (refResult.tagk == 0x17 && refResult.n != 0) {
                pfound->n = 1;
                break;
            }
            ppair = ppair->next;
        } while (ppair);
    }
    CRef_CopyConstruct(pret, pfound);
    CRef_Destruct(pfound);
    CRef *pelement = arefPair + 2;
    while (arefPair != pelement) {
        --pelement;
        CRef_Destruct(pelement);
    }
    CRef_Destruct(&refResult);
    return pret;
}
