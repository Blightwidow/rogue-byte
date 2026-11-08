// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct RefT { int tagk; int n; };
struct CPair { int cref; int field4; RefT ref; CPair *next; };
struct SLOTHEAP;
struct EOPID { int otyp; int grf; int ibGet; int fieldC[7]; };
struct PairHandle;
extern "C" {
CPair *PpairNew(void);
void PairHandle_Init(PairHandle *, CPair *);
void PairHandle_Assign(PairHandle *, CPair *);
void CRef_Destruct(RefT *);
void SetTag__4CRef4TAGK(RefT *, int);
void CPairPtr_Destructor(CPair **, int);
void UnlinkPairNode(CPair *);
void FreeSlotheapPv(SLOTHEAP *, void *);
void RefGetPeopid(RefT *, void *, EOPID *);
void __as__4CRefRC4CRef(RefT *dst, RefT *src);
void CRef_ConstructPair(RefT *, CPair *);
extern SLOTHEAP B_004520A8;
}
// A counted handle to a pair: PairHandle_Init (0x256C38) is its constructor, PairHandle_Assign (0x256C58) its assignment, and the
// release block retail repeats for the loop's handle and for the head is its inline destructor.
struct PairHandle {
    CPair *p;
    PairHandle() : p(0) {}
    PairHandle(CPair *pair) { PairHandle_Init(this, pair); }
    PairHandle(const PairHandle &other);
    void operator=(CPair *pair) { PairHandle_Assign(this, pair); }
    ~PairHandle()
    {
        CPair *held = p;
        if (held) {
            if (--held->cref == 0) {
                CPairPtr_Destructor(&held->next, 2);
                CRef_Destruct(&held->ref);
                UnlinkPairNode(held);
                FreeSlotheapPv(&B_004520A8, held);
            }
        }
    }
};
// Builds a list of count refs read through RefGetPeopid (otyp, grf 2, ibGet index * 4) and returns it as a ref to the head pair.
// Retail computes sp+0x30 twice: once into $a0 for `head = 0` and again into $s4 for the tail pointer. A direct call
// PairHandle_Assign(&head, 0) puts the argument in a pseudo that CSE then reuses for the tail (score 22); the inline operator=
// passes `this` as the fixed frame address straight into $a0, so the tail recomputes it, as retail does.
// memset takes the size 0x28 (retail loads $a2). Retail puts head at sp+0x30 after the 0x28-byte eopid and handle at 0x40: 16-byte
// slots, so the handle is a BLKmode class (the declared copy constructor makes it one, as a counted handle has); a plain 4-byte struct
// packs them (head 0x28) and a 16-byte struct needs a padding field. Still differs (score 4): sched2 puts `a1 = v0` before
// `a0 = sp+0x40` ahead of PairHandle_Init, so the delay slot gets a0; retail has a0 first and a1 in the slot. The padded variant
// 200F58_pad.cpp (int pad[3] in the handle, TImode) scores 0 but breaks the padding rule.
extern "C" RefT *func_00200F58(RefT *pret, int count, int otyp, void *pbasic)
{
    if (count == 0) {
        SetTag__4CRef4TAGK(pret, 0);
        return pret;
    }
    EOPID eopid;
    PairHandle head;
    memset(&eopid, 0, sizeof(eopid));
    eopid.otyp = otyp;
    eopid.grf = 2;
    head = 0;
    PairHandle *tail = &head;
    for (int index = 0; index < count; index++) {
        eopid.ibGet = index * 4;
        PairHandle handle(PpairNew());
        RefT element;
        RefT *dst = &handle.p->ref;
        RefGetPeopid(&element, pbasic, &eopid);
        __as__4CRefRC4CRef(dst, &element);
        CRef_Destruct(&element);
        *tail = handle.p;
        tail = (PairHandle *)&handle.p->next;
    }
    CRef_ConstructPair(pret, head.p);
    return pret;
}
