#include "sly2.h"
#include "bis.h"
typedef CBinaryInputStream Bis;
struct SLOTHEAP;
struct BLOT { char pad[0xC4]; SLOTHEAP *heap; };
struct B4 { char b[4]; };
struct M3 { QW r[3]; };
#include "alloc.h"
struct PRIM { int w0; int w4; int colour; unsigned char cvtx; char p0[3]; int cslot; unsigned char b14; char p1[3]; short *axy; unsigned char hasBytes; char p2[3]; unsigned char *abyte; };
struct BATCH { int cprim; int cslot; int cvtx; PRIM *pfirst; PRIM *pend; };
struct CHAR { int id; int kind; void *owner; int pad0; union { struct { unsigned short cprim; unsigned short cbatch; int cvtxTotal; int cqw; int pk; } shape; float f[13]; int i[13]; } u; };
struct SVEC { short x, y; };
struct B8 { char b[8]; };
struct PL { long v; } __attribute__((packed));
struct GIFSX { char pad0[4]; char *ab; char pad1[4]; char *pb; char pad2[0x20]; };
struct L { char frame[0x10] __attribute__((aligned(16))); M3 mat; union { ALLOCREQ req; char vifs[0x30]; M3 mat2; struct { SVEC lt; SVEC pad[3]; SVEC rb; } sv; } a; char frame2[0x10] __attribute__((aligned(16))); union { GIFSX gifs; int cprimBatch; } b; char vifs2[0x30]; };
extern "C" {
void CBinaryInputStream_Read_thunk(Bis *, int, void *);
void *PvAllocSlotheapClearImpl__FP8SLOTHEAP(SLOTHEAP *, int, int);
void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void LoadMovieDictionary(BLOT *, Bis *, void *, void *, void *);
void __4GIFS(void *);
void AllocStack__4DMASi(void *, int);
void AddPrimPack__4GIFSiiUl(void *, int, int, unsigned long);
void PackAD__4GIFSll(void *, long, long);
void PackRGBA__4GIFSUi(void *, unsigned);
void PackSTQ__4GIFSfff(void *, float, float, float);
void PackXYZ__4GIFSiii(void *, int, int, int);
void EndPrim__4GIFSi(void *, int);
void __4VIFS(void *);
void AddDmaCnt__4DMAS(void *);
void AddDmaRet__4DMAS(void *);
void EndDmaCnt__4DMAS(void *);
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
void AddVifMscal__4VIFSPv(void *, void *);
void AddVifStrow__4VIFSP2QW(void *, void *);
void AddVifStcycl__4VIFSii(void *, int, int);
void UnpackHelper__4VIFS3UPKiiPiPPUi(void *, int, int, int, int *, unsigned **);
void AddVifStmask__4VIFSUi(void *, unsigned);
void DMAS_DetachCopy(void *, SLOTHEAP *, void *, int, void *);
void QueueSwCallback(void *, BLOT *, long, void *);
extern int D_002C40A4;
extern char B_003DD490[];
extern char g_2a2e10[];
extern const B8 RO_002A8B08;
extern char VU1_ENTRY_650[], VU1_ENTRY_140[];
}
static inline ALLOCREQ *Aligned(ALLOCREQ *preq)
{
    preq->cbAlign = 0x10;
    return preq;
}
void LoadMovieCharacter(BLOT *pblot, Bis *pbis, void *owner, int cchar, char *achar)
{
    L l;
    CStackFrame_Construct(l.frame);
    int ichar = pbis->U16Read();
    CHAR *pchar = (CHAR *)(achar + ichar * 0x40);
    pchar->id = ichar;
    pchar->owner = owner;
    unsigned kind = pbis->U32Read();
    pchar->kind = kind;
    switch (kind) {
    case 0:
    case 5:
        break;
    case 4:
        pchar->u.i[0] = pbis->U16Read();
        break;
    case 8: {
        D_002C40A4 = 1;
        LoadMovieDictionary(pblot, pbis, owner, &pchar->u.i[0], &pchar->u.i[1]);
        pchar->u.i[4] = pbis->U32Read();
        pchar->u.i[5] = (int)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, pchar->u.i[4] << 2, 0x13);
        for (int icode = 0; icode < pchar->u.i[4]; icode++)
            ((unsigned *)pchar->u.i[5])[icode] = pbis->U32Read();
        pchar->u.i[2] = pbis->U32Read();
        pchar->u.i[3] = (int)PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, pchar->u.i[2] << 2, 0x13);
        for (int iadvance = 0; iadvance < pchar->u.i[2]; iadvance++)
            ((float *)pchar->u.i[3])[iadvance] = pbis->F32Read();
        D_002C40A4 = 0;
        break;
    }
    case 3: {
        pchar->u.i[0] = pbis->U32Read();
        pchar->u.i[3] = pbis->U32Read();
        pchar->u.f[4] = pbis->F32Read();
        pchar->u.f[6] = pbis->F32Read();
        pchar->u.f[5] = pbis->F32Read();
        pchar->u.i[7] = pbis->S8Read();
        int textk = pbis->S8Read();
        pchar->u.i[1] = textk;
        if (textk == 1) goto rd;
        if (textk != 0) goto nord;
    rd:
        pchar->u.i[2] = pbis->S32Read();
    nord:
        if (pchar->u.i[1] == 1 && pchar->u.i[2] == 0x2F2)
            pchar->u.i[8] = 1;
        else
            pchar->u.i[8] = 0;
        break;
    }
    case 2: {
        CBinaryInputStream_ReadMatrix(pbis, (MATRIX3 *)&l.mat);
        l.a.mat2 = l.mat;
        float *pf = &pchar->u.f[0];
        float *pm = (float *)&l.a.mat2;
        pf[0] = pm[0];
        pf[1] = pm[1];
        pf[2] = pm[4];
        pf[3] = pm[5];
        pf[4] = pm[8];
        pf[5] = pm[9];
        *(unsigned short *)&pchar->u.i[8] = pbis->U16Read();
        void *pv = PvAllocSlotheapClearImpl__FP8SLOTHEAP(pblot->heap, *(unsigned short *)&pchar->u.i[8] * 0x18, 0x14);
        pchar->u.i[9] = (int)pv;
        CBinaryInputStream_Read_thunk(pbis, *(unsigned short *)&pchar->u.i[8] * 0x18, pv);
        break;
    }
    case 6:
    case 7: {
        l.a.sv.lt.x = pbis->S16Read();
        l.a.sv.lt.y = pbis->S16Read();
        l.a.sv.rb.x = pbis->S16Read();
        l.a.sv.rb.y = pbis->S16Read();
        int oid = pbis->S32Read();
        CStackFrame_Construct(l.frame2);
        __4GIFS(&l.b.gifs);
        AllocStack__4DMASi(&l.b.gifs, 0x10);
        AddPrimPack__4GIFSiiUl(&l.b.gifs, 0, 1, 0xE);
        pchar->u.i[0] = oid;
        if (pchar->kind == 6) {
            pchar->u.i[1] = 0;
            PackAD__4GIFSll(&l.b.gifs, 0x47, 0x5000F);
            PackAD__4GIFSll(&l.b.gifs, 0x42, 0x80000000A8UL);
        } else {
            PackAD__4GIFSll(&l.b.gifs, 0x42, 0x44);
            PackAD__4GIFSll(&l.b.gifs, 0x47, 0x50000);
        }
        AddPrimPack__4GIFSiiUl(&l.b.gifs, 0x54, 9, 0x525252521UL);
        PackRGBA__4GIFSUi(&l.b.gifs, 0x80808080);
        if (pchar->kind == 6) {
            PackSTQ__4GIFSfff(&l.b.gifs, 0.0f, 0.0f, 0.0f);
            PackXYZ__4GIFSiii(&l.b.gifs, l.a.sv.lt.x, l.a.sv.lt.y, 0);
            PackSTQ__4GIFSfff(&l.b.gifs, 1.0f, 0.0f, 0.0f);
            PackXYZ__4GIFSiii(&l.b.gifs, l.a.sv.rb.x, l.a.sv.lt.y, 0);
            PackSTQ__4GIFSfff(&l.b.gifs, 0.0f, 1.0f, 0.0f);
            PackXYZ__4GIFSiii(&l.b.gifs, l.a.sv.lt.x, l.a.sv.rb.y, 0);
            PackSTQ__4GIFSfff(&l.b.gifs, 1.0f, 1.0f, 0.0f);
            PackXYZ__4GIFSiii(&l.b.gifs, l.a.sv.rb.x, l.a.sv.rb.y, 0);
            AddPrimPack__4GIFSiiUl(&l.b.gifs, 0, 1, 0xE);
            PackAD__4GIFSll(&l.b.gifs, 0x42, 0x44);
            PackAD__4GIFSll(&l.b.gifs, 0x47, 0x50000);
        } else {
            PackSTQ__4GIFSfff(&l.b.gifs, 0.0f, 1.0f, 0.0f);
            PackXYZ__4GIFSiii(&l.b.gifs, l.a.sv.lt.x, l.a.sv.lt.y, 0);
            PackSTQ__4GIFSfff(&l.b.gifs, 1.0f, 1.0f, 0.0f);
            PackXYZ__4GIFSiii(&l.b.gifs, l.a.sv.rb.x, l.a.sv.lt.y, 0);
            PackSTQ__4GIFSfff(&l.b.gifs, 0.0f, 0.0f, 0.0f);
            PackXYZ__4GIFSiii(&l.b.gifs, l.a.sv.lt.x, l.a.sv.rb.y, 0);
            PackSTQ__4GIFSfff(&l.b.gifs, 1.0f, 0.0f, 0.0f);
            PackXYZ__4GIFSiii(&l.b.gifs, l.a.sv.rb.x, l.a.sv.rb.y, 0);
        }
        EndPrim__4GIFSi(&l.b.gifs, 1);
        __4VIFS(l.vifs2);
        AllocStack__4DMASi(l.vifs2, 0x14);
        AddDmaCnt__4DMAS(l.vifs2);
        char *pstart = l.b.gifs.ab;
        char *pcur = l.b.gifs.pb;
        AddVifUnpack__4VIFS3UPKiPvi(l.vifs2, 0xC, (unsigned)(pcur - pstart) >> 4, pstart, 7);
        AddVifMscal__4VIFSPv(l.vifs2, VU1_ENTRY_650);
        EndDmaCnt__4DMAS(l.vifs2);
        AddDmaRet__4DMAS(l.vifs2);
        if (pchar->kind == 6) {
            DMAS_DetachCopy(l.vifs2, pblot->heap, &pchar->u.i[2], 0, &pchar->u.i[3]);
        } else {
            DMAS_DetachCopy(l.vifs2, pblot->heap, &pchar->u.i[1], 0, &pchar->u.i[2]);
            QueueSwCallback(B_003DD490, pblot, ((const PL *)&RO_002A8B08)->v, pchar);
        }
        CStackFrame_Destructor(l.frame2, 2);
        break;
    }
    case 1: {
        pchar->u.shape.cprim = pbis->U16Read();
        l.a.req.cb = pchar->u.shape.cprim * 0x24;
        PRIM *aprim = (PRIM *)PvAllocStackClearImpl__Fi(Aligned(&l.a.req));
        l.a.req.cb = pchar->u.shape.cprim * 0x14;
        BATCH *abatch = (BATCH *)PvAllocStackClearImpl__Fi(Aligned(&l.a.req));
        for (int iprim = 0; iprim < pchar->u.shape.cprim; iprim++) {
            PRIM *pprim = aprim + iprim;
            pprim->cvtx = pbis->U8Read();
            pprim->b14 = pbis->U8Read();
            pprim->w0 = pbis->U8Read();
            pprim->w4 = pbis->U8Read();
            pprim->hasBytes = pbis->U8Read();
            pprim->cslot = pprim->cvtx + 2;
            l.a.req.cb = pprim->cvtx << 2;
            pprim->axy = (short *)PvAllocStackClearImpl__Fi(Aligned(&l.a.req));
            l.a.req.cb = pprim->cvtx;
            pprim->abyte = (unsigned char *)PvAllocStackClearImpl__Fi(Aligned(&l.a.req));
            for (int ivtx = 0; ivtx < pprim->cvtx; ivtx++) {
                short *pxy = (short *)((char *)pprim->axy + ivtx * 4);
                pprim->colour = pbis->U32Read();
                pprim->abyte[ivtx] = pbis->U8Read();
                pxy[0] = pbis->S16Read();
                pxy[1] = pbis->S16Read();
            }
        }
        pchar->u.shape.cbatch = 0;
        pchar->u.shape.cqw = 0;
        pchar->u.shape.cvtxTotal = 0;
        int iprim = 0;
        while (iprim < pchar->u.shape.cprim) {
            BATCH *pbatch = abatch + pchar->u.shape.cbatch;
            pbatch->cprim = 0;
            pbatch->cvtx = 0;
            pbatch->cslot = 0;
            pbatch->pfirst = aprim + iprim;
            while (iprim < pchar->u.shape.cprim && pbatch->cslot + aprim[iprim].cslot < 0xBD) {
                pbatch->cslot += aprim[iprim].cslot;
                pbatch->cprim += 1;
                pbatch->pend = aprim + iprim + 1;
                pbatch->cvtx += aprim[iprim].cvtx;
                iprim++;
            }
            int cprimBatch = pbatch->cprim;
            int cvtxBatch = pbatch->cvtx;
            pchar->u.shape.cqw += (cvtxBatch + 1) / 4 + cvtxBatch / 16 + (cprimBatch * 3 + 3) / 4 + 3;
            pchar->u.shape.cbatch += 1;
            pchar->u.shape.cvtxTotal += pbatch->cvtx;
        }
        __4VIFS(l.a.vifs);
        AllocStack__4DMASi(l.a.vifs, pchar->u.shape.cqw << 1);
        AddDmaCnt__4DMAS(l.a.vifs);
        AddVifStrow__4VIFSP2QW(l.a.vifs, g_2a2e10);
        for (int ibatch = 0; ibatch < pchar->u.shape.cbatch; ibatch++) {
            BATCH *pbatch = abatch + ibatch;
            l.b.cprimBatch = pbatch->cprim;
            AddVifUnpack__4VIFS3UPKiPvi(l.a.vifs, 4, 1, &l.b.cprimBatch, 7);
            AddVifStcycl__4VIFSii(l.a.vifs, 1, 2);
            unsigned *pbHeader = 0;
            unsigned *pwColor = 0;
            UnpackHelper__4VIFS3UPKiiPiPPUi(l.a.vifs, 0xA, pbatch->cprim, 8, 0, &pbHeader);
            UnpackHelper__4VIFS3UPKiiPiPPUi(l.a.vifs, 0xE, pbatch->cprim, 9, 0, &pwColor);
            int iqwVtx = pbatch->cprim * 2 + 8;
            AddVifStcycl__4VIFSii(l.a.vifs, 1, 1);
            int iqwXy = iqwVtx;
            AddVifStmask__4VIFSUi(l.a.vifs, 0x50505050);
            int iprimBatch = 0;
            int ibHeader = 0;
            for (PRIM *pprim = pbatch->pfirst; pprim != pbatch->pend; pprim++) {
                ((unsigned char *)pbHeader)[ibHeader] = pprim->w0;
                ((unsigned char *)pbHeader)[ibHeader + 1] = pprim->cvtx;
                ((unsigned char *)pbHeader)[ibHeader + 2] = pprim->b14;
                ibHeader += 3;
                *(B4 *)&pwColor[iprimBatch] = *(B4 *)&pprim->colour;
                iprimBatch++;
                AddVifUnpack__4VIFS3UPKiPvi(l.a.vifs, 0x15, pprim->cvtx, pprim->axy, iqwXy);
                iqwXy += pprim->cvtx;
            }
            AddVifStmask__4VIFSUi(l.a.vifs, 0x3F3F3F3F);
            for (PRIM *pprim = pbatch->pfirst; pprim != pbatch->pend; pprim++) {
                if (pprim->hasBytes)
                    AddVifUnpack__4VIFS3UPKiPvi(l.a.vifs, 0x12, pprim->cvtx, pprim->abyte, iqwVtx);
                iqwVtx += pprim->cvtx;
            }
            AddVifStmask__4VIFSUi(l.a.vifs, 0);
            AddVifMscal__4VIFSPv(l.a.vifs, VU1_ENTRY_140);
        }
        EndDmaCnt__4DMAS(l.a.vifs);
        AddDmaRet__4DMAS(l.a.vifs);
        DMAS_DetachCopy(l.a.vifs, pblot->heap, &pchar->u.shape.cqw, 0, &pchar->u.shape.pk);
        break;
    }
    }
    CStackFrame_Destructor(l.frame, 2);
}
