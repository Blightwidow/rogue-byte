// SPDX-License-Identifier: GPL-3.0-or-later
struct CRV { char pad0[0x40]; unsigned grf; char pad1[0x138]; void *pattach; };
extern "C" void *__builtin_new(unsigned);
extern "C" void *ConstructRopeSim(void *, CRV *);
extern "C" void MeasureCrv(CRV *);
extern "C" void func_001A6CA8(CRV *, int);

static inline void ClearGrf(CRV *pcrv, unsigned mask)
{
    unsigned tagged = pcrv->grf;
    if (((tagged ^ 1) & 1) != 0) {
        unsigned *pu = (unsigned *)tagged;
        *pu = *pu & ~mask;
    } else {
        pcrv->grf = tagged & ~mask;
    }
}
static inline void SetGrf(CRV *pcrv, unsigned mask)
{
    unsigned tagged = pcrv->grf;
    if (((tagged ^ 1) & 1) != 0) {
        unsigned *pu = (unsigned *)tagged;
        *pu = *pu | mask;
    } else {
        pcrv->grf = tagged | mask;
    }
}

extern "C" void *PattachCrv(CRV *pcrv, int n)
{
    if (pcrv->pattach == 0) {
        void *pnew = __builtin_new(0x90);
        pcrv->pattach = ConstructRopeSim(pnew, pcrv);
        MeasureCrv(pcrv);
        func_001A6CA8(pcrv, 0);
        ClearGrf(pcrv, 0x20);
        SetGrf(pcrv, 0xC);
    } else if (n == 1) {
        func_001A6CA8(pcrv, 0);
        SetGrf(pcrv, 4);
    }
    return pcrv->pattach;
}
