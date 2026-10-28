// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct PairHandle { CPair *p; int pad; };
struct CFrame;
struct SLOTHEAP;
extern "C" {
PairHandle *func_00121578(PairHandle *, CRef **, CRef **);
CRef *RefEval(CRef *, CPair *, CFrame *);
void CRef_Destruct(CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
}
extern "C" CRef *RefOpForEach(CRef *pretRef, int carg, CRef *aref, CFrame *pframe)
{
    if (aref[1].tagk == 0x1F) {
        PairHandle call;
        CRef refIgnored;
        CRef *prefCallee;
        CRef *prefArg;
        func_00121578(&call, &prefCallee, &prefArg);
        *prefCallee = aref[0];
        for (CPair *element = (CPair *)aref[1].n; element; ) {
            *prefArg = element->ref;
            RefEval(&refIgnored, call.p, pframe);
            element = element->next;
            CRef_Destruct(&refIgnored);
        }
        CPair *held = call.p;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode(held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
    }
    SetTag__4CRef4TAGK(pretRef, 0x24);
    return pretRef;
}
