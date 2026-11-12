#include "sly2.h"
struct QWL { long lo; long hi; };
struct GIFS { char pad0[0xC]; QWL *pend; char pad10[0x20]; };
struct VIFS { char pad[0x30]; };
struct SFRAME { int a; QW *pqw; int pad[2]; };
struct Ctl { int pad0; int f4; int f8; };
struct Clut { int id; unsigned char group; char pad5[5]; unsigned short size; int fC; int f10; long f18; };
struct Bmp { int id; unsigned char group; char pad5[7]; unsigned char fC; char padD; unsigned short size; int f10; int f14; int f18; int pad1C; long f20; };
extern "C" {
void __4GIFS(GIFS *);
void __4VIFS(VIFS *);
int CStackFrame_Construct(SFRAME *);
void CStackFrame_Destructor(SFRAME *, int);
void AllocStack__4DMASi(VIFS *, int);
void AddDmaCnt__4DMAS(VIFS *);
void AddVifFlush__4VIFS(VIFS *);
void Reset__4DMAS(GIFS *);
void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
int AllocZpr(Ctl *, int);
void BuildClutTex2__FP4CLUTi(Clut *, int);
void BuildClutGifs__FP4CLUTiP4GIFS(Clut *, int, GIFS *);
void BuildBmpTex0__FP3BMPi(Bmp *, int);
void BuildBmpGifs__FP3BMPiP4GIFS(Bmp *, int, GIFS *);
void Detach__4DMASPiPP2QW(GIFS *, int *, QW **);
void AddVifDirect__4VIFSiP2QWi(VIFS *, int, QW *, int);
void AddVifDirectRefs__4VIFSiP2QWi(VIFS *, int, int, int);
void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
void PackAD__4GIFSll(GIFS *, long, long);
void AddPrimEnd__4GIFS(GIFS *);
void EndDmaCnt__4DMAS(VIFS *);
void AddDmaRet__4DMAS(VIFS *);
void DMAS_DetachCopyPermanent(VIFS *, int, int, int *);
extern int B_003DCF98;
extern int B_003DCF9C;
extern int B_003DCFF0;
extern Bmp *B_003DCFF4;
extern int B_003DCFF8;
extern Clut *B_003DCFFC;
}
extern "C" int PqwVifsBitmapUpload__Fi(Ctl *pctl, int group)
{
    GIFS gifs;
    VIFS vifs;
    SFRAME frame;
    QW aqw[10];
    int cbDetach;
    QW *pqwDetach;
    int result;
    int cStart;
    int i;
    i = 0;
    __4GIFS(&gifs);
    result = 0;
    __4VIFS(&vifs);
    cStart = pctl->f4;
    CStackFrame_Construct(&frame);
    AllocStack__4DMASi(&vifs, (B_003DCF9C * 3 + B_003DCF98) * 10 + 4);
    AddDmaCnt__4DMAS(&vifs);
    AddVifFlush__4VIFS(&vifs);
    for (i = 0; i < B_003DCFF8; i++) {
        Clut *pclut = &B_003DCFFC[i];
        if (pclut->group == group) {
            Reset__4DMAS(&gifs);
            AllocStatic__4DMASiP2QW(&gifs, 10, aqw);
            int zpr = AllocZpr(pctl, pclut->size);
            BuildClutTex2__FP4CLUTi(pclut, zpr);
            BuildClutGifs__FP4CLUTiP4GIFS(pclut, zpr, &gifs);
            { QWL *pqwl = gifs.pend - 1; pqwl->lo = pqwl->lo | 0x8000; }
            Detach__4DMASPiPP2QW(&gifs, &cbDetach, (QW **)&pqwDetach);
            AddVifDirect__4VIFSiP2QWi(&vifs, cbDetach, pqwDetach, 0);
            AddVifDirectRefs__4VIFSiP2QWi(&vifs, pclut->f10, pclut->fC, 0);
        }
    }
    for (i = 0; i < B_003DCFF0; i++) {
        Bmp *pbmp = &B_003DCFF4[i];
        if (group == pbmp->group) {
            Reset__4DMAS(&gifs);
            AllocStatic__4DMASiP2QW(&gifs, 10, aqw);
            int zpr = AllocZpr(pctl, pbmp->size);
            BuildBmpTex0__FP3BMPi(pbmp, zpr);
            BuildBmpGifs__FP3BMPiP4GIFS(pbmp, zpr, &gifs);
            { QWL *pqwl = gifs.pend - 1; pqwl->lo = pqwl->lo | 0x8000; }
            Detach__4DMASPiPP2QW(&gifs, &cbDetach, (QW **)&pqwDetach);
            AddVifDirect__4VIFSiP2QWi(&vifs, cbDetach, pqwDetach, 0);
            AddVifDirectRefs__4VIFSiP2QWi(&vifs, pbmp->f18, pbmp->f14, 0);
        }
    }
    if (cStart < pctl->f4) {
        Reset__4DMAS(&gifs);
        AllocStatic__4DMASiP2QW(&gifs, 10, aqw);
        AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
        PackAD__4GIFSll(&gifs, 0x3F, 0);
        AddPrimEnd__4GIFS(&gifs);
        Detach__4DMASPiPP2QW(&gifs, &cbDetach, (QW **)&pqwDetach);
        AddVifDirect__4VIFSiP2QWi(&vifs, cbDetach, pqwDetach, 0);
        AddVifFlush__4VIFS(&vifs);
        EndDmaCnt__4DMAS(&vifs);
        AddDmaRet__4DMAS(&vifs);
        DMAS_DetachCopyPermanent(&vifs, 0, 0, &result);
    }
    int resultFinal = result;
    CStackFrame_Destructor(&frame, 2);
    return resultFinal;
}
