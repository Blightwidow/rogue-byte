// SPDX-License-Identifier: GPL-3.0-or-later
struct GIFS { char pad[0x30]; };
struct QW;
struct CMpeg { char pad0[0x110]; int ibDma; char pad114[0x118 - 0x114]; int uFrame; int vFrame; };
extern "C" {
GIFS *__4GIFS(GIFS *);
void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
void AddDmaCnt__4DMAS(GIFS *);
void AddDmaEnd__4DMAS(GIFS *);
void AddDmaRefs__4DMASiP2QW(GIFS *, int, int);
void Detach__4DMASPiPP2QW(GIFS *, int *, QW **);
void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
void AddPrimEnd__4GIFS(GIFS *);
void AddImage__4GIFSi(GIFS *, int);
void PackAD__4GIFSll(GIFS *, long, long);

void BuildMpegGifs__FP2QWP11sceIpuRGB32iiiii(CMpeg *pmpeg)
{
    GIFS gifs;
    int cbRow;
    int cbCol;
    int ibImage = pmpeg->ibDma + 0x285A80;
    cbRow = pmpeg->uFrame / 16;
    cbCol = pmpeg->vFrame / 16;
    __4GIFS(&gifs);
    AllocStatic__4DMASiP2QW(&gifs, 0x22D6, (QW *)(pmpeg->ibDma + 0x3F8E80));
    AddDmaCnt__4DMAS(&gifs);
    AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
    PackAD__4GIFSll(&gifs, 0x50, 0xC180L << 0x24);
    PackAD__4GIFSll(&gifs, 0x52, (0x8000L << 0x15) | 0x10);
    for (int row = 0; row < cbRow; row++) {
        for (int col = 0; col < cbCol; col++) {
            AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
            PackAD__4GIFSll(&gifs, 0x51, ((long)row << 0x24) | ((long)(col * 0x10) << 0x30));
            PackAD__4GIFSll(&gifs, 0x53, 0);
            AddImage__4GIFSi(&gifs, 0x40);
            AddDmaRefs__4DMASiP2QW(&gifs, 0x40, ibImage & 0x0FFFFFFF);
            ibImage += 0x400;
        }
    }
    AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
    PackAD__4GIFSll(&gifs, 0x3F, 0);
    PackAD__4GIFSll(&gifs, 0x61, 0);
    AddPrimEnd__4GIFS(&gifs);
    AddDmaEnd__4DMAS(&gifs);
    Detach__4DMASPiPP2QW(&gifs, 0, 0);
}
}
