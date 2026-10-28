#include "sly2.h"
struct CRef { int tagk; union { int n; QW *pv; }; };
struct CPair;
struct PairHandle { CPair *p; };
struct CPair { int cref; int pad4; CRef ref; PairHandle next; };
struct SLOTHEAP;
struct CFrame;
struct MATRIX3;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(PairHandle *, CPair *);
void CRef_Destruct(CRef *);
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_SetF32(CRef *, float);
CRef *CRef_ConstructPair(CRef *, CPair *);
void CPairPtr_Destructor(PairHandle *, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
extern SLOTHEAP B_004520A8;
}
extern "C" void DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(MATRIX3 *, float *, QW *);
extern "C" CRef *RefOpMatrixDecomposeToRadianNormal(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    struct L { PairHandle h; int pad[3]; float gAngle[4]; } l;
    PairHandle &h = l.h;
    PairHandle_Init(&h, PpairNew());
    CPair *pp = h.p;
    CPair *pnew = PpairNew();
    PairHandle_Assign(&pp->next, pnew);
    CRef *pnormal = &h.p->next.p->ref;
    CRef_Destruct(pnormal);
    SetTag__4CRef4TAGK(pnormal, 0x1A);
    DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR((MATRIX3 *)aref[0].pv, l.gAngle, pnormal->pv);
    CRef_SetF32(&h.p->ref, l.gAngle[0]);
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
