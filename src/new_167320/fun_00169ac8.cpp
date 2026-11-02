// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct BIS_169AC8;
struct REQ_169AC8 { int size; int align; };
struct MATRIX4_169AC8 { QW row[4]; };
struct HDR_169AC8 { int a[5]; };
struct INFO_169AC8 { int a[10]; };
struct EXTRA_169AC8 { int a[6]; };
struct DESC_169AC8 { char pad0[2]; unsigned char fShared; signed char fSkip; char pad4[0x10 - 4]; int cqw; };
struct VTE_169AC8 { short delta; short index; int (*fn)(char *, int); };
struct VT_169AC8 { char pad[0x198]; VTE_169AC8 find; };
struct OBJ_169AC8 { char pad[0xC]; VT_169AC8 *vt; };
struct CTX_169AC8 { OBJ_169AC8 *pobj; };
struct GEOM_169AC8 { int unk0; int unk4; MATRIX4_169AC8 *pmat; int grf; char *pb; int cb; char pad[0x28 - 0x18]; };
struct VTX_169AC8 { unsigned short a; unsigned short b; unsigned char c; char pad; };
struct VTXL_169AC8 { int unk0; VTX_169AC8 *avtx; };
struct MAP_169AC8 { int unk0; VTXL_169AC8 *avtxl; int *aivtxl; };
struct STRIP_169AC8 { int cidx; char pad0[8 - 4]; unsigned grf; char pad1[0x14 - 0xC]; int *aidx; char pad2[0x24 - 0x18]; int offA; int offB; int pad2C; int offC; char pad3[0x40 - 0x34]; };
extern "C" {
int S8Read__18CBinaryInputStream(BIS_169AC8 *);
int S16Read__18CBinaryInputStream(BIS_169AC8 *);
int S32Read__18CBinaryInputStream(BIS_169AC8 *);
unsigned U32Read__18CBinaryInputStream(BIS_169AC8 *);
void CBinaryInputStream_ReadMatrix4(BIS_169AC8 *, MATRIX4_169AC8 *);
void *PvAllocSwImpl__Fi(REQ_169AC8 *);
void *PvAllocSwCopyImpl__FiPv(REQ_169AC8 *, void *);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
MAP_169AC8 *func_0016C8E0(CTX_169AC8 *, BIS_169AC8 *);
void __ml__FRC7MATRIX4T0(MATRIX4_169AC8 *, MATRIX4_169AC8 *, MATRIX4_169AC8 *);
void CopyAb__FPvT0Ui(void *, void *, unsigned);

void func_00169AC8(CTX_169AC8 *pctx, HDR_169AC8 *phdrSrc, INFO_169AC8 *pinfoSrc, EXTRA_169AC8 *pextraSrc, DESC_169AC8 *pdesc,
                   GEOM_169AC8 *pgeom, EXTRA_169AC8 *pextra, int cstrip, int *acstrip, STRIP_169AC8 **aastrip, BIS_169AC8 *pbis)
{
    struct {
        MATRIX4_169AC8 mat;
        REQ_169AC8 req;
        char pad[8];
        char frame[0x10];
        MATRIX4_169AC8 matCopy;
        MATRIX4_169AC8 matProduct;
    } l;
    S8Read__18CBinaryInputStream(pbis);
    *(HDR_169AC8 *)pdesc = *phdrSrc;
    *(INFO_169AC8 *)pgeom = *pinfoSrc;
    if (pextra != 0) {
        *pextra = *pextraSrc;
        pextra->a[5] = U32Read__18CBinaryInputStream(pbis);
    }
    OBJ_169AC8 *pobj = pctx->pobj;
    VTE_169AC8 *pvte = &pobj->vt->find;
    pgeom->unk4 = pvte->fn((char *)pobj + pvte->delta, S16Read__18CBinaryInputStream(pbis));
    if (pgeom->grf & 0x1000) {
        CBinaryInputStream_ReadMatrix4(pbis, &l.mat);
    } else {
        REQ_169AC8 *preq = &l.req;
        l.req.size = 0x40;
        preq->align = 0x10;
        pgeom->pmat = (MATRIX4_169AC8 *)PvAllocSwImpl__Fi(preq);
        CBinaryInputStream_ReadMatrix4(pbis, pgeom->pmat);
    }
    pgeom->unk0 = S32Read__18CBinaryInputStream(pbis);
    pgeom->grf = (pgeom->grf & ~0x800) | ((S8Read__18CBinaryInputStream(pbis) & 1) << 11);
    CStackFrame_Construct(l.frame);
    MAP_169AC8 *pmap = func_0016C8E0(pctx, pbis);
    if (!(pdesc->fShared & 1) && pdesc->fSkip == 0) {
        char *pbOld = pgeom->pb;
        REQ_169AC8 *preq = &l.req;
        l.req.size = pdesc->cqw << 4;
        preq->align = 0x10;
        char *pbNew = (char *)PvAllocSwCopyImpl__FiPv(preq, pbOld);
        pgeom->cb += pbNew - pbOld;
        pgeom->pb = pbNew;
        if (pgeom->grf & 0x1000) {
            __ml__FRC7MATRIX4T0(&l.matProduct, (MATRIX4_169AC8 *)((char *)pgeom->unk4 + 0x40), &l.mat);
            l.matCopy = l.matProduct;
            CopyAb__FPvT0Ui(pgeom->pb + 0x14, &l.matCopy, 0x40);
        }
        if (pmap != 0) {
            for (int istrip = 0; istrip < cstrip; istrip++) {
                int c = acstrip[istrip];
                STRIP_169AC8 *astrip = aastrip[istrip];
                for (int i = 0; i < c; i++) {
                    STRIP_169AC8 *pstrip = &astrip[i];
                    if (!(pstrip->grf & 0x20))
                        continue;
                    int cb = pgeom->cb;
                    unsigned short *pa = (unsigned short *)(pstrip->offA + cb);
                    unsigned short *pb = (unsigned short *)(pstrip->offB + cb);
                    unsigned char *pc = (unsigned char *)(pstrip->offC + cb);
                    for (int k = 0; k < pstrip->cidx; k++) {
                        int ivtx = pstrip->aidx[k];
                        VTXL_169AC8 *pvtxl = &pmap->avtxl[pmap->aivtxl[istrip]];
                        pa[k] = pvtxl->avtx[ivtx].a;
                        pb[k] = pvtxl->avtx[ivtx].b;
                        pc[k] = pvtxl->avtx[ivtx].c;
                    }
                }
            }
        }
    }
    CStackFrame_Destructor(l.frame, 2);
}
}
