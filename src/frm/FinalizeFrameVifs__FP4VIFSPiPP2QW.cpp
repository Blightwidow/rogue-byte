// SPDX-License-Identifier: GPL-3.0-or-later
struct GIFS { char pad[0x30]; };
struct VIFS { char pad[0x30]; };
struct QW { char b[16]; } __attribute__((aligned(16)));
extern "C" {
void __4GIFS(GIFS *);
void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
void PackAD__4GIFSll(GIFS *, long, long);
void AddPrimEnd__4GIFS(GIFS *);
void AddDmaCnt__4DMAS(VIFS *);
void AddVifFlush__4VIFS(VIFS *);
void AddVifGifs__4VIFSP4GIFS(VIFS *, GIFS *);
void EndDmaCnt__4DMAS(VIFS *);
void EnsureVu1Code__FP4VIFSPvT1(VIFS *, void *, void *);
void AddDmaEnd__4DMAS(VIFS *);
void Detach__4DMASPiPP2QW(VIFS *, int *, QW **);
extern char RO_0025E680[];
extern char RO_00262320[];
}
void FinalizeFrameVifs(VIFS *pvifs, int *pcqw, QW **ppqw)
{
    QW buffer[8];
    GIFS gifs;
    __4GIFS(&gifs);
    AllocStatic__4DMASiP2QW(&gifs, 8, buffer);
    AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
    PackAD__4GIFSll(&gifs, 0x61, 0);
    AddPrimEnd__4GIFS(&gifs);
    AddDmaCnt__4DMAS(pvifs);
    AddVifFlush__4VIFS(pvifs);
    AddVifGifs__4VIFSP4GIFS(pvifs, &gifs);
    EndDmaCnt__4DMAS(pvifs);
    EnsureVu1Code__FP4VIFSPvT1(pvifs, RO_0025E680, RO_00262320);
    AddDmaEnd__4DMAS(pvifs);
    Detach__4DMASPiPP2QW(pvifs, pcqw, ppqw);
}
