// SPDX-License-Identifier: GPL-3.0-or-later
struct ROPESIM { char pad[0x4C]; int nMode; };
struct CRV { char pad0[0x40]; unsigned grfField; char pad1[0x17C - 0x44]; ROPESIM *prope; };
extern "C" void *PattachCrv(CRV *, int);
extern "C" void func_001A6CA8(CRV *, int);

static inline void SetFlags(CRV *pcrv, unsigned mask)
{
    if (((pcrv->grfField ^ 1) & 1) != 0)
        *(unsigned *)pcrv->grfField |= mask;
    else
        pcrv->grfField |= mask;
}

static inline void ClearFlags(CRV *pcrv, unsigned mask)
{
    if (((pcrv->grfField ^ 1) & 1) != 0)
        *(unsigned *)pcrv->grfField &= ~mask;
    else
        pcrv->grfField &= ~mask;
}

extern "C" void SetCrvRopeMode(CRV *pcrv, int nMode)
{
    if (nMode != -1) {
        PattachCrv(pcrv, 1);
        func_001A6CA8(pcrv, 0);
        ClearFlags(pcrv, 0x20u);
        SetFlags(pcrv, 0xCu);
    } else {
        func_001A6CA8(pcrv, 0);
        SetFlags(pcrv, 0x20u);
        ClearFlags(pcrv, 0xCu);
    }
    if (pcrv->prope != 0)
        pcrv->prope->nMode = nMode;
}
