// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct GIFS_16FCA8 { char pad[0x30]; };
struct VIFS_16FCA8 { char pad[0x30]; };
struct GSFRAME_16FCA8 {
    unsigned long FBP : 9;
    unsigned long pad0 : 7;
    unsigned long FBW : 6;
    unsigned long pad1 : 2;
    unsigned long PSM : 6;
    unsigned long pad2 : 2;
    unsigned long FBMSK : 32;
};
struct GSTEX0_16FCA8 {
    unsigned long TBP0 : 14;
    unsigned long TBW : 6;
    unsigned long PSM : 6;
    unsigned long TW : 4;
    unsigned long TH : 4;
    unsigned long TCC : 1;
    unsigned long TFX : 2;
    unsigned long CBP : 14;
    unsigned long CPSM : 4;
    unsigned long CSM : 1;
    unsigned long CSA : 5;
    unsigned long CLD : 3;
};
union FRAMEU_16FCA8 { GSFRAME_16FCA8 f; unsigned long ul; };
union TEX0U_16FCA8 { GSTEX0_16FCA8 f; unsigned long ul; };
struct ENV_16FCA8 {
    FRAMEU_16FCA8 frame; long pad0;
    long zbuf; long pad1;
    long xyoffset; long pad2;
    long scissor; long pad3;
    char pad4[0x70 - 0x40];
    long test; long pad5;
    char pad6[0xF0 - 0x80];
};
struct VIFBUF_16FCA8 { int frame[2]; int tex0[2]; int frame16[2]; int tex016[2]; };
extern "C" {
void __4GIFS(GIFS_16FCA8 *);
void AllocStatic__4DMASiP2QW(void *, int, QW *);
void AddPrimPack__4GIFSiiUl(GIFS_16FCA8 *, int, int, unsigned long);
void PackAD__4GIFSll(GIFS_16FCA8 *, long, long);
void AddPrimEnd__4GIFS(GIFS_16FCA8 *);
void __4VIFS(VIFS_16FCA8 *);
void AddDmaCnt__4DMAS(VIFS_16FCA8 *);
void AddVifDirectRefs__4VIFSiP2QWi(VIFS_16FCA8 *, int, QW *, int);
void AddVifBaseOffset__4VIFSii(VIFS_16FCA8 *, int, int);
void AddVifUnpack__4VIFS3UPKiPvi(VIFS_16FCA8 *, int, int, void *, int);
void EndDmaCnt__4DMAS(VIFS_16FCA8 *);
void AddDmaRet__4DMAS(VIFS_16FCA8 *);
extern int g_2dedb0;
extern ENV_16FCA8 g_2decd0;
extern ENV_16FCA8 B_002DEBE0;

void BuildDrawEnvGifs(int cqwGifs, QW *aqwGifs, int cqwVifs, QW *aqwVifs, int fbmsk)
{
    ENV_16FCA8 *penv;
    ENV_16FCA8 *penvOther;
    if (g_2dedb0 & 1) {
        penv = &g_2decd0;
        penvOther = penv - 1;
    } else {
        penv = &B_002DEBE0;
        penvOther = penv + 1;
    }
    GIFS_16FCA8 gifs;
    __4GIFS(&gifs);
    AllocStatic__4DMASiP2QW(&gifs, cqwGifs, aqwGifs);
    AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
    PackAD__4GIFSll(&gifs, 0x4C, penv->frame.f.FBP | (penv->frame.f.FBW << 16) | (penv->frame.f.PSM << 24) | ((unsigned long)fbmsk << 32));
    PackAD__4GIFSll(&gifs, 0x4E, penv->zbuf);
    PackAD__4GIFSll(&gifs, 0x18, penv->xyoffset);
    PackAD__4GIFSll(&gifs, 0x40, penv->scissor);
    PackAD__4GIFSll(&gifs, 0x47, penv->test);
    AddPrimPack__4GIFSiiUl(&gifs, 0x200, 1, 0xE);
    PackAD__4GIFSll(&gifs, 0x4D, penv->frame.f.FBP | (penv->frame.f.FBW << 16) | (penv->frame.f.PSM << 24) | ((unsigned long)fbmsk << 32));
    PackAD__4GIFSll(&gifs, 0x4F, penv->zbuf);
    PackAD__4GIFSll(&gifs, 0x19, penv->xyoffset);
    PackAD__4GIFSll(&gifs, 0x41, penv->scissor);
    PackAD__4GIFSll(&gifs, 0x48, penv->test);
    AddPrimEnd__4GIFS(&gifs);

    VIFBUF_16FCA8 buf;
    memset(&buf, 0, sizeof(buf));
    GSFRAME_16FCA8 frame;
    GSTEX0_16FCA8 tex0;
    frame = penv->frame.f;
    tex0.TBP0 = frame.FBP << 5;
    tex0.TBW = frame.FBW;
    tex0.PSM = 0;
    tex0.TW = 10;
    tex0.TH = 10;
    tex0.TCC = 1;
    tex0.TFX = 0;
    buf.frame[0] = *(int *)&frame;
    buf.tex0[0] = *(int *)&tex0;
    frame.PSM = 2;
    tex0.PSM = 2;
    buf.frame16[0] = *(int *)&frame;
    buf.tex016[0] = *(int *)&tex0;
    frame = penvOther->frame.f;
    tex0.TBP0 = frame.FBP << 5;
    tex0.TBW = frame.FBW;
    tex0.PSM = 0;
    buf.frame[1] = *(int *)&frame;
    buf.tex0[1] = *(int *)&tex0;
    frame.PSM = 2;
    tex0.PSM = 2;
    buf.frame16[1] = *(int *)&frame;
    buf.tex016[1] = *(int *)&tex0;

    VIFS_16FCA8 vifs;
    __4VIFS(&vifs);
    AllocStatic__4DMASiP2QW(&vifs, cqwVifs, aqwVifs);
    AddDmaCnt__4DMAS(&vifs);
    AddVifDirectRefs__4VIFSiP2QWi(&vifs, cqwGifs, aqwGifs, 0);
    AddVifBaseOffset__4VIFSii(&vifs, 0, 0);
    AddVifUnpack__4VIFS3UPKiPvi(&vifs, 0xC, 2, &buf, 0xB);
    EndDmaCnt__4DMAS(&vifs);
    AddDmaRet__4DMAS(&vifs);
}
}
