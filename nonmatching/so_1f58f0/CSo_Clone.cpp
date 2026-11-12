// SPDX-License-Identifier: GPL-3.0-or-later
// CSo_Clone: copy a solid object from its template, then give the copy its own allocations and relocate the pointers into it.
#include "types.h"
#include "alloc.h"

struct ACT_1F6068 {
    u8 unknown_0x0[0x10];
    /* 0x10 */ ACT_1F6068 *pactNext;
};

/* one 0x100-byte entry of the array at SO+0x54 */
struct ENTRY_1F6068 {
    u8 unknown_0x0[0x90];
    /* 0x90 */ ACT_1F6068 *pactFirst;
    u8 unknown_0x94[0x4];
    /* 0x98 */ s16 kind;
    u8 unknown_0x9A[0x6];
    /* 0xA0 */ void *pvA0;
    u8 unknown_0xA4[0x4];
    /* 0xA8 */ void *pvA8;
    u8 unknown_0xAC[0x54];
};

struct CHAIN_1F6068 {
    void *pv0;
    void *pv4;
    void *pv8;
    void *pvC;
};

struct LINK_1F6068 {
    u8 unknown_0x0[0x60];
    /* 0x60 */ struct SET_1F6068 *pset;
    /* 0x64 */ ENTRY_1F6068 *pentry;
    u8 unknown_0x68[0x8];
};

struct SET_1F6068 {
    /* 0x0 */ s32 clink;
    /* 0x4 */ LINK_1F6068 *alink;
    u8 unknown_0x8[0x48];
};

struct GEOMDATA_1F6068 {
    s32 an[6];
};

struct BSPS_1F6068 {
    void *pv0;
    void *pv4;
    void *pv8;
};

/* one 0xB0-byte geom of the array at SO+0xE4 */
struct GEOM_1F6068 {
    u8 unknown_0x0[0x4];
    /* 0x4 */ struct SO_1F6068 *pso;
    u8 unknown_0x8[0x8];
    /* 0x10 */ BSPS_1F6068 *pbsps;
    u8 unknown_0x14[0x4C];
    /* 0x60 */ u8 dle[0x8];
    /* 0x68 */ u8 bspc[0x10];
    /* 0x78 */ s32 cvtx;
    u8 unknown_0x7C[0x4];
    /* 0x80 */ s32 ctri;
    u8 unknown_0x84[0xC];
    /* 0x90 */ GEOMDATA_1F6068 geom;
    u8 unknown_0xA8[0x8];
};

struct PHYSX_1F6068 {
    u8 unknown_0x0[0xDC];
    /* 0xDC */ struct SO_1F6068 **ppso;
};

struct DLSAVE_1F6068 {
    void *pvFirst;
    void *pvLast;
    s32 ibDle;
};

struct VTENTRY_1F6068 {
    s16 delta;
    s16 index;
    void *pfn;
};

struct SO_1F6068 {
    u8 unknown_0x0[0xC];
    /* 0xC */ VTENTRY_1F6068 *vt;
    u8 unknown_0x10[0x18];
    /* 0x28 */ u64 grfo;
    u8 unknown_0x30[0x20];
    /* 0x50 */ s32 centry;
    /* 0x54 */ ENTRY_1F6068 *aentry;
    /* 0x58 */ void *pxfLinear;
    /* 0x5C */ void *pxfAngular;
    /* 0x60 */ void *pxfRoot;
    /* 0x64 */ DLSAVE_1F6068 dlChild;
    /* 0x70 */ void *ploChildEnd;
    u8 unknown_0x74[0xC];
    /* 0x80 */ u8 globset[0x60];
    /* 0xE0 */ s32 cgeom;
    /* 0xE4 */ GEOM_1F6068 *ageom;
    /* 0xE8 */ PHYSX_1F6068 *pphys;
    /* 0xEC */ void *poxa;
    u8 unknown_0xF0[0x44];
    /* 0x134 */ s32 field_0x134;
};

extern "C" {
void CLo_Clone(SO_1F6068 *pso, SO_1F6068 *psoBase);
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *preq, void *pv);
void *PvAllocStackImpl__Fi(ALLOCREQ *preq);
void *CStackFrame_Construct(void *pframe);
void CStackFrame_Destructor(void *pframe, int grf);
ACT_1F6068 *PactClone(ACT_1F6068 *pact, SO_1F6068 *pso, ENTRY_1F6068 *pentry);
void InsertXfAct(SO_1F6068 *pso, ENTRY_1F6068 *pentry, ACT_1F6068 *pact);
void CloneGlobset(void *pglobset, SO_1F6068 *pso, SO_1F6068 *psoBase);
void ClearDle__FP3DLE(void *pdle);
void CloneGeom(GEOMDATA_1F6068 *pgeom, int grf, GEOMDATA_1F6068 *pgeomOut);
void CloneBspc__FP4GEOMP4BSPCT0T1(void *pbspcBase, GEOMDATA_1F6068 *pgeomBase, void *pbspc, GEOMDATA_1F6068 *pgeom);
void AddSoGeomsToOxa(SO_1F6068 *pso);
void func_001F2500(SO_1F6068 *pso);
extern s32 D_002C44F0;
}

/* SO's slot 52 (vtable +0x1A0): relocate the pointer at ppv from the template to the clone */
static inline void Relocate(SO_1F6068 *pso, SO_1F6068 *psoBase, void *ppv)
{
    VTENTRY_1F6068 *pvte = (VTENTRY_1F6068 *)((u8 *)pso->vt + 0x1A0);
    ((void (*)(void *, SO_1F6068 *, void *))pvte->pfn)((u8 *)pso + pvte->delta, psoBase, ppv);
}

extern "C" void CSo_Clone(SO_1F6068 *pso, SO_1F6068 *psoBase)
{
    void *poxa = pso->poxa;
    void *ploChildEnd = pso->ploChildEnd;
    DLSAVE_1F6068 dlChild = pso->dlChild;
    int ientry = 0;
    CLo_Clone(pso, psoBase);
    pso->poxa = poxa;
    pso->dlChild = dlChild;
    pso->ploChildEnd = ploChildEnd;
    pso->field_0x134 = 0;

    ALLOCREQ req;
    {
        ALLOCREQ *preq = &req;
        req.cb = pso->centry << 8;
        preq->cbAlign = 0x10;
        pso->aentry = (ENTRY_1F6068 *)PvAllocSwCopyImpl__FiPv(preq, pso->aentry);
    }
    for (; ientry < pso->centry; ientry++) {
        ALLOCREQ *preq = &req;
        ENTRY_1F6068 *pentry = &pso->aentry[ientry];
        Relocate(pso, psoBase, &pentry->pvA0);
        switch (pentry->kind) {
        case 4:
            Relocate(pso, psoBase, &pentry->pvA8);
            break;
        case 0xD: {
            req.cb = 0xE0;
            preq->cbAlign = 0x10;
            CHAIN_1F6068 *pchain = (CHAIN_1F6068 *)PvAllocSwCopyImpl__FiPv(preq, pentry->pvA8);
            Relocate(pso, psoBase, &pchain->pv0);
            Relocate(pso, psoBase, &pchain->pv4);
            Relocate(pso, psoBase, &pchain->pv8);
            Relocate(pso, psoBase, &pchain->pvC);
            ((ENTRY_1F6068 *)pchain->pv4)->pvA8 = pchain;
            ((ENTRY_1F6068 *)pchain->pv8)->pvA8 = pchain;
            break;
        }
        case 0xF: {
            req.cb = 0x10;
            preq->cbAlign = 0x10;
            CHAIN_1F6068 *pchain = (CHAIN_1F6068 *)PvAllocSwCopyImpl__FiPv(preq, pentry->pvA8);
            pentry->pvA8 = pchain;
            if (pchain->pv0 != &D_002C44F0)
                Relocate(pso, psoBase, &pchain->pv0);
            Relocate(pso, psoBase, &pchain->pv4);
            break;
        }
        case 0x10: {
            LINK_1F6068 *plink = (LINK_1F6068 *)pentry->pvA8;
            SET_1F6068 *pset = plink->pset;
            if (plink == pset->alink) {
                req.cb = 0x50;
                preq->cbAlign = 0x10;
                pset = (SET_1F6068 *)PvAllocSwCopyImpl__FiPv(preq, pset);
                preq->cbAlign = 0x10;
                req.cb = pset->clink * 0x70;
                pset->alink = (LINK_1F6068 *)PvAllocSwCopyImpl__FiPv(preq, pset->alink);
                for (int ilink = 0; ilink < pset->clink; ilink++) {
                    LINK_1F6068 *plinkNew = &pset->alink[ilink];
                    plinkNew->pset = pset;
                    Relocate(pso, psoBase, &plinkNew->pentry);
                    plinkNew->pentry->pvA8 = plinkNew;
                }
            }
            break;
        }
        }

        ACT_1F6068 *pact = pentry->pactFirst;
        if (pact != 0) {
            int cact = 0;
            do {
                pact = pact->pactNext;
                cact++;
            } while (pact != 0);
            u8 frame[16];
            CStackFrame_Construct(frame);
            preq->cbAlign = 0x10;
            req.cb = cact * 4;
            ACT_1F6068 **apact = (ACT_1F6068 **)PvAllocStackImpl__Fi(preq);
            ACT_1F6068 **ppact = apact;
            for (pact = pentry->pactFirst; pact != 0; pact = pact->pactNext)
                *ppact++ = pact;
            pentry->pactFirst = 0;
            for (int iact = cact - 1; iact >= 0; iact--)
                InsertXfAct(pso, pentry, PactClone(apact[iact], pso, pentry));
            CStackFrame_Destructor(frame, 2);
        }
    }

    Relocate(pso, psoBase, &pso->pxfLinear);
    Relocate(pso, psoBase, &pso->pxfAngular);
    Relocate(pso, psoBase, &pso->pxfRoot);
    CloneGlobset(pso->globset, pso, psoBase);
    VTENTRY_1F6068 *pvte = (VTENTRY_1F6068 *)((u8 *)pso->vt + 0x1F8);
    int cgeomExtra = ((int (*)(void *))pvte->pfn)((u8 *)pso + pvte->delta);
    req.cbAlign = 0x10;
    req.cb = (pso->cgeom + cgeomExtra) * 0xB0;
    pso->ageom = (GEOM_1F6068 *)PvAllocSwCopyImpl__FiPv(&req, pso->ageom);
    for (int igeom = 0; igeom < pso->cgeom; igeom++) {
        ALLOCREQ *preq = &req;
        GEOM_1F6068 *pgeom = &pso->ageom[igeom];
        Relocate(pso, psoBase, pgeom);
        pgeom->pso = pso;
        ClearDle__FP3DLE(pgeom->dle);
        GEOMDATA_1F6068 geom;
        CloneGeom(&pgeom->geom, 0, &geom);
        pgeom->geom = geom;
        GEOM_1F6068 *pgeomBase = &psoBase->ageom[igeom];
        CloneBspc__FP4GEOMP4BSPCT0T1(pgeomBase->bspc, &pgeomBase->geom, pgeom->bspc, &pgeom->geom);
        if (pgeom->pbsps != 0) {
            req.cb = 0xC;
            preq->cbAlign = 0x10;
            BSPS_1F6068 *pbsps = (BSPS_1F6068 *)PvAllocSwCopyImpl__FiPv(preq, pgeom->pbsps);
            pgeom->pbsps = pbsps;
            req.cb = pgeom->cvtx << 4;
            preq->cbAlign = 0x10;
            pgeom->pbsps->pv0 = PvAllocSwCopyImpl__FiPv(preq, pbsps->pv0);
            preq->cbAlign = 0x10;
            req.cb = pgeom->cvtx << 4;
            pgeom->pbsps->pv4 = PvAllocSwCopyImpl__FiPv(preq, pgeom->pbsps->pv4);
            preq->cbAlign = 0x10;
            req.cb = pgeom->ctri * 0xC;
            pgeom->pbsps->pv8 = PvAllocSwCopyImpl__FiPv(preq, pgeom->pbsps->pv8);
        }
    }

    if (pso->pphys != 0) {
        req.cb = 0xE0;
        req.cbAlign = 0x10;
        PHYSX_1F6068 *pphys = (PHYSX_1F6068 *)PvAllocSwCopyImpl__FiPv(&req, pso->pphys);
        pso->pphys = pphys;
        if (pphys->ppso != 0) {
            req.cbAlign = 0x10;
            req.cb = 0x70;
            pso->pphys->ppso = (SO_1F6068 **)PvAllocSwCopyImpl__FiPv(&req, pphys->ppso);
            *pso->pphys->ppso = pso;
        }
    }
    if ((int)(pso->grfo >> 60) & 1)
        AddSoGeomsToOxa(pso);
    func_001F2500(pso);
}
