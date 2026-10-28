#include "sly2.h"
struct GIFS { char pad[0x30]; };
struct CTextBox { float x, y, dx, dy; };
struct CFontBrx { char pad[0x3C]; int fGstest; long gstest; char pad48[8]; long tex0; };
extern "C" void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
extern "C" void PackAD__4GIFSll(GIFS *, long, long);
extern "C" void AddPrimList__4GIFSiUl(GIFS *, int, unsigned long);
extern "C" int FEnsureLoaded__8CFontBrxP4GIFS(CFontBrx *, GIFS *);

extern "C" int SetupDraw__8CFontBrxP8CTextBoxP4GIFS(CFontBrx *pfont, CTextBox *ptbx, GIFS *pgifs)
{
    if (ptbx != 0) {
        float x = ptbx->x;
        float y = ptbx->y;
        float dx = ptbx->dx;
        float dy = ptbx->dy;
        int xStart = (int)(x * 0.8f);
        int xEnd = (int)((x + dx * 512.0f) * 0.0015625f);
        int yStart = (int)(y * 0.45454547f);
        int yEnd = (int)((y + dy) * 0.45454547f);
        AddPrimPack__4GIFSiiUl(pgifs, 0, 1, 0xE);
        PackAD__4GIFSll(pgifs, 0x40, (long)xStart | (long)(xEnd - 1) << 16 | (long)yStart << 32 | (long)(yEnd - 1) << 48);
    }
    int fLoaded = FEnsureLoaded__8CFontBrxP4GIFS(pfont, pgifs);
    AddPrimPack__4GIFSiiUl(pgifs, 6, 1, 0xE);
    if (fLoaded)
        PackAD__4GIFSll(pgifs, 0x3F, 0);
    long gstest = 0x31001;
    if (pfont->fGstest)
        gstest = pfont->gstest;
    PackAD__4GIFSll(pgifs, 0x47, gstest);
    PackAD__4GIFSll(pgifs, 0x42, 0x44);
    PackAD__4GIFSll(pgifs, 6, pfont->tex0);
    PackAD__4GIFSll(pgifs, 0x14, 0x60);
    PackAD__4GIFSll(pgifs, 8, 5);
    PackAD__4GIFSll(pgifs, 0, 0x1D6);
    AddPrimList__4GIFSiUl(pgifs, 5, 0x43431);
    return 0;
}
