// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct ALO;
struct ALOV;
struct XF;
union CHN_137A30 {
    int grf;
    struct { unsigned id : 20; unsigned kind : 10; unsigned fSkip : 1; unsigned fPos : 1; } bits;
};
struct ASEGCHN_137A30 { CHN_137A30 chn; int val; };
struct ENT_137A30 { CHN_137A30 chn; struct ACR_137A30 *pacr; };
struct ACR_137A30 { int n0; struct ASEG_137A30 *paseg; void *p8; int *an; QW dof; };
struct DOF_137A30 { int n0; int n4; void *p8; };
struct VT_137A30 { char pad[0x48]; short delta; short index; void (*fn)(void *); };
struct ASEG_137A30 {
    void *pframe;
    char pad0[8];
    VT_137A30 *vt;
    char pad1[0x5C - 0x10];
    int cent;
    ENT_137A30 *aent;
    char pad2[0x6C - 0x64];
    int n6C;
    char pad3[0x78 - 0x70];
    float g78;
    char pad4[0x98 - 0x7C];
    int n98;
    int n9C;
    int cA0;
    QW *aA4;
    int nA8;
    int nAC;
    char pad5[0xC0 - 0xB0];
    int cb;
    int cbl;
    struct BL_137A30 *abl;
    int cdof;
    DOF_137A30 *adof;
    int nD4;
    ASEG_137A30 *pasegSrc;
};
struct BL_137A30 { float w; ASEG_137A30 *paseg; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
ASEG_137A30 *PloNew(int, ALO *, int, int);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
void BindAsegChn(ASEG_137A30 *, ALO *, ENT_137A30 *, ALOV **, XF **);
QW GetXfDofValue(XF *, XF *);
void CFramePtr_Assign(void *, void *);
void ReblendAsegbl(void *);
}
extern "C" ACR_137A30 *PacrNew(int);
enum ACVK { ACVK_Nil };
ACR_137A30 *PacpNew(ACVK);
static inline void *PvAllocSw(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwImpl__Fi(&req);
}
static inline void *PvAllocSwClear(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwClearImpl__Fi(&req);
}
static inline void *PvAllocStackClear(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocStackClearImpl__Fi(&req);
}
static inline void *PvAllocSwCopy(int cb, void *pv)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwCopyImpl__FiPv(&req, pv);
}
static inline ACR_137A30 *PacrEnsure(ASEG_137A30 *paseg, ALO *paloRoot, ENT_137A30 *pent, int cbl)
{
    ACR_137A30 *pacr = pent->pacr;
    if (!pacr) {
        pacr = PacrNew(5);
        ALOV *palo;
        XF *pxf;
        BindAsegChn(paseg, paloRoot, pent, &palo, &pxf);
        pacr->dof = GetXfDofValue(pxf, pxf);
        pacr->paseg = paseg;
        pacr->p8 = paseg->adof;
        pacr->an = (int *)PvAllocSwClear(cbl * 4);
        pent->pacr = pacr;
    }
    return pacr;
}
static inline ACR_137A30 *PacpEnsure(ASEG_137A30 *paseg, ENT_137A30 *pent, int cbl)
{
    ACR_137A30 *pacr = pent->pacr;
    if (!pacr) {
        pacr = PacpNew((ACVK)2);
        pacr->paseg = paseg;
        pacr->p8 = paseg->adof;
        pacr->an = (int *)PvAllocSwClear(cbl * 4);
        pent->pacr = pacr;
        pent->chn.grf |= 0x80000000;
    }
    return pacr;
}
static inline BL_137A30 *Pbl(BL_137A30 *abl, int cb, int i) { return (BL_137A30 *)((char *)abl + i * cb); }
extern "C" void EnsureAsegBlendDynamic(ALO *paloRoot, int cb, int cbl, BL_137A30 *abl, int cdof, int *an0, int *an4, ASEG_137A30 **ppaseg)
{
    ASEG_137A30 *pasegSrc = 0;
    ASEG_137A30 *pasegFrame = 0;
    ASEG_137A30 *pasegFirst = 0;
    int i;
    for (i = 0; i < cbl; i++) {
        BL_137A30 *pbl = Pbl(abl, cb, i);
        ASEG_137A30 *paseg = pbl->paseg;
        if (paseg) {
            if (!pasegFirst)
                pasegFirst = paseg;
            if (!pasegSrc && (paseg->n98 || paseg->nA8 || paseg->cA0))
                pasegSrc = pbl->paseg;
            if (!pasegFrame)
                pasegFrame = pbl->paseg->pframe ? pbl->paseg : 0;
        }
    }
    if (!pasegFirst) {
        *ppaseg = 0;
        return;
    }
    char frame[0x10];
    CStackFrame_Construct(frame);
    ASEG_137A30 *paseg = PloNew(0x6E, paloRoot, -1, -1);
    paseg->vt->fn((char *)paseg + paseg->vt->delta);
    paseg->cb = cb;
    paseg->cbl = cbl;
    paseg->cdof = cdof;
    paseg->abl = abl;
    paseg->adof = (DOF_137A30 *)PvAllocSw(cdof * sizeof(DOF_137A30));
    for (i = 0; i < cdof; i++) {
        DOF_137A30 *pdof = &paseg->adof[i];
        pdof->n0 = an0[i];
        pdof->n4 = an4[i];
        pdof->p8 = PvAllocSw(pdof->n4 * 8);
    }
    if (pasegSrc) {
        paseg->pasegSrc = pasegSrc;
        paseg->n98 = pasegSrc->n98;
        paseg->n9C = pasegSrc->n9C;
        paseg->cA0 = pasegSrc->cA0;
        paseg->aA4 = (QW *)PvAllocSwCopy(pasegSrc->cA0 * sizeof(QW), pasegSrc->aA4);
        paseg->nA8 = pasegSrc->nA8;
        paseg->nAC = pasegSrc->nAC;
    }
    int cent = 0;
    for (i = 0; i < cbl; i++) {
        BL_137A30 *pbl = Pbl(abl, cb, i);
        if (pbl->paseg)
            cent += pbl->paseg->cent;
    }
    paseg->aent = (ENT_137A30 *)PvAllocStackClear(cent * sizeof(ENT_137A30));
    paseg->cent = 0;
    for (i = 0; i < cbl; i++) {
        BL_137A30 *pbl = Pbl(abl, cb, i);
        if (!pbl->paseg)
            continue;
        for (int ichn = 0; ichn < pbl->paseg->cent; ichn++) {
            ASEGCHN_137A30 *pchn = (ASEGCHN_137A30 *)&pbl->paseg->aent[ichn];
            if (pchn->chn.bits.fSkip)
                continue;
            ENT_137A30 *pent;
            int ient;
            for (ient = 0; ient < paseg->cent; ient++) {
                pent = &paseg->aent[ient];
                if ((pchn->chn.grf & 0x3FFFFFFF) == (paseg->aent[ient].chn.grf & 0x3FFFFFFF))
                    goto found;
            }
            pent = &paseg->aent[paseg->cent++];
            pent->chn.grf = (pent->chn.grf & 0xFFF00000) | ((unsigned)(pchn->chn.grf << 12) >> 12);
            pent->chn.grf = (pent->chn.grf & 0xC00FFFFF) | (pchn->chn.grf & 0x3FF00000);
        found:
            ACR_137A30 *pacr;
            if (!(pchn->chn.grf & 0x80000000))
                pacr = PacrEnsure(paseg, paloRoot, pent, cbl);
            else
                pacr = PacpEnsure(paseg, pent, cbl);
            pacr->an[i] = pchn->val;
        }
    }
    paseg->aent = (ENT_137A30 *)PvAllocSwCopy(paseg->cent * sizeof(ENT_137A30), paseg->aent);
    paseg->n6C = pasegFirst->n6C;
    paseg->nD4 = -1;
    paseg->g78 = pasegFirst->g78;
    if (pasegFrame)
        CFramePtr_Assign(paseg, pasegFrame->pframe);
    for (i = 0; i < cbl; i++) {
        BL_137A30 *pbl = Pbl(abl, cb, i);
        pbl->w = pbl->paseg == pasegFirst ? 1.0f : 0.0f;
    }
    ReblendAsegbl(paseg);
    *ppaseg = paseg;
    CStackFrame_Destructor(frame, 2);
}
