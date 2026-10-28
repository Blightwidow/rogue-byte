#include "sly2.h"
struct GIFS { char pad[0x30]; };
struct GSB;
struct SFRAME { int a; QW *pqw; int pad[2]; };
struct DMACHAN;
extern int B_003DCF98;
extern int B_003DCF9C;
extern DMACHAN *g_2de598;
extern "C" void __4GIFS(GIFS *);
extern "C" void CStackFrame_Construct(SFRAME *);
extern "C" void CStackFrame_Destructor(SFRAME *, int);
extern "C" void AllocStack__4DMASi(GIFS *, int);
extern "C" void AddDmaCnt__4DMAS(GIFS *);
extern "C" int FBuildUploadBitmapGifs__FiP3GSBP4GIFS(int, GSB *, GIFS *);
extern "C" void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
extern "C" void PackAD__4GIFSll(GIFS *, long, long);
extern "C" void AddPrimEnd__4GIFS(GIFS *);
extern "C" void AddDmaEnd__4DMAS(GIFS *);
extern "C" void Detach__4DMASPiPP2QW(GIFS *, int *, QW **);
extern "C" void SendDmaSyncGsFinish__FP10sceDmaChanP2QW(DMACHAN *, QW *);
extern "C" void UploadBitmaps__FiP3GSB(GSB *pgsb)
{
    GIFS gifs;
    SFRAME frame;
    __4GIFS(&gifs);
    CStackFrame_Construct(&frame);
    AllocStack__4DMASi(&gifs, (B_003DCF9C * 3 + B_003DCF98) * 8 | 4);
    AddDmaCnt__4DMAS(&gifs);
    if (FBuildUploadBitmapGifs__FiP3GSBP4GIFS(1, pgsb, &gifs) != 0) {
        AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
        PackAD__4GIFSll(&gifs, 0x3F, 0);
        PackAD__4GIFSll(&gifs, 0x61, 0);
        AddPrimEnd__4GIFS(&gifs);
        AddDmaEnd__4DMAS(&gifs);
        Detach__4DMASPiPP2QW(&gifs, 0, &frame.pqw);
        SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de598, frame.pqw);
    }
    CStackFrame_Destructor(&frame, 2);
}
