/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "bis.h"
#include "alloc.h"
struct GLOB { char pad0[1]; signed char cweight; char pad2[0xA]; int base; int dma; };
struct ENTRY { int n0; int n4; int n8; char pad[0x50 - 0xC]; };
struct GLOBI { char pad0[0x10]; int dma; char pad14[4]; ENTRY *aentry; };
struct GLOBD { char pad0[8]; int grf; };
struct SHD { char pad0[0x1C]; int cpass; };
struct UNP { unsigned short w[10]; unsigned short ashd[2]; unsigned short aweight[4]; };
extern "C" {
void __4VIFS(void *);
void *CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void AllocStack__4DMASi(void *, int);
void AddDmaCnt__4DMAS(void *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocStackImpl__Fi(ALLOCREQ *);
void UnpackHelper__4VIFS3UPKiiPiPPUi(void *, int, int, int, int, void *);
void AddVifStcycl__4VIFSii(void *, int, int);
void AddVifStrow__4VIFSP2QW(void *, void *);
void AddVifStmask__4VIFSUi(void *, int);
void AddVifMscal__4VIFSPv(void *, void *);
void EndDmaCnt__4DMAS(void *);
void AddDmaRet__4DMAS(void *);
void DMAS_DetachCopyPermanent(void *, void *, void *, void *);
SHD *PshdFromIndex(int);
int func_001EC688(SHD *, int, int, void *);
float func_002599D8(VECTOR *);
float func_002599E0(VECTOR *);
float func_002599E8(VECTOR *);
void func_001699E8(void *, GLOB *, GLOBI *, int, int, int, int, int, CBinaryInputStream *);
extern char B_002DEB60[];
extern int D_002BE540[];
extern int D_002BE558[];
extern char VU1_START_0[];
extern char D_00001910[];
extern char D_00001A68[];
}
void CopyAb(void *, void *, unsigned int);
static inline ALLOCREQ *Aligned(ALLOCREQ *preq)
{
    preq->cbAlign = 0x10;
    return preq;
}
static inline void *PvAllocSwClear(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    return PvAllocSwClearImpl__Fi(Aligned(&req));
}
static inline void *PvAllocStack(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    return PvAllocStackImpl__Fi(Aligned(&req));
}
extern "C" void LoadGlobIndexedFromBrx(void *pv, GLOB *pglob, GLOBI *pglobi, GLOBD *pglobd, int arg4, int arg5, CBinaryInputStream *pbis)
{
    char vifs[0x30];
    char frame0[0x10];
    int frame1;
    UNP *punpack;
    unsigned char *pweights;
    VECTOR *pvtx;
    int dmaOut;
    int count = 0;
    __4VIFS(vifs);
    CStackFrame_Construct(frame0);
    AllocStack__4DMASi(vifs, 0x2000);
    AddDmaCnt__4DMAS(vifs);
    pglob->cweight = pbis->U8Read();
    pglobi->aentry = (ENTRY *)PvAllocSwClear(pglob->cweight * sizeof(ENTRY));
    for (; count < pglob->cweight; count++) {
        ENTRY *pentry = &pglobi->aentry[count];
        pentry->n0 = pbis->S32Read();
        pentry->n8 = pbis->S16Read();
    }
    int base = 0x1B;
    if (pglob->cweight != 0) {
        pglob->base = 0x1B;
        base = pglob->cweight * 4 + 0x1B;
    }
    int index = 0;
    int cpass = pbis->S16Read();
    if (cpass > 0) {
        do {
            CStackFrame_Construct(&frame1);
            UnpackHelper__4VIFS3UPKiiPiPPUi(vifs, 0xD, 4, 0xA, 0, &punpack);
            memset(punpack, 0, 0x20);
            switch (index) {
            case 0:
                punpack->w[0] = 1;
                if (cpass == 1)
                    punpack->w[0] |= 8;
                if (pglobd->grf == 2)
                    punpack->w[0] |= 0x400;
                break;
            case 1:
                punpack->w[0] = 2;
                break;
            }
            int next = index + 1;
            punpack->w[1] = base;
            SHD *pshd = PshdFromIndex(pbis->U16Read());
            int cvtx = pbis->U8Read();
            int cpos = pbis->U8Read();
            VECTOR *apos = (VECTOR *)PvAllocStack(cpos * sizeof(VECTOR));
            for (int ipos = 0; ipos < cpos; ipos++)
                pbis->ReadVector(&apos[ipos]);
            int cweight = pglob->cweight < 4 ? pglob->cweight : 4;
            unsigned char *aweight;
            if (pglob->cweight != 0) {
                for (int slot = 0; slot < 4; slot++)
                    punpack->aweight[slot] = pglob->base + pbis->U8Read() * 4;
                aweight = (unsigned char *)PvAllocStack(cweight * cpos);
                CBinaryInputStream_Read_thunk(pbis, cweight * cpos, aweight);
            } else {
                aweight = 0;
            }
            unsigned char *aipos = (unsigned char *)PvAllocStack(cvtx);
            CBinaryInputStream_Read_thunk(pbis, cvtx, aipos);
            int cbBits = (cvtx + 31) / 32 * 4;
            unsigned int *abits = (unsigned int *)PvAllocStack(cbBits);
            CBinaryInputStream_Read_thunk(pbis, cbBits, abits);
            int cursor = base;
            for (int ishd = 0; ishd < pshd->cpass; ishd++) {
                punpack->ashd[ishd] = cursor;
                cursor += func_001EC688(pshd, ishd, cursor, vifs);
            }
            cursor++;
            punpack->w[8] = cursor;
            cursor += cvtx * 2;
            punpack->w[9] = cursor;
            punpack->w[2] = cvtx;
            AddVifStcycl__4VIFSii(vifs, 1, 2);
            if (pglob->cweight != 0) {
                int fShort = cweight < 4;
                if (fShort) {
                    AddVifStrow__4VIFSP2QW(vifs, B_002DEB60);
                    AddVifStmask__4VIFSUi(vifs, D_002BE540[cweight]);
                }
                UnpackHelper__4VIFS3UPKiiPiPPUi(vifs, D_002BE558[cweight], cvtx, punpack->w[8], 0, &pweights);
                if (fShort)
                    AddVifStmask__4VIFSUi(vifs, 0);
            }
            UnpackHelper__4VIFS3UPKiiPiPPUi(vifs, 0xC, cvtx, punpack->w[8] + 1, 0, &pvtx);
            AddVifStcycl__4VIFSii(vifs, 1, 1);
            unsigned int mask = 1;
            for (int ivtx = 0; ivtx < cvtx; ivtx++) {
                VECTOR *pdst = &pvtx[ivtx];
                VECTOR pos = apos[aipos[ivtx]];
                float x = func_002599D8(&pos);
                float y = func_002599E0(&pos);
                pdst->z = func_002599E8(&pos);
                pdst->x = x;
                pdst->y = y;
                if (*abits & mask)
                    pvtx[ivtx].w = 8421376.0f;
                else
                    pvtx[ivtx].w = 8417280.0f;
                mask <<= 1;
                if (mask == 0) {
                    abits++;
                    mask = 1;
                }
            }
            if (pglob->cweight != 0) {
                for (int ivtx = 0; ivtx < cvtx; ivtx++)
                    CopyAb(pweights + ivtx * cweight, aweight + aipos[ivtx] * cweight, cweight);
            }
            AddVifMscal__4VIFSPv(vifs, VU1_START_0);
            index = next;
            AddVifMscal__4VIFSPv(vifs, D_00001910);
            AddVifMscal__4VIFSPv(vifs, D_00001A68);
            CStackFrame_Destructor(&frame1, 2);
        } while (index < cpass);
    }
    EndDmaCnt__4DMAS(vifs);
    AddDmaRet__4DMAS(vifs);
    DMAS_DetachCopyPermanent(vifs, &pglob->dma, &dmaOut, &pglobi->dma);
    func_001699E8(pv, pglob, pglobi, arg4, arg5, 0, 0, 0, pbis);
    CStackFrame_Destructor(frame0, 2);
}
