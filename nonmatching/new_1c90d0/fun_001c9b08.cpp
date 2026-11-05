#include "sly2.h"
struct ALLOCREQ_1C9B08 { int cb; int cbAlign; };
struct VTSINK_1C9B08 { char pad[8]; short delta; short index; void (*fn)(void *, int, void *); };
struct SINK_1C9B08 { VTSINK_1C9B08 *vt; };
struct LO_1C9B08;
struct PLOARRAY_1C9B08 { VTSINK_1C9B08 *vt; int unk4; int cplo; LO_1C9B08 **aplo; };
struct VTE_1C9B08 { short delta; short index; void *fn; };
struct VTLO_1C9B08 { char pad0[0xC8]; VTE_1C9B08 setCloneId; char pad1[0x128 - 0xD0]; VTE_1C9B08 transform; };
struct CLONESET_1C9B08 { int cpalo; LO_1C9B08 **apalo; int cpaloStride; int icloneFree; int id; char pad14[0x60 - 0x14]; int fShared; char pad64[0x6C - 0x64]; };
struct OPTION_1C9B08 { int kind; int cid; void *pframe; int cb; void *pv; int unk14; };
struct LO_1C9B08 {
    void *pframe;
    char pad4[0xC - 0x4];
    VTLO_1C9B08 *vt;
    char pad10[0x28 - 0x10];
    unsigned long grfo;
    char pad30[0x38 - 0x30];
    float unk38;
    char pad3C[0x50 - 0x3C];
    void *pxfParent;
    char pad54[0x60 - 0x54];
    MATRIX4 mat;
    char padA0[0xE0 - 0xA0];
    CLONESET_1C9B08 *pcloneset;
    char padE4[0xEC - 0xE4];
    int coption;
    OPTION_1C9B08 *aoption;
};
struct SW_1C9B08 { char pad[0x3F08]; CLONESET_1C9B08 *acloneSet; int pcnodeRoot; };
extern "C" {
int S32Read__18CBinaryInputStream(void *);
int S8Read__18CBinaryInputStream(void *);
int S16Read__18CBinaryInputStream(void *);
unsigned U32Read__18CBinaryInputStream(void *);
unsigned U16Read__18CBinaryInputStream(void *);
unsigned U8Read__18CBinaryInputStream(void *);
void *PxfFromRef(int, void *, int);
void CBinaryInputStream_ReadMatrix4(void *, MATRIX4 *);
void CBinaryInputStream_Skip(void *, int);
void CBinaryInputStream_Read_thunk(void);
int func_001CB770(SW_1C9B08 *, int);
int MakeCloneId(int, int);
LO_1C9B08 *PloNew(int, void *, int, int);
void InvalidateXfmMatWorld(LO_1C9B08 *);
void SetLoGrfzon(LO_1C9B08 *, unsigned);
void *PvAllocSwClearImpl__Fi(ALLOCREQ_1C9B08 *);
void *PvAllocSwImpl__Fi(ALLOCREQ_1C9B08 *);
void *PframeFromSpliceBlock(SW_1C9B08 *, int, void *);
void CFramePtr_Assign(void *, void *);
void CFrame_AddParent(void *, void *);
int FIsBasicDerivedFrom(void *, int);
void LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, void *);
void InitStackImpl__Fv(void);
void FreeStackImpl__Fv(void);
void InitPloarray(PLOARRAY_1C9B08 *);
void InstantiateClone(SW_1C9B08 *, int, void *, void *, int, MATRIX4 *, PLOARRAY_1C9B08 *);
int PcnodeFindOrAddClonePath(int, int, int *);
void CploFindSwObjects(SW_1C9B08 *, int, int, int, int, int, LO_1C9B08 **);
void func_0022D670(void *);
void func_0022D698(void *);
void LoadSwObjectsFromBrx(void *, void *, PLOARRAY_1C9B08 *);
}
static inline void *PvAllocSwClear_1C9B08(int cb)
{
    ALLOCREQ_1C9B08 req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwClearImpl__Fi(&req);
}
static inline void *PvAllocSw_1C9B08(int cb)
{
    ALLOCREQ_1C9B08 req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwImpl__Fi(&req);
}
extern "C" {

void func_001C9B08(SW_1C9B08 *psw, void *paloParent, int cid, int oid, int isplice, void *pbis, SINK_1C9B08 *psink)
{
    MATRIX4 mat;
    int idSet = S32Read__18CBinaryInputStream(pbis);
    int kind = S8Read__18CBinaryInputStream(pbis);
    void *pxf = PxfFromRef(S16Read__18CBinaryInputStream(pbis), paloParent, 0);
    CBinaryInputStream_ReadMatrix4(pbis, &mat);
    unsigned grfzon = U32Read__18CBinaryInputStream(pbis);
    int iset = func_001CB770(psw, idSet);
    int cloneid = MakeCloneId(iset, psw->acloneSet[iset].icloneFree);
    int fNew = 0;
    if (kind == 1 || (kind == -1 && psw->acloneSet[iset].fShared != 0))
        fNew = 1;
    if (fNew) {
        LO_1C9B08 *plo = PloNew(cid, paloParent, oid, -1);
        plo->pxfParent = pxf;
        plo->mat = mat;
        InvalidateXfmMatWorld(plo);
        SetLoGrfzon(plo, grfzon);
        CLONESET_1C9B08 *set = &psw->acloneSet[iset];
        plo->pcloneset = set;
        int cpalo = set->cpalo;
        if (cpalo > 0)
            plo->unk38 = set->apalo[cpalo * set->cpaloStride - 1]->unk38;
        plo->coption = U8Read__18CBinaryInputStream(pbis);
        plo->aoption = (OPTION_1C9B08 *)PvAllocSwClear_1C9B08(plo->coption * 0x18);
        for (int ioption = 0; ioption < plo->coption; ioption++) {
            OPTION_1C9B08 *poption = &plo->aoption[ioption];
            poption->kind = S32Read__18CBinaryInputStream(pbis);
            poption->cid = S16Read__18CBinaryInputStream(pbis);
            int iblock = S16Read__18CBinaryInputStream(pbis);
            if (iblock != -1)
                poption->pframe = PframeFromSpliceBlock(psw, iblock, 0);
            if (poption->kind == 5) {
                CFramePtr_Assign(plo, poption->pframe);
                int cb = U16Read__18CBinaryInputStream(pbis);
                if (!FIsBasicDerivedFrom(plo, poption->cid))
                    CBinaryInputStream_Skip(pbis, cb);
                else
                    LoadOptionsFromBrx__FPvP18CBinaryInputStream(plo, pbis);
            } else {
                poption->cb = U16Read__18CBinaryInputStream(pbis);
                poption->pv = PvAllocSw_1C9B08(poption->cb);
                CBinaryInputStream_Read_thunk();
            }
        }
        int cbSkip = S32Read__18CBinaryInputStream(pbis);
        S16Read__18CBinaryInputStream(pbis);
        CBinaryInputStream_Skip(pbis, cbSkip - 2);
        if (psink)
            psink->vt->fn((char *)psink + psink->vt->delta, 1, &plo);
    } else {
    if (!psink)
        InitStackImpl__Fv();
    PLOARRAY_1C9B08 ploarrayClone;
    PLOARRAY_1C9B08 ploarrayLoaded;
    InitPloarray(&ploarrayClone);
    InstantiateClone(psw, iset, paloParent, pxf, oid, &mat, &ploarrayClone);
    for (int iplo = 0; iplo < ploarrayClone.cplo; iplo++) {
        LO_1C9B08 *plo = ploarrayClone.aplo[iplo];
        if (!(plo->grfo & ((unsigned long)0x8000 << 43)))
            SetLoGrfzon(plo, grfzon);
    }
    int pcnode = PcnodeFindOrAddClonePath(psw->pcnodeRoot, 1, &cloneid);
    int cpatch = U8Read__18CBinaryInputStream(pbis);
    {
        for (int ipatch = 0; ipatch < cpatch; ipatch++) {
            LO_1C9B08 *ploTarget = 0;
            int oidTarget = S32Read__18CBinaryInputStream(pbis);
            int cidTarget = S16Read__18CBinaryInputStream(pbis);
            if ((unsigned)(oidTarget - 5) < 2) {
                if (ploarrayClone.cplo > 0)
                    ploTarget = ploarrayClone.aplo[0];
            } else {
                CploFindSwObjects(psw, 0xA05, oidTarget, 0, pcnode, 1, &ploTarget);
            }
            if (ploTarget && !FIsBasicDerivedFrom(ploTarget, cidTarget))
                ploTarget = 0;
            int iblock = S16Read__18CBinaryInputStream(pbis);
            if (ploTarget && iblock != -1) {
                void *pframe = PframeFromSpliceBlock(psw, iblock, ploTarget);
                if (ploTarget->pframe)
                    CFrame_AddParent(pframe, ploTarget->pframe);
                CFramePtr_Assign(ploTarget, pframe);
            }
            int cb = U16Read__18CBinaryInputStream(pbis);
            if (ploTarget)
                LoadOptionsFromBrx__FPvP18CBinaryInputStream(ploTarget, pbis);
            else
                CBinaryInputStream_Skip(pbis, cb);
        }
    }
    InitPloarray(&ploarrayLoaded);
    S32Read__18CBinaryInputStream(pbis);
    func_0022D670(pxf);
    LoadSwObjectsFromBrx(paloParent, pbis, &ploarrayLoaded);
    func_0022D698(pxf);
    for (int iplo = 0; iplo < ploarrayLoaded.cplo; iplo++) {
        LO_1C9B08 *plo = ploarrayLoaded.aplo[iplo];
        ((void (*)(void *, int, int))plo->vt->setCloneId.fn)((char *)plo + plo->vt->setCloneId.delta, cloneid, 1);
        ((void (*)(void *, MATRIX4 *))plo->vt->transform.fn)((char *)plo + plo->vt->transform.delta, &mat);
        if (!(plo->grfo & ((unsigned long)0x8000 << 43)))
            SetLoGrfzon(plo, grfzon);
    }
    if (!psink) {
        FreeStackImpl__Fv();
    } else {
        psink->vt->fn((char *)psink + psink->vt->delta, ploarrayClone.cplo, ploarrayClone.aplo);
        psink->vt->fn((char *)psink + psink->vt->delta, ploarrayLoaded.cplo, ploarrayLoaded.aplo);
    }
}
}
}
