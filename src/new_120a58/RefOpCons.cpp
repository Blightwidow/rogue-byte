// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; };
struct SLOTHEAP;
struct CFrame;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void CRef_Destruct(CRef *);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
void PairHandle_Assign(CPair **, CPair *);
void CRef_ConstructPair(CRef *, CPair *);
}
extern "C" CRef *RefOpCons(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    PairHandle h;
    PairHandle_Init(&h, PpairNew());
    h.p->ref = *aref;
    CRef *pcdr = &aref[1];
    if (pcdr->tagk == 0x1F) {
        PairHandle_Assign(&h.p->next, (CPair *)pcdr->n);
    }
    CRef_ConstructPair(pref, h.p);
    CPair *held = h.p;
    if (held) {
        if (--held->cref == 0) {
            CPairPtr_Destructor(&held->next, 2);
            CRef_Destruct(&held->ref);
            UnlinkPairNode(held);
            FreeSlotheapPv(&B_004520A8, held);
        }
    }
    return pref;
}
