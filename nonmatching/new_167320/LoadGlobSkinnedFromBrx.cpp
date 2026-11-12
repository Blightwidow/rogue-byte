/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "bis.h"
struct CM;
struct FGFN;
#include "alloc.h"
struct GLOB { char pad0[1]; signed char cweight; char pad2[0xA]; int base; };
struct ENTRY { int n0; int n4; int n8; char pad[0x50 - 0xC]; };
struct GLOBI { char pad0[0x18]; ENTRY *aentry; };
struct DESC { unsigned short w[8]; unsigned short aweight[4]; };
struct L {
    char vifs[0x30];
    int frame0;
    char pad44[0xC];
    ALLOCREQ req;
    char pad58[8];
    struct { int w0; unsigned pqwStart; int w8; unsigned pqwCur; char pad10[0x20]; } gifs;
    int frame1;
    struct FGFN *pfgfn;
    struct DESC *pdesc;
    int dmaOut;
};
extern "C" {
void __4VIFS(void *);
void __4GIFS(void *);
void *CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void AllocStack__4DMASi(void *, int);
void AddDmaCnt__4DMAS(void *);
void Reset__4DMAS(void *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void UnpackHelper__4VIFS3UPKiiPiPPUi(void *, int, int, int, int, void *);
void BuildCmFgfn__FP2CMfP4FGFN(CM *, float, FGFN *);
void AddPrimPack__4GIFSiiUl(void *, int, int, unsigned long);
void PackAD__4GIFSll(void *, long, long);
void PackRGBA__4GIFSUi(void *, unsigned);
void PackXYZF__4GIFSiiii(void *, int, int, int, int);
void EndPrim__4GIFSi(void *, int);
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
void VIFS_AddVifUnpackFromStream(void *, int, int, CBinaryInputStream *, int);
void AddVifStrow__4VIFSP2QW(void *, void *);
void AddVifStmask__4VIFSUi(void *, int);
void AddVifMscal__4VIFSPv(void *, void *);
void EndDmaCnt__4DMAS(void *);
void AddDmaRet__4DMAS(void *);
void DMAS_DetachCopyPermanent(void *, void *, void *, void *);
void func_001699E8(void *, GLOB *, GLOBI *, int, int, int, int, int, CBinaryInputStream *);
extern CM B_002DDF40;
extern char B_002DEB60[];
extern unsigned g_2deb50;
extern int D_002BE540[2][6];
extern char VU1_START_0[];
extern char D_00000738[];
extern char D_000007F0[];
}
static inline void *PvAllocSwClear(ALLOCREQ *preq, int cb)
{
    preq->cb = cb;
    preq->cbAlign = 0x10;
    return PvAllocSwClearImpl__Fi(preq);
}
extern "C" void LoadGlobSkinnedFromBrx(void *pv, GLOB *pglob, GLOBI *pglobi, float *pr, int arg4, int arg5, CBinaryInputStream *pbis)
{
    L l;
    int count = 0;
    __4VIFS(l.vifs);
    CStackFrame_Construct(&l.frame0);
    AllocStack__4DMASi(l.vifs, 0x2000);
    AddDmaCnt__4DMAS(l.vifs);
    UnpackHelper__4VIFS3UPKiiPiPPUi(l.vifs, 0xC, 1, 9, 0, &l.pfgfn);
    BuildCmFgfn__FP2CMfP4FGFN(&B_002DDF40, *pr, l.pfgfn);
    pglob->cweight = pbis->U8Read();
    pglobi->aentry = (ENTRY *)PvAllocSwClear(&l.req, pglob->cweight * sizeof(ENTRY));
    for (; count < pglob->cweight; count++) {
        ENTRY *pentry = &pglobi->aentry[count];
        pentry->n0 = pbis->S32Read();
        pentry->n8 = pbis->S16Read();
    }
    int base = 0x22;
    __4GIFS(&l.gifs);
    AllocStack__4DMASi(&l.gifs, 8);
    AddPrimPack__4GIFSiiUl(&l.gifs, 0, 2, 0x1E);
    PackAD__4GIFSll(&l.gifs, 0x42, 0x44);
    PackRGBA__4GIFSUi(&l.gifs, g_2deb50);
    EndPrim__4GIFSi(&l.gifs, 1);
    AddVifUnpack__4VIFS3UPKiPvi(l.vifs, 0xC, (l.gifs.pqwCur - l.gifs.pqwStart) >> 4, (void *)l.gifs.pqwStart, 0xD);
    Reset__4DMAS(&l.gifs);
    AddPrimPack__4GIFSiiUl(&l.gifs, 0xC1, 3, 0x44E);
    PackAD__4GIFSll(&l.gifs, 0x47, 0x73001);
    PackXYZF__4GIFSiiii(&l.gifs, 0, 0, 0, 0);
    PackXYZF__4GIFSiiii(&l.gifs, 0, 0, 0, 0);
    EndPrim__4GIFSi(&l.gifs, 0);
    AddPrimPack__4GIFSiiUl(&l.gifs, 1, 3, 0x44E);
    PackAD__4GIFSll(&l.gifs, 0x47, 0x72001);
    PackXYZF__4GIFSiiii(&l.gifs, 0, 0, 0, 0);
    PackXYZF__4GIFSiiii(&l.gifs, 0, 0, 0, 0);
    EndPrim__4GIFSi(&l.gifs, 1);
    AddVifUnpack__4VIFS3UPKiPvi(l.vifs, 0xC, 2, (void *)l.gifs.pqwStart, 0x12);
    AddVifUnpack__4VIFS3UPKiPvi(l.vifs, 0xC, 2, (void *)(l.gifs.pqwStart + 0x40), 0x16);
    AddVifUnpack__4VIFS3UPKiPvi(l.vifs, 0xC, 2, (void *)l.gifs.pqwStart, 0x1A);
    AddVifUnpack__4VIFS3UPKiPvi(l.vifs, 0xC, 2, (void *)(l.gifs.pqwStart + 0x40), 0x1E);
    if (pglob->cweight != 0) {
        pglob->base = base;
        base = pglob->cweight * 4 + 0x22;
    }
    int index = 0;
    int cpass = pbis->S16Read();
    if (cpass > 0) {
        do {
            CStackFrame_Construct(&l.frame1);
            UnpackHelper__4VIFS3UPKiiPiPPUi(l.vifs, 0xD, 3, 0xA, 0, &l.pdesc);
            memset(l.pdesc, 0, 0x18);
            switch (index) {
            case 0:
                l.pdesc->w[0] |= 1;
                break;
            case 1:
                l.pdesc->w[0] |= 2;
                break;
            }
            int cursor = base;
            l.pdesc->w[1] = cursor;
            int cvtx = pbis->U8Read();
            VIFS_AddVifUnpackFromStream(l.vifs, 8, cvtx, pbis, cursor);
            l.pdesc->w[4] = cursor;
            cursor += cvtx;
            l.pdesc->w[5] = cursor;
            if (pglob->cweight != 0) {
                int slot;
                int nweights = pbis->U8Read();
                for (slot = 0; slot < nweights; slot++)
                    l.pdesc->aweight[slot] = pglob->base + pbis->U8Read() * 4;
                for (; slot < 4; slot++)
                    l.pdesc->aweight[slot] = l.pdesc->aweight[0];
                if (nweights < 4) {
                    AddVifStrow__4VIFSP2QW(l.vifs, B_002DEB60);
                    AddVifStmask__4VIFSUi(l.vifs, D_002BE540[0][nweights]);
                }
                VIFS_AddVifUnpackFromStream(l.vifs, D_002BE540[1][nweights], cvtx, pbis, cursor);
                l.pdesc->w[2] = cursor;
                cursor += cvtx;
                if (nweights < 4)
                    AddVifStmask__4VIFSUi(l.vifs, 0);
            }
            int cnormal = pbis->U8Read();
            VIFS_AddVifUnpackFromStream(l.vifs, 0xE, cnormal, pbis, cursor);
            l.pdesc->w[6] = cursor;
            cursor += cnormal;
            l.pdesc->w[7] = cursor;
            AddVifMscal__4VIFSPv(l.vifs, VU1_START_0);
            AddVifMscal__4VIFSPv(l.vifs, D_00000738);
            AddVifMscal__4VIFSPv(l.vifs, D_000007F0);
            CStackFrame_Destructor(&l.frame1, 2);
            index++;
        } while (index < cpass);
    }
    EndDmaCnt__4DMAS(l.vifs);
    AddDmaRet__4DMAS(l.vifs);
    DMAS_DetachCopyPermanent(l.vifs, (char *)pglob + 0x10, &l.dmaOut, (char *)pglobi + 0x10);
    func_001699E8(pv, pglob, pglobi, arg4, arg5, 0, 0, 0, pbis);
    CStackFrame_Destructor(&l.frame0, 2);
}
